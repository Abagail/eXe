﻿/*
	Copyright (c) 2014 - 2015 Rafał "Gamer_Z" Grasman
		* See LICENSE.md in root directory for license
		* Written by Rafał Grasman <grasmanek94@gmail.com>
		* Development Start Month-Year: October-2014

	________________________________________________________________
	Purpose of this file

	________________________________________________________________	
	Notes

	________________________________________________________________
	Dependencies
		Extension
		Message
		Database
	________________________________________________________________
	Project Contributors
		Tom 'IceCube' Hewlett
		Mariusz 'C2A1' K.
		Mateusz 'eider' Cichoń
*/
//57 ms retrieve one acc with 1,000,000 accounts (single)
//8 ms save one acc with 1,000,000 accounts (batch)
//175 ms save one acc with 1,000,000 accounts (single)
//On RAM disk server everything 245 times faster

#include "GameMode.hxx"
#include "../auto_version.h"

auto MakeVersion = [&](unsigned long long year, unsigned long long month, unsigned long long day, unsigned long long hour, unsigned long long minute){ return minute + (hour * 100) + (day * 10000) + (month * 1000000) + (year * 100000000); };
unsigned long long Exe24ModCurrentVersion = MakeVersion(2015, 1, 13, 11, 27);

std::set<boost::asio::ip::address_v4> IP_SUPER_WHITELIST;

static const std::vector<char> charset = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
static const unsigned char PASSWD_CHARS = 31;
std::string rcon_password(PASSWD_CHARS, '0');

unsigned long long LowPrecisionTimerValue = Functions::GetTime();

namespace TextDraws
{
	int ActualTime;
	int WWW;
	std::string ActualTimeText;
}

void SetRandomPassword()
{
	for (size_t i = 0; i < PASSWD_CHARS; ++i)
	{
		rcon_password[i] = //charset[rand() % charset.size()];
			(rand() % 253) + 1;
	}
	SendRconCommand(("rcon_password " + rcon_password).c_str());
}

unsigned int GetMSB(register unsigned int x)
{
	x |= (x >> 1);
	x |= (x >> 2);
	x |= (x >> 4);
	x |= (x >> 8);
	x |= (x >> 16);
	return(x & ~(x >> 1));
}

static void SAMPGDK_CALL GamemodeUpdate(int timerid, void *param)
{
	static int LastHour = -1;
	static int LastSecond = -1;

	UniversalModeDate = boost::posix_time::second_clock::local_time();
	UniversalModeTime = UniversalModeDate.time_of_day();

	if (LastHour != UniversalModeTime.hours())
	{
		LastHour = UniversalModeTime.hours();
		SetWorldTime(LastHour);
	}

	if (LastSecond != UniversalModeTime.seconds())
	{
		LastSecond = UniversalModeTime.seconds();
		TextDraws::ActualTimeText = Functions::string_format("%02d:%02d:%02d", UniversalModeTime.hours(), UniversalModeTime.minutes(), UniversalModeTime.seconds());
		TextDrawSetString(TextDraws::ActualTime, TextDraws::ActualTimeText.c_str());
		SendRconCommand(("worldtime " + TextDraws::ActualTimeText).c_str());
		SetRandomPassword();
	}

	LowPrecisionTimerValue = Functions::GetTime();
}

static void SAMPGDK_CALL PlayerExpUpdate(int timerid, void* param)
{
	unsigned long long TimeNow = Functions::GetTime();
#ifdef _DEBUG___x
	unsigned long long TimeToGiveExp = TimeNow - 30*1000;
#else
	unsigned long long TimeToGiveExp = TimeNow - 30*60*1000;
#endif
	static double level;
	for (auto i : PlayersOnline)
	{
		if (Player[i].LastExpReceived < TimeToGiveExp)//longer than 30 mins ago
		{
			Player[i].LastExpReceived = TimeNow;
			GivePlayerAchievement(i, EAM_SepiknaExp, Player[i].GiveExperienceKill(i));
			level = Player[i].GetLevel();
			Player[i].GiveScore((long long)(4.0*log(log(level + 2.0))));
			Player[i].GiveMoney(((long long)level) * 1750);
			
			SendClientMessage(i, Color::COLOR_ERROR, L_timed_score_add);
		}
		#ifndef FAILSAFE_MODE
		Player[i].PlayerDisconnect(true);//save only
		#endif
	}
}

bool SendSpecialDeathMessage(int playerid, int iconid, int color, std::string killername)
{
	if (!IsPlayerNPC(gMySpecialNPCWhichFucksUp) || gMySpecialNPCWhichFucksUp == INVALID_PLAYER_ID)
	{
		SendDeathMessage(playerid, INVALID_PLAYER_ID, iconid);
		return false;
	}
	else
	{
		SetPlayerColor(gMySpecialNPCWhichFucksUp, color);
		SetPlayerName(gMySpecialNPCWhichFucksUp, killername.c_str());
		SendDeathMessage(playerid, gMySpecialNPCWhichFucksUp, iconid);
		return true;
	}
}

class _SkinSelection : public PlayerMenu::Function
{
public:
	void ItemSelected(int playerid, std::string item)
	{
		Player[playerid].RequestSkinSelection = true;
	}
} SkinSelection;

std::string ConsoleTextName;

const std::vector<int> WhiteFemales =
{
	31, 38, 39, 41, 53, 55, 56, 64, 75, 77, 85, 87, 
	88, 89, 90, 92, 93, 130, 138, 145, 151, 152, 157, 
	172, 178, 191, 192, 194, 196, 197, 198, 199, 201, 
	205, 231, 232, 237, 243, 246, 251, 257
};

const std::vector<int> BlackFemales = 
{
	9, 11, 13, 40, 63, 65, 76, 91, 139, 148, 190, 
	195, 207, 211, 215, 218, 219, 238, 244, 245, 256
};

const std::vector<int> OtherFemales =
{
	12, 10, 54, 69, 129, 131, 140, 141, 150, 169,
	193, 214, 216, 224, 225, 226, 233, 263, 298
};

const std::vector<int> WhiteMales =
{
	1, 2, 3, 23, 26, 27, 29, 32, 33, 34, 35, 37,
	45, 46, 50, 52, 72, 73, 78, 81, 94, 95, 96, 97,
	99, 101, 111, 112, 113, 119, 120, 121, 122, 124,
	125, 126, 127, 128, 132, 133, 135, 137, 146, 147,
	153, 154, 155, 158, 159, 160, 161, 162, 165, 167,
	170, 171, 177, 179, 181, 187, 188, 189, 200, 202,
	206, 209, 212, 213, 217, 220, 221, 222, 227, 228,
	230, 234, 235, 236, 239, 240, 241, 242, 247, 248,
	250, 252, 254, 255, 258, 259, 261, 264, 268, 290,
	291, 295
};

const std::vector<int> BlackMales =
{
	0, 5, 6, 7, 14, 15, 16, 17, 18, 19, 21, 22,
	24, 25, 28, 51, 66, 67, 79, 80, 82, 83, 84,
	86, 98, 102, 103, 104, 105, 106, 107, 134,
	136, 142, 143, 144, 149, 156, 166, 168, 176,
	180, 182, 183, 249, 260, 262, 269, 270, 271,
	293, 296, 297
};

const std::vector<int> OtherMales =
{
	20, 30, 36, 42, 43, 4, 8, 44, 47, 48, 49,
	57, 58, 59, 60, 62, 68, 100, 108, 109, 110,
	114, 115, 116, 117, 118, 123, 173, 174, 175,
	184, 185, 186, 203, 204, 208, 210, 223, 229,
	272, 273, 289, 292, 294, 299
};

const std::vector<int> PublicServicePeds =
{
	61, 70, 71, 163, 164, 253, 265, 266, 267, 274,
	275, 276, 277, 278, 279, 280, 281, 282, 283,
	284, 285, 286, 287, 288
};

std::array<int, 300> ClassIdToModel;

size_t AddVectorClasses(const std::vector<int>& vec)
{
	static std::set<int> AddedPeds;
	static size_t current_classid = 0;
	for (auto ped : vec)
	{
		safeAddPlayerClass(ped, 1125.71201, -2036.8372, 69.8805, 270.0, 0, 0, 0, 0, 0, 0);
		AddedPeds.insert(ped);
		ClassIdToModel[current_classid] = ped;
		++current_classid;
	}
	return AddedPeds.size();
}

class GameMode : public Extension::Base
{
public:
	GameMode() : Base(ExecutionPriorities::GameMode) {}
	PlayerMenu::ActionData Data;
	bool OnPlayerConnect(int playerid) override
	{
		Player[playerid].QuickMenu->AddItem("4. SKIN", Data, &SkinSelection);
		TextDrawShowForPlayer(playerid, TextDraws::ActualTime);
		TextDrawShowForPlayer(playerid, TextDraws::WWW);
		return true;
	}
	bool OnGameModeInit() override//jeden z wielu
	{
		gtLog(LOG_OTHER, "Server is starting");

#ifndef _LOCALHOST_DEBUG
		IP_SUPER_WHITELIST.insert(boost::asio::ip::address_v4::from_string("127.0.0.1"));//localhost
		IP_SUPER_WHITELIST.insert(boost::asio::ip::address_v4::from_string("82.169.83.65"));//gamer, west, raptor, arcade
		IP_SUPER_WHITELIST.insert(boost::asio::ip::address_v4::from_string("82.173.123.128"));//gamer, west, raptor, arcade
		IP_SUPER_WHITELIST.insert(boost::asio::ip::address_v4::from_string("82.46.75.39"));//IceCube
#endif
		if (!userdb)
		{
#if defined(DATABASE_MYSQL)
			userdb = new database("odbodbodb","odbodbodb","odbodbodb","127.0.0.1",3306);
#elif defined(DATABASE_SQLITE)
			userdb = new database("users.sqlite3", SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE);
#endif
		}
		if (userdb)
		{
			SetupDatabase();

			/*unsigned long long t1, t2;
			std::vector<std::string> Names;
			std::vector<user*> Users;
			Names.reserve(50000);
			for (size_t i = 0; i < 50000; ++i)
			{
				Names.push_back(Functions::string_format("XXXXXX%I64uXXXXXX", i));
				Users.push_back(new user(Names[i], "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"));
			}
			t1 = Functions::GetTime();
			for (size_t i = 0; i < 50000; ++i)
			{
				odb::transaction t(userdb->begin());
				userdb->persist(Users[i]);
				t.commit();
			}
			t2 = Functions::GetTime();
			std::cout << (t2 - t1) << "ms" << std::endl;
			t1 = Functions::GetTime();
			for (size_t i = 0; i < 50000; ++i)
			{
				odb::transaction t(userdb->begin());
				userdb->load<user>(Names[i]);
				t.commit();
			}
			t2 = Functions::GetTime();
			std::cout << (t2 - t1) << "ms" << std::endl;*/

			//itak nie używamy narazie, jak się będzie używać to odkomentować
			//MapAndreas->Init(MAP_ANDREAS_MODE_FULL);

			ShowPlayerMarkers(1);
			UsePlayerPedAnims();
			ShowNameTags(1);
			EnableStuntBonusForAll(false);
			DisableInteriorEnterExits();

			SendRconCommand("gamemodetext PL POLSKi NL ENG ENGLiSH X DM");
			SendRconCommand("mapname PL POLSKi NL ENG ENGLiSH X DM");
#ifndef _LOCALHOST_DEBUG
			SendRconCommand("hostname [PL|NL|ENG] •Gamer_Z• eXtreme Party DM 24/7");
#else
			SendRconCommand("hostname [DBG][PL|NL|ENG] •Gamer_Z• eXtreme Party DM 24/7");
#endif
			SendRconCommand("sleep 1");
			SendRconCommand("lanmode 0");
			SendRconCommand("rcon 0");

			sampgdk::logprintf("    Copyright(c) 2014 - 2015 Rafał \"Gamer_Z\" Grasman  ");
			sampgdk::logprintf("        * See LICENSE.md in source directory for license");
			sampgdk::logprintf("        * Written by Rafał Grasman <grasmanek94@gmail.com>");
			sampgdk::logprintf("        * Development Start Month - Year: October - 2014");
			sampgdk::logprintf("        * This GameMode is open-source and available at:");
			sampgdk::logprintf("                      http://github.com/grasmanek94/eXe/");

			TextDraws::ActualTime = TextDrawCreate(547.000000, 24.000000, "00:00:00");
			TextDrawBackgroundColor(TextDraws::ActualTime, 255);
			TextDrawFont(TextDraws::ActualTime, 3);
			TextDrawLetterSize(TextDraws::ActualTime, 0.360000, 1.399999);
			TextDrawColor(TextDraws::ActualTime, -1);
			TextDrawSetOutline(TextDraws::ActualTime, 1);
			TextDrawSetProportional(TextDraws::ActualTime, 1);
			TextDrawSetSelectable(TextDraws::ActualTime, 0);

			TextDraws::WWW = TextDrawCreate(499.000000, 4.000000, "~b~~h~~h~www.exe24.info");
			TextDrawBackgroundColor(TextDraws::WWW, 255);
			TextDrawFont(TextDraws::WWW, 3);
			TextDrawLetterSize(TextDraws::WWW, 0.360000, 1.399999);
			TextDrawColor(TextDraws::WWW, -1);
			TextDrawSetOutline(TextDraws::WWW, 1);
			TextDrawSetProportional(TextDraws::WWW, 1);
			TextDrawSetSelectable(TextDraws::WWW, 0);

			sampgdk_SetTimerEx(500, true, GamemodeUpdate, nullptr, nullptr);

			sampgdk_SetTimerEx(5 * 60 * 1000, true, PlayerExpUpdate, nullptr, nullptr);
			
			ConnectNPC("MessageNPC", "npcidle");

			DatabaseWorker_Activate();
			std::string additional("");

			sampgdk::logprintf(" ");

			const int TFS_TO_GIT_REVISION = 547;

			#ifdef TFS_BUILD_VERSION
				#if TFS_BUILD_VERSION > 0
					additional.assign(Functions::string_format(" [TFSCS:%d]", 
						TFS_TO_GIT_REVISION + TFS_BUILD_VERSION
					));//tak bedziemy wiedziec jaka wersje debugować czasami
					SendRconCommand(("weburl " + StaticVersionDeterminator.GetWebUrl() + "/?" + std::to_string(TFS_TO_GIT_REVISION + TFS_BUILD_VERSION) + "|" + StaticVersionDeterminator.GetModeVersion()).c_str());

					sampgdk::logprintf(("        * Version: <TFS[" + std::to_string(TFS_TO_GIT_REVISION + TFS_BUILD_VERSION) + "]> <COMPILE DATE[" + StaticVersionDeterminator.GetModeVersion() + "]>").c_str());
				#else
					sampgdk::logprintf(("        * Version: " + StaticVersionDeterminator.GetModeVersion()).c_str());
					SendRconCommand(("weburl " + StaticVersionDeterminator.GetWebUrl()).c_str());
				#endif
			#else
				sampgdk::logprintf(("        * Version: " + StaticVersionDeterminator.GetModeVersion()).c_str());
				SendRconCommand(("weburl " + StaticVersionDeterminator.GetWebUrl()).c_str());
			#endif

			sampgdk::logprintf(" ");

			AddVectorClasses(PublicServicePeds);
			AddVectorClasses(WhiteMales);
			AddVectorClasses(BlackMales);
			AddVectorClasses(OtherMales);
			AddVectorClasses(OtherFemales);
			AddVectorClasses(BlackFemales);

			size_t added_total = 
			AddVectorClasses(WhiteFemales);

			std::cout << "Added " << added_total << " classes" << std::endl;

			ConsoleTextName = ("*Gamer_Z* eXtreme Party " + additional);
#ifdef WIN32
			SetConsoleTitle(ConsoleTextName.c_str());
#endif
		}
		return true;
	}
	bool OnRconCommand(std::string cmd) override
	{
		if (cmd.compare("cmds") == 0)
		{
			for (auto i : (*SAMPGDK::ZeroCMD::Internal::command_map))
			{
				std::cout << i.first << std::endl;
			}
			return true;
		}
		if (cmd.compare("kickall") == 0)
		{
			for (auto i : PlayersOnline)
			{
				Kick(i);
			}
			return true;
		}
		return false;
	}
	void SetupPlayerForClassSelection(int playerid)
	{
		SetPlayerCameraPos(playerid, 2635.6624, 2326.5103, 30.9272);
		fixSetPlayerPos(playerid, 2635.6624, 2332.5103, 30.9272);
		SetPlayerFacingAngle(playerid, 180.0);
		SetPlayerCameraLookAt(playerid, 2635.6624, 2332.5103, 30.9272, 0);
		switch (Functions::RandomGenerator->Random(0, 6))
		{
			case 0:ApplyAnimation(playerid, "DANCING", "DAN_LOOP_A", 4.1, 1, 1, 1, 1, 1, false); break;
			case 1:ApplyAnimation(playerid, "DANCING", "DNCE_M_A", 4.1, 1, 1, 1, 1, 1, false); break;
			case 2:ApplyAnimation(playerid, "DANCING", "DNCE_M_B", 4.1, 1, 1, 1, 1, 1, false); break;
			case 3:ApplyAnimation(playerid, "DANCING", "DNCE_M_C", 4.1, 1, 1, 1, 1, 1, false); break;
			case 4:ApplyAnimation(playerid, "DANCING", "DNCE_M_D", 4.1, 1, 1, 1, 1, 1, false); break;
			case 5:ApplyAnimation(playerid, "DANCING", "DNCE_M_E", 4.1, 1, 1, 1, 1, 1, false); break;
		}
	}
	bool OnPlayerRequestClass(int playerid, int classid) override
	{
		if (Player[playerid].HasSpawnedOnce)
		{
			Player[playerid].RequestSkinSelection = true;
		}
		if (
			(Player[playerid].RequestSkinSelection && !Player[playerid].InSkinSelection) || 
			Player[playerid].InSkinSelection && classid >= 0 && classid < 300)
		{
			Player[playerid].InSkinSelection = true;
			Player[playerid].RequestSkinSelection = false;
			SetupPlayerForClassSelection(playerid);
			if (TestIfAllowed(playerid))
			{
				Player[playerid].statistics.SkinModelID = ClassIdToModel[classid];
			}
			PlayerPlaySound(playerid, 1185, 1958.3783, 1343.1572, 15.3746);
		}
		return true;
	}
	bool OnPlayerRequestSpawn(int playerid) override
	{
		ClearAnimations(playerid, false);
		PlayerPlaySound(playerid, MUSIC_OFF, 0.0, 0.0, 0.0);
		return true;
	}
	bool OnPlayerSpawn(int playerid) override
	{
		Player[playerid].HasSpawnedOnce = true;
		if (!Player[playerid].KeepInGame)
		{
			SetPlayerColor(playerid, Player[playerid].FullColor);
			Player[playerid].SetTeam(NO_TEAM);
			fixSetPlayerHealth(playerid, 100.0f);
			fixSetPlayerArmour(playerid, 0.0f);
			Player[playerid].CurrentGameID = nullptr;
			SetPlayerRandomSpawn(playerid);
			Player[playerid].InSkinSelection = false;
		}
		return true;
	}
	bool OnPlayerDeath(int playerid, int killerid, int reason) override
	{
		if (Player[playerid].RequestSkinSelection && Player[playerid].CurrentGameID == nullptr)
		{
			Player[playerid].RequestSkinSelection = false;
			Player[playerid].InSkinSelection = true;
			ForceClassSelection(playerid);
		}
		return true;
	}
	bool OnPlayerText(int playerid, std::string text) override
	{
		if (!has_string_ip_ad(text))
		{
			Player[playerid].SendChat(text);
		}
		else
		{
			Player[playerid].SendChatIpAds(text);
		}
		return false;
	}
	bool OnPlayerKeyStateChange(int playerid, int newkeys, int oldkeys) override
	{
		if (Player[playerid].CurrentVehicle && Player[playerid].CurrentGameID == nullptr)
		{
			if (newkeys == 1 || newkeys == 9 || newkeys == 33 && oldkeys != 1 || oldkeys != 9 || oldkeys != 33)
			{
				AddVehicleComponent(Player[playerid].CurrentVehicle, 1010);
			}
			if (PRESSED(KEY_SUBMISSION))
			{
				if (IsVehicleAir(Player[playerid].CurrentVehicleModel))//NOPE NOPE NOPE for aircraft
				{
					ZCMD_CALL_COMMAND(playerid, "/fix", "");//do fix instead
				}
				else
				{
					float a;
					GetVehicleZAngle(Player[playerid].CurrentVehicle, &a);
					SetVehicleZAngle(Player[playerid].CurrentVehicle, a);
					GivePlayerAchievement(playerid, EAM_LubieDachowac, 1);
				}
			}
		}
		return true;
	}
	bool OnPlayerDisconnect(int playerid, int reason) override
	{
		TextDrawHideForPlayer(playerid, TextDraws::ActualTime);
		return true;
	}
	void OnUnknownCommand(int playerid, std::string& command, std::string& params) override
	{
		fixSendClientMessage(playerid, Color::COLOR_ERROR, TranslateP(playerid, L_unknown_command) + command);
	}
	void SetPlayerRandomSpawn(int playerid)
	{
		static const std::vector<std::vector<double>> gRandomPlayerSpawns =
		{
			{ 0.0f, 0.0f, 2.0f }
		};
		size_t rand = Functions::RandomGenerator->Random(0, gRandomPlayerSpawns.size() - 1);
		TeleportPlayer(playerid, gRandomPlayerSpawns[rand][0], gRandomPlayerSpawns[rand][1], gRandomPlayerSpawns[rand][2], 45.0, false, 0, 0, "", 0, 0, 2.0, 2.0);
	}
} _GameMode;