/* :ts=4
 *  $VER: InitCard.c $Revision$ (29-Sep-2022)
 *
 *  This file is part of dummy_chip.
 *
 *  Copyright (c) 2022 LiveForIt Software.
 *  LGPL.
 *
 * $Id$
 *
 * $Log$
 *
 *
 */

#define __USE_INLINE__

#include <exec/exec.h>
#include <proto/exec.h>
#include <dos/dos.h>
#include <exec/types.h>
#include <exec/Interrupts.h>
#include <proto/exec.h>
#include <proto/dos.h>
#include <libraries/dummy_card.h>
#include <proto/dummy_card.h>
#include <stdarg.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../functions.h"

/****** dummy_card/main/InitCard ******************************************
*
*   NAME
*      InitCard -- Description
*
*   SYNOPSIS
*      void InitCard(struct BoardInfo * bi, char ** ToolTypes);
*
*   FUNCTION
*
*   INPUTS
*       bi - 
*       ToolTypes - 
*
*   RESULT
*       This function does not return a result
*
*   EXAMPLE
*
*   NOTES
*
*   BUGS
*
*   SEE ALSO
*
*****************************************************************************
*
*/

extern struct Library *ExecBase;

const char *name = "dummy.chip";

struct SignalSemaphore *BoardLock;

void _dummy_card_InitCard(struct DummyChipIFace *Self, struct BoardInfo * bi, char ** ToolTypes)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	// setup init data.

	bi -> BoardName = name;
	sprintf(bi -> VBIName,"%s",name);
	bi -> CardBase = NULL;
	bi -> ChipBase = NULL;
	bi -> ExecBase = NULL;
	bi -> UtilBase = NULL;

	bi -> HardInterrupt;
	bi -> SoftInterrupt;

	InitSemaphore( &bi -> BoardLock );
	NewMinList( &bi -> ResolutionsList );

	bi -> BoardType = BT_powerfb;

	bi -> PaletteChipType = 0;
	bi -> GraphicsControllerType = 0;
	bi -> MoniSwitch = 0;
	bi -> BitsPerCannon = 0;
	bi -> Flags = BIF_NOBLITTER | BIF_NOP2CBLITS |  BIF_NOMASKBLITS | BIF_NEEDSALIGNMENT;
	bi -> SoftSpriteFlags = 0;

	bi -> RGBFormats = MAXMODES;

/**/

	// setup functions.

	bi -> AllocCardMem = _AllocCardMem_ ;
	bi -> FreeCardMem = _FreeCardMem_ ;
	bi -> SetSwitch = _SetSwitch_ ;
	bi -> SetColorArray = _SetColorArray_ ;
	bi -> SetDAC = _SetDAC_ ;
	bi -> SetGC = _SetGC_ ;
	bi -> SetPanning = _SetPanning_ ;
	bi -> CalculateBytesPerRow = _CalculateBytesPerRow_ ;
	bi -> CalculateMemory = _CalculateMemory_ ;
	bi -> GetCompatibleFormats = _GetCompatibleFormats_ ;
	bi -> SetDisplay = _SetDisplay_ ;
	bi -> ResolvePixelClock = _ResolvePixelClock_ ;
	bi -> GetPixelClock = _GetPixelClock_ ;
	bi -> SetClock = _SetClock_ ;
	bi -> SetMemoryMode = _SetMemoryMode_ ;
	bi -> SetWriteMask = _SetWriteMask_ ;
	bi -> SetClearMask = _SetClearMask_ ;
	bi -> SetReadPlane = _SetReadPlane_ ;
	bi -> WaitVerticalSync = _WaitVerticalSync_ ;
	bi -> SetInterrupt = _SetInterrupt_ ;
	bi -> WaitBlitter = _WaitBlitter_ ;
	bi -> ScrollPlanar = _ScrollPlanar_ ;
	bi -> ScrollPlanarDefault = _ScrollPlanarDefault_ ;
	bi -> UpdatePlanar = _UpdatePlanar_ ;
	bi -> UpdatePlanarDefault = _UpdatePlanarDefault_ ;
	bi -> BlitPlanar2Chunky = _BlitPlanar2Chunky_ ;
	bi -> BlitPlanar2ChunkyDefault = _BlitPlanar2ChunkyDefault_ ;
	bi -> FillRect = _FillRect_ ;
	bi -> FillRectDefault = _FillRectDefault_ ;
	bi -> InvertRect = _InvertRect_ ;
	bi -> InvertRectDefault = _InvertRectDefault_ ;
	bi -> BlitRect = _BlitRect_ ;
	bi -> BlitRectDefault = _BlitRectDefault_ ;
	bi -> BlitTemplate = _BlitTemplate_ ;
	bi -> BlitTemplateDefault = _BlitTemplateDefault_ ;
	bi -> BlitPattern = _BlitPattern_ ;
	bi -> BlitPatternDefault = _BlitPatternDefault_ ;
	bi -> DrawLine = _DrawLine_ ;
	bi -> DrawLineDefault = _DrawLineDefault_ ;
	bi -> BlitRectNoMaskComplete = _BlitRectNoMaskComplete_ ;
	bi -> BlitRectNoMaskCompleteDefault = _BlitRectNoMaskCompleteDefault_ ;
	bi -> BlitPlanar2Direct = _BlitPlanar2Direct_ ;
	bi -> BlitPlanar2DirectDefault = _BlitPlanar2DirectDefault_ ;
	bi -> EnableSoftSprite = _EnableSoftSprite_ ;
	bi -> EnableSoftSpriteDefault = _EnableSoftSpriteDefault_ ;
	bi -> AllocCardMemAbs = _AllocCardMemAbs_ ;
	bi -> SetSplitPosition = _SetSplitPosition_ ;
	bi -> ReInitMemory = _ReInitMemory_ ;
	bi -> Reserved2Default = _Reserved2Default_ ;
	bi -> Reserved3 = _Reserved3_ ;
	bi -> Reserved3Default = _Reserved3Default_ ;
	bi -> WriteYUVRect = _WriteYUVRect_ ;
	bi -> WriteYUVRectDefault = _WriteYUVRectDefault_ ;
	bi -> GetVSyncState = _GetVSyncState_ ;
	bi -> GetVBeamPos = _GetVBeamPos_ ;
	bi -> SetDPMSLevel = _SetDPMSLevel_ ;
	bi -> ResetChip = _ResetChip_ ;
	bi -> GetFeatureAttrs = _GetFeatureAttrs_ ;
	bi -> AllocBitMap = _AllocBitMap_ ;
	bi -> FreeBitMap = _FreeBitMap_ ;
	bi -> GetBitMapAttr = _GetBitMapAttr_ ;
	bi -> SetSprite = _SetSprite_ ;
	bi -> SetSpritePosition = _SetSpritePosition_ ;
	bi -> SetSpriteImage = _SetSpriteImage_ ;
	bi -> SetSpriteColor = _SetSpriteColor_ ;
	bi -> CreateFeature = _CreateFeature_ ;
	bi -> SetFeatureAttrs = _SetFeatureAttrs_ ;
	bi -> DeleteFeature = _DeleteFeature_ ;

}

