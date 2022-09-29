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


#include <exec/exec.h>
#include <proto/exec.h>
#include <dos/dos.h>
#include <exec/types.h>
#include <proto/exec.h>
#include <proto/dos.h>
#include <libraries/dummy_chip.h>
#include <proto/dummy_chip.h>
#include <stdarg.h>

/****** dummy_chip/main/InitCard ******************************************
*
*   NAME
*      InitCard -- Description
*
*   SYNOPSIS
*      void InitCard(struct boardinfo * bi, char ** ToolTypes);
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

void _dummy_chip_InitCard(struct dummy_chipIFace *Self,
       struct boardinfo * bi,
       char ** ToolTypes)
{
  InitCard(bi, ToolTypes);
}

