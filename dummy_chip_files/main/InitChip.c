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


#include <exec/exec.h>
#include <proto/exec.h>
#include <dos/dos.h>
#include <exec/types.h>
#include <proto/exec.h>
#include <proto/dos.h>
#include <libraries/dummy_chip.h>
#include <proto/dummy_chip.h>
#include <stdarg.h>

/****** dummy_chip/main/InitChip ******************************************
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

BOOL _dummy_chip_InitChip(struct DummyChipIFace *Self,
       struct BoardInfo * bi)
{
  return InitChip(bi);
}
