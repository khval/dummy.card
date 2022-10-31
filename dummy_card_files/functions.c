
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

#define CLOCK_HZ 1000000000

#define dprintf IExec->DebugPrintF


APTR  _AllocCardMem_( struct BoardInfo *bi, ULONG size, BOOL force, BOOL system)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return malloc( size );
}

BOOL  _FreeCardMem_( struct BoardInfo *bi, APTR membase)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	free( membase );
	return TRUE;
}

BOOL  _SetSwitch_( struct BoardInfo *bi, BOOL enable)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return FALSE;
}

void  _SetColorArray_( struct BoardInfo *bi,UWORD startIndex, UWORD count)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	dprintf("start index: %d, count %d\n",startIndex, count);
}

void  _SetDAC_( struct BoardInfo *bi, RGBFTYPE rgbtype)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _SetGC_( struct BoardInfo *bi, struct ModeInfo *mi, BOOL border)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _SetPanning_( struct BoardInfo *bi,UBYTE *Memory, UWORD Width, WORD Height, WORD XOffset, WORD YOffset, RGBFTYPE rgbtype)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

UWORD  _CalculateBytesPerRow_( struct BoardInfo *bi,UWORD width, UWORD height, struct ModeInfo *mi, RGBFTYPE rgbtype)
{
	int bpp=1;
	int bpr ;
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	switch (mi -> Depth)
	{
		case 8:	bpp =1;  break;
		case 15:	bpp = 3;	break;
		case 16:	bpp = 3;	break;
		case 24:	bpp = 4;	break;
	}

	bpr = width * bpp;

	return (bpr&3) ?  (bpr & ~3) +4 : bpr;	// round up to closes 4 bytes...
}

APTR  _CalculateMemory_( struct BoardInfo *bi,APTR mem,  RGBFTYPE rgbtype)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return mem;
}

ULONG  _GetCompatibleFormats_( struct BoardInfo *bi, RGBFTYPE rgbtype)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return 1<<0 | 1<<0;		// return mask of formats
}

BOOL  _SetDisplay_( struct BoardInfo *bi, BOOL state)	// enable / disable video output
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return FALSE;		// doc says no output. hemm...
}

int resolved_modes = 0;

LONG  _ResolvePixelClock_( struct BoardInfo *bi, struct ModeInfo *mi, ULONG pixelClock, RGBFTYPE rgbtype)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	dprintf("ModeInfo: w: %d, h: %d, d: %d pixel clock %ld\n",
		mi -> Width,
		mi -> Height,
		mi -> Depth,
		mi -> PixelClock );

	dprintf("arg ModeInfo %ld\n", pixelClock);


//	mi -> PixelClock = CLOCK_HZ;
	mi -> pll1.Clock = 1;
	mi -> pll2.ClockDivide = 1;

	return bi -> BoardNum;
}

ULONG  _GetPixelClock_( struct BoardInfo *bi, struct ModeInfo *mi,ULONG index, RGBFTYPE rgbtype)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return mi -> PixelClock;
}

void  _SetClock_( struct BoardInfo *bi)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _SetMemoryMode_( struct BoardInfo *bi, RGBFTYPE rgbtype)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _SetWriteMask_( struct BoardInfo *bi,UBYTE mask)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _SetClearMask_( struct BoardInfo *bi,UBYTE mask)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _SetReadPlane_( struct BoardInfo *bi,UBYTE plane)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _WaitVerticalSync_( struct BoardInfo *bi, BOOL enable)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

BOOL  _SetInterrupt_( struct BoardInfo *bi, BOOL enable)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return FALSE;
}

void  _WaitBlitter_( struct BoardInfo *bi)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _ScrollPlanar_( struct BoardInfo *bi,struct RenderInfo *ri, UWORD a, UWORD b, UWORD c , UWORD d, UWORD e, UWORD f, UBYTE g)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _ScrollPlanarDefault_( struct BoardInfo *bi,struct RenderInfo *ri, UWORD a, UWORD b, UWORD c, UWORD d, UWORD e, UWORD f, UBYTE g)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _UpdatePlanar_( struct BoardInfo *bi,struct BitMap *bm, struct RenderInfo *ri, SHORT a, SHORT b, SHORT c, SHORT d, UBYTE e)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _UpdatePlanarDefault_( struct BoardInfo *bi,struct BitMap *bm, struct RenderInfo *ri, SHORT a, SHORT b, SHORT c, SHORT d, UBYTE e)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _BlitPlanar2Chunky_( struct BoardInfo *bi,struct BitMap *bm, struct RenderInfo *ri, SHORT a, SHORT b, SHORT c, SHORT d, SHORT e, SHORT f, UBYTE g, UBYTE h)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _BlitPlanar2ChunkyDefault_( struct BoardInfo *bi,struct BitMap *bm, struct RenderInfo *ri, SHORT a, SHORT b, SHORT c, SHORT d, SHORT e, SHORT f, UBYTE g, UBYTE h)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _FillRect_( struct BoardInfo *bi,struct RenderInfo *ri, WORD x, WORD y, WORD w, WORD h, ULONG pen, UBYTE mask, RGBFTYPE rgbtype)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _FillRectDefault_( struct BoardInfo *bi,struct RenderInfo *ri, WORD x, WORD y, WORD w, WORD h, ULONG pen, UBYTE mask, RGBFTYPE rgbtype)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _InvertRect_( struct BoardInfo *bi,struct RenderInfo *ri, WORD x, WORD y, WORD w, WORD h, UBYTE mask, RGBFTYPE rgbtype)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _InvertRectDefault_( struct BoardInfo *bi,struct RenderInfo *ri, WORD x, WORD y, WORD w, WORD h, UBYTE mask, RGBFTYPE rgbtype)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _BlitRect_( struct BoardInfo *bi,struct RenderInfo *ri, WORD srcx, WORD srcy, WORD desx, WORD dexy, WORD w, WORD h, UBYTE mask, RGBFTYPE rgbtype)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _BlitRectDefault_( struct BoardInfo *bi,struct RenderInfo *ri, WORD srcx, WORD srcy, WORD desx, WORD desy, WORD w, WORD h, UBYTE mask, RGBFTYPE rgbtype)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _BlitTemplate_( struct BoardInfo *bi,struct RenderInfo *ri, struct Template *t, WORD x, WORD y, WORD w, WORD h, UBYTE mask, RGBFTYPE rgbtype)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _BlitTemplateDefault_( struct BoardInfo *bi,struct RenderInfo *ri, struct Template *t, WORD x, WORD y, WORD w, WORD h, UBYTE mask, RGBFTYPE rgbtype)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _BlitPattern_( struct BoardInfo *bi,struct RenderInfo *ri, struct Pattern *p, WORD x, WORD y, WORD w, WORD h, UBYTE mask, RGBFTYPE rgbtype)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _BlitPatternDefault_( struct BoardInfo *bi,struct RenderInfo *ri, struct Pattern *p, WORD x, WORD y, WORD w, WORD h, UBYTE mask, RGBFTYPE rgbtype)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _DrawLine_( struct BoardInfo *bi,struct RenderInfo *ri, struct Line *l, UBYTE mask, RGBFTYPE rgbtype)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _DrawLineDefault_( struct BoardInfo *bi,struct RenderInfo *ri, struct Line *l, UBYTE mask, RGBFTYPE rgbtype)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _BlitRectNoMaskComplete_( struct BoardInfo *bi,struct RenderInfo *s_ri, struct RenderInfo *d_ri, WORD srcx, WORD srcy, WORD desx, WORD desy, WORD w, WORD h, UBYTE OpCode, RGBFTYPE rgbtype)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _BlitRectNoMaskCompleteDefault_( struct BoardInfo *bi,struct RenderInfo *s_ri, struct RenderInfo *d_ri, WORD srcx, WORD srcy, WORD desx, WORD desy, WORD w, WORD h, UBYTE OpCode, RGBFTYPE rgbtype)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _BlitPlanar2Direct_( struct BoardInfo *bi,struct BitMap *bm, struct RenderInfo *ri, struct ColorIndexMapping *cim, SHORT a, SHORT b, SHORT c, SHORT d, SHORT e, SHORT f, UBYTE g, UBYTE h)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _BlitPlanar2DirectDefault_( struct BoardInfo *bi,struct BitMap *bm, struct RenderInfo *ri, struct ColorIndexMapping *cim, SHORT a, SHORT b, SHORT c, SHORT d, SHORT e, SHORT f, UBYTE g, UBYTE h)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

BOOL  _EnableSoftSprite_( struct BoardInfo *bi,ULONG formatflags,  struct ModeInfo *mi)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return FALSE;
}

BOOL  _EnableSoftSpriteDefault_( struct BoardInfo *bi,ULONG formatflags, struct ModeInfo *mi)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return FALSE;
}

APTR  _AllocCardMemAbs_( struct BoardInfo *bi,ULONG size, char *target)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return 0xDEAD000;
}

void  _SetSplitPosition_( struct BoardInfo *bi,SHORT y)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _ReInitMemory_( struct BoardInfo *bi, RGBFTYPE rgbtype)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _Reserved2Default_( struct BoardInfo *bi)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _Reserved3_( struct BoardInfo *bi)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _Reserved3Default_( struct BoardInfo *bi)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

int  _WriteYUVRect_( struct BoardInfo *bi,APTR ptr, SHORT x, SHORT y, struct RenderInfo *ri, SHORT dx, SHORT dy, SHORT w, SHORT h, struct TagItem *tagList)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return 0;
}

int  _WriteYUVRectDefault_( struct BoardInfo *bi,APTR ptr, SHORT x, SHORT y, struct RenderInfo *ri, SHORT dx, SHORT dy, SHORT w, SHORT h, struct TagItem *tagList)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return 0;
}

BOOL  _GetVSyncState_( struct BoardInfo *bi, BOOL enable)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return FALSE;
}

ULONG  _GetVBeamPos_( struct BoardInfo *bi)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return 0;
}

void  _SetDPMSLevel_( struct BoardInfo *bi,ULONG dpmslevel)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _ResetChip_( struct BoardInfo *bi)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

ULONG  _GetFeatureAttrs_( struct BoardInfo *bi,APTR ULONG, struct TagItem *tagList)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return 0;
}

struct BitMap *  _AllocBitMap_( struct BoardInfo *bi,ULONG w, ULONG h, struct TagItem *tagList)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return NULL;
}

BOOL  _FreeBitMap_( struct BoardInfo *bi,struct BitMap *bm, struct TagItem *tagList)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return FALSE;
}

ULONG  _GetBitMapAttr_( struct BoardInfo *bi,struct BitMap *bm, ULONG attr)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	dprintf("attr: %08x\n",(int) attr);

	return 0;
}

BOOL  _SetSprite_( struct BoardInfo *bi, BOOL enable, RGBFTYPE rgbtype)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return FALSE;
}

void  _SetSpritePosition_( struct BoardInfo *bi, WORD x, WORD y,  RGBFTYPE rgbtype)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
}

void  _SetSpriteImage_( struct BoardInfo *bi, RGBFTYPE rgbtype)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

void  _SetSpriteColor_( struct BoardInfo *bi,UBYTE index, UBYTE red, UBYTE green, UBYTE blue, RGBFTYPE rgbtype)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

}

APTR  _CreateFeature_( struct BoardInfo *bi,ULONG type, struct TagItem *tagList)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return NULL;
}

ULONG  _SetFeatureAttrs_( struct BoardInfo *bi,APTR ptr, ULONG type, struct TagItem *tagList)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return 0;
}

BOOL  _DeleteFeature_( struct BoardInfo *bi,APTR ptr, ULONG type)
{
	dprintf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);
	return FALSE;
}
