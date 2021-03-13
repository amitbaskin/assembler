;file example10.as
;test operators


mov
mov #1
mov r0
mov LOOP
mov %LOOP
mov #1, r0
mov #1, #1
mov #1, LOOP
mov #1, %LOOP
mov LOOP, r0
mov LOOP, #1
mov LOOP, LOOP
mov LOOP, %LOOP
mov %LOOP, #1
mov %LOOP, r0
mov %LOOP, LOOP
mov %LOOP, %LOOP
mov r0, #1
mov r0, r0
mov r0, LOOP
mov r0, %LOOP

cmp
cmp #1
cmp r0
cmp LOOP
cmp %LOOP
cmp #1, r0
cmp #1, #1
cmp #1, LOOP
cmp #1, %LOOP
cmp LOOP, r0
cmp LOOP, #1
cmp LOOP, LOOP
cmp LOOP, %LOOP
cmp %LOOP, #1
cmp %LOOP, r0
cmp %LOOP, LOOP
cmp %LOOP, %LOOP
cmp r0, #1
cmp r0, r0
cmp r0, LOOP
cmp r0, %LOOP

add
add #1
add r0
add LOOP
add %LOOP
add #1, r0
add #1, #1
add #1, LOOP
add #1, %LOOP
add LOOP, r0
add LOOP, #1
add LOOP, LOOP
add LOOP, %LOOP
add %LOOP, #1
add %LOOP, r0
add %LOOP, LOOP
add %LOOP, %LOOP
add r0, #1
add r0, r0
add r0, LOOP
add r0, %LOOP

sub
sub #1
sub r0
sub LOOP
sub %LOOP
sub #1, r0
sub #1, #1
sub #1, LOOP
sub #1, %LOOP
sub LOOP, r0
sub LOOP, #1
sub LOOP, LOOP
sub LOOP, %LOOP
sub %LOOP, #1
sub %LOOP, r0
sub %LOOP, LOOP
sub %LOOP, %LOOP
sub r0, #1
sub r0, r0
sub r0, LOOP
sub r0, %LOOP

lea
lea #1
lea r0
lea LOOP
lea %LOOP
lea #1, r0
lea #1, #1
lea #1, LOOP
lea #1, %LOOP
lea LOOP, r0
lea LOOP, #1
lea LOOP, LOOP
lea LOOP, %LOOP
lea %LOOP, #1
lea %LOOP, r0
lea %LOOP, LOOP
lea %LOOP, %LOOP
lea r0, #1
lea r0, r0
lea r0, LOOP
lea r0, %LOOP

clr
clr #1
clr r0
clr LOOP
clr %LOOP
clr #1, r0
clr #1, #1
clr #1, LOOP
clr #1, %LOOP
clr LOOP, r0
clr LOOP, #1
clr LOOP, LOOP
clr LOOP, %LOOP
clr %LOOP, #1
clr %LOOP, r0
clr %LOOP, LOOP
clr %LOOP, %LOOP
clr r0, #1
clr r0, r0
clr r0, LOOP
clr r0, %LOOP

not
not #1
not r0
not LOOP
not %LOOP
not #1, r0
not #1, #1
not #1, LOOP
not #1, %LOOP
not LOOP, r0
not LOOP, #1
not LOOP, LOOP
not LOOP, %LOOP
not %LOOP, #1
not %LOOP, r0
not %LOOP, LOOP
not %LOOP, %LOOP
not r0, #1
not r0, r0
not r0, LOOP
not r0, %LOOP

inc
inc #1
inc r0
inc LOOP
inc %LOOP
inc #1, r0
inc #1, #1
inc #1, LOOP
inc #1, %LOOP
inc LOOP, r0
inc LOOP, #1
inc LOOP, LOOP
inc LOOP, %LOOP
inc %LOOP, #1
inc %LOOP, r0
inc %LOOP, LOOP
inc %LOOP, %LOOP
inc r0, #1
inc r0, r0
inc r0, LOOP
inc r0, %LOOP

dec
dec #1
dec r0
dec LOOP
dec %LOOP
dec #1, r0
dec #1, #1
dec #1, LOOP
dec #1, %LOOP
dec LOOP, r0
dec LOOP, #1
dec LOOP, LOOP
dec LOOP, %LOOP
dec %LOOP, #1
dec %LOOP, r0
dec %LOOP, LOOP
dec %LOOP, %LOOP
dec r0, #1
dec r0, r0
dec r0, LOOP
dec r0, %LOOP

jmp
jmp #1
jmp r0
jmp LOOP
jmp %LOOP
jmp #1, r0
jmp #1, #1
jmp #1, LOOP
jmp #1, %LOOP
jmp LOOP, r0
jmp LOOP, #1
jmp LOOP, LOOP
jmp LOOP, %LOOP
jmp %LOOP, #1
jmp %LOOP, r0
jmp %LOOP, LOOP
jmp %LOOP, %LOOP
jmp r0, #1
jmp r0, r0
jmp r0, LOOP
jmp r0, %LOOP

bne
bne #1
bne r0
bne LOOP
bne %LOOP
bne #1, r0
bne #1, #1
bne #1, LOOP
bne #1, %LOOP
bne LOOP, r0
bne LOOP, #1
bne LOOP, LOOP
bne LOOP, %LOOP
bne %LOOP, #1
bne %LOOP, r0
bne %LOOP, LOOP
bne %LOOP, %LOOP
bne r0, #1
bne r0, r0
bne r0, LOOP
bne r0, %LOOP

jsr
jsr #1
jsr r0
jsr LOOP
jsr %LOOP
jsr #1, r0
jsr #1, #1
jsr #1, LOOP
jsr #1, %LOOP
jsr LOOP, r0
jsr LOOP, #1
jsr LOOP, LOOP
jsr LOOP, %LOOP
jsr %LOOP, #1
jsr %LOOP, r0
jsr %LOOP, LOOP
jsr %LOOP, %LOOP
jsr r0, #1
jsr r0, r0
jsr r0, LOOP
jsr r0, %LOOP

red
red #1
red r0
red LOOP
red %LOOP
red #1, r0
red #1, #1
red #1, LOOP
red #1, %LOOP
red LOOP, r0
red LOOP, #1
red LOOP, LOOP
red LOOP, %LOOP
red %LOOP, #1
red %LOOP, r0
red %LOOP, LOOP
red %LOOP, %LOOP
red r0, #1
red r0, r0
red r0, LOOP
red r0, %LOOP

prn
prn #1
prn r0
prn LOOP
prn %LOOP
prn #1, r0
prn #1, #1
prn #1, LOOP
prn #1, %LOOP
prn LOOP, r0
prn LOOP, #1
prn LOOP, LOOP
prn LOOP, %LOOP
prn %LOOP, #1
prn %LOOP, r0
prn %LOOP, LOOP
prn %LOOP, %LOOP
prn r0, #1
prn r0, r0
prn r0, LOOP
prn r0, %LOOP

rts
rts #1
rts r0
rts LOOP
rts %LOOP
rts #1, r0
rts #1, #1
rts #1, LOOP
rts #1, %LOOP
rts LOOP, r0
rts LOOP, #1
rts LOOP, LOOP
rts LOOP, %LOOP
rts %LOOP, #1
rts %LOOP, r0
rts %LOOP, LOOP
rts %LOOP, %LOOP
rts r0, #1
rts r0, r0
rts r0, LOOP
rts r0, %LOOP

stop
stop #1
stop r0
stop LOOP
stop %LOOP
stop #1, r0
stop #1, #1
stop #1, LOOP
stop #1, %LOOP
stop LOOP, r0
stop LOOP, #1
stop LOOP, LOOP
stop LOOP, %LOOP
stop %LOOP, #1
stop %LOOP, r0
stop %LOOP, LOOP
stop %LOOP, %LOOP
stop r0, #1
stop r0, r0
stop r0, LOOP
stop r0, %LOOP
