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
#include <proto/graphics.h>
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
extern struct GraphicsIFace *IGfx;

//struct SignalSemaphore *BoardLock;

struct ChipBase chipbase;
//struct CardBase cardbase;

#define CLOCK_HZ 1000000000 

void hard()
{
	DebugPrintF("hard\n");
}

void soft()
{
	DebugPrintF("soft\n");
}


void init_interrupt( struct Interrupt *i, VOID (*ifn)() )
{
	i -> is_Node.ln_Pri  = 50;  
	i -> is_Node.ln_Name = "Example Handler";  
	i -> is_Node.ln_Type = NT_INTERRUPT;
	i -> is_Data = 0;
	i -> is_Code = ifn;
}

extern void init_api( struct BoardInfo * bi );
extern void show_func(struct BoardInfo * bi);

const char *name = "test dummy card";

char *sem_name = "dummy card";

struct BitMap *bm;
struct BitMapExtra _BitMapExtra;

void init_BitMapExtra(struct BitMapExtra *bme,struct BoardInfo * bi)
{
//	InitBitMap( &_bm, 8, 640, 480 );

	NewMinList( &(bme -> BoardNode));
	bme -> HashChain = NULL;
	bme -> Match = 0xBADCAFE1;

	bme -> BitMap = AllocBitMapTags( 640, 480, 8,
				BMATags_PixelFormat, PIXF_CLUT,
				TAG_END	 ) ;

	bme -> BoardInfo = bi;
	bme -> MemChunk = 0xBADCAFE3;
	// bme -> RenderInfo;
	bme -> Width = 640;
	bme -> Height = 480;
	bme -> Flags = 0;
	// NEW !!!
	bme -> BaseLevel =0;
	bme -> CurrentLevel = 0;
	bme -> CompanionMaster = NULL;	// think I need to set this to NULL...
}

void _dummy_card_InitCard(struct DummycardIFace *Self, struct BoardInfo * bi, char ** ToolTypes)
{
	int i;

	struct ExecBase *ExecBase = (struct ExecBase *)(*(struct ExecBase **)4);

	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	init_BitMapExtra( &_BitMapExtra, bi );

	printf("%s:%s:%d ExecBase: %08x\n",__FILE__,__FUNCTION__,__LINE__, (int) bi-> ExecBase);
	printf("%s:%s:%d UtilBase: %08x\n",__FILE__,__FUNCTION__,__LINE__, (int) bi-> UtilBase);
	printf("%s:%s:%d CardBase: %08x\n",__FILE__,__FUNCTION__,__LINE__, (int) bi-> CardBase);
	printf("%s:%s:%d ChipBase: %08x\n",__FILE__,__FUNCTION__,__LINE__, (int) bi-> ChipBase);

	// setup init data.

	bi -> BoardName = (char *) name;
	bi -> BoardType = 14;			// set like this in ZZ9000 driver not sure why....

//	bi -> CardBase = &cardbase;		// this one looks like is setup from before.

	chipbase.ExecBase = ExecBase;

	bzero(&chipbase,sizeof(chipbase));
//	bi -> ChipBase = &chipbase;		// not sure about this one!!!		should point to a library base...

//	bi -> ExecBase = ExecBase;		// this one is setup by rtg.library !!
//	bi -> UtilBase = NULL;			// this one is setup by rtg.library !!

	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	printf("%s:%s:%d ExecBase: %08x\n",__FILE__,__FUNCTION__,__LINE__, (int) bi-> ExecBase);
	printf("%s:%s:%d UtilBase: %08x\n",__FILE__,__FUNCTION__,__LINE__, (int) bi-> UtilBase);
	printf("%s:%s:%d CardBase: %08x\n",__FILE__,__FUNCTION__,__LINE__, (int) bi-> CardBase);
	printf("%s:%s:%d ChipBase: %08x\n",__FILE__,__FUNCTION__,__LINE__, (int) bi-> ChipBase);

	init_interrupt( &(bi -> HardInterrupt), hard );
	init_interrupt( &(bi -> SoftInterrupt), soft ) ;

// this code is maybe allready setup by AmigaOS4.
#if 0
//	memset(&bi -> BoardLock, 0, sizeof(struct SignalSemaphore));	// doc, says clear it, first...
//	InitSemaphore( &(bi -> BoardLock) );
//	bi -> BoardLock.ss_Link.ln_Name = sem_name; 
//	AddSemaphore( &(bi -> BoardLock) );
#endif

	NewMinList( &bi -> ResolutionsList );
	NewMinList( &bi -> SpecialFeatures );

	// 2 4 8 A C E 0
	// 4 8 C 0

	bi -> ModeInfo = 0xDEAD0004;
	bi -> ViewPort = 0xDEAD0008;
	bi -> VisibleBitMap = 0xDEAD000C;

	NewMinList( &bi -> BitMapList);
	NewMinList( &bi -> MemList);
	NewMinList( &bi -> WaitQ);

	bi -> BoardType = BT_powerfb;

//	bi -> SoftVBlankPort ;
	bi -> MouseImage = 0xDEAD0014;
	bi -> MouseRendered = 0xDEAD0018;
	bi -> MouseSaveBuffer = 0xDEAD001C;
	bi -> MouseImageBuffer = 0xDEAD0020;
	bi -> backViewPort = 0xDEAD0024;
	bi -> backBitMap = 0xDEAD0028;
	bi -> backExtra = 0xDEAD002C;
	bi -> MouseChunky = 0xDEAD0030;


	printf("bi -> BitMapExtra: %08x\n", (unsigned int) bi -> BitMapExtra);

	bi -> BitMapExtra = &_BitMapExtra;

	bi -> PaletteChipType = 0;
	bi -> GraphicsControllerType = 0;
	bi -> MoniSwitch = 0;
	bi -> BitsPerCannon = 8;
	bi -> Flags = BIF_NOBLITTER | BIF_NOP2CBLITS |  BIF_NOMASKBLITS | BIF_NEEDSALIGNMENT;
	bi -> SoftSpriteFlags = 0;

	bi -> RGBFormats = 1 | 2 | 512 | 1024 | 2048;

	for (i=0; i < MAXMODES; i++ )
	{
		bi -> MaxHorValue[i] = 8192;
		bi -> MaxVerValue[i] = 8192;
		bi -> MaxHorResolution[i] = 8192;
		bi -> MaxVerResolution[i] = 8192;
		bi -> PixelClockCount[i] = 1;
	}

	bi -> MemoryClock = CLOCK_HZ;

	// setup functions.

	show_func(bi);

	init_api( bi );

	printf("%s:%s:%d End of Function\n",__FILE__,__FUNCTION__,__LINE__);

}

