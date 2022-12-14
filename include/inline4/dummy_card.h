#ifndef INLINE4_DUMMY_CARD_H
#define INLINE4_DUMMY_CARD_H

/*
** This file was auto generated by idltool 53.24.
**
** It provides compatibility to OS3 style library
** calls by substituting functions.
**
** Do not edit manually.
*/ 

#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif
#ifndef EXEC_EXEC_H
#include <exec/exec.h>
#endif
#ifndef EXEC_INTERFACES_H
#include <exec/interfaces.h>
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
#include <interfaces/dummy_card.h>

/* Inline macros for Interface "main" */
#define FindCard(bi) IDummyCard->FindCard((bi))
#define InitCard(bi, ToolTypes) IDummyCard->InitCard((bi), (ToolTypes))
#define InitChip(bi) IDummyCard->InitChip((bi))

#endif /* INLINE4_DUMMY_CARD_H */
