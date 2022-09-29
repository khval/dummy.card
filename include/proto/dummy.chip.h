#ifndef PROTO_DUMMY.CHIP_H
#define PROTO_DUMMY.CHIP_H

/*
**	$Id$
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef PROTO_EXEC_H
#include <proto/exec.h>
#endif
#ifndef PROTO_DOS_H
#include <proto/dos.h>
#endif
#ifndef LIBRARIES_DUMMY_CHIP_H
#include <libraries/dummy_chip.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * DummyChipBase;
 #else
  extern struct Library * DummyChipBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/dummy.chip.h>
 #ifdef __USE_INLINE__
  #include <inline4/dummy.chip.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_DUMMY.CHIP_PROTOS_H
  #define CLIB_DUMMY.CHIP_PROTOS_H 1
 #endif /* CLIB_DUMMY.CHIP_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::DummyChipIFace * IDummyChip;
  #else
   extern struct DummyChipIFace * IDummyChip;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_DUMMY.CHIP_PROTOS_H
  #include <clib/dummy.chip_protos.h>
 #endif /* CLIB_DUMMY.CHIP_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/dummy.chip.h>
  #else /* __PPC__ */
   #include <ppcinline/dummy.chip.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/dummy.chip_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/dummy.chip_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_DUMMY.CHIP_H */
