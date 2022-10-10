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
