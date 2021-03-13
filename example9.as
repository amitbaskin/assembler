;file example9.as
;example3 without spaces, commas and colon in necessary places
;hashtag missing where should be and appears in wrong places


    .entry LIST


    .externW

    .extern L3
MAIN:add     #r3, LIST
LOOP:prn     48
leaW, r6


inc     r6
    .entry LIST

STR .string "abcd"
mov     r3 K
        sub #r1,1
bne     END
    .entry   MAIN



LIST:.data 6,       -9
        .data-100
K .data 31
    .entry LIST


    cmp     K, #-6
bne     %END1
    .extern L3
dec     W
    .entry MAIN
jmp     %LOOP

mov 1,1
add     L3, L3

END: stop
    .extern L3




