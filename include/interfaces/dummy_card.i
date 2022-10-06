#ifndef DUMMY_CARD_INTERFACE_DEF_H
#define DUMMY_CARD_INTERFACE_DEF_H
/*
** This file is machine generated from idltool
** Do not edit
*/ 

#include <exec/types.i>
#include <exec/exec.i>
#include <exec/interfaces.i>

STRUCTURE DummycardIFace, InterfaceData_SIZE
	    FPTR IDummycard_Obtain
	    FPTR IDummycard_Release
	    FPTR DummycardIFace_Expunge_UNIMPLEMENTED
	    FPTR DummycardIFace_Clone_UNIMPLEMENTED
	    FPTR IDummycard_FindCard
	    FPTR IDummycard_InitCard
	    FPTR IDummycard_InitChip
	LABEL DummycardIFace_SIZE

#endif
