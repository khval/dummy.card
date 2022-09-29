#ifndef PROTO_DUMMY_CHIP_H
#define PROTO_DUMMY_CHIP_H

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
  extern struct AmigaOS::Library * dummy_chipBase;
 #else
  extern struct Library * dummy_chipBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/dummy_chip.h>
 #ifdef __USE_INLINE__
  #include <inline4/dummy_chip.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_DUMMY_CHIP_PROTOS_H
  #define CLIB_DUMMY_CHIP_PROTOS_H 1
 #endif /* CLIB_DUMMY_CHIP_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::dummy_chipIFace * Idummy_chip;
  #else
   extern struct dummy_chipIFace * Idummy_chip;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_DUMMY_CHIP_PROTOS_H
  #include <clib/dummy_chip_protos.h>
 #endif /* CLIB_DUMMY_CHIP_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/dummy_chip.h>
  #else /* __PPC__ */
   #include <ppcinline/dummy_chip.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/dummy_chip_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/dummy_chip_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_DUMMY_CHIP_H */
