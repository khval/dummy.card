
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

	UWORD			HorTotal;				// wichtig f�r aufziehen (beeinflu�t Timings)
	UWORD			HorBlankSize;			// Rahmengr��e
	UWORD			HorSyncStart;			// bestimmt Bildlage
	UWORD			HorSyncSize;			// mu� Spezifikation f�r Sync-L�cke erf�llen

	UBYTE			HorSyncSkew;			// im Moment obsolet
	UBYTE			HorEnableSkew;			//

	UWORD			VerTotal;				// analog zu horizontalen Werten
	UWORD			VerBlankSize;
	UWORD			VerSyncStart;
	UWORD			VerSyncSize;

	union{
		UBYTE		Clock;					// Tseng: Nummer der Hardwareclock
		UBYTE		Numerator;				// Cirrus: Mumerator f�r PLL
	} pll1;
	union{
		UBYTE		ClockDivide;			// Tseng: Clockteiler
		UBYTE		Denominator;			// Cirrus: Denominator f�r PLL
	} pll2;
	ULONG			PixelClock;				// PixelClock in Hz
};


#endif

