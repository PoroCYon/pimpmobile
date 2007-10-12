const u16 amiga_period_lut[] =
{
	/* this is for negative fine-tunes... */
	907,900,894,887,881,875,868,862,	/* B-0 */

	856,850,844,838,832,826,820,814,	/* C-1 */
	808,802,796,791,785,779,774,768,	/* C#1 */
	762,757,752,746,741,736,730,725,	/* D-1 */
	720,715,709,704,699,694,689,684,	/* D#1 */
	678,674,670,665,660,655,651,646,	/* E-1 */
	640,637,632,628,623,619,614,610,	/* F-1 */
	604,601,597,592,588,584,580,575,	/* F#1 */
	570,567,563,559,555,551,547,543,	/* G-1 */
	538,535,532,528,524,520,516,513,	/* G#1 */
	508,505,502,498,495,491,487,484,	/* A-1 */
	480,477,474,470,467,463,460,457,	/* A#1 */
	453,450,447,444,441,437,434,431,	/* B-1 */
	
	428,425,422,419,416,413,410,407,	/* C-2 */
	404,401,398,395,392,390,387,384,	/* C#2 */
	381,379,376,373,370,368,365,363,	/* D-2 */
	360,357,355,352,350,347,345,342,	/* D#2 */
	339,337,335,332,330,328,325,323,	/* E-2 */
	320,318,316,314,312,309,307,305,	/* F-2 */
	302,300,298,296,294,292,290,288,	/* F#2 */
	285,284,282,280,278,276,274,272,	/* G-2 */
	269,268,266,264,262,260,258,256,	/* G#2 */
	254,253,251,249,247,245,244,242,	/* A-2 */
	240,239,237,235,233,232,230,228,	/* A#2 */
	226,225,224,222,220,219,217,216,	/* B-2 */
	
	214,213,211,209,208,206,205,204,	/* C-3 */
	202,201,199,198,196,195,193,192,	/* C#3 */
	190,189,188,187,185,184,183,181,	/* D-3 */
	180,179,177,176,175,174,172,171,	/* D#3 */
	170,169,167,166,165,164,163,161,	/* E-3 */
	160,159,158,157,156,155,154,152,	/* F-3 */
	151,150,149,148,147,146,145,144,	/* F#3 */
	143,142,141,140,139,138,137,136,	/* G-3 */
	135,134,133,132,131,130,129,128,	/* G#3 */
	127,126,125,125,124,123,122,121,	/* A-3 */
	120,119,118,118,117,116,115,114,	/* A#3 */
/*	113,113,112,111,110,109,109,108, */	/* B-3 */
	
	/* this is for positive fine-tunes */
/*	107,106,105,104,104,103,102,102,*/	/* C-4 */
};
