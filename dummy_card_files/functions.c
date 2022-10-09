
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include <proto/exec.h>
#include <proto/dos.h>
#include <exec/types.h>

#define OLD_TYPEDEFS

#include <libraries/Picasso96.h>
#include <libraries/dummy_card.h>
#include <libraries/maybe_boardinfo.h>

#include "functions.h"

APTR  _AllocCardMem_( struct BoardInfo *bi, ULONG size, BOOL force, BOOL system)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return malloc( size );
}

BOOL  _FreeCardMem_( struct BoardInfo *bi, APTR membase)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	free( membase );
	return TRUE;
}

BOOL  _SetSwitch_( struct BoardInfo *bi, BOOL enable)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return FALSE;
}

void  _SetColorArray_( struct BoardInfo *bi,UWORD startIndex, UWORD count)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _SetDAC_( struct BoardInfo *bi, RGBFTYPE rgbtype)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _SetGC_( struct BoardInfo *bi, struct ModeInfo *mi, BOOL border)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _SetPanning_( struct BoardInfo *bi,UBYTE *Memory, UWORD Width, WORD Height, WORD XOffset, WORD YOffset, RGBFTYPE rgbtype)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

UWORD  _CalculateBytesPerRow_( struct BoardInfo *bi,UWORD width, UWORD height, RGBFTYPE rgbtype)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return 20;
}

APTR  _CalculateMemory_( struct BoardInfo *bi,APTR mem,  RGBFTYPE rgbtype)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return mem;
}

ULONG  _GetCompatibleFormats_( struct BoardInfo *bi, RGBFTYPE rgbtype)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return 1<<0 | 1<<0;		// return mask of formats
}

BOOL  _SetDisplay_( struct BoardInfo *bi, BOOL state)	// enable / disable video output
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return FALSE;		// doc says no output. hemm...
}

LONG  _ResolvePixelClock_( struct BoardInfo *bi, struct ModeInfo *mi, ULONG pixelClock, RGBFTYPE rgbtype)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return 0;
}

ULONG  _GetPixelClock_( struct BoardInfo *bi, struct ModeInfo *mi,ULONG index, RGBFTYPE rgbtype)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return 0;
}

void  _SetClock_( struct BoardInfo *bi)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _SetMemoryMode_( struct BoardInfo *bi, RGBFTYPE rgbtype)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _SetWriteMask_( struct BoardInfo *bi,UBYTE mask)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _SetClearMask_( struct BoardInfo *bi,UBYTE mask)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _SetReadPlane_( struct BoardInfo *bi,UBYTE plane)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _WaitVerticalSync_( struct BoardInfo *bi, BOOL enable)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

BOOL  _SetInterrupt_( struct BoardInfo *bi, BOOL enable)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return FALSE;
}

void  _WaitBlitter_( struct BoardInfo *bi)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _ScrollPlanar_( struct BoardInfo *bi,struct RenderInfo *ri, UWORD a, UWORD b, UWORD c , UWORD d, UWORD e, UWORD f, UBYTE g)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _ScrollPlanarDefault_( struct BoardInfo *bi,struct RenderInfo *ri, UWORD a, UWORD b, UWORD c, UWORD d, UWORD e, UWORD f, UBYTE g)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _UpdatePlanar_( struct BoardInfo *bi,struct BitMap *bm, struct RenderInfo *ri, SHORT a, SHORT b, SHORT c, SHORT d, UBYTE e)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _UpdatePlanarDefault_( struct BoardInfo *bi,struct BitMap *bm, struct RenderInfo *ri, SHORT a, SHORT b, SHORT c, SHORT d, UBYTE e)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _BlitPlanar2Chunky_( struct BoardInfo *bi,struct BitMap *bm, struct RenderInfo *ri, SHORT a, SHORT b, SHORT c, SHORT d, SHORT e, SHORT f, UBYTE g, UBYTE h)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _BlitPlanar2ChunkyDefault_( struct BoardInfo *bi,struct BitMap *bm, struct RenderInfo *ri, SHORT a, SHORT b, SHORT c, SHORT d, SHORT e, SHORT f, UBYTE g, UBYTE h)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _FillRect_( struct BoardInfo *bi,struct RenderInfo *ri, WORD x, WORD y, WORD w, WORD h, ULONG pen, UBYTE mask, RGBFTYPE rgbtype)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _FillRectDefault_( struct BoardInfo *bi,struct RenderInfo *ri, WORD x, WORD y, WORD w, WORD h, ULONG pen, UBYTE mask, RGBFTYPE rgbtype)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _InvertRect_( struct BoardInfo *bi,struct RenderInfo *ri, WORD x, WORD y, WORD w, WORD h, UBYTE mask, RGBFTYPE rgbtype)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _InvertRectDefault_( struct BoardInfo *bi,struct RenderInfo *ri, WORD x, WORD y, WORD w, WORD h, UBYTE mask, RGBFTYPE rgbtype)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _BlitRect_( struct BoardInfo *bi,struct RenderInfo *ri, WORD srcx, WORD srcy, WORD desx, WORD dexy, WORD w, WORD h, UBYTE mask, RGBFTYPE rgbtype)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _BlitRectDefault_( struct BoardInfo *bi,struct RenderInfo *ri, WORD srcx, WORD srcy, WORD desx, WORD desy, WORD w, WORD h, UBYTE mask, RGBFTYPE rgbtype)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _BlitTemplate_( struct BoardInfo *bi,struct RenderInfo *ri, struct Template *t, WORD x, WORD y, WORD w, WORD h, UBYTE mask, RGBFTYPE rgbtype)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _BlitTemplateDefault_( struct BoardInfo *bi,struct RenderInfo *ri, struct Template *t, WORD x, WORD y, WORD w, WORD h, UBYTE mask, RGBFTYPE rgbtype)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _BlitPattern_( struct BoardInfo *bi,struct RenderInfo *ri, struct Pattern *p, WORD x, WORD y, WORD w, WORD h, UBYTE mask, RGBFTYPE rgbtype)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _BlitPatternDefault_( struct BoardInfo *bi,struct RenderInfo *ri, struct Pattern *p, WORD x, WORD y, WORD w, WORD h, UBYTE mask, RGBFTYPE rgbtype)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _DrawLine_( struct BoardInfo *bi,struct RenderInfo *ri, struct Line *l, UBYTE mask, RGBFTYPE rgbtype)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _DrawLineDefault_( struct BoardInfo *bi,struct RenderInfo *ri, struct Line *l, UBYTE mask, RGBFTYPE rgbtype)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _BlitRectNoMaskComplete_( struct BoardInfo *bi,struct RenderInfo *s_ri, struct RenderInfo *d_ri, WORD srcx, WORD srcy, WORD desx, WORD desy, WORD w, WORD h, UBYTE OpCode, RGBFTYPE rgbtype)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _BlitRectNoMaskCompleteDefault_( struct BoardInfo *bi,struct RenderInfo *s_ri, struct RenderInfo *d_ri, WORD srcx, WORD srcy, WORD desx, WORD desy, WORD w, WORD h, UBYTE OpCode, RGBFTYPE rgbtype)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _BlitPlanar2Direct_( struct BoardInfo *bi,struct BitMap *bm, struct RenderInfo *ri, struct ColorIndexMapping *cim, SHORT a, SHORT b, SHORT c, SHORT d, SHORT e, SHORT f, UBYTE g, UBYTE h)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _BlitPlanar2DirectDefault_( struct BoardInfo *bi,struct BitMap *bm, struct RenderInfo *ri, struct ColorIndexMapping *cim, SHORT a, SHORT b, SHORT c, SHORT d, SHORT e, SHORT f, UBYTE g, UBYTE h)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

BOOL  _EnableSoftSprite_( struct BoardInfo *bi,ULONG formatflags,  struct ModeInfo *mi)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return FALSE;
}

BOOL  _EnableSoftSpriteDefault_( struct BoardInfo *bi,ULONG formatflags, struct ModeInfo *mi)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return FALSE;
}

APTR  _AllocCardMemAbs_( struct BoardInfo *bi,ULONG size, char *target)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return NULL;
}

void  _SetSplitPosition_( struct BoardInfo *bi,SHORT y)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _ReInitMemory_( struct BoardInfo *bi, RGBFTYPE rgbtype)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _Reserved2Default_( struct BoardInfo *bi)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _Reserved3_( struct BoardInfo *bi)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _Reserved3Default_( struct BoardInfo *bi)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

int  _WriteYUVRect_( struct BoardInfo *bi,APTR ptr, SHORT x, SHORT y, struct RenderInfo *ri, SHORT dx, SHORT dy, SHORT w, SHORT h, struct TagItem *tagList)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return 0;
}

int  _WriteYUVRectDefault_( struct BoardInfo *bi,APTR ptr, SHORT x, SHORT y, struct RenderInfo *ri, SHORT dx, SHORT dy, SHORT w, SHORT h, struct TagItem *tagList)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return 0;
}

BOOL  _GetVSyncState_( struct BoardInfo *bi, BOOL enable)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return FALSE;
}

ULONG  _GetVBeamPos_( struct BoardInfo *bi)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return 0;
}

void  _SetDPMSLevel_( struct BoardInfo *bi,ULONG dpmslevel)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _ResetChip_( struct BoardInfo *bi)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

ULONG  _GetFeatureAttrs_( struct BoardInfo *bi,APTR ULONG, struct TagItem *tagList)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return 0;
}

struct BitMap *  _AllocBitMap_( struct BoardInfo *bi,ULONG w, ULONG h, struct TagItem *tagList)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return NULL;
}

BOOL  _FreeBitMap_( struct BoardInfo *bi,struct BitMap *bm, struct TagItem *tagList)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return FALSE;
}

ULONG  _GetBitMapAttr_( struct BoardInfo *bi,struct BitMap *bm, ULONG attr)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

BOOL  _SetSprite_( struct BoardInfo *bi, BOOL enable, RGBFTYPE rgbtype)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return FALSE;
}

void  _SetSpritePosition_( struct BoardInfo *bi, WORD x, WORD y,  RGBFTYPE rgbtype)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void  _SetSpriteImage_( struct BoardInfo *bi, RGBFTYPE rgbtype)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _SetSpriteColor_( struct BoardInfo *bi,UBYTE index, UBYTE red, UBYTE green, UBYTE blue, RGBFTYPE rgbtype)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

APTR  _CreateFeature_( struct BoardInfo *bi,ULONG type, struct TagItem *tagList)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return NULL;
}

ULONG  _SetFeatureAttrs_( struct BoardInfo *bi,APTR ptr, ULONG type, struct TagItem *tagList)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return 0;
}

BOOL  _DeleteFeature_( struct BoardInfo *bi,APTR ptr, ULONG type)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return FALSE;
}
