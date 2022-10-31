/* :ts=4
 *  $VER: FindCard.c $Revision$ (29-Sep-2022)
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


#include <exec/exec.h>
#include <proto/exec.h>
#include <dos/dos.h>
#include <exec/types.h>
#include <proto/exec.h>
#include <proto/dos.h>
#include <libraries/dummy_card.h>
#include <proto/dummy_card.h>
#include <stdarg.h>

#include <stdio.h>
#include <stdlib.h>

/****** dummy_card/main/FindCard ******************************************
*
*   NAME
*      FindCard -- Description
*
*   SYNOPSIS
*      BOOL FindCard(struct BoardInfo * bi);
*
*   FUNCTION
*
*   INPUTS
*       bi - 
*
*   RESULT
*       The result ...
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

BOOL card_found = FALSE;

#define MEMSIZE 2*1024*1024

UBYTE board_memory[MEMSIZE];
UBYTE palette[256*4];

BOOL _dummy_card_FindCard(struct DummycardIFace *Self, struct BoardInfo * bi)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);

	if (card_found == FALSE)
	{
		card_found = TRUE;	//  only one card!!

		bi -> MemorySize = MEMSIZE;	// 2 mb
		bi -> MemoryBase = board_memory;
		bi -> RegisterBase = palette;		// 256 color 4 channels

		bi -> MemoryIOBase = 0xBEEF0000;				// not use by zz9000

		bi -> MaxPlanarMemory = 0;

	 	return TRUE;
	}
	else
	{
		return FALSE;
	}
}

