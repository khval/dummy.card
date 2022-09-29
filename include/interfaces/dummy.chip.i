#ifndef DUMMY.CHIP_INTERFACE_DEF_H
#define DUMMY.CHIP_INTERFACE_DEF_H
/*
** This file is machine generated from idltool
** Do not edit
*/ 

#include <exec/types.i>
#include <exec/exec.i>
#include <exec/interfaces.i>

STRUCTURE DummyChipIFace, InterfaceData_SIZE
	    FPTR IDummyChip_Obtain
	    FPTR IDummyChip_Release
	    FPTR DummyChipIFace_Expunge_UNIMPLEMENTED
	    FPTR DummyChipIFace_Clone_UNIMPLEMENTED
	    FPTR IDummyChip_FindCard
	    FPTR IDummyChip_InitCard
	    FPTR IDummyChip_InitChip
	LABEL DummyChipIFace_SIZE

#endif
