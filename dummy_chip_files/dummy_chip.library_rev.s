VERSION = 53
REVISION = 2

.macro DATE
.ascii "29.9.2022"
.endm

.macro VERS
.ascii "dummy_chip.library 53.2"
.endm

.macro VSTRING
.ascii "dummy_chip.library 53.2 (29.9.2022)"
.byte 13,10,0
.endm

.macro VERSTAG
.byte 0
.ascii "$VER: dummy_chip.library 53.2 (29.9.2022)"
.byte 0
.endm
