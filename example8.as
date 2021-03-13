;file example8.as
;fail example
;example 3 mixed with all errors


    .entry LIST
    .extern W
    .extern L3
MAIN:add     r3, LIST
LOOP:prn     #48
    .entry entryAlone

    .entry externAndEntryClash
    .extern externAndEntryClash

dec undeclaredLabel

lea     W, r6
inc     r6
    .entry
    .extern
MAIN:
    .data
    .string "hi
    .string hi"
r0: .data 5
SRg
SR
debuggerSR
gS
rg

dec: .data 7
SRg
r
Sgr
    .entry LIST
STR:.string "abcd"
mov     r3, K

S
G
RSg
sub     r1, r4
    .extern a0123456789012345678901234567890

bne     END
    .entry MAIN
    .string
    .data5
    .string hi

LIST:.data 6, -9

    .data 5 6
    .data  , 7
    .data c
    .string"hi"

MAIN: .data 5
    .string "012345678901234567890123456789012345678901234567890123456789012345678901"
MAIN: .data 6


    .data -100
K:.data 31

GSRTg
SRg

    .entry LIST
cmp     K, #-6
bne     %END

SRg
RS
debugger
    .extern L3
dec     W

GR

debuggerGSR
externAndRegular0: stop
    .extern externAndRegular0

    .entry MAIN
jmp     %LOOP
    .extern externAndRegular
externAndRegular: stop

add     L3, L3
END:stop
    .extern L3




