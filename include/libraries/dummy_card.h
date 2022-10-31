
#ifndef dummy_card_h
#define dummy_card_h

enum
{
    PLANAR,
    CHUNKY,
    HICOLOR,
    TRUECOLOR,
    TRUEALPHA,
    MAXMODES
};

struct ModeInfo
{
	struct Node	Node;						// used for linking ModeInfos e.g. within MoniTool
	WORD			OpenCount;
	BOOL			Active;
	UWORD			Width;
	UWORD			Height;
	UBYTE			Depth;
	UBYTE			Flags;

	UWORD			HorTotal;				// wichtig für aufziehen (beeinflußt Timings)
	UWORD			HorBlankSize;			// Rahmengröße
	UWORD			HorSyncStart;			// bestimmt Bildlage
	UWORD			HorSyncSize;			// muß Spezifikation für Sync-Lücke erfüllen

	UBYTE			HorSyncSkew;			// im Moment obsolet
	UBYTE			HorEnableSkew;			//

	UWORD			VerTotal;				// analog zu horizontalen Werten
	UWORD			VerBlankSize;
	UWORD			VerSyncStart;
	UWORD			VerSyncSize;

	union{
		UBYTE		Clock;					// Tseng: Nummer der Hardwareclock
		UBYTE		Numerator;				// Cirrus: Mumerator für PLL
	} pll1;
	union{
		UBYTE		ClockDivide;			// Tseng: Clockteiler
		UBYTE		Denominator;			// Cirrus: Denominator für PLL
	} pll2;
	ULONG			PixelClock;				// PixelClock in Hz
};


#endif

