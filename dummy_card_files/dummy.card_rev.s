VERSION = 53
REVISION = 2

.macro DATE
.ascii "5.10.2022"
.endm

.macro VERS
.ascii "dummy.card 53.2"
.endm

.macro VSTRING
.ascii "dummy.card 53.2 (5.10.2022)"
.byte 13,10,0
.endm

.macro VERSTAG
.byte 0
.ascii "$VER: dummy.card 53.2 (5.10.2022)"
.byte 0
.endm
