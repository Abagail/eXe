/*
	Copyright (c) 2014 - 2015 Rafa� "Gamer_Z" Grasman
		* See LICENSE.md in root directory for license
		* Written by Rafa� Grasman <grasmanek94@gmail.com>
		* Development Start Month-Year: October-2014

	________________________________________________________________
	Purpose of this file
		-	Neccesary structures and function prototypes to communicate with the eXe24+ module

	________________________________________________________________	
	Notes

	________________________________________________________________
	Dependencies

	________________________________________________________________
	Project Contributors
		Tom 'IceCube' Hewlett
		Mariusz 'C2A1' K.
		Mateusz 'eider' Cicho�
*/
#pragma once

namespace Exe24Tool
{
	enum Patches
	{
		Antibikefalloff,				
		Removespeedheightlimitsofaircraft,					
		Allcarshavenitro,
		Perfecthandling,
		Infiniterun		,	
		Infiniteoxygen,
		MegaJumpOnFoot	,	
		MegaJumpOnBike	,	
		Wheelsonly,
		Tankmode,
		Carsfloatawaywhenhit,		
		FullWeaponaiming	,	
		Freepaintandspray	,		
		Walkdriveunderwater,		
		Carshoveroverwater	,		
		Toggleradar	,				
		ToggleGTASAsHUD,		
		ScaledowntheHUD,		
		Enablevehiclenamerendering,
		Enablespeedblur	,			
		AntiDerail,					
		Sprintonanysurface	,
		max_patches
	};

	enum SampPatches
	{
		No_connecting_delay,
		samp_patch_dummy,
		max_samp_patches
	};

	const size_t g_INI_PATCHES_MAX = max_patches;
	const size_t g_INI_SAMPPATCHES_MAX = max_samp_patches;

	struct CRemoteOptions;
	struct CRemoteOptions
	{
		int Fly;
		int FlyModeIsHeli;
		int Speed;
		int Spider;
		int SpeedoMeter;
		int BreakDance;
		int QuickTurn;
		int AirBrake;
		int Unflip;
		int GodMode;
		int SuperBrake;
		int AntiBikeFallOff;
		int RemAircraftSpeedHeightLimits;
		int PerfectHanding;
		int FullWeaponAim;
		int WalkDriveUnderWater;
		int SpeedBlur;
		int EnableRejoin;
		int EnablePatch[g_INI_PATCHES_MAX];
		int EnableSampPatch[g_INI_SAMPPATCHES_MAX];
		void Reset()
		{
			SecureZeroMemory(this, sizeof(CRemoteOptions));
		}
		int GetAt(size_t index)
		{
			return *(int*)(this + (index*sizeof(int)));
		}
		void SetAt(size_t index, int val)
		{
			*(int*)(this + (index*sizeof(int))) = val;
		}
		size_t GetIndex(int* var)
		{
			return (size_t)( ( (int)var - (int)this ) / sizeof(int) );
		}
		CRemoteOptions()
		{
			Reset();
		}
	};

	#ifndef SAMPGDK_STATIC
	extern CRemoteOptions* RemoteOptions;
	#endif
};

#ifdef SAMPGDK_STATIC

#include "Structs.h"

extern RakServer *pRakServer;

//latanie wszystkimi pojazdami jak samolot
bool TogglePlayerFly(int playerid, bool toggle);
//latanie wszystkimi pojazdami jak helikopter
bool TogglePlayerFlyMode(int playerid, bool helicopter);
//airbreak
bool TogglePlayerAirBreak(int playerid, bool toggle);
//przeciw spadanie z motocykl�w itp
bool TogglePlayerAntiBikeFallOff(int playerid, bool toggle);
//BreakDance
bool TogglePlayerBreakDance(int playerid, bool toggle);
//Rejoin na LSHIFT+0
bool TogglePlayerRejoin(int playerid, bool toggle);
//Zawsze strzelasz broni�
bool TogglePlayerFullWeaponAim(int playerid, bool toggle);
//Prawdziwy GodMode
bool TogglePlayerGodMode(int playerid, bool toggle);
//Perfect Handling
bool TogglePlayerPerfectHanding(int playerid, bool toggle);
//Szybkie obracanie sie [ ] i BACKSPACE
bool TogglePlayerQuickTurn(int playerid, bool toggle);
//Usuni�cie limit�w samolot�w
bool RemPlayerAircraftSpeedHeightLimits(int playerid, bool toggle);
//Dodatkowa pr�dko�� na ALT
bool TogglePlayerSuperSpeed(int playerid, bool toggle);
//Rozmazanie przy wi�kszych pr�dko�ciach
bool TogglePlayerSpeedBlur(int playerid, bool toggle);
//Spider wheels / je�dzenie po wszystkim pod ka�dym k�tem
bool TogglePlayerSpider(int playerid, bool toggle);
//Super hamulec na /
bool TogglePlayerSuperBrake(int playerid, bool toggle);
//Postawienie pojazdu na ko�a za pomoc� DEL
bool TogglePlayerUnflip(int playerid, bool toggle);
//je�dzenie oraz chodzenie pod wod�
bool TogglePlayerWalkDriveUnderWater(int playerid, bool toggle);
//Wszystkie pojazdy maj� nitro
bool TogglePlayerPatch_Allcarshavenitro(int playerid, bool toggle);
//Zabezpieczenie przeciwko wykolejeniu si�
bool TogglePlayerPatch_AntiDerail(int playerid, bool toggle);
//Pojazdy odlatuj� kiedy s� trafione
bool TogglePlayerPatch_Carsfloatawaywhenhit(int playerid, bool toggle);
//Ka�dy pojazd zachowuje si� jak hovercraft na wodzie
bool TogglePlayerPatch_Carshoveroverwater(int playerid, bool toggle);
//GTA-owe pokazywanie nazw pojazd�w
bool TogglePlayerPatch_Enablevehiclenamerendering(int playerid, bool toggle);
//Darmowe paint & spray
bool TogglePlayerPatch_Freepaintandspray(int playerid, bool toggle);
//Nieskonczono�� oddychania
bool TogglePlayerPatch_Infiniteoxygen(int playerid, bool toggle);
//Nieskonczone bieganie
bool TogglePlayerPatch_Infiniterun(int playerid, bool toggle);
//Du�e skoki na motocyklach itp
bool TogglePlayerPatch_MegaJumpOnBike(int playerid, bool toggle);
//Du�e skoki na nogach
bool TogglePlayerPatch_MegaJumpOnFoot(int playerid, bool toggle);
//Perfekcyjne sterowanie
bool TogglePlayerPatch_Perfecthandling(int playerid, bool toggle);
//Pomniejszenie HUDa
bool TogglePlayerPatch_ScaledowntheHUD(int playerid, bool toggle);
//Sprint na ka�dej powierzchni
bool TogglePlayerPatch_Sprintonanysurface(int playerid, bool toggle);
//Tryb czo�ga
bool TogglePlayerPatch_Tankmode(int playerid, bool toggle);
//Wy�./W� HUDy GTA
bool TogglePlayerPatch_ToggleGTASAsHUD(int playerid, bool toggle);
//Wy�./W� Radar
bool TogglePlayerPatch_Toggleradar(int playerid, bool toggle);
//Tylko wida� ko�a pojazd�w
bool TogglePlayerPatch_Wheelsonly(int playerid, bool toggle);

#endif