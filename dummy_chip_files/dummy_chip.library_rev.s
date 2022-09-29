VERSION = 53
REVISION = 1

.macro DATE
.ascii "29.9.2022"
.endm

.macro VERS
.ascii "dummy_chip.library 53.1"
.endm

.macro VSTRING
.ascii "dummy_chip.library 53.1 (29.9.2022)"
.byte 13,10,0
.endm

.macro VERSTAG
.byte 0
.ascii "$VER: dummy_chip.library 53.1 (29.9.2022)"
.byte 0
.endm
