
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include <proto/exec.h>
#include <proto/dos.h>

APTR  _AllocCardMem_( struct BoardInfo *bi, ULONG size, BOOL force, BOOL system);
{

}

BOOL  _FreeCardMem_( (struct BoardInfo *bi), (APTR membase));
{

}

BOOL  _SetSwitch_( struct BoardInfo *bi, BOOL enable);
{

}

void  _SetColorArray_( struct BoardInfo *bi, (UWORD), (UWORD));
{

}

void  _SetDAC_( struct BoardInfo *bi, RGBFTYPE rgbtype);
{

}

void  _SetGC_( struct BoardInfo *bi, struct ModeInfo *mi, BOOL enable);
{

}

void  _SetPanning_( struct BoardInfo *bi, (UBYTE *), (UWORD), (WORD), (WORD), RGBFTYPE rgbtype);
{

}

UWORD  _CalculateBytesPerRow_( struct BoardInfo *bi, (UWORD), RGBFTYPE rgbtype);
{

}

APTR  _CalculateMemory_( struct BoardInfo *bi, (APTR), RGBFTYPE rgbtype);
{

}

ULONG  _GetCompatibleFormats_( struct BoardInfo *bi, RGBFTYPE rgbtype);
{

}

BOOL  _SetDisplay_( struct BoardInfo *bi, BOOL enable);
{

}

LONG  _ResolvePixelClock_( struct BoardInfo *bi, struct ModeInfo *mi, (ULONG), RGBFTYPE rgbtype);
{

}

ULONG  _GetPixelClock_( (struct BoardInfo *bi), struct ModeInfo *mi, (ULONG), RGBFTYPE rgbtype);
{

}

void  _SetClock_( struct BoardInfo *bi);
{

}

void  _SetMemoryMode_( struct BoardInfo *bi, RGBFTYPE rgbtype);
{

}

void  _SetWriteMask_( struct BoardInfo *bi, (UBYTE));
{

}

void  _SetClearMask_( struct BoardInfo *bi, (UBYTE));
{

}

void  _SetReadPlane_( struct BoardInfo *bi, (UBYTE));
{

}

void  _WaitVerticalSync_( struct BoardInfo *bi, BOOL enable);
{

}

BOOL  _SetInterrupt_( struct BoardInfo *bi, BOOL enable);
{

}

void  _WaitBlitter_( struct BoardInfo *bi);
{

}

void  _ScrollPlanar_( struct BoardInfo *bi, (struct RenderInfo *), (UWORD), (UWORD), (UWORD), (UWORD), (UWORD), (UWORD), (UBYTE));
{

}

void  _ScrollPlanarDefault_( struct BoardInfo *bi, (struct RenderInfo *), (UWORD), (UWORD), (UWORD), (UWORD), (UWORD), (UWORD), (UBYTE));
{

}

void  _UpdatePlanar_( struct BoardInfo *bi, (struct BitMap *), (struct RenderInfo *), (SHORT), (SHORT), (SHORT), (SHORT), (UBYTE));
{

}

void  _UpdatePlanarDefault_( struct BoardInfo *bi, (struct BitMap *), (struct RenderInfo *), (SHORT), (SHORT), (SHORT), (SHORT), (UBYTE));
{

}

void  _BlitPlanar2Chunky_( struct BoardInfo *bi, (struct BitMap *), (struct RenderInfo *), (SHORT), (SHORT), (SHORT), (SHORT), (SHORT), (SHORT), (UBYTE), (UBYTE));
{

}

void  _BlitPlanar2ChunkyDefault_( struct BoardInfo *bi, (struct BitMap *), (struct RenderInfo *), (SHORT), (SHORT), (SHORT), (SHORT), (SHORT), (SHORT), (UBYTE), (UBYTE));
{

}

void  _FillRect_( struct BoardInfo *bi, (struct RenderInfo *), (WORD), (WORD), (WORD), (WORD), (ULONG), (UBYTE), RGBFTYPE rgbtype);
{

}

void  _FillRectDefault_( struct BoardInfo *bi, (struct RenderInfo *), (WORD), (WORD), (WORD), (WORD), (ULONG), (UBYTE), RGBFTYPE rgbtype);
{

}

void  _InvertRect_( struct BoardInfo *bi, (struct RenderInfo *), (WORD), (WORD), (WORD), (WORD), (UBYTE), RGBFTYPE rgbtype);
{

}

void  _InvertRectDefault_( struct BoardInfo *bi, (struct RenderInfo *), (WORD), (WORD), (WORD), (WORD), (UBYTE), RGBFTYPE rgbtype);
{

}

void  _BlitRect_( struct BoardInfo *bi, (struct RenderInfo *), (WORD), (WORD), (WORD), (WORD), (WORD), (WORD), (UBYTE), RGBFTYPE rgbtype);
{

}

void  _BlitRectDefault_( struct BoardInfo *bi, (struct RenderInfo *), (WORD), (WORD), (WORD), (WORD), (WORD), (WORD), (UBYTE), RGBFTYPE rgbtype);
{

}

void  _BlitTemplate_( struct BoardInfo *bi, (struct RenderInfo *), (struct Template *), (WORD), (WORD), (WORD), (WORD), (UBYTE), RGBFTYPE rgbtype);
{

}

void  _BlitTemplateDefault_( struct BoardInfo *bi, (struct RenderInfo *), (struct Template *), (WORD), (WORD), (WORD), (WORD), (UBYTE), RGBFTYPE rgbtype);
{

}

void  _BlitPattern_( struct BoardInfo *bi, (struct RenderInfo *), (struct Pattern *), (WORD), (WORD), (WORD), (WORD), (UBYTE), RGBFTYPE rgbtype);
{

}

void  _BlitPatternDefault_( struct BoardInfo *bi, (struct RenderInfo *), (struct Pattern *), (WORD), (WORD), (WORD), (WORD), (UBYTE), RGBFTYPE rgbtype);
{

}

void  _DrawLine_( struct BoardInfo *bi, (struct RenderInfo *), (struct Line *), (UBYTE), RGBFTYPE rgbtype);
{

}

void  _DrawLineDefault_( struct BoardInfo *bi, (struct RenderInfo *), (struct Line *), (UBYTE), RGBFTYPE rgbtype);
{

}

void  _BlitRectNoMaskComplete_( struct BoardInfo *bi, (struct RenderInfo *), (struct RenderInfo *), (WORD), (WORD), (WORD), (WORD), (WORD), (WORD), (UBYTE), RGBFTYPE rgbtype);
{

}

void  _BlitRectNoMaskCompleteDefault_( struct BoardInfo *bi, (struct RenderInfo *), (struct RenderInfo *), (WORD), (WORD), (WORD), (WORD), (WORD), (WORD), (UBYTE), RGBFTYPE rgbtype);
{

}

void  _BlitPlanar2Direct_( struct BoardInfo *bi, (struct BitMap *), (struct RenderInfo *), __REGA3(struct ColorIndexMapping *), (SHORT), (SHORT), (SHORT), (SHORT), (SHORT), (SHORT), (UBYTE), (UBYTE));
{

}

void  _BlitPlanar2DirectDefault_( struct BoardInfo *bi, (struct BitMap *), (struct RenderInfo *), __REGA3(struct ColorIndexMapping *), (SHORT), (SHORT), (SHORT), (SHORT), (SHORT), (SHORT), (UBYTE), (UBYTE));
{

}

BOOL  _EnableSoftSprite_( struct BoardInfo *bi, (ULONG formatflags), struct ModeInfo *mi);
{

}

BOOL  _EnableSoftSpriteDefault_( struct BoardInfo *bi, (ULONG formatflags), struct ModeInfo *mi);
{

}

APTR  _AllocCardMemAbs_( struct BoardInfo *bi, (ULONG size), (char *target));
{

}

void  _SetSplitPosition_( struct BoardInfo *bi, (SHORT));
{

}

void  _ReInitMemory_( struct BoardInfo *bi, RGBFTYPE rgbtype);
{

}

void  _Reserved2Default_( struct BoardInfo *bi);
{

}

void  _Reserved3_( struct BoardInfo *bi);
{

}

void  _Reserved3Default_( struct BoardInfo *bi);
{

}

int  _WriteYUVRect_( struct BoardInfo *bi, (APTR), (SHORT), (SHORT), (struct RenderInfo *), (SHORT), (SHORT), (SHORT), (SHORT), __REGA3(struct TagItem *));
{

}

int  _WriteYUVRectDefault_( struct BoardInfo *bi, (APTR), (SHORT), (SHORT), (struct RenderInfo *), (SHORT), (SHORT), (SHORT), (SHORT), __REGA3(struct TagItem *));
{

}

BOOL  _GetVSyncState_( struct BoardInfo *bi, BOOL enable);
{

}

ULONG  _GetVBeamPos_( struct BoardInfo *bi);
{

}

void  _SetDPMSLevel_( struct BoardInfo *bi, (ULONG));
{

}

void  _ResetChip_( struct BoardInfo *bi);
{

}

ULONG  _GetFeatureAttrs_( struct BoardInfo *bi, (APTR), (ULONG), (struct TagItem *));
{

}

struct BitMap *  _AllocBitMap_( struct BoardInfo *bi, (ULONG), (ULONG), (struct TagItem *));
{

}

BOOL  _FreeBitMap_( struct BoardInfo *bi, (struct BitMap *), (struct TagItem *));
{

}

ULONG  _GetBitMapAttr_( struct BoardInfo *bi, (struct BitMap *), (ULONG));
{

}

BOOL  _SetSprite_( struct BoardInfo *bi, BOOL enable, RGBFTYPE rgbtype);
{

}

void  _SetSpritePosition_( struct BoardInfo *bi, (WORD), (WORD), RGBFTYPE rgbtype);
{

}

void  _SetSpriteImage_( struct BoardInfo *bi, RGBFTYPE rgbtype);
{

}

void  _SetSpriteColor_( struct BoardInfo *bi, (UBYTE), (UBYTE), (UBYTE), (UBYTE), RGBFTYPE rgbtype);
{

}

APTR  _CreateFeature_( struct BoardInfo *bi, (ULONG), (struct TagItem *));
{

}

ULONG  _SetFeatureAttrs_( struct BoardInfo *bi, (APTR), (ULONG), (struct TagItem *));
{

}

BOOL  _DeleteFeature_( struct BoardInfo *bi, (APTR), (ULONG));
{

}
