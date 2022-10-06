#ifndef PROTO_DUMMY_CARD_H
#define PROTO_DUMMY_CARD_H

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
#ifndef DEVICES_TIMER_H
#include <devices/timer.h>
#endif
#ifndef PROTO_EXEC_H
#include <proto/exec.h>
#endif
#ifndef PROTO_DOS_H
#include <proto/dos.h>
#endif
#ifndef LIBRARIES_DUMMY_CARD_H
#include <libraries/dummy_card.h>
#endif
#ifndef LIBRARIES_MAYBE_BOARDINFO_H
#include <libraries/maybe_boardinfo.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
  extern struct AmigaOS::Library * DummyCardBase;
 #else
  extern struct Library * DummyCardBase;
 #endif
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/dummy_card.h>
 #ifdef __USE_INLINE__
  #include <inline4/dummy_card.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_DUMMY_CARD_PROTOS_H
  #define CLIB_DUMMY_CARD_PROTOS_H 1
 #endif /* CLIB_DUMMY_CARD_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::DummycardIFace * IDummyCard;
  #else
   extern struct DummycardIFace * IDummyCard;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_DUMMY_CARD_PROTOS_H
  #include <clib/dummy_card_protos.h>
 #endif /* CLIB_DUMMY_CARD_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/dummy_card.h>
  #else /* __PPC__ */
   #include <ppcinline/dummy_card.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/dummy_card_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/dummy_card_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_DUMMY_CARD_H */
