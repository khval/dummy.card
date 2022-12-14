/*
**	$Id$
**	Generated by IDLTool 53.24
**	Do not edit
**
**	AutoInit stub for dummy_card
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#include <exec/types.h>
#include <proto/exec.h>
#include <proto/dos.h>
#include <libraries/dummy_card.h>

#include <interfaces/dummy_card.h>
#include <proto/exec.h>
#include <proto/dos.h>
#include <stdlib.h>

struct dummy_cardIFace * Idummy_card = NULL;
static struct Library * __dummy_cardBase = NULL;
static struct dummy_cardIFace * __Idummy_card = NULL;

/****************************************************************************/

extern struct Library * dummy_cardBase;

/****************************************************************************/

void dummy_card_main_constructor(void)
{
    if (Idummy_card != NULL)
    {
        return; /* Someone was quicker */
    }
    if (dummy_cardBase == NULL) /* Library base is NULL, we need to open it */
    {
        /* We were called before the base constructor.
         * This means we will be called _after_ the base destructor.
         * So we cant drop the interface _after_ closing the last library base,
         * we just open the library here which ensures that.
         */
        __dummy_cardBase = dummy_cardBase = IExec->OpenLibrary("dummy.card", 0);
        if (dummy_cardBase == NULL)
        {
            IDOS->PutErrStr("ERROR: Failed to open 'dummy.card'.\n");
            abort();
        }
    }

    __Idummy_card = Idummy_card = (struct dummy_cardIFace *)IExec->GetInterface((struct Library *)dummy_cardBase, "main", 1, NULL);
    if (Idummy_card == NULL)
    {
        IDOS->PutErrStr("ERROR: Failed to get 'main' V1 interface for 'dummy.card'.\n");
        abort();
    }
}
__attribute__((section(".ctors.zzzy"))) static void
(*dummy_card_main_constructor_ptr)(void) USED = dummy_card_main_constructor;

/****************************************************************************/

void dummy_card_main_destructor(void)
{
    if (__Idummy_card)
    {
        IExec->DropInterface ((struct Interface *)__Idummy_card);
    }
    if (__dummy_cardBase)
    {
        IExec->CloseLibrary(__dummy_cardBase);
    }
}
__attribute__((section(".dtors.zzzy"))) static void
(*dummy_card_main_destructor_ptr)(void) USED = dummy_card_main_destructor;

/****************************************************************************/

