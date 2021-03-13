;file example3.as
;the same as example2 except:
;   --data appears before the end
;   --no space after colon in label declaration
;   --multiple .entry declarations with the same label name
;   --multiple .extern declarations with the same label name


    .entry LIST
    .extern W
    .extern L3
MAIN: add     r3, LIST
LOOP: prn     #48
lea     W, r6
inc     r6
    .entry LIST
STR: .string "abcd"
mov     r3, K
sub     r1, r4
bne     END
    .entry MAIN
LIST: .data 6, -9
    .data -100
K: .data 31
    .entry LIST
cmp     K, #-6
bne     %END
    .extern L3
dec     W
    .entry MAIN
jmp     %LOOP
add     L3, L3
END: stop
    .extern L3
