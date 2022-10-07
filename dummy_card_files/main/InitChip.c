/* :ts=4
 *  $VER: InitChip.c $Revision$ (29-Sep-2022)
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
#include <proto/exec.h>
#include <proto/dos.h>
#include <libraries/dummy_card.h>
#include <libraries/maybe_boardinfo.h>
#include <proto/dummy_card.h>
#include <stdarg.h>

#include <stdio.h>
#include <string.h>

#include "../functions.h"

/****** dummy_card/main/InitChip ******************************************
*
*   NAME
*      InitChip -- Description
*
*   SYNOPSIS
*      BOOL InitChip(struct BoardInfo * bi);
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

BOOL _dummy_card_InitChip(struct DummycardIFace *Self,  struct BoardInfo * bi)
{
	printf("%s:%s:%d\n",__FILE__,__FUNCTION__,__LINE__);


	return TRUE;
}

