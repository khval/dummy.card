
#ifndef boardinfo_h
#define boardinfo_h

#ifdef __GNUC__
 #ifdef __PPC__
 #pragma pack(2)
 #endif
#elif defined(__VBCC__)
 #pragma amiga-align
#endif

#ifndef  LIBRARIES_PICASSO96_H
#include <libraries/Picasso96.h>
#endif

#ifndef  EXEC_INTERRUPTS_H
#include <exec/interrupts.h>
#endif

#ifndef  EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif

#ifndef  EXEC_SEMAPHORES_H
#include <exec/semaphores.h>
#endif

#ifndef  GRAPHICS_GFX_H
#include <graphics/gfx.h>
#endif

#ifndef  GRAPHICS_VIEW_H
#include <graphics/view.h>
#endif

#ifndef DEVICES_TIMER_H
#include <devices/timer.h>
#endif


/* registerized parameters */

/************************************************************************/

#define MAXSPRITEWIDTH 32
#define MAXSPRITEHEIGHT 48

/************************************************************************/

#define DI_P96_INVALID 0x1000
#define DI_P96_MONITOOL 0x2000

/************************************************************************/
/* Types for BoardType Identification */

typedef enum
{
	BT_NoBoard, 
	BT_oMniBus, 
	BT_Graffity, 
	BT_CyberVision, 
	BT_Domino, 
	BT_Merlin, 
	BT_PicassoII, 
	BT_Piccolo, 
	BT_RetinaBLT, 
	BT_Spectrum, 
	BT_PicassoIV, 
	BT_PiccoloSD64, 
	BT_A2410, 
	BT_Pixel64, 
	BT_uaegfx,  // 14
	BT_CVision3D, 
	BT_Altais, 
	BT_Prometheus, 
	BT_Mediator, 
	BT_powerfb, 
	BT_powerpci, 
	BT_CVisionPPC, 
	BT_GREX, 
	BT_Prototype7, 
	BT_Reserved, 
	BT_Reserved2, 
	BT_MNT_VA2000, 
	BT_MNT_ZZ9000, 
	BT_MaxBoardTypes
} BTYPE;

/************************************************************************/
/* Types for PaletteChipType Identification
 */
typedef enum
{
	PCT_Unknown, 
	PCT_S11483,  // Sierra S11483: HiColor 15 bit,  oMniBus,  Domino
	PCT_S15025,  // Sierra S15025: TrueColor 32 bit,  oMniBus
	PCT_CirrusGD542x,  // Cirrus GD542x internal: TrueColor 24 bit
	PCT_Domino,  // is in fact a Sierra S11483
	PCT_BT482,  // BrookTree BT482: TrueColor 32 bit,  Merlin
	PCT_Music,  // Music MU9C4910: TrueColor 24 bit,  oMniBus
	PCT_ICS5300,  // ICS 5300: ....,  Retina BLT Z3
	PCT_CirrusGD5446,  // Cirrus GD5446 internal: TrueColor 24 bit
	PCT_CirrusGD5434,  // Cirrus GD5434 internal: TrueColor 32 bit
	PCT_S3Trio64,  // S3 Trio64 internal: TrueColor 32 bit
	PCT_A2410_xxx,  // A2410 DAC,  *type unknown*
	PCT_S3ViRGE,  // S3 ViRGE internal: TrueColor 32 bit
	PCT_3dfxVoodoo,  // 3dfx Voodoo internal
	PCT_TIPermedia2,  // TexasInstruments TVP4020 Permedia2 internal
	PCT_ATIRV100,  // ATI Technologies Radeon/Radeon 7000 internal
	PCT_reserved, 
	PCT_reserved2, 
	PCT_MNT_VA2000, 
	PCT_MNT_ZZ9000, 
	PCT_MaxPaletteChipTypes
} PCTYPE;

/************************************************************************/
/* Types for GraphicsControllerType Identification
 */
typedef enum
{
	GCT_Unknown, 
	GCT_ET4000, 
	GCT_ETW32,  
	GCT_CirrusGD542x, 
	GCT_NCR77C32BLT,  
	GCT_CirrusGD5446, 
	GCT_CirrusGD5434, 
	GCT_S3Trio64, 
	GCT_TI34010, 
	GCT_S3ViRGE, 
	GCT_3dfxVoodoo, 
	GCT_TIPermedia2, 
	GCT_ATIRV100, 
	GCT_reserved, 
	GCT_reserved2, 
	GCT_MNT_VA2000, 
	GCT_MNT_ZZ9000, 
	GCT_MaxGraphicsControllerTypes
} GCTYPE;

/************************************************************************/

#define RGBFF_PLANAR RGBFF_NONE
#define RGBFF_CHUNKY RGBFF_CLUT

#define RGBFB_PLANAR RGBFB_NONE
#define RGBFB_CHUNKY RGBFB_CLUT

/************************************************************************/

enum
{
	DPMS_ON,  /* Full operation */
	DPMS_STANDBY,  /* Optional state of minimal power reduction */
	DPMS_SUSPEND,  /* Significant reduction of power consumption */
	DPMS_OFF /* Lowest level of power consumption */
};

/************************************************************************/

struct CLUTEntry
{
	UBYTE Red;
	UBYTE Green;
	UBYTE Blue;
};

struct ColorIndexMapping
{
	ULONG ColorMask;
	ULONG Colors[256];
};

/************************************************************************/

struct GfxMemChunk
{
	struct MinNode Node;
	char *Ptr;
	ULONG Size;
	BOOL Used;
};

/************************************************************************/

struct Template
{
	APTR Memory;
	WORD BytesPerRow;
	UBYTE XOffset; // 0 <= XOffset <= 15
	UBYTE DrawMode;
	ULONG FgPen;
	ULONG BgPen;
};

/************************************************************************/

struct Pattern
{
	APTR Memory;
	UWORD XOffset,  YOffset;
	ULONG FgPen,  BgPen;
	UBYTE Size;  // Width: 16,  Height: (1<<pat_Size)
	UBYTE DrawMode;
};

/************************************************************************/

struct Line
{
	WORD X,  Y;
	UWORD Length;
	WORD dX,  dY;
	WORD sDelta,  lDelta,  twoSDminusLD;
	UWORD LinePtrn;
	UWORD PatternShift;
	ULONG FgPen,  BgPen;
	BOOL Horizontal;
	UBYTE DrawMode;
	BYTE pad;
	UWORD Xorigin,  Yorigin;
};

/************************************************************************/

struct BitMapExtra
{
	struct MinNode BoardNode;
	struct BitMapExtra *HashChain;
	APTR Match;
	struct BitMap *BitMap;
	struct BoardInfo *BoardInfo;
	APTR MemChunk;
	struct RenderInfo RenderInfo;
	UWORD Width,  Height;
	UWORD Flags;
	// NEW !!!
	WORD BaseLevel,  CurrentLevel;
	struct BitMapExtra *CompanionMaster;
};

/* BitMapExtra flags */
#define BMEF_ONBOARD 0x0001
#define BMEF_SPECIAL 0x0002
#define BMEF_VISIBLE 0x0800
#define BMEF_DISPLAYABLE 0x1000
#define BMEF_SPRITESAVED 0x2000
#define BMEF_CHECKSPRITE 0x4000
#define BMEF_INUSE 0x8000

/************************************************************************/

struct SpecialFeature
{
	struct MinNode Node;
	struct BoardInfo *BoardInfo;
	struct BitMap *BitMap;
	ULONG Type;
	APTR FeatureData;
};

enum
{
	SFT_INVALID,  SFT_FLICKERFIXER,  SFT_VIDEOCAPTURE,  SFT_VIDEOWINDOW,  SFT_MEMORYWINDOW
};

#define FA_Restore  (TAG_USER+0) /* becomes visible again */
#define FA_Onboard  (TAG_USER+1)
#define FA_Active  (TAG_USER+2)
#define FA_Left  (TAG_USER+3)
#define FA_Top  (TAG_USER+4)
#define FA_Width  (TAG_USER+5)
#define FA_Height  (TAG_USER+6)
#define FA_Format  (TAG_USER+7)
#define FA_Color  (TAG_USER+8)
#define FA_Occlusion  (TAG_USER+9)
#define FA_SourceWidth  (TAG_USER+10)
#define FA_SourceHeight  (TAG_USER+11)
#define FA_MinWidth  (TAG_USER+12)
#define FA_MinHeight  (TAG_USER+13)
#define FA_MaxWidth  (TAG_USER+14)
#define FA_MaxHeight  (TAG_USER+15)
#define FA_Interlace  (TAG_USER+16)
#define FA_PAL  (TAG_USER+17)
#define FA_BitMap  (TAG_USER+18)
#define FA_Brightness  (TAG_USER+19)
#define FA_ModeInfo  (TAG_USER+20)
#define FA_ModeFormat  (TAG_USER+21)
#define FA_Colors  (TAG_USER+22)
#define FA_Colors32  (TAG_USER+23)
#define FA_NoMemory  (TAG_USER+24)
#define FA_RenderFunc  (TAG_USER+25)
#define FA_SaveFunc  (TAG_USER+26)
#define FA_UserData  (TAG_USER+27)
#define FA_Alignment  (TAG_USER+28)
#define FA_ConstantBytesPerRow (TAG_USER+29)
#define FA_DoubleBuffer  (TAG_USER+30)
#define FA_Pen  (TAG_USER+31)
#define FA_ModeMemorySize (TAG_USER+32)
#define FA_ClipLeft  (TAG_USER+33)
#define FA_ClipTop  (TAG_USER+34)
#define FA_ClipWidth  (TAG_USER+35)
#define FA_ClipHeight  (TAG_USER+36)
#define FA_ConstantByteSwapping (TAG_USER+37)

/************************************************************************/

/* Tags for bi->AllocBitMap() */

#define ABMA_Friend  (TAG_USER+0)
#define ABMA_Depth  (TAG_USER+1)
#define ABMA_RGBFormat  (TAG_USER+2)
#define ABMA_Clear  (TAG_USER+3)
#define ABMA_Displayable (TAG_USER+4)
#define ABMA_Visible  (TAG_USER+5)
#define ABMA_NoMemory  (TAG_USER+6)
#define ABMA_NoSprite  (TAG_USER+7)
#define ABMA_Colors  (TAG_USER+8)
#define ABMA_Colors32  (TAG_USER+9)
#define ABMA_ModeWidth  (TAG_USER+10)
#define ABMA_ModeHeight  (TAG_USER+11)
#define ABMA_RenderFunc  (TAG_USER+12)
#define ABMA_SaveFunc  (TAG_USER+13)
#define ABMA_UserData  (TAG_USER+14)
#define ABMA_Alignment  (TAG_USER+15)
#define ABMA_ConstantBytesPerRow (TAG_USER+16)
#define ABMA_UserPrivate (TAG_USER+17)
#define ABMA_ConstantByteSwapping (TAG_USER+18)
/* the following are reserved for Os 4 but not in current use */
#define ABMA_Memory  (TAG_USER+19)
#define ABMA_NotifyHook  (TAG_USER+20)
#define ABMA_Locked  (TAG_USER+21)
/* the following are new */
#define ABMA_System  (TAG_USER+22)
/*
 * THOR: New for V45 Gfx/Intuiton
 * "by accident",  this is identically to SA_DisplayID of intuition
 * resp. SA_Behind,  SA_Colors,  SA_Colors32
 */
#define ABMA_DisplayID  (TAG_USER + 32 + 0x12)
#define ABMA_BitmapInvisible (TAG_USER + 32 + 0x17)
#define ABMA_BitmapColors (TAG_USER + 32 + 0x09)
#define ABMA_BitmapColors32 (TAG_USER + 32 + 0x23)

/************************************************************************/

/* Tags for bi->GetBitMapAttr() */

#define GBMA_MEMORY  (TAG_USER+0)
#define GBMA_BASEMEMORY  (TAG_USER+1)
#define GBMA_BYTESPERROW (TAG_USER+2)
#define GBMA_BYTESPERPIXEL (TAG_USER+3)
#define GBMA_BITSPERPIXEL (TAG_USER+4)
#define GBMA_RGBFORMAT  (TAG_USER+6)
#define GBMA_WIDTH  (TAG_USER+7)
#define GBMA_HEIGHT  (TAG_USER+8)
#define GBMA_DEPTH  (TAG_USER+9)

/************************************************************************/

struct BoardInfo
{
		UBYTE  *RegisterBase,  *MemoryBase,  *MemoryIOBase;
		ULONG  MemorySize;
		char  *BoardName, VBIName[32];
		struct CardBase  *CardBase;
		struct ChipBase  *ChipBase;
		struct ExecBase  *ExecBase;
		struct Library  *UtilBase;
		struct Interrupt  HardInterrupt;
		struct Interrupt  SoftInterrupt;
		struct SignalSemaphore BoardLock;
		struct MinList  ResolutionsList;
		BTYPE  BoardType;
		PCTYPE  PaletteChipType;
		GCTYPE  GraphicsControllerType;
		UWORD  MoniSwitch;
		UWORD  BitsPerCannon;
		ULONG  Flags;
		UWORD  SoftSpriteFlags;
		UWORD  ChipFlags;  // private,  chip specific,  not touched by RTG
		ULONG  CardFlags;  // private,  card specific,  not touched by RTG
		UWORD  BoardNum;  // set by rtg.library
		UWORD  RGBFormats;
		UWORD  MaxHorValue[MAXMODES];
		UWORD  MaxVerValue[MAXMODES];
		UWORD  MaxHorResolution[MAXMODES];
		UWORD  MaxVerResolution[MAXMODES];
		ULONG  MaxMemorySize,  MaxChunkSize;
		ULONG  MemoryClock;
		ULONG  PixelClockCount[MAXMODES];
		APTR (*AllocCardMem)(struct BoardInfo *bi, ULONG size, BOOL force, BOOL system);
		BOOL (*FreeCardMem)(struct BoardInfo *bi, APTR membase);
		BOOL (*SetSwitch)(struct BoardInfo *, BOOL);
		void (*SetColorArray)(struct BoardInfo *, UWORD,  UWORD);
		void (*SetDAC)(struct BoardInfo *, RGBFTYPE);
		void (*SetGC)(struct BoardInfo *, struct ModeInfo *, BOOL);
		void (*SetPanning)(struct BoardInfo *, UBYTE *, UWORD, WORD, WORD, RGBFTYPE);
		UWORD (*CalculateBytesPerRow)(struct BoardInfo *, UWORD, RGBFTYPE);
		APTR (*CalculateMemory)(struct BoardInfo *, APTR, RGBFTYPE);
		ULONG (*GetCompatibleFormats)(struct BoardInfo *, RGBFTYPE);
		BOOL (*SetDisplay)(struct BoardInfo *, BOOL);
		LONG (*ResolvePixelClock)(struct BoardInfo *, struct ModeInfo *, ULONG, RGBFTYPE);
		ULONG (*GetPixelClock)(struct BoardInfo *bi, struct ModeInfo *, ULONG, RGBFTYPE);
		void (*SetClock)(struct BoardInfo *);
		void (*SetMemoryMode)(struct BoardInfo *, RGBFTYPE);
		void (*SetWriteMask)(struct BoardInfo *, UBYTE);
		void (*SetClearMask)(struct BoardInfo *, UBYTE);
		void (*SetReadPlane)(struct BoardInfo *, UBYTE);
		void (*WaitVerticalSync)(struct BoardInfo *, BOOL);
		BOOL (*SetInterrupt)(struct BoardInfo *, BOOL);
		void (*WaitBlitter)(struct BoardInfo *);
		void (*ScrollPlanar)(struct BoardInfo *, struct RenderInfo *, UWORD,  UWORD,  UWORD,  UWORD,  UWORD, UWORD, UBYTE);
		void (*ScrollPlanarDefault)(struct BoardInfo *, struct RenderInfo *, UWORD,  UWORD,  UWORD,  UWORD,  UWORD, UWORD, UBYTE);
		void (*UpdatePlanar)(struct BoardInfo *, struct BitMap *, struct RenderInfo *, SHORT, SHORT, SHORT, SHORT, UBYTE);
		void (*UpdatePlanarDefault)(struct BoardInfo *, struct BitMap *, struct RenderInfo *, SHORT, SHORT, SHORT, SHORT, UBYTE);
		void (*BlitPlanar2Chunky)(struct BoardInfo *, struct BitMap *, struct RenderInfo *, SHORT, SHORT, SHORT, SHORT, SHORT, SHORT, UBYTE, UBYTE);
		void (*BlitPlanar2ChunkyDefault)(struct BoardInfo *, struct BitMap *, struct RenderInfo *, SHORT, SHORT, SHORT, SHORT, SHORT, SHORT, UBYTE, UBYTE);
		void (*FillRect)(struct BoardInfo *, struct RenderInfo *, WORD, WORD, WORD, WORD, ULONG, UBYTE, RGBFTYPE);
		void (*FillRectDefault)(struct BoardInfo *, struct RenderInfo *, WORD, WORD, WORD, WORD, ULONG, UBYTE, RGBFTYPE);
		void (*InvertRect)(struct BoardInfo *, struct RenderInfo *, WORD, WORD, WORD, WORD, UBYTE, RGBFTYPE);
		void (*InvertRectDefault)(struct BoardInfo *, struct RenderInfo *, WORD, WORD, WORD, WORD, UBYTE, RGBFTYPE);
		void (*BlitRect)(struct BoardInfo *, struct RenderInfo *, WORD, WORD, WORD, WORD, WORD, WORD, UBYTE, RGBFTYPE);
		void (*BlitRectDefault)(struct BoardInfo *, struct RenderInfo *, WORD, WORD, WORD, WORD, WORD, WORD, UBYTE, RGBFTYPE);
		void (*BlitTemplate)(struct BoardInfo *, struct RenderInfo *, struct Template *, WORD, WORD, WORD, WORD, UBYTE, RGBFTYPE);
		void (*BlitTemplateDefault)(struct BoardInfo *, struct RenderInfo *, struct Template *, WORD, WORD, WORD, WORD, UBYTE, RGBFTYPE);
		void (*BlitPattern)(struct BoardInfo *, struct RenderInfo *, struct Pattern *, WORD, WORD, WORD, WORD, UBYTE, RGBFTYPE);
		void (*BlitPatternDefault)(struct BoardInfo *, struct RenderInfo *, struct Pattern *, WORD, WORD, WORD, WORD, UBYTE, RGBFTYPE);
		void (*DrawLine)(struct BoardInfo *, struct RenderInfo *, struct Line *, UBYTE, RGBFTYPE);
		void (*DrawLineDefault)(struct BoardInfo *, struct RenderInfo *, struct Line *, UBYTE, RGBFTYPE);
		void (*BlitRectNoMaskComplete)(struct BoardInfo *, struct RenderInfo *, struct RenderInfo *, WORD, WORD, WORD, WORD, WORD, WORD, UBYTE, RGBFTYPE);
		void (*BlitRectNoMaskCompleteDefault)(struct BoardInfo *, struct RenderInfo *, struct RenderInfo *, WORD, WORD, WORD, WORD, WORD, WORD, UBYTE, RGBFTYPE);
		void (*BlitPlanar2Direct)(struct BoardInfo *, struct BitMap *, struct RenderInfo *, struct ColorIndexMapping *, SHORT, SHORT, SHORT, SHORT, SHORT, SHORT, UBYTE, UBYTE);
		void (*BlitPlanar2DirectDefault)(struct BoardInfo *, struct BitMap *, struct RenderInfo *, struct ColorIndexMapping *, SHORT, SHORT, SHORT, SHORT, SHORT, SHORT, UBYTE, UBYTE);
		BOOL (*EnableSoftSprite)(struct BoardInfo *, ULONG formatflags, struct ModeInfo *);
		BOOL (*EnableSoftSpriteDefault)(struct BoardInfo *, ULONG formatflags, struct ModeInfo *);
		APTR (*AllocCardMemAbs)(struct BoardInfo *, ULONG size, char *target);
		void (*SetSplitPosition)(struct BoardInfo *, SHORT);
		void (*ReInitMemory)(struct BoardInfo *, RGBFTYPE);
		void (*Reserved2Default)(struct BoardInfo *);
		void (*Reserved3)(struct BoardInfo *);
		void (*Reserved3Default)(struct BoardInfo *);
		int (*WriteYUVRect)(struct BoardInfo *, APTR, SHORT, SHORT, struct RenderInfo *, SHORT, SHORT, SHORT, SHORT, struct TagItem *);
		int (*WriteYUVRectDefault)(struct BoardInfo *, APTR, SHORT, SHORT, struct RenderInfo *, SHORT, SHORT, SHORT, SHORT, struct TagItem *);
		BOOL (*GetVSyncState)(struct BoardInfo *, BOOL);
		ULONG (*GetVBeamPos)(struct BoardInfo *);
		void (*SetDPMSLevel)(struct BoardInfo *, ULONG);
		void (*ResetChip)(struct BoardInfo *);
		ULONG (*GetFeatureAttrs)(struct BoardInfo *, APTR, ULONG, struct TagItem *);
		struct BitMap * (*AllocBitMap)(struct BoardInfo *, ULONG, ULONG, struct TagItem *);
		BOOL (*FreeBitMap)(struct BoardInfo *, struct BitMap *, struct TagItem *);
		ULONG (*GetBitMapAttr)(struct BoardInfo *, struct BitMap *, ULONG);
		BOOL (*SetSprite)(struct BoardInfo *, BOOL, RGBFTYPE);
		void (*SetSpritePosition)(struct BoardInfo *, WORD, WORD, RGBFTYPE);
		void (*SetSpriteImage)(struct BoardInfo *, RGBFTYPE);
		void (*SetSpriteColor)(struct BoardInfo *, UBYTE, UBYTE, UBYTE, UBYTE, RGBFTYPE);
		APTR (*CreateFeature)(struct BoardInfo *, ULONG, struct TagItem *);
		ULONG (*SetFeatureAttrs)(struct BoardInfo *, APTR, ULONG, struct TagItem *);
		BOOL (*DeleteFeature)(struct BoardInfo *, APTR, ULONG);
		struct MinList  SpecialFeatures;
		struct ModeInfo  *ModeInfo;  /* Chip Settings Stuff */
		RGBFTYPE  RGBFormat;
		WORD  XOffset;
		WORD  YOffset;
		UBYTE  Depth;
		UBYTE  ClearMask;
		BOOL  Border;
		ULONG  Mask;
		struct CLUTEntry  CLUT[256];
		struct ViewPort  *ViewPort;  /* ViewPort Stuff */
		struct BitMap  *VisibleBitMap;
		struct BitMapExtra  *BitMapExtra;
		struct MinList  BitMapList;
		struct MinList  MemList;
		WORD  MouseX;
		WORD  MouseY;  /* Sprite Stuff */
		UBYTE  MouseWidth;
		UBYTE  MouseHeight;
		UBYTE  MouseXOffset;
		UBYTE  MouseYOffset;
		UWORD  *MouseImage;
		UBYTE  MousePens[4];
		struct Rectangle  MouseRect;
		UBYTE  *MouseChunky;
		UWORD  *MouseRendered;
		UBYTE  *MouseSaveBuffer;
		ULONG  ChipData[16];  /* for chip driver needs */
		ULONG  CardData[16];  /* for card driver needs */
		APTR  MemorySpaceBase;  /* the base address of the board memory address space */
		ULONG  MemorySpaceSize;  /* size of that area */
		APTR  DoubleBufferList;  /* chain of dbinfos being notified on vblanks */
		struct timeval  SyncTime;  /* system time when screen was set up,  used for pseudo vblanks */
		ULONG  SyncPeriod;  /* length of one frame in micros */
		struct MsgPort  SoftVBlankPort;  /* MsgPort for software emulation of board interrupt */
		struct MinList  WaitQ;   /* for WaitTOF and WaitBOVP,  all elements will be signaled on VBlank */
		LONG  EssentialFormats;  /* these RGBFormats will be used when user does not choose "all"
		     will be filled by InitBoard() */
		UBYTE  *MouseImageBuffer;  /* rendered to the destination color format */
		/* Additional viewport stuff */
		struct ViewPort  *backViewPort; /* The view port visible on the screen behind */
		struct BitMap  *backBitMap; /* Its bitmap */
		struct BitMapExtra  *backExtra; /* its bitmapExtra */
		WORD  YSplit;
		ULONG  MaxPlanarMemory; /* Size of a bitplane if planar. If left blank,  MemorySize>>2 */
		ULONG  MaxBMWidth; /* Maximum width of a bitmap */
		ULONG  MaxBMHeight; /* Maximum height of a bitmap */
		struct CLUTEntry  SecondaryCLUT[256]; /* Switched to for lower/front screen */
};

/* BoardInfo flags */
/* 0-15: hardware flags */
/* 16-31: user flags */
#define BIB_HARDWARESPRITE 0 /* board has hardware sprite */
#define BIB_NOMEMORYMODEMIX 1 /* board does not support modifying planar bitmaps while displaying chunky and vice versa */
#define BIB_NEEDSALIGNMENT 2 /* bitmaps have to be aligned (not yet supported!) */
#define BIB_CACHEMODECHANGE 3 /* board memory may be set to Imprecise (060) or Nonserialised (040) */
#define BIB_VBLANKINTERRUPT 4 /* board can cause a hardware interrupt on a vertical retrace */
#define BIB_HASSPRITEBUFFER 5 /* board has allocated memory for software sprite image and save buffer */

#define BIB_VGASCREENSPLIT 6 /* has a screen B with fixed screen position for split-screens */
#define BIB_DBLCLOCKHALFSPRITEX 7 /* horizontal sprite position halfed for double clock modes */
#define BIB_DBLSCANDBLSPRITEY 8 /* hardware sprite y position is doubled on doublescan display modes */
#define BIB_ILACEHALFSPRITEY 9 /* hardware sprite y position is halved on interlace display modes */
#define BIB_ILACEDBLROWOFFSET 10 /* doubled row offset in interlaced display modes needs additional horizontal bit */
#define BIB_INTERNALMODESONLY 11 /* board creates its resolutions and modes automatically and does not support user setting files (UAE) */
#define BIB_FLICKERFIXER 12 /* board can flicker fix Amiga RGB signal */
#define BIB_VIDEOCAPTURE 13 /* board can capture video data to a memory area */
#define BIB_VIDEOWINDOW 14 /* board can display a second mem area as a pip */
#define BIB_BLITTER 15 /* board has blitter */

#define BIB_HIRESSPRITE 16 /* mouse sprite has double resolution */
#define BIB_BIGSPRITE 17 /* user wants big mouse sprite */
#define BIB_BORDEROVERRIDE 18 /* user wants to override system overscan border prefs */
#define BIB_BORDERBLANK 19 /* user wants border blanking */
#define BIB_INDISPLAYCHAIN 20 /* board switches Amiga signal */
#define BIB_QUIET 21 /* not yet implemented */
#define BIB_NOMASKBLITS 22 /* perform blits without taking care of mask */
#define BIB_NOP2CBLITS 23 /* use CPU for planar to chunky conversions */
#define BIB_NOBLITTER 24 /* disable all blitter functions */
#define BIB_SYSTEM2SCREENBLITS 25 /* allow data to be written to screen memory for cpu as blitter source */
#define BIB_GRANTDIRECTACCESS 26 /* all data on the board can be accessed at any time without bi->SetMemoryMode() */
#define BIB_PALETTESWITCH 27 /* board provides secondary palette for screen panning */
#define BIB_OVERCLOCK 31 /* enable overclocking for some boards */

#define BIB_IGNOREMASK BIB_NOMASKBLITS

#define BIF_HARDWARESPRITE (1<<BIB_HARDWARESPRITE)
#define BIF_NOMEMORYMODEMIX (1<<BIB_NOMEMORYMODEMIX)
#define BIF_NEEDSALIGNMENT (1<<BIB_NEEDSALIGNMENT)
#define BIF_CACHEMODECHANGE (1<<BIB_CACHEMODECHANGE)
#define BIF_VBLANKINTERRUPT (1<<BIB_VBLANKINTERRUPT)
#define BIF_HASSPRITEBUFFER (1<<BIB_HASSPRITEBUFFER)
#define BIF_VGASCREENSPLIT (1<<BIB_VGASCREENSPLIT)
#define BIF_DBLCLOCKHALFSPRITEX (1<<BIB_DBLCLOCKHALFSPRITEX)
#define BIF_DBLSCANDBLSPRITEY (1<<BIB_DBLSCANDBLSPRITEY)
#define BIF_ILACEHALFSPRITEY (1<<BIB_ILACEHALFSPRITEY)
#define BIF_ILACEDBLROWOFFSET (1<<BIB_ILACEDBLROWOFFSET)
#define BIF_INTERNALMODESONLY (1<<BIB_INTERNALMODESONLY)
#define BIF_FLICKERFIXER (1<<BIB_FLICKERFIXER)
#define BIF_VIDEOCAPTURE (1<<BIB_VIDEOCAPTURE)
#define BIF_VIDEOWINDOW (1<<BIB_VIDEOWINDOW)
#define BIF_BLITTER (1<<BIB_BLITTER)
#define BIF_HIRESSPRITE (1<<BIB_HIRESSPRITE)
#define BIF_BIGSPRITE (1<<BIB_BIGSPRITE)
#define BIF_BORDEROVERRIDE (1<<BIB_BORDEROVERRIDE)
#define BIF_BORDERBLANK (1<<BIB_BORDERBLANK)
#define BIF_INDISPLAYCHAIN (1<<BIB_INDISPLAYCHAIN)
#define BIF_QUIET (1<<BIB_QUIET)
#define BIF_NOMASKBLITS (1<<BIB_NOMASKBLITS)
#define BIF_NOP2CBLITS (1<<BIB_NOP2CBLITS)
#define BIF_NOBLITTER (1<<BIB_NOBLITTER)
#define BIF_SYSTEM2SCREENBLITS (1<<BIB_SYSTEM2SCREENBLITS)
#define BIF_GRANTDIRECTACCESS (1<<BIB_GRANTDIRECTACCESS)
#define BIF_PALETTESWITCH (1<<BIB_PALETTESWITCH)
#define BIF_OVERCLOCK (1<<BIB_OVERCLOCK)

#define BIF_IGNOREMASK BIF_NOMASKBLITS

/* write errors,  continued for historical reasons... :-) */
#define BIB_NOC2PBLITS BIB_NOP2CBLITS
#define BIF_NOC2PBLITS BIF_NOP2CBLITS

/************************************************************************/

struct CardBase {
 struct Library LibBase;
 UBYTE  Flags;
 UBYTE  pad;

 struct ExecBase *ExecBase;
 struct Library *ExpansionBase;

 APTR  SegList;
 char  *Name;
};

struct ChipBase {
 struct Library LibBase;
 UBYTE  Flags;
 UBYTE  pad;

 struct ExecBase *ExecBase;

 APTR  SegList;
};

/************************************************************************/
/* private Tags */
#define P96BD_BoardType  (P96BD_Dummy+0x101)
#define P96BD_ChipType  (P96BD_Dummy+0x102)
#define P96BD_DACType  (P96BD_Dummy+0x103)
#define P96BD_CurrentScreenBitMap (P96BD_Dummy+0x104)


#ifdef __GNUC__
 #ifdef __PPC__
 #pragma pack()
 #endif
#elif defined(__VBCC__)
 #pragma default-align
#endif

#endif

