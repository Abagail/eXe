/*
	Copyright (c) 2014 - 2015 Rafa� "Gamer_Z" Grasman
		* See LICENSE.md in root directory for license
		* Written by Rafa� Grasman <grasmanek94@gmail.com>
		* Development Start Month-Year: October-2014

	________________________________________________________________
	Purpose of this file

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

#ifdef SAMPGDK_AMALGAMATION
#include "GameMode.hxx"
#else
#include <array>
#include <string>
#include <map>
#endif

enum language_string_ids
{
	L_language_name,
	L_empty_underscore,
	L_empty,
	L_invalid_playerid,
	L_eyecmd_player_enabled,
	L_eyecmd_player_disabled,
	L_eyecmd_player_watching_everyone,
	L_eyecmd_player_usage,
	L_eyecmdall_enabled,
	L_eyecmdall_disabled,
	L_global_chat_history,
	L_no_history,
	L_eyeip_enabled,
	L_eyeip_disabled,
	L_mm_achievement_newlevel,
	L_local_message_too_long,
	L_cheats_detected,
	L_chat_history,
	L_lastchat_usage,
	L_PM_history,
	L_lastpm_usage,
	L_CMD_history,
	L_lastcmd_usage,
	L_spectate_usage,
	L_player_not_connected,
	L_player_not_spawned,
	L_spectate_generic_error,
	L_specoff_need_spectate_first,
	L_games_stagecheck_msg,
	L_games_exit_info,
	L_games_exited,
	L_games_all_list_stub,
	L_games_help,
	L_games_ArenaGranaty_name,
	L_games_ArenaMinigun_name,
	L_games_ArenaOneDe_name,
	L_games_ArenaOneShot_name,
	L_games_ArenaPaintBall_name,
	L_games_ArenaRPG_name,
	L_games_ArenaSawnOff_name,
	L_games_ArenaSniper_name,
	L_games_ArenaTankBattle_name,
	L_games_ZabawaBagno_name,
	L_games_ZabawaDerby_name,
	L_games_ArenaFlyingTank_name,
	L_games_ZabawaHay_name,
	L_games_ZabawaTDM_name,
	L_games_ArenaWigilia_name,
	L_password_change,
	L_setpass_usage,
	L_unbanip_usage,
	L_player_is_online,
	L_unban_usage,
	L_PAP_LackOfPermissions,
	L_PAP_DoesNotExist,
	L_Staff_CurrentlyOnline,
	L_Staff_CurrentlyNone,
	L_Staff_DisplayTitle,
	L_report_reason_TooShortOrLong,
	L_report_send,
	L_report_usage,
	L_promote_info_msg_1,
	L_promote_add_error,
	L_promote_add_success,
	L_word_ranks,
	L_promote_noaccess,
	L_promote_params_error,
	L_promote_params_invalid,
	L_promote_usage,
	L_promote_take_error,
	L_promote_take_success,
	L_depromote_usage,
	L_kicked_player,
	L_kicked_word,
	L_kicked_dialoginfo,
	L_kicked_bye,
	L_banned_player,
	L_banned_dialogdisplay,
	L_banned_ipandaccount,
	L_banned_ip,
	L_banned_iphost,
	L_banned_account,
	L_kick_usage,
	L_ban_usage_1,
	L_ban_usage_2,
	L_mm_join_game,
	L_mm_bag_startcd,
	L_mm_bag_staging,
	L_mm_bag_not_enough_players,
	L_mm_bag_announce_winner,
	L_mm_drb_announce_winner,
	L_mm_drb_startcd,
	L_mm_drb_staging,
	L_mm_drb_not_enough_players,
	L_mm_mute_player,
	L_mm_mute_player_announce,
	L_mute_player_title,
	L_mute_player_info,
	L_mute_usage,
	L_mm_tdm_team_red,
	L_mm_tdm_team_blue,
	L_mm_tdm_announce_winner,
	L_mm_tdm_startcd,
	L_mm_tdm_staging,
	L_mm_tdm_not_enough_players,
	L_mm_hay_announce_winner,
	L_mm_hay_startcd,
	L_mm_hay_staging,
	L_mm_hay_not_enough_players,
	L_aexplode_executed,
	L_aexplode_usage,
	L_aslap_executed,
	L_aslap_reversed,
	L_aslap_usage,
	L_apaddhp_executed,
	L_apaddhp_usage,
	L_apsethp_executed,
	L_apsethp_usage,
	L_apaddarmor_executed,
	L_apaddarmor_usage,
	L_apsetarmor_executed,
	L_apsetarmor_usage,
	L_targetplayer_not_in_vehicle,
	L_apvaddhp_executed,
	L_apvaddhp_usage,
	L_apvsethp_executed,
	L_apvsethp_usage,
	L_atp_move_info,
	L_atp_move_error,
	L_atp_id_error,
	L_atp_usage,
	L_banip_success,
	L_banip_usage,
	L_banhost_success,
	L_banhost_usage_1,
	L_banhost_usage_2,
	L_unbanhost_success,
	L_unbanhost_failed,
	L_unbanhost_usage,
	L_emulate_executed,
	L_emulate_usage,
	L_emulateall_usage,
	L_dbworker_userpwchange_success,
	L_dbworker_userpwchange_failure,
	L_dbworker_unban_usr_success_p,
	L_dbworker_unban_usr_success_k,
	L_dbworker_unban_usr_fail,
	L_dbworker_unban_ip_success_p,
	L_dbworker_unban_ip_success_k,
	L_dbworker_unban_ip_fail,
	L_v_usage,
	L_v_slot_error,
	L_v_slot_error_mafia,
	L_v_no_car_found_error,
	L_v_cannot_spawn_error,
	L_vehicles_carlist_head,
	L_vehicles_carlist,
	L_vehicles_planes,
	L_vehicles_helis,
	L_vehicles_twowheeled,
	L_vehicles_cabrio,
	L_vehicles_industrial,
	L_vehicles_lowriders,
	L_vehicles_public_service,
	L_vehicles_sport,
	L_vehicles_wagons,
	L_vehicles_boats,
	L_vehicles_trailers,
	L_vehicles_unique,
	L_vehicles_offroad,
	L_vehicles_saloons,
	L_vehicles_remotecontrol,
	L_vcolor_usage,
	L_vpaint_usage,
	L_tune_cannot_tune_error,
	L_countdown_counter,
	L_countdown_removed,
	L_countdown_joined,
	L_email_send_error,
	L_email_send_success,
	L_timed_score_add,
	L_unknown_command,
	L_lotto_win,
	L_lotto_lose,
	L_lotto_winannounce,
	L_lotto_loseannounce,
	L_lotto_number_error,
	L_lotto_send_success,
	L_lotto_already_submitted,
	L_lotto_usage_1,
	L_lotto_usage_2,
	L_error_insufficient_funds,
	L_stats_totalgivenbounty,
	L_stats_mytotalbounty,
	L_stats_collectedbounty,
	L_stats_bountykillers,
	L_stats_vehicleflip,
	L_stats_pmspammer,
	L_stats_chatspammer,
	L_stats_lottowins,
	L_stats_totallottowon,
	L_stats_quizgood,
	L_stats_quizbad,
	L_stats_amountteleported,
	L_stats_rampscount,
	L_stats_vehiclespawncount,
	L_stats_gamejoiner,
	L_stats_mng_kills,
	L_stats_mng_deaths,
	L_stats_hay_wins,
	L_stats_hay_loses,
	L_stats_ode_kills,
	L_stats_ode_deaths,
	L_stats_snp_kills,
	L_stats_snp_deaths,
	L_stats_sof_kills,
	L_stats_sof_deaths,
	L_stats_mafispammer,
	L_stats_vipspammer,
	L_stats_sponsorspammer,
	L_stats_modspammer,
	L_stats_adminspam,
	L_stats_cheater,
	L_stats_helpme,
	L_stats_privatevehicles,
	L_stats_mafiavehicles,
	L_stats_amounthealed,
	L_stats_mammothtank,
	L_stats_acsuspect,
	L_stats_roleplayer,
	L_stats_gotmafiascore,
	L_stats_givenmafiascore,
	L_stats_biggestkillstreak,
	L_stats_currentkillstreak,
	L_stats_headshots,
	L_stats_waitforxp,
	L_stats_agr_kills,
	L_stats_agr_deaths,
	L_stats_arpg_kills,
	L_stats_arpg_deaths,
	L_stats_osh_kills,
	L_stats_osh_deaths,
	L_stats_apb_kills,
	L_stats_apb_deaths,
	L_stats_ctf_kills,
	L_stats_ctf_deaths,
	L_stats_ctf_pickedupflags,
	L_stats_ctf_capturedflags,
	L_stats_wns_kills,
	L_stats_wns_deaths,
	L_stats_ww3_kills,
	L_stats_ww3_deaths,
	L_stats_seeknhide_finds,
	L_stats_seeknhide_besttime,
	L_stats_drb_won,
	L_stats_drb_lost,
	L_stats_maze_fastesttime,
	L_stats_tdm_kills,
	L_stats_tdm_deaths,
	L_stats_tdm_wins,
	L_stats_tdm_loses,
	L_stats_bmxparkourft,
	L_stats_nrgparkourft,
	L_stats_parkourft,
	L_stats_spm_kills,
	L_stats_spm_deaths,
	L_stats_spm_wins,
	L_stats_spm_loses,
	L_stats_mma_wins,
	L_stats_mma_loses,
	L_stats_wjg_kills,
	L_stats_wjg_deaths,
	L_stats_wjg_wins,
	L_stats_wjg_loses,
	L_stats_racekartft,
	L_stats_bag_kills,
	L_stats_bag_deaths,
	L_stats_bag_wins,
	L_stats_bag_loses,
	L_stats_new_achievement,
	L_stats_achievement_info,
	L_stats_achievement_title,
	L_stats_txt_none,
	L_stats_amount_not_achieved,
	L_stats_additional_none,
	L_stats_additional_info_1,
	L_stats_additional_info_2,
	L_stats_killsfromweapons,
	L_stats_killedbyweapons,
	L_stats_biggestkillstreaks,
	L_stats_killswithsameweapons,
	L_stats_deathswithsameweapons,
	L_stats_weaponlevels,
	L_anim_invalid_category,
	L_anim_title,
	L_anim_display_info,
	L_setskin_usage,
	L_savecar_cannot_save,
	L_mm_savecar_success,
	L_savecar_usage_1,
	L_savecar_usage_2,
	L_ramp_succes,
	L_ramp_usage,
	L_tip_01,
	L_tip_02,
	L_tip_03,
	L_tip_04,
	L_tip_05,
	L_tip_06,
	L_tip_07,
	L_tip_08,
	L_tip_09,
	L_tip_10,
	L_tip_11,
	L_tip_12,
	L_tip_13,
	L_tip_14,
	L_tip_15,
	L_tip_16,
	L_tip_17,
	L_tip_18,
	L_tip_19,
	L_tip_20,
	L_bounty_noheadsonline,
	L_bounty_preinfo,
	L_bounty_title,
	L_invalid_funds_amount,
	L_givebounty_usage,
	L_givebounty_pricechange,
	L_givebounty_headtagged,
	L_givebounty_sendtag,
	L_SGMI_title,
	L_SGMI_info,
	L_sentrygun_created,
	L_sentrygun_usage,
	L_sentrygun_invalid_action,
	L_sentrygun_notfound,
	L_sentrygun_manage_usage,
	L_sentrygun_manage_nexuse,
	L_SendPM_ownID,
	L_SendPM_pmAreOff,
	L_SendPM_receiverIsBlockedInfo,
	L_SendPM_tooLong,
	L_pm_wasMutedByAdmin,
	L_pm_turnOn,
	L_pm_turnOff,
	L_pm_usage,
	L_pm_usage2,
	L_reply_cannotFoundLastID,
	L_reply_cannotBeEmpty,
	L_pmblock_playerBlockedInfo,
	L_pmblock_usage,
	L_pmunblock_playerBlocked,
	L_pmunblock_usage,
	L_mm_tdm_teamselector_red,
	L_mm_tdm_teamselector_blue,
	L_help_timespan,
	L_help_stats_exe24mod_on,
	L_help_stats_exe24mod_off,
	L_help_stats_infostringadmin,
	L_help_stats_infostringuser,
	L_help_stats_title,
	L_help_account_title,
	L_help_account_text,
	L_help_monety_title,
	L_help_monety_text,
	L_help_plus_title,
	L_help_plus_text,
	L_help_vip_title,
	L_help_vip_text,
	L_help_vip_mailverified,
	L_help_vip_mailnotverified,
	L_help_vehicle_title,
	L_help_vehicle_text,
	L_help_chat_title,
	L_help_chat_text,
	L_help_staff_title,
	L_help_staff_text,
	L_help_global_title,
	L_help_global_text,
	L_help_global2_title,
	L_help_global2_text,
	L_help_virtualworld,
	L_help_animationid,
	L_help_acmd_title,
	L_help_acmd_text,
	L_help_acmd2_title,
	L_help_acmd2_text,
	L_help_mafia_title,
	L_help_mafia_text,
	L_help_pm_title,
	L_help_pm_text,
	L_help_teleport_title,
	L_help_serverinfo_title,
	L_help_serverinfo_text,
	L_help_rules_title,
	L_help_rules_text,
	L_help_house_title,
	L_help_house_text,
	L_help_center_title,
	L_help_center_text,
	L_help_center_admincmd,
	L_mafia_rank_worker,
	L_mafia_rank_vicepresident,
	L_mafia_rank_president,
	L_mafia_rank_owner,
	L_dbworker_mafia_creationerror,
	L_mafia_create_invalidname,
	L_mafia_create_alreadyexists,
	L_mafia_create_usage_1,
	L_mafia_create_usage_2,
	L_mafia_quit_ownererror,
	L_mafia_vsave_error,
	L_mm_mafia_vsave_success,
	L_mafia_vsave_usage_1,
	L_mafia_vsave_usage_2,
	L_mafia_invite_sent,
	L_mafia_invite_success,
	L_mafia_invite_alreadyinvited,
	L_mafia_invite_alreadyinmafia,
	L_mafia_infive_usage,
	L_mm_mafia_join_success,
	L_mafia_join_error,
	L_mafia_join_usage,
	L_mafia_givecash_success_1,
	L_mafia_givecash_success_2,
	L_mafia_givecash_success_3,
	L_mafia_givecash_nocash,
	L_mafia_player_notinmafiaerror,
	L_mafia_givecash_casherror,
	L_mafia_givecash_usage,
	L_mafia_givescore_success_1,
	L_mafia_givescore_success_2,
	L_mafia_givescore_success_3,
	L_mafia_givescore_noscore,
	L_mafia_givescore_scoreerror,
	L_mafia_givescore_usage,
	L_mafia_donatecash_success,
	L_mafia_donatecash_error,
	L_mafia_donatecash_usage,
	L_mafia_loaded_success,
	L_mafia_deleted,
	L_mafia_kicked,
	L_mafia_permission_error,
	L_mafia_spawnoff,
	L_mafia_spawnon,
	L_mafia_skinoff,
	L_mafia_skinon,
	L_mafia_setspawn,
	L_mafia_setskin,
	L_mafia_online_title,
	L_mafia_online_text,
	L_mafia_donatescore_success,
	L_mafia_donatescore_error,
	L_mafia_donatescore_usage,
	L_mafia_color_setsuccess,
	L_color_too_dark_error,
	L_mafia_color_set_usage,
	L_mafia_kick_cannotquit,
	L_mafia_playernotinmafia,
	L_mafia_kick_permissionerror,
	L_mafia_kick_success,
	L_mafia_kick_usage,
	L_mafia_status_ownererror,
	L_mafia_status_permissionerror_1,
	L_mafia_status_permissionerror_2,
	L_mafia_status_success_1,
	L_mafia_status_success_2,
	L_mafia_status_usage,
	L_mafia_permissions_success,
	L_mafia_permissions_error,
	L_mafia_permissions_usage,
	L_dialog_title_info,
	L_mafia_lista_name_error,
	L_mafia_lista_info,
	L_mafia_lista_info_2,
	L_mafia_lista_title,
	L_antispam,
	L_chatmute,
	L_cmdchatmute,
	L_commandrestriction_game,
	L_commandrestriction_onlyingame,
	L_commandrestriction_onlyonfoot,
	L_commandrestriction_onlyasdriver,
	L_commandrestriction_onlyinvehicle,
	L_commandrestriction_onlyloggedin,
	L_commandrestriction_onlyinmafia,
	L_commandrestriction_notinmafia,
	L_commandrestriction_onlyincar,
	L_commandrestriction_onlyinairplane,
	L_commandrestriction_onlyinhelicopter,
	L_commandrestriction_onlyregisteredanddataloaded,
	L_commandrestriction_afterfight,
	L_commandrestriction_spawned,
	L_commandrestriction_exe24plus_1,
	L_commandrestriction_exe24plus_2,
	L_commandrestriction_vehorfoot,
	L_command_nopermission,
	L_Yes,
	L_No,
	L_Cancel,
	L_Login,
	L_Confirm,
	L_Help,
	L_login_dialog_title,
	L_login_dialog_text,
	L_registerq_title,
	L_registerq_text,
	L_updatepass_title,
	L_register_text,
	L_loginhelp_askmail_title,
	L_loginhelp_askmail_text,
	L_loginhelp_askmail_button_a,
	L_loginhelp_askmail_button_b,
	L_loginhelp_antyspam,
	L_loginhelp_checkmail,
	L_login_noverifiedmail,
	L_login_welcomeback,
	L_importantmessage,
	L_vip_upgrade,
	L_mm_vip_upgrade,
	L_information,
	L_register_canceled,
	L_already_registered,
	L_register_success,
	L_newpass_success_text,
	L_newpass_success_title,
	L_manageemail_text,
	L_manageemail_title,
	L_email_action_change_title,
	L_email_action_change_text_a,
	L_email_action_change_text_b,
	L_email_action_success_title,
	L_email_action_success_text,
	L_email_change_newemail,
	L_email_change_verify_fail,
	L_email_verify_text,
	L_email_verify_title,
	L_email_verify_success,
	L_email_verification_error,
	L_email_activation_limit,
	L_email_change_verify_text_a,
	L_email_change_verify_text_b,
	L_mm_APTITT,
	L_mm_RTTP_a,
	L_mm_ITPTM_a,
	L_mm_RTTP_b,
	L_mm_ITPTM_b,
	L_mm_invalid_playerid,
	L_mm_player_in_minigame,
	L_tpto_cannot_tp,
	L_tpto_usage,
	L_mm_APTRTM,
	L_tphere_usage,
	L_mm_cannot_tphere,
	L_pickupmessage_house,
	L_house_nohouse,
	L_house_infostringbuilder_a,
	L_house_infostringbuilder_locked,
	L_house_infostringbuilder_b,
	L_house_infostringbuilder_c,
	L_house_infostringbuilder_d,
	L_house_infostringbuilder_e,
	L_house_info_title,
	L_house_infostringbuilder_money,
	L_house_infostringbuilder_score,
	L_house_enter_permissionerror,
	L_house_rentlimit_reached,
	L_house_owneronly_action,
	L_house_rent_mintime_error,
	L_house_resources_error,
	L_house_rent_success,
	L_house_rent_usage,
	L_house_door_open,
	L_house_door_close,
	L_house_kick_usage,
	L_house_kick_error,
	L_house_kick_success_1,
	L_house_kick_success_2,
	L_house_range_error,
	L_house_action_executed,
	L_house_invalid_interiorid,
	L_house_invalid_hours,
	L_house_player_notonline,
	L_house_player_supplyerror,
	L_house_uninvite_usage,
	L_house_uninvite_success_1,
	L_house_uninvite_success_2,
	L_house_score_error,
	L_house_money_error,
	L_houseadd_usage_1,
	L_houseadd_usage_2,
	L_credits_scene_1,
	L_credits_scene_2,
	L_credits_scene_3,
	L_credits_scene_4,
	L_credits_scene_5,
	L_credits_scene_6,
	L_credits_scene_7,
	L_weapons_dialog_text_a,
	L_weapons_dialog_text_dequip,
	L_weapons_dialog_text_equip,
	L_weapons_dialog_text_ammo,
	L_weapons_dialog_text_magazinestatus,
	L_weapons_dialog_text_buy,
	L_weapons_dialog_text_level,
	L_weapons_dialog_text_b,
	L_weapons_dialog_title,
	L_weapons_dialog_text_weaponowned,
	L_weapons_dialog_text_lowlevel,
	L_weapons_dialog_text_lowscore,
	L_weapons_dialog_text_invalidweaponid,
	L_weapons_dialog_text_lowcash,
	L_weapons_dialog_text_notequiped,
	L_weapons_dialog_text_noammo,
	L_weapons_dialog_text_needbuy,
	L_buyammo_usage,
	L_buyammo_error_badbulletweapon,
	L_buyammo_error_0ammo,
	L_buyammo_error_maxammo,
	L_buyammo_success,
	L_error_cant_usecmd_atm,
	L_setcolor_removed,
	L_setcolor_usage,
	L_say_usage,
	L_asay_usage,
	L_msay_usage,
	L_lsay_usage,
	L_savepos_success,
	L_givecash_success_1,
	L_givecash_success_2,
	L_givecash_usage,
	L_givescore_success_1,
	L_givescore_success_2,
	L_givescore_error,
	L_givescore_usage,
	L_agivecash_success_1,
	L_agivecash_success_2,
	L_agivecash_usage,
	L_agivescore_success_1,
	L_agivescore_success_2,
	L_agivescore_usage,
	L_agiveexp_success_1,
	L_agiveexp_success_2,
	L_agiveexp_usage,
	L_bank_withdraw_success,
	L_bank_transfer_success,
	L_bank_nofunds_bank,
	L_bank_nofunds_here,
	L_bank_usage_1,
	L_bank_usage_2,
	L_race_joined_success,
	L_race_staging, 
	L_race_not_enough_players,
	L_race_winner_text,
	L_race_gametxt,
	L_announce_usage,
	L_minigame_inactivity,
	L_goldcoin_foundnew,
	L_goldcoin_helpmsg,
	//------------------
	MAX_LANGUAGE_STRINGS
	//------------------
};

namespace Language
{
	namespace InternalLanguage
	{
		void Add(const std::map<language_string_ids, std::string> &translation);
	};

	const unsigned long LANGUAGES_SIZE = 3;//max languages
	extern unsigned long CURRENT_LANGUAGE_ID;

	extern std::array<std::array<std::string, MAX_LANGUAGE_STRINGS>, LANGUAGES_SIZE> Translations;
	extern std::array<std::string, LANGUAGES_SIZE> Languages;
	extern std::array<std::set<int>, LANGUAGES_SIZE> PlayersUsingLanguage;
	extern std::string language_list;

	extern std::map<unsigned long, unsigned long> LanguageIDToIndex;
	extern std::array<unsigned long, LANGUAGES_SIZE> IndexToLanguageID;

	const std::string& Translate(unsigned long language, language_string_ids string_id);
	const std::string& TranslateP(int playerid, language_string_ids string_id);
	const std::string TranslateF(unsigned long language, language_string_ids string_id, ...);
	const std::string TranslatePF(int playerid, language_string_ids string_id, ...);

	void SendClientMessageF(int playerid, int color, language_string_ids string_id, bool playSound, bool displayPrefix, ...);
	void SendClientMessageToAllF(int color, language_string_ids string_id, bool playSound, bool displayPrefix, ...);

	void SendClientMessage(int playerid, int color, language_string_ids string_id, bool playSound = false, bool displayPrefix = false);
	void SendClientMessageToAll(int color, language_string_ids string_id, bool playSound = false, bool displayPrefix = false);

	void fixSendClientMessageF(int playerid, int color, language_string_ids string_id, bool playSound, bool displayPrefix, ...);
	void fixSendClientMessageToAllF(int color, language_string_ids string_id, bool playSound, bool displayPrefix, ...);
		 
	void fixSendClientMessage(int playerid, int color, language_string_ids string_id, bool playSound = false, bool displayPrefix = false);
	void fixSendClientMessageToAll(int color, language_string_ids string_id, bool playSound = false, bool displayPrefix = false);

	void AddPlayerToLanguage(int playerid, unsigned long language);
};

using namespace Language;