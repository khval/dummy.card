#ifndef DUMMY_CHIP_INTERFACE_DEF_H
#define DUMMY_CHIP_INTERFACE_DEF_H
/*
** This file is machine generated from idltool
** Do not edit
*/ 

#include <exec/types.i>
#include <exec/exec.i>
#include <exec/interfaces.i>

STRUCTURE dummy_chipIFace, InterfaceData_SIZE
	    FPTR Idummy_chip_Obtain
	    FPTR Idummy_chip_Release
	    FPTR dummy_chipIFace_Expunge_UNIMPLEMENTED
	    FPTR dummy_chipIFace_Clone_UNIMPLEMENTED
	    FPTR Idummy_chip_FindCard
	    FPTR Idummy_chip_InitCard
	    FPTR Idummy_chip_InitChip
	LABEL dummy_chipIFace_SIZE

#endif
