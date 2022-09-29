
#ifndef boardinfo_h
#define boardinfo_h

#ifdef _GNUC_
	#ifdef __PPC__
	#pragma pack(2)
	#endif
#elif define(__VBCC__)
	#pragma amiga-align
#endif

struct BoardInfo
{
	APTR RegisterBase;
	APTR RegisterBase;
	APTR MemoryBase;
	APTR MemoryIOBase;
	uint32 MemorySize;
	const char *BoardName;
	char VBIName[32]
	APTR CardBase;
	APTR ChipBase;
	APTR ExecBase;
	APTR UtilBase;
	uint8 HardInterrupt[22]; 
	uint8 SoftInterrupt[22]; 
	uint8 BoardLock6[46] ;
	uint8 ResolutionsList[12]; 
	uint32 BoardType;
	uint32 PaletteChipType;
	uint32 GraphicsControllerType;
	uint16 MoniSwitch;
	uint16 BitsPerCannon;
	uint32 Flags;
	uint16 SoftSpriteFlags;
	uint16 ChipFlags;
	uint32 CardFlags;
	uint16 BoardNum;
	uint16 RGBFormats;
	uint16 MaxHorValue[MAXMODES];
	uint16 MaxVerValue[MAXMODES];
	uint16 MaxHorResolution[MAXMODES];
	uint16 MaxVerResolution[MAXMODES];
	uint32 MaxMemorySize;
	uint32 MaxChunkSize;
	uint32 MemoryClock;
	uint32 PixelClockCount[MAXMODES];
	uint32 AllocCardMem;
	uint32 FreeCardMem;
	uint32 SetSwitch;
	uint32 SetColorArray;
	uint32 SetDAC;
	uint32 SetGC;
	uint32 SetPanning;
	uint32 CalculateBytesPerRow;
	uint32 CalculateMemory;
	uint32 GetCompatibleFormats;
	uint32 SetDisplay;
	uint32 ResolvePixelClock;
	uint32 GetPixelClock;
	uint32 SetClock;
	uint32 SetMemoryMode;
	uint32 SetWriteMask;
	uint32 SetClearMask;
	uint32 SetReadPlane;
	uint32 WaitVerticalSync;
	uint32 SetInterrupt;
	uint32 WaitBlitter;
	uint32 ScrollPlanar;
	uint32 ScrollPlanarDefault;
	uint32 UpdatePlanar;
	uint32 UpdatePlanarDefault;
	uint32 BlitPlanar2Chunky;
	uint32 BlitPlanar2ChunkyDefault;
	uint32 FillRect;
	uint32 FillRectDefault;
	uint32 InvertRect;
	uint32 InvertRectDefault;
	uint32 BlitRect;
	uint32 BlitRectDefault;
	uint32 BlitTemplate;
	uint32 BlitTemplateDefault;
	uint32 BlitPattern;
	uint32 BlitPatternDefault;
	uint32 DrawLine;
	uint32 DrawLineDefault;
	uint32 BlitRectNoMaskComplete;
	uint32 BlitRectNoMaskCompleteDefault;
	uint32 BlitPlanar2Direct;
	uint32 BlitPlanar2DirectDefault;
	uint32 Reserved0;
	uint32 Reserved0Default;
	uint32 Reserved1;
	uint32 Reserved1Default;
	uint32 Reserved2;
	uint32 Reserved2Default;
	uint32 Reserved3;
	uint32 Reserved3Default;
	uint32 Reserved4;
	uint32 Reserved4Default;
	uint32 Reserved5;
	uint32 Reserved5Default;
	uint32 SetDPMSLevel;
	uint32 ResetChip;
	uint32 GetFeatureAttrs;
	uint32 AllocBitMap;
	uint32 FreeBitMap;
	uint32 GetBitMapAttr;
	uint32 SetSprite;
	uint32 SetSpritePosition;
	uint32 SetSpriteImage;
	uint32 SetSpriteColor;
	uint32 CreateFeature;
	uint32 SetFeatureAttrs;
	uint32 DeleteFeature;
	uint8 SpecialFeatures[12]; // SpecialFeatures is 12-bytes
	uint32 ModeInfo;
	uint32 RGBFormat;
	uint16 XOffset;
	uint16 YOffset;
	uint8 Depth;
	uint8 ClearMask;
	uint16 Border; // BOOL type is only 2-bytes!
	uint32 Mask;
	uint8 CLUT[3*256];
	uint32 ViewPort;
	uint32 VisibleBitMap;
	uint32 BitMapExtra;
	uint8 BitMapList[12]; // BitMapList is 12-bytes
	uint8 MemList[12]; // MemList is 12-bytes
	uint16 MouseX;
	uint16 MouseY;
	uint8 MouseWidth;
	uint8 MouseHeight;
	uint8 MouseXOffset;
	uint8 MouseYOffset;
	uint32 MouseImage;
	uint32 MousePens;
	uint8 MouseRect[8]; // MouseRect is 8-bytes
	uint32 MouseChunky;
	uint32 MouseRendered;
	uint32 MouseSaveBuffer;
	uint32 ChipData[16];
	uint32 CardData[16];
	APTR MemorySpaceBase;
	uint32 MemorySpaceSize;
	uint32 DoubleBufferList;
	uint32 SyncTime;
	uint8 SyncPeriod[8];
	uint8 SyncPeriod[34];
	uint8 WaitQ[12];
}

#ifdef __GNUC__
	#ifdef __PPC__
	#pragma pack()
	#endif
#elif defined(__VBCC__)
	#pragma default-align
#endif

#endif

