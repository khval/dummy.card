
/* :ts=4
 *  $VER: InitCard.c $Revision$ (29-Sep-2022)
 *
 *  This file is part of dummy_card.
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
#include <exec/emulation.h>
#include <proto/exec.h>
#include <proto/dos.h>
#include <libraries/dummy_card.h>
#include <proto/dummy_card.h>
#include <stdarg.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"
#include "68k_stubs.h"

// wrapped in a macro, so it's easy to change for a 680x0 trap call if needed.

#define M68K(x) const struct EmuTrap stub_ ## x = { TRAPINST, TRAPTYPE, (void *) stub_##x##_ppc };

#define API(x) (void *) &stub_##x

M68K(AllocCardMem);
M68K(FreeCardMem);
M68K(SetSwitch);
M68K(SetColorArray);
M68K(SetDAC);
M68K(SetGC);
M68K(SetPanning);
M68K(CalculateBytesPerRow);
M68K(CalculateMemory);
M68K(GetCompatibleFormats);
M68K(SetDisplay);
M68K(ResolvePixelClock);
M68K(GetPixelClock);
M68K(SetClock);
M68K(SetMemoryMode);
M68K(SetWriteMask);
M68K(SetClearMask);
M68K(SetReadPlane);
M68K(WaitVerticalSync);
M68K(SetInterrupt);
M68K(WaitBlitter);
M68K(ScrollPlanar);
M68K(ScrollPlanarDefault);
M68K(UpdatePlanar);
M68K(UpdatePlanarDefault);
M68K(BlitPlanar2Chunky);
M68K(BlitPlanar2ChunkyDefault);
M68K(FillRect);
M68K(FillRectDefault);
M68K(InvertRect);
M68K(InvertRectDefault);
M68K(BlitRect);
M68K(BlitRectDefault);
M68K(BlitTemplate);
M68K(BlitTemplateDefault);
M68K(BlitPattern);
M68K(BlitPatternDefault);
M68K(DrawLine);
M68K(DrawLineDefault);
M68K(BlitRectNoMaskComplete);
M68K(BlitRectNoMaskCompleteDefault);
M68K(BlitPlanar2Direct);
M68K(BlitPlanar2DirectDefault);
M68K(EnableSoftSprite);
M68K(EnableSoftSpriteDefault);
M68K(AllocCardMemAbs);
M68K(SetSplitPosition);
M68K(ReInitMemory);
M68K(Reserved2Default);
M68K(Reserved3);
M68K(Reserved3Default);
M68K(WriteYUVRect);
M68K(WriteYUVRectDefault);
M68K(GetVSyncState);
M68K(GetVBeamPos);
M68K(SetDPMSLevel);
M68K(ResetChip);
M68K(GetFeatureAttrs);
M68K(AllocBitMap);
M68K(FreeBitMap);
M68K(GetBitMapAttr);
M68K(SetSprite);
M68K(SetSpritePosition);
M68K(SetSpriteImage);
M68K(SetSpriteColor);
M68K(CreateFeature);
M68K(SetFeatureAttrs);
M68K(DeleteFeature);

void init_api( struct BoardInfo * bi )
{
	bi -> AllocCardMem = API(AllocCardMem);
	bi -> FreeCardMem = API(FreeCardMem);
	bi -> SetSwitch = API(SetSwitch);
	bi -> SetColorArray = API(SetColorArray);
	bi -> SetDAC = API(SetDAC);
	bi -> SetGC = API(SetGC);
	bi -> SetPanning = API(SetPanning);
	bi -> CalculateBytesPerRow = API(CalculateBytesPerRow);
	bi -> CalculateMemory = API(CalculateMemory);
	bi -> GetCompatibleFormats = API(GetCompatibleFormats);
	bi -> SetDisplay = API(SetDisplay);
	bi -> ResolvePixelClock = API(ResolvePixelClock);
	bi -> GetPixelClock = API(GetPixelClock);
	bi -> SetClock = API(SetClock);
	bi -> SetMemoryMode = API(SetMemoryMode);
	bi -> SetWriteMask = API(SetWriteMask);
	bi -> SetClearMask = API(SetClearMask);
	bi -> SetReadPlane = API(SetReadPlane);
	bi -> WaitVerticalSync = API(WaitVerticalSync);
	bi -> SetInterrupt = API(SetInterrupt);
	bi -> WaitBlitter = API(WaitBlitter);
	bi -> ScrollPlanar = API(ScrollPlanar);
	bi -> ScrollPlanarDefault = API(ScrollPlanarDefault);
	bi -> UpdatePlanar = API(UpdatePlanar);
	bi -> UpdatePlanarDefault = API(UpdatePlanarDefault);
	bi -> BlitPlanar2Chunky = API(BlitPlanar2Chunky);
	bi -> BlitPlanar2ChunkyDefault = API(BlitPlanar2ChunkyDefault);
	bi -> FillRect = API(FillRect);
	bi -> FillRectDefault = API(FillRectDefault);
	bi -> InvertRect = API(InvertRect);
	bi -> InvertRectDefault = API(InvertRectDefault);
	bi -> BlitRect = API(BlitRect);
	bi -> BlitRectDefault = API(BlitRectDefault);
	bi -> BlitTemplate = API(BlitTemplate);
	bi -> BlitTemplateDefault = API(BlitTemplateDefault);
	bi -> BlitPattern = API(BlitPattern);
	bi -> BlitPatternDefault = API(BlitPatternDefault);
	bi -> DrawLine = API(DrawLine);
	bi -> DrawLineDefault = API(DrawLineDefault);
	bi -> BlitRectNoMaskComplete = API(BlitRectNoMaskComplete);
	bi -> BlitRectNoMaskCompleteDefault = API(BlitRectNoMaskCompleteDefault);
	bi -> BlitPlanar2Direct = API(BlitPlanar2Direct);
	bi -> BlitPlanar2DirectDefault = API(BlitPlanar2DirectDefault);
	bi -> EnableSoftSprite = API(EnableSoftSprite);
	bi -> EnableSoftSpriteDefault = API(EnableSoftSpriteDefault);
	bi -> AllocCardMemAbs = API(AllocCardMemAbs);
	bi -> SetSplitPosition = API(SetSplitPosition);
	bi -> ReInitMemory = API(ReInitMemory);
	bi -> Reserved2Default = API(Reserved2Default);
	bi -> Reserved3 = API(Reserved3);
	bi -> Reserved3Default = API(Reserved3Default);
	bi -> WriteYUVRect = API(WriteYUVRect);
	bi -> WriteYUVRectDefault = API(WriteYUVRectDefault);
	bi -> GetVSyncState = API(GetVSyncState);
	bi -> GetVBeamPos = API(GetVBeamPos);
	bi -> SetDPMSLevel = API(SetDPMSLevel);
	bi -> ResetChip = API(ResetChip);
	bi -> GetFeatureAttrs = API(GetFeatureAttrs);
	bi -> AllocBitMap = API(AllocBitMap);
	bi -> FreeBitMap = API(FreeBitMap);
	bi -> GetBitMapAttr = API(GetBitMapAttr);
	bi -> SetSprite = API(SetSprite);
	bi -> SetSpritePosition = API(SetSpritePosition);
	bi -> SetSpriteImage = API(SetSpriteImage);
	bi -> SetSpriteColor = API(SetSpriteColor);
	bi -> CreateFeature = API(CreateFeature);
	bi -> SetFeatureAttrs = API(SetFeatureAttrs);
	bi -> DeleteFeature = API(DeleteFeature);
}

