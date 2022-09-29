VERSION		EQU	53
REVISION	EQU	1

DATE	MACRO
		dc.b '29.9.2022'
		ENDM

VERS	MACRO
		dc.b 'dummy_chip.library 53.1'
		ENDM

VSTRING	MACRO
		dc.b 'dummy_chip.library 53.1 (29.9.2022)',13,10,0
		ENDM

VERSTAG	MACRO
		dc.b 0,'$VER: dummy_chip.library 53.1 (29.9.2022)',0
		ENDM
