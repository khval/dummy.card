VERSION		EQU	53
REVISION	EQU	2

DATE	MACRO
		dc.b '5.10.2022'
		ENDM

VERS	MACRO
		dc.b 'dummy.card 53.2'
		ENDM

VSTRING	MACRO
		dc.b 'dummy.card 53.2 (5.10.2022)',13,10,0
		ENDM

VERSTAG	MACRO
		dc.b 0,'$VER: dummy.card 53.2 (5.10.2022)',0
		ENDM
