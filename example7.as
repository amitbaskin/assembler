;file example7.as
;fail example
;example 3 mixed with second parse errors


    .extern W
    .extern L3
MAIN:add     r3, LIST
                    LOOP:prn     #48
    .entry LIST


lea     W, r6
inc     r6
    .entry LIST
STR:.string "abcd"
    .entry externAndEntryClash
mov     r3, K
sub     r1, r4

    .extern externAndEntryClash
bne     END
        .entry MAIN


LIST:.data 6, -9
dec undeclaredLabel
    .data -100

K:.data 31
    .entry LIST
    cmp     K, #-6
bne     %END
    .extern L3
dec     W

    .entry MAIN
jmp     %LOOP


add     L3, L3

    .entry entryAlone
END:stop
    .extern L3







