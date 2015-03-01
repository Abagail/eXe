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
#include "GameMode.hxx"

using namespace Zabawy;
namespace OneShot
{
	class Arena : public Base
	{
	public:
		std::vector<SObject> ArenaObjects;

		std::vector<SSpawnPoint> ArenaSpawns;

		Arena() :
			Base(L_games_ArenaOneShot_name, "/osh"),
			ArenaSpawns({
				{ 688.9683, -2438.8049, 3.2756, 359.0600 }, // os
				{ 667.8015, -2419.5896, 3.2839, 356.5532 }, // os
				{ 667.3264, -2386.9858, 7.2900, 185.8083 }, // os
				{ 652.7877, -2372.1155, 7.2839, 179.5415 }, // os
				{ 609.5746, -2375.3450, 3.2839, 221.5052 }, // os
				{ 582.7526, -2387.6802, 7.2839, 241.5588 }, // os
				{ 591.5375, -2425.0586, 1.7339, 328.3530 }, // os
				{ 625.0488, -2423.1794, 8.5525, 5.9533 }, // os
				{ 563.2192, -2433.6257, 3.2429, 359.3499 }, // os
				{ 0.0f, 0.0f, 0.0f, 0.0f }
			}),
			ArenaObjects({
				{ 8838, 692.8480200, -2429.2722200, 0.7298700, 0.0000000, 0.0000000, -90.0000000 }, //Object number 0
				{ 8838, 687.7562300, -2429.2912600, 0.7450200, 0.0000000, 0.0000000, -630.0000000 }, //Object number 1
				{ 8838, 682.6424600, -2429.2812500, 0.7341100, 0.0000000, 0.0000000, -990.0000000 }, //Object number 2
				{ 12957, 692.8043200, -2424.6767600, 2.9136800, 0.0000000, 0.0000000, -135.0000000 }, //Object number 3
				{ 986, 695.3487600, -2417.6960400, 4.0082900, 0.0000000, 0.0000000, -90.0000000 }, //Object number 4
				{ 986, 693.8175100, -2410.0256300, 4.0203200, 0.0000000, 0.0000000, -67.5000000 }, //Object number 5
				{ 986, 689.4600800, -2403.5092800, 4.0203200, 0.0000000, 0.0000000, -45.0000000 }, //Object number 6
				{ 986, 682.9632600, -2399.1613800, 4.0203200, 0.0000000, 0.0000000, -22.5000000 }, //Object number 7
				{ 986, 675.2874800, -2397.6433100, 4.0203200, 0.0000000, 0.0000000, 0.0000000 }, //Object number 8
				{ 8664, 624.6429400, -2351.8461900, 2.2058100, 0.0000000, 0.0000000, -180.0000000 }, //Object number 9
				{ 956, 671.1246300, -2396.8896500, 2.5879500, 0.0000000, 0.0000000, -45.0000000 }, //Object number 10
				{ 1775, 671.0369900, -2396.9563000, 5.4826200, 0.0000000, 0.0000000, -45.0000000 }, //Object number 11
				{ 1684, 676.8172600, -2395.5246600, 3.8738100, 0.0000000, 0.0000000, 0.0000000 }, //Object number 12
				{ 16096, 686.0667700, -2396.4035600, 4.1927600, 0.0000000, 0.0000000, 67.5000000 }, //Object number 13
				{ 11426, 692.6202400, -2401.0385700, 2.2774900, 0.0000000, 0.0000000, -135.0000000 }, //Object number 14
				{ 11496, 663.2242400, -2389.1101100, 6.0900300, 0.0000000, 0.0000000, 90.0000000 }, //Object number 15
				{ 14407, 651.3143300, -2389.7858900, 3.0765600, 0.0000000, 0.0000000, -360.0000000 }, //Object number 16
				{ 11496, 657.3902600, -2394.0478500, 6.0702500, 0.0000000, 0.0000000, -90.0000000 }, //Object number 17
				{ 8838, 654.9115000, -2381.8803700, 4.7283300, 0.0000000, 0.0000000, -1170.0000000 }, //Object number 18
				{ 1684, 657.3136000, -2379.5795900, 7.8488100, 0.0000000, 0.0000000, -270.0000000 }, //Object number 19
				{ 1684, 657.3079800, -2369.6355000, 7.8488100, 0.0000000, 0.0000000, -270.0000000 }, //Object number 20
				{ 11496, 654.0667700, -2375.9328600, 6.0839300, 0.0000000, 0.0000000, -180.0000000 }, //Object number 21
				{ 1684, 654.5511500, -2366.3022500, 7.8488100, 0.0000000, 0.0000000, -180.0000000 }, //Object number 22
				{ 1684, 664.4261500, -2382.5317400, 7.8488100, 0.0000000, 0.0000000, -360.0000000 }, //Object number 23
				{ 3578, 650.1903100, -2378.6762700, 6.6110400, 0.0000000, 0.0000000, 90.0000000 }, //Object number 24
				{ 3578, 650.1971400, -2373.0908200, 6.6119700, 0.0000000, 0.0000000, 90.0000000 }, //Object number 25
				{ 1348, 656.4102800, -2400.3046900, 6.8335900, 0.0000000, 0.0000000, -45.0000000 }, //Object number 26
				{ 1348, 664.5130600, -2400.3964800, 6.8563500, 0.0000000, 0.0000000, 45.0000000 }, //Object number 27
				{ 1685, 664.2691700, -2392.4792500, 7.0202500, 0.0000000, 0.0000000, 0.0000000 }, //Object number 28
				{ 1685, 656.5191700, -2392.4436000, 7.0202500, 0.0000000, 0.0000000, 0.0000000 }, //Object number 29
				{ 14414, 668.4869400, -2393.4206500, 3.0683800, 0.0000000, 0.0000000, -180.0000000 }, //Object number 30
				{ 14414, 666.9805900, -2393.4201700, 3.0856500, 0.0000000, 0.0000000, -180.0000000 }, //Object number 31
				{ 7021, 607.0343000, -2343.9226100, 5.8601500, 0.0000000, 0.0000000, -90.0000000 }, //Object number 32
				{ 1684, 625.1610100, -2373.0544400, 3.8738100, 0.0000000, 0.0000000, -270.0000000 }, //Object number 33
				{ 1684, 625.1163300, -2373.0283200, 6.7288100, 0.0000000, 0.0000000, -270.0000000 }, //Object number 34
				{ 1684, 625.1375700, -2379.6506300, 3.8238100, 0.0000000, 0.0000000, -90.0000000 }, //Object number 35
				{ 1684, 625.1544200, -2379.6801800, 6.7295700, 0.0000000, 0.0000000, -270.0000000 }, //Object number 36
				{ 1684, 625.1392800, -2393.1208500, 3.8738100, 0.0000000, 0.0000000, -270.0000000 }, //Object number 37
				{ 1684, 625.0950900, -2393.0944800, 6.7288100, 0.0000000, 0.0000000, -90.0000000 }, //Object number 38
				{ 1684, 595.6866500, -2365.8630400, 7.7738100, 0.0000000, 0.0000000, -180.0000000 }, //Object number 39
				{ 1684, 592.9503200, -2369.6918900, 7.8547800, 0.0000000, 0.0000000, -270.0000000 }, //Object number 40
				{ 11496, 596.1739500, -2376.0000000, 6.0682200, 0.0000000, 0.0000000, -360.0000000 }, //Object number 41
				{ 1684, 592.9442100, -2379.6501500, 7.8580900, 0.0000000, 0.0000000, -270.0000000 }, //Object number 42
				{ 1684, 585.7852800, -2382.5966800, 7.8580900, 0.0000000, 0.0000000, -360.0000000 }, //Object number 43
				{ 3578, 600.0897200, -2378.7753900, 6.5869600, 0.0000000, 0.0000000, 90.0000000 }, //Object number 44
				{ 3578, 600.0926500, -2369.7673300, 6.5962500, 0.0000000, 0.0000000, 90.0000000 }, //Object number 45
				{ 11496, 592.7042200, -2394.0681100, 6.0702500, 0.0000000, 0.0000000, -90.0000000 }, //Object number 46
				{ 14407, 598.6998300, -2389.7536600, 3.0765600, 0.0000000, 0.0000000, -360.0000000 }, //Object number 47
				{ 8838, 595.1190200, -2381.6489300, 4.7283400, 0.0000000, 0.0000000, -1350.0000000 }, //Object number 48
				{ 11496, 587.0255100, -2389.1054700, 6.0839400, 0.0000000, 0.0000000, -270.0000000 }, //Object number 49
				{ 14414, 582.7249800, -2393.4235800, 3.0683800, 0.0000000, 0.0000000, -180.0000000 }, //Object number 50
				{ 14414, 581.6583300, -2393.4228500, 3.0830900, 0.0000000, 0.0000000, -180.0000000 }, //Object number 51
				{ 1348, 593.7540300, -2400.3010300, 6.8234800, 0.0000000, 0.0000000, -135.0000000 }, //Object number 52
				{ 1348, 585.6097400, -2400.3115200, 6.8186100, 0.0000000, 0.0000000, -225.0000000 }, //Object number 53
				{ 1685, 593.6554000, -2392.5051300, 7.0202500, 0.0000000, 0.0000000, 0.0000000 }, //Object number 54
				{ 1685, 585.7603800, -2392.5012200, 7.0202500, 0.0000000, 0.0000000, 0.0000000 }, //Object number 55
				{ 956, 579.0011000, -2396.8730500, 2.6879500, 0.0000000, 0.0000000, 45.0000000 }, //Object number 56
				{ 986, 574.8424100, -2397.6106000, 4.0069600, 0.0000000, 0.0000000, 0.0000000 }, //Object number 57
				{ 1775, 579.0286900, -2396.9082000, 5.5826200, 0.0000000, 0.0000000, 45.0000000 }, //Object number 58
				{ 986, 567.1514900, -2399.1374500, 3.9946000, 0.0000000, 0.0000000, 22.5000000 }, //Object number 59
				{ 986, 560.6612600, -2403.4931600, 4.0008900, 0.0000000, 0.0000000, 45.0000000 }, //Object number 60
				{ 986, 556.3067600, -2410.0131800, 3.9946000, 0.0000000, 0.0000000, 67.5000000 }, //Object number 61
				{ 986, 554.7752700, -2417.7182600, 3.9946000, 0.0000000, 0.0000000, 90.0000000 }, //Object number 62
				{ 11426, 557.6468500, -2401.3984400, 2.2775000, 0.0000000, 0.0000000, -45.0000000 }, //Object number 63
				{ 16096, 564.0675100, -2396.2390100, 4.1927700, 0.0000000, 0.0000000, 112.5000000 }, //Object number 64
				{ 1684, 573.2696500, -2395.4697300, 3.8738100, 0.0000000, 0.0000000, -360.0000000 }, //Object number 65
				{ 8838, 557.2833300, -2429.2907700, 0.7283400, 0.0000000, 0.0000000, -270.0000000 }, //Object number 66
				{ 8838, 562.3700000, -2429.2836900, 0.7123400, 0.0000000, 0.0000000, -450.0000000 }, //Object number 67
				{ 8838, 567.4635000, -2429.2990700, 0.7253000, 0.0000000, 0.0000000, -1170.0000000 }, //Object number 68
				{ 12957, 558.2796600, -2425.3933100, 2.9621500, 0.0000000, 0.0000000, -225.0000000 }, //Object number 69
				{ 1684, 678.0260000, -2441.0222200, 3.8045900, 0.0000000, 0.0000000, -450.0000000 }, //Object number 70
				{ 1684, 678.0667700, -2441.0661600, 6.7353400, 0.0000000, 0.0000000, -630.0000000 }, //Object number 71
				{ 1684, 572.0719000, -2441.0222200, 3.7957800, 0.0000000, 0.0000000, -630.0000000 }, //Object number 72
				{ 1684, 572.0289300, -2441.0073200, 6.7265300, 0.0000000, 0.0000000, -810.0000000 }, //Object number 73
				{ 1684, 678.0374800, -2431.1076700, 3.8045900, 0.0000000, 0.0000000, -630.0000000 }, //Object number 74
				{ 1684, 678.0086700, -2431.0773900, 6.7353400, 0.0000000, 0.0000000, -810.0000000 }, //Object number 75
				{ 1684, 678.0208700, -2421.1467300, 3.7738100, 0.0000000, 0.0000000, -810.0000000 }, //Object number 76
				{ 1684, 678.0457800, -2421.1645500, 6.7295700, 0.0000000, 0.0000000, -990.0000000 }, //Object number 77
				{ 1684, 572.0550500, -2431.0639600, 3.7957800, 0.0000000, 0.0000000, -810.0000000 }, //Object number 78
				{ 1684, 572.0623800, -2431.1020500, 6.7265300, 0.0000000, 0.0000000, -990.0000000 }, //Object number 79
				{ 1684, 572.0843500, -2421.1396500, 3.7738100, 0.0000000, 0.0000000, -990.0000000 }, //Object number 80
				{ 1684, 572.0836200, -2421.1364700, 6.7295700, 0.0000000, 0.0000000, -990.0000000 }, //Object number 81
				{ 8838, 648.9593500, -2424.6030300, -0.8216600, 0.0000000, 0.0000000, -1260.0000000 }, //Object number 82
				{ 14394, 661.5877700, -2422.5502900, 1.4622700, 0.0000000, 0.0000000, 90.0000000 }, //Object number 83
				{ 14394, 653.5972900, -2422.5478500, 1.4622700, 0.0000000, 0.0000000, 90.0000000 }, //Object number 84
				{ 14394, 645.6807900, -2422.6035200, 1.4622700, 0.0000000, 0.0000000, 90.0000000 }, //Object number 85
				{ 14394, 637.7191200, -2422.5996100, 1.4622700, 0.0000000, 0.0000000, 90.0000000 }, //Object number 86
				{ 1684, 670.5213600, -2423.8002900, 2.2628900, 0.0000000, 0.0000000, -900.0000000 }, //Object number 87
				{ 1684, 670.4945100, -2423.8378900, 5.1238100, 0.0000000, 0.0000000, -1080.0000000 }, //Object number 88
				{ 1684, 670.5140400, -2427.8962400, 2.2488100, 0.0000000, 0.0000000, -1080.0000000 }, //Object number 89
				{ 1684, 670.5050100, -2427.9069800, 5.1045700, 0.0000000, 0.0000000, -1260.0000000 }, //Object number 90
				{ 1684, 579.2479300, -2423.8066400, 5.1488000, 0.0000000, 0.0000000, -1080.0000000 }, //Object number 91
				{ 1684, 579.2540300, -2423.7981000, 2.2738100, 0.0000000, 0.0000000, -1080.0000000 }, //Object number 92
				{ 8838, 600.8907500, -2424.7263200, -0.7966600, 0.0000000, 0.0000000, -1260.0000000 }, //Object number 93
				{ 1684, 579.2706300, -2427.8706000, 2.2738100, 0.0000000, 0.0000000, -1080.0000000 }, //Object number 94
				{ 1684, 579.2611100, -2427.8840300, 5.1545700, 0.0000000, 0.0000000, -1080.0000000 }, //Object number 95
				{ 14394, 588.2074000, -2422.5703100, 1.4622600, 0.0000000, 0.0000000, 90.0000000 }, //Object number 96
				{ 14394, 596.1439200, -2422.5854500, 1.4622600, 0.0000000, 0.0000000, 90.0000000 }, //Object number 97
				{ 14394, 604.0965600, -2422.5798300, 1.4622600, 0.0000000, 0.0000000, 90.0000000 }, //Object number 98
				{ 14394, 612.0113500, -2422.5920400, 1.4622600, 0.0000000, 0.0000000, 90.0000000 }, //Object number 99
				{ 1685, 658.0904500, -2422.6601600, 1.6315400, 0.0000000, 0.0000000, 0.0000000 }, //Object number 100
				{ 1685, 658.0975300, -2422.6726100, 3.1315400, 0.0000000, 0.0000000, 0.0000000 }, //Object number 101
				{ 1685, 643.4666800, -2422.6486800, 1.6328400, 0.0000000, 0.0000000, 0.0000000 }, //Object number 102
				{ 1685, 643.4752200, -2422.6508800, 3.1328400, 0.0000000, 0.0000000, 0.0000000 }, //Object number 103
				{ 1685, 650.6854300, -2422.7309600, 1.6410800, 0.0000000, 0.0000000, 0.0000000 }, //Object number 104
				{ 1685, 650.6746800, -2422.7204600, 3.1410800, 0.0000000, 0.0000000, 0.0000000 }, //Object number 105
				{ 1684, 635.7750200, -2426.7565900, 2.2477400, 0.0000000, 0.0000000, -1170.0000000 }, //Object number 106
				{ 1685, 591.8988000, -2422.6835900, 3.1315400, 0.0000000, 0.0000000, 0.0000000 }, //Object number 107
				{ 1685, 591.8922100, -2422.6784700, 1.6288800, 0.0000000, 0.0000000, 0.0000000 }, //Object number 108
				{ 1684, 613.9993900, -2426.7954100, 2.2537300, 0.0000000, 0.0000000, -1350.0000000 }, //Object number 109
				{ 1684, 635.7711200, -2427.2876000, 8.5785000, 0.0000000, -90.2410000, -1350.0000000 }, //Object number 110
				{ 1684, 614.0567600, -2427.2094700, 8.3587300, 0.0000000, -90.2410000, -1530.8600000 }, //Object number 111
				{ 1685, 606.8851300, -2422.6897000, 1.6237300, 0.0000000, 0.0000000, 0.0000000 }, //Object number 112
				{ 1685, 606.8773200, -2422.7001900, 3.1237300, 0.0000000, 0.0000000, 0.0000000 }, //Object number 113
				{ 1685, 599.6180400, -2422.7876000, 1.6347200, 0.0000000, 0.0000000, 0.0000000 }, //Object number 114
				{ 1685, 599.6202400, -2422.7822300, 3.1347200, 0.0000000, 0.0000000, 0.0000000 }, //Object number 115
				{ 1684, 616.9410400, -2423.8100600, 3.8738100, 0.0000000, 0.0000000, -1440.0000000 }, //Object number 116
				{ 1684, 632.8309300, -2423.7690400, 3.8488100, 0.0000000, 0.0000000, -1800.0000000 }, //Object number 117
				{ 1684, 616.9676500, -2423.7817400, 6.7295700, 0.0000000, 0.0000000, -1980.0000000 }, //Object number 118
				{ 1684, 632.8009000, -2423.7817400, 6.7295700, 0.0000000, 0.0000000, -1800.0000000 }, //Object number 119
				{ 14414, 632.3443600, -2419.7846700, 4.3355800, 0.0000000, 0.0000000, -450.0000000 }, //Object number 120
				{ 14414, 617.4791300, -2419.8088400, 4.3355800, 0.0000000, 0.0000000, -630.0000000 }, //Object number 121
				{ 1684, 632.8165300, -2423.7614700, 9.6853200, 0.0000000, 0.0000000, -2340.0010000 }, //Object number 122
				{ 1684, 616.9608200, -2423.8112800, 9.7103200, 0.0000000, 0.0000000, -1800.0000000 }, //Object number 123
				{ 3389, 627.3267800, -2425.3696300, 7.5597900, 0.0000000, 0.0000000, -90.0000000 }, //Object number 124
				{ 3388, 622.4747300, -2425.3654800, 7.5605500, 0.0000000, 0.0000000, -90.0000000 }, //Object number 125
				{ 1684, 624.8592500, -2423.8540000, 12.5660800, 0.0000000, 0.0000000, -1980.0000000 }, //Object number 126
				{ 3594, 573.4730200, -2410.1359900, 2.9151100, 0.0000000, 0.0000000, -123.7500000 }, //Object number 127
				{ 3593, 570.6514900, -2406.1596700, 2.8191000, 0.0000000, 0.0000000, 22.5000000 }, //Object number 128
				{ 3578, 591.4227300, -2408.2121600, 2.5119700, 0.0000000, 0.0000000, 180.0000000 }, //Object number 129
				{ 3578, 594.2269300, -2408.2175300, 2.5119700, 0.0000000, 0.0000000, 180.0000000 }, //Object number 130
				{ 3578, 656.7642800, -2408.2368200, 2.3869600, 0.0000000, 0.0000000, 180.0000000 }, //Object number 131
				{ 3578, 658.1248800, -2408.2563500, 2.3869600, 0.0000000, 0.0000000, 180.0000000 }, //Object number 132
				{ 3594, 595.8719500, -2408.3642600, 3.5401100, -17.1890000, 0.0000000, -157.5000000 }, //Object number 133
				{ 3593, 624.4971900, -2416.1293900, 2.9863100, 0.0000000, 0.0000000, 94.2970000 }, //Object number 134
				{ 3594, 624.6126700, -2416.2583000, 3.9573100, 0.0000000, 0.0000000, -258.7500000 }, //Object number 135
				{ 3593, 624.2032500, -2416.1367200, 4.7478300, 0.0000000, 0.0000000, 96.9530000 }, //Object number 136
				{ 12957, 624.9263900, -2403.0954600, 3.1621500, 0.0000000, 0.0000000, -270.0000000 }, //Object number 137
				{ 3593, 616.1793200, -2411.0075700, 2.9941000, 10.3130000, 0.0000000, -7.7350000 }, //Object number 138
				{ 3594, 615.2906500, -2405.8120100, 2.9073200, 0.0000000, 0.0000000, -506.2500000 }, //Object number 139
				{ 3594, 633.4544700, -2411.2419400, 2.9151100, 0.0000000, 0.0000000, -517.5000000 }, //Object number 140
				{ 3593, 633.3487600, -2407.3823200, 3.2691000, -20.6260000, -185.6380000, -15.5470000 }, //Object number 141
				{ 1362, 633.9449500, -2409.1176800, 2.9127500, 0.0000000, 0.0000000, 0.0000000 }, //Object number 142
				{ 3593, 655.3404500, -2408.7741700, 3.2191000, 12.0320000, 0.0000000, 14.7650000 }, //Object number 143
				{ 3594, 641.3695100, -2401.1372100, 2.9151100, 0.0000000, 0.0000000, -585.0000000 }, //Object number 144
				{ 3594, 606.9715600, -2398.9550800, 2.9151100, 0.0000000, 0.0000000, -483.7500000 }, //Object number 145
				{ 3593, 616.8094500, -2393.0183100, 2.6691000, 0.0000000, 0.0000000, -101.2500000 }, //Object number 146
				{ 3594, 614.3167700, -2388.0161100, 2.7299700, 0.0000000, 0.0000000, -551.2500000 }, //Object number 147
				{ 12957, 617.1143800, -2374.3984400, 2.9121500, 0.0000000, 0.0000000, -191.2500000 }, //Object number 148
				{ 12957, 632.2530500, -2373.6777300, 2.9871500, 0.0000000, 0.0000000, -168.7500000 }, //Object number 149
				{ 3594, 633.2186300, -2393.3142100, 2.9151200, 0.0000000, 0.0000000, -618.7500000 }, //Object number 150
				{ 3593, 635.8602300, -2388.5988800, 2.7941000, 0.0000000, 0.0000000, -168.7500000 }, //Object number 151
				{ 3594, 677.0836200, -2410.5517600, 2.9151100, -12.8920000, 0.0000000, -236.2500000 }, //Object number 152
				{ 3593, 679.7218000, -2407.3181100, 2.7941000, 0.0000000, 0.0000000, -202.5000000 }, //Object number 153
				{ 8210, 546.0885000, -2445.5881300, 2.3349600, 0.0000000, 0.0000000, -180.0000000 }, //Object number 154
				{ 8210, 703.9237100, -2445.5410200, 2.3657400, 0.0000000, 0.0000000, -180.0000000 }, //Object number 155
				{ 986, 583.6075400, -2384.5769000, 7.9946000, 0.0000000, 0.0000000, 0.0000000 }, //Object number 156
				{ 986, 666.5015900, -2384.5026900, 7.9757000, 0.0000000, 0.0000000, -180.0000000 }, //Object number 157
				{ 1348, 658.0806900, -2427.1731000, 0.9614600, 0.0000000, 0.0000000, 90.0000000 }, //Object number 158
				{ 1348, 650.7388900, -2427.1735800, 0.9614600, 0.0000000, 0.0000000, 90.0000000 }, //Object number 159
				{ 1348, 643.5411400, -2427.1711400, 0.9864600, 0.0000000, 0.0000000, 90.0000000 }, //Object number 160
				{ 1348, 606.9683800, -2427.3017600, 0.9864600, 0.0000000, 0.0000000, 90.0000000 }, //Object number 161
				{ 1348, 599.6883500, -2427.2981000, 0.9864600, 0.0000000, 0.0000000, 90.0000000 }, //Object number 162
				{ 1348, 591.9344500, -2427.2553700, 1.0364600, 0.0000000, 0.0000000, 90.0000000 }, //Object number 163
				{ 986, 577.1046100, -2418.9196800, 3.9696000, 0.0000000, 0.0000000, -43.2810000 }, //Object number 164
				{ 986, 673.0843500, -2418.8947800, 3.9946000, 0.0000000, 0.0000000, 44.1410000 }, //Object number 165
				{ 1684, 660.4871800, -2399.1140100, 4.7238100, 0.0000000, 0.0000000, -540.0000000 }, //Object number 166
				{ 1684, 589.7218000, -2399.2177700, 4.7238100, 0.0000000, 0.0000000, -540.0000000 }, //Object number 167
				{ 8326, 600.6021700, -2376.3054200, 3.8483200, 0.0000000, 0.0000000, -180.0000000 }, //Object number 168
				{ 14467, 625.3831800, -2396.8103000, 10.9034800, 0.0000000, 0.0000000, 0.0000000 }, //Object number 169
				{ 8326, 649.6265900, -2376.3825700, 3.8733200, 0.0000000, 0.0000000, -360.0000000 }, //Object number 170
				{ 979, 589.7491500, -2401.2150900, 6.9299100, 0.0000000, 0.0000000, -540.0000000 }, //Object number 171
				{ 978, 584.8033500, -2396.3029800, 6.9354700, 0.0000000, 0.0000000, -270.0000000 }, //Object number 172
				{ 979, 594.6536900, -2396.3176300, 6.9354700, 0.0000000, 0.0000000, -810.0000000 }, //Object number 173
				{ 979, 655.6099900, -2396.3288600, 6.9354700, 0.0000000, 0.0000000, -990.0000000 }, //Object number 174
				{ 979, 660.4268800, -2401.2185100, 6.9299100, 0.0000000, 0.0000000, -900.0000000 }, //Object number 175
				{ 979, 665.3870800, -2396.3291000, 6.9354700, 0.0000000, 0.0000000, -810.0000000 }, //Object number 176
				{ 1684, 660.4881600, -2399.1313500, 1.8738100, 0.0000000, 0.0000000, -900.0000000 }, //Object number 177
				{ 1684, 589.7120400, -2399.1982400, 1.8488100, 0.0000000, 0.0000000, -900.0000000 }, //Object number 178
				{ 12814, 634.5887500, -2368.4167500, 9.7487300, 0.0000000, 90.2410000, -270.0000000 }, //Object number 179
				{ 7913, 624.7735600, -2426.4162600, 7.1129000, -90.2410000, 0.0000000, -270.0000000 }, //Object number 180
				{ 979, 626.2025100, -2417.8129900, 8.1424500, 0.0000000, 0.0000000, -720.0000000 }, //Object number 181
				{ 7915, 624.9132100, -2418.2209500, 2.2092600, 0.0000000, 0.0000000, -180.0000000 }, //Object number 182
				{ 979, 634.4976800, -2417.8166500, 5.5741600, 0.0000000, 34.3770000, -720.0000000 }, //Object number 183
				{ 979, 623.6004600, -2417.8398400, 8.1461200, 0.0000000, 0.0000000, -720.0000000 }, //Object number 184
				{ 979, 615.3258100, -2417.8154300, 5.5318600, 0.0000000, -34.3770000, -1080.0000000 }, //Object number 185
				{ 7915, 635.2974900, -2418.2358400, -0.0621100, 0.0000000, -34.3770000, -180.0000000 }, //Object number 186
				{ 7915, 614.5516400, -2418.2185100, -0.0489800, 0.0000000, 34.3770000, -180.0000000 }, //Object number 187
				{ 1684, 624.9093000, -2420.0119600, 6.0087300, 0.0000000, 0.0000000, -2160.0010000 }, //Object number 188
				{ 8210, 670.7874800, -2368.8442400, 5.3599600, 0.0000000, 0.0000000, -90.0000000 }, //Object number 189
				{ 8210, 670.7994400, -2368.8332500, 9.6660700, 0.0000000, 0.0000000, -90.0000000 }, //Object number 190
				{ 12814, 615.7777100, -2367.9506800, 9.7487300, 0.0000000, 90.2410000, -270.0000000 }, //Object number 191
				{ 8210, 579.2921100, -2369.0000000, 5.3849600, 0.0000000, 0.0000000, 90.0000000 }, //Object number 192
				{ 8210, 579.3033500, -2368.9917000, 9.6849700, 0.0000000, 0.0000000, -270.0000000 }, //Object number 193
				{ 944, 650.9071000, -2397.8230000, 6.9300300, 0.0000000, 0.0000000, 0.0000000 }, //Object number 194
				{ 944, 653.7918700, -2397.8261700, 6.9300300, 0.0000000, 0.0000000, 0.0000000 }, //Object number 195
				{ 944, 599.1981200, -2397.8566900, 6.9300300, 0.0000000, 0.0000000, 0.0000000 }, //Object number 196
				{ 944, 596.3062700, -2397.8645000, 6.9300300, 0.0000000, 0.0000000, 0.0000000 }, //Object number 197
				{ 7906, 594.5614000, -2376.1540500, 12.4586800, 0.0000000, 0.0000000, 90.0000000 }, //Object number 198
				{ 7907, 586.5343000, -2384.1784700, 12.4771600, 0.0000000, 0.0000000, 0.0000000 }, //Object number 199
				{ 7909, 655.6605200, -2376.1594200, 12.4939900, 0.0000000, 0.0000000, -90.0000000 }, //Object number 200
				{ 7912, 663.7032500, -2384.1943400, 12.4936500, 0.0000000, 0.0000000, 0.0000000 }, //Object number 201
				{ 989, 665.3172600, -2394.4968300, 4.3980800, 0.0000000, 0.0000000, 17.3430000 }, //Object number 202
				{ 989, 584.7557400, -2394.6103500, 4.1079300, 0.0000000, 0.0000000, 17.3430000 }, //Object number 203
				{ 986, 675.3038300, -2397.6191400, 9.9446000, 0.0000000, 0.0000000, 0.0000000 }, //Object number 204
				{ 3578, 671.3260500, -2396.6799300, 9.9369600, 0.0000000, -90.2410000, 44.2090000 }, //Object number 205
				{ 986, 682.9542200, -2399.1650400, 9.9311000, 0.0000000, 0.0000000, -22.5000000 }, //Object number 206
				{ 986, 574.8397200, -2397.6052200, 9.9328900, 0.0000000, 0.0000000, 0.0000000 }, //Object number 207
				{ 986, 567.1663800, -2399.1267100, 9.9228400, 0.0000000, 0.0000000, 22.5000000 }, //Object number 208
				{ 3578, 578.7274200, -2396.5849600, 10.3633300, 0.0000000, -90.2410000, 134.2090000 }, //Object number 209
				{ 1684, 677.9962200, -2421.1577100, 9.5845700, 0.0000000, 0.0000000, -1170.0000000 }, //Object number 210
				{ 1684, 670.5181900, -2423.8059100, 7.9778700, 0.0000000, 0.0000000, -1260.0000000 }, //Object number 211
				{ 1684, 572.0528600, -2421.1218300, 9.6103300, 0.0000000, 0.0000000, -1170.0000000 }, //Object number 212
				{ 1684, 579.2728300, -2423.7797900, 8.0045600, 0.0000000, 0.0000000, -1260.0000000 }, //Object number 213
				{ 1684, 632.7891900, -2423.7976100, 12.5660800, 0.0000000, 0.0000000, -1800.0000000 }, //Object number 214
				{ 1684, 616.9659400, -2423.8071300, 12.5660800, 0.0000000, 0.0000000, -2340.0010000 }, //Object number 215
				{ 1684, 625.0704400, -2386.3852500, 6.7324200, 0.0000000, 0.0000000, -90.0000000 }, //Object number 216
				{ 7073, 573.7796600, -2390.2934600, 20.5506800, 0.0000000, 0.0000000, -45.0000000 }, //Object number 217
				{ 7392, 678.6207300, -2387.5820300, 13.5040100, 0.0000000, 0.0000000, 45.0000000 }, //Object number 218
				{ 16776, 624.8729300, -2362.2678200, 9.1601100, 0.0000000, 0.0000000, 0.0000000 }, //Object number 219
				{ 4002, 623.2794200, -2443.6796900, 18.1022700, 0.0000000, 0.0000000, 0.0000000 }, //Object number 220
				{ 4007, 695.7318100, -2360.5769000, 20.9131800, 0.0000000, 0.0000000, -348.7500000 }, //Object number 221
				{ 4113, 557.2159400, -2360.9663100, 32.8125400, 0.0000000, 0.0000000, 11.2500000 }, //Object number 222
				{ 4550, 625.8548600, -2307.1081500, 82.4300700, 0.0000000, 0.0000000, 0.0000000 }, //Object number 223
				{ 4563, 524.7269300, -2436.3171400, -4.7504400, 0.0000000, 0.0000000, 0.0000000 }, //Object number 224
				{ 4586, 735.0076900, -2441.4426300, 4.0159300, 0.0000000, 0.0000000, 0.0000000 }, //Object number 225
				{ 3881, 652.1031500, -2394.4929200, 4.1105000, 0.0000000, 0.0000000, -180.0000000 }, //Object number 226
				{ 3881, 597.9549600, -2395.4126000, 4.1265500, 0.0000000, 0.0000000, 0.0000000 }, //Object number 227
				{ 974, 649.3133500, -2389.2138700, 4.5866700, 0.0000000, 0.0000000, -90.0000000 }, //Object number 228
				{ 974, 649.3282500, -2393.8442400, 4.5616800, 0.0000000, 0.0000000, -90.0000000 }, //Object number 229
				{ 7913, 652.7777100, -2383.2961400, 2.9128900, 0.0000000, 0.0000000, -90.0000000 }, //Object number 230
				{ 974, 652.9429900, -2383.5839800, 3.3148900, 0.0000000, 0.0000000, 0.0000000 }, //Object number 231
				{ 979, 652.3409400, -2387.2978500, 6.9241500, 0.0000000, 0.0000000, -990.0000000 }, //Object number 232
				{ 974, 600.7222900, -2389.0964400, 4.5866700, 0.0000000, 0.0000000, -90.0000000 }, //Object number 233
				{ 974, 600.7210700, -2393.7873500, 4.5866700, 0.0000000, 0.0000000, -90.0000000 }, //Object number 234
				{ 979, 597.6661400, -2387.4567900, 6.9241600, 0.0000000, 0.0000000, -1170.0000000 }, //Object number 235
				{ 974, 597.3963600, -2383.4963400, 3.3957900, 0.0000000, 0.0000000, -180.0000000 }, //Object number 236
				{ 7913, 597.2518300, -2383.3147000, 2.8981800, 0.0000000, 0.0000000, -270.0000000 }, //Object number 237
				{ 944, 650.9700900, -2383.1804200, 7.1687200, 0.0000000, 0.0000000, 0.0000000 }, //Object number 238
				{ 944, 599.1947000, -2383.2551300, 7.1530000, 0.0000000, 0.0000000, 0.0000000 }, //Object number 239
				{ 964, 626.5260000, -2418.4077100, 7.5488500, 0.0000000, 0.0000000, 0.0000000 }, //Object number 240
				{ 964, 623.2379200, -2418.3735400, 7.5238500, 0.0000000, 0.0000000, -90.0000000 }, //Object number 241
				{ 964, 598.4993900, -2419.5163600, 2.2839300, 0.0000000, 0.0000000, -180.0000000 }, //Object number 242
				{ 964, 651.4613000, -2419.3815900, 2.2839300, 0.0000000, 0.0000000, -180.0000000 }, //Object number 243
				{ 7914, 624.8643800, -2426.2768500, 8.4618200, 0.0000000, 0.0000000, -180.0000000 }, //Object number 244
				{ 8210, 648.2088600, -2427.4699700, 3.7849600, 0.0000000, 0.0000000, -180.0000000 }, //Object number 245
				{ 8210, 601.7115500, -2427.6154800, 3.8099600, 0.0000000, 0.0000000, -180.0000000 }//Object number 246
			})
		{}

		bool OnGameModeInit()
		{
			MakeAllDynamicObjects(ArenaObjects, CurrentGameVW);
			return true;
		}

		void Timer(int timerid, ZabawyTimerVector& vector)
		{
			int playerid = TimerDataGet<int>(vector, 0);
			if (Player[playerid].CurrentGameID == this)
			{
				safeGivePlayerWeapon(playerid, 31, 999999);
				fixSetPlayerHealth(playerid, 33);
				fixSetPlayerArmour(playerid, 0);
				fixTogglePlayerControllable(playerid, true);
			}
		}

		void PutPlayerIntoGame(int playerid)
		{
			fixSetPlayerHealth(playerid, 10000);
			fixSetPlayerArmour(playerid, 10000);
			fixTogglePlayerControllable(playerid , false);

			auto i = ArenaSpawns[Functions::RandomGenerator->Random(0, ArenaSpawns.size() - 1)];
			TeleportPlayer(playerid, i.x, i.y, i.z, i.a, false, 0, CurrentGameVW, "", 0, 0, 0.0, 0.0, true);

			CreateTimer<Arena>(333, false, &Arena::Timer, playerid);		
		}

		bool OnKeepInGameSpawn(int playerid) 
		{ 
			PutPlayerIntoGame(playerid);
			return true; 
		}

		bool OnGameCommandExecute(int playerid, std::string params)
		{
			AddPlayer(playerid, true);
			PutPlayerIntoGame(playerid);
			return true;
		}

		bool OnPlayerDeath(int playerid, int killerid, int reason)
		{
			GivePlayerAchievement(playerid, EAM_ZabawyOneShotDeaths, 1);
			if (killerid != INVALID_PLAYER_ID)
			{
				GivePlayerAchievement(killerid, EAM_ZabawyOneShotKills, 1);
			}
			return true;
		}

		bool PlayerRequestGameExit(int playerid, int reason)
		{
			switch (reason)
			{
			case PlayerRequestExitTypeDisconnect:
				PlayerExitGame(playerid);
				break;
			case PlayerRequestExitTypeExit:
				PlayerExitGame(playerid);
				break;
			}
			return true;
		}
	} _Arena;
};