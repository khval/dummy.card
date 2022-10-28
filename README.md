# dummy.card
Dummy.card is going to be a framebuffer video driver for AmigaOS4.1

This is not a working video card driver for AmigaOS4.1. 
But you can look at this code, if want to write your own video board driver for AmigaOS4.1.

It does open, and the rtg.library is able to access the API, 
but system gets confused, as functions are not doing anything, or not what they are supposed to anyhow.

This project started by asking for help on Amigans.net:
https://www.amigans.net/modules/newbb/viewtopic.php?topic_id=8982

As you can see from the comments, there no official documentations, 
about this subject for AmigaOS4.1, instead we have depended on the AmigaOS3.x docs.
And open source video board / card drivers for AmigaOS3.x

BUG:
Right now monitor program crashes, not in the driver itself, when trying to access a unknown function in graphic.library. 
the symbols are stripped, I might need to do some magic to figure out what function is called, 
functions names are documented in the API, so it question of mapping the know API to know addresses..
(how hard can it be, it can be useful too in other projects too..)...

Then it finally crashes in Exec, most likely some memory free, or memory allocation.

18.10.2022:
A bit of digging, comparing relative address of graphic library init, with address of routines in the interface, 
I don’t exactly get correct offset, but one pretty close is, InitBoardTagList(). That makes sense.
(That’s one of functions undocumented in autodocs)

What tags and what data pushed into function can be interesting to know.
(Finding the tag values associated with function can be useful as well.)

27.10.2022:
I patched the function can can confirm its the InitBoardTagList() function.

I tried to do the same for exec.library, but init code is in middle of memory code chunk, 
so offset are wrong, however, by looking at disassembly I can see abs memory address, where it failed.
And last closest Exec call is CopyMem or CopyMemQuick functions.
if I compare to the function pointer addresses in main interface of exec.library, so likely it’s one of this.
why error is unknown is yet unknown, but I expect it might be set, when the function has bad input maybe.

08.10.2022:
So looked at error code 0x01000008 its AN_SemCorrupt, A Semaphore is in a illigal state.
