;file example6.as
;fail example
;example3 mixed with first parse errors


.entry LIST
    .extern W
    .extern L3
MAIN:add     r3, LIST
LOOP:prn     #48
lea     W, r6
.extern externAndRegular
externAndRegular: stop
.entry
.extern
MAIN:

externAndRegular0: stop
.extern externAndRegular0

inc     r6
SRg
SR
debuggerSR

    .entry LIST
STR: .string "abcd"

mov     r3, K
.data
.string
.data5

sub     r1, r4

.string hi"
r0: .data 5
dec: .data 7

bne     END
    .entry MAIN
LIST:.data 6, -9
    .data -100
K:.data 31
GR
SRg
RS
debugger

MAIN: .data 5
.extern a0123456789012345678901234567890
MAIN: .data 6
rg
SRg
r
Sgr


.string "012345678901234567890123456789012345678901234567890123456789012345678901"



    .entry LIST
cmp     K, #-6
bne     %END
.data c
.string"hi"
.string hi

debuggerGSR
G
RSg
gS

.string "hi

    .extern L3
dec     W
    .entry MAIN
jmp     %LOOP
add     L3, L3
END:stop
    .extern L3







.data 5 6
.data  , 7

GSRTg
SRg
S
