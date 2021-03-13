;file example4.as
;fail example
;first parse errors
;declaring .extern and a regular label with the same label name
;declaring regular label twice
;line exceeds limit
;label name exceeds limit
;empty entry declaration
;empty extern declaration
;empty regular label declaration
;empty .data declaration
;empty .string declaration
;.data without space before num
;.data without comma between nums
;.data with comma before first num
;operator without comma between operands
;.data with wrong value
;.string without space before string
;.string without quatation marks
;.string without closing quation mark
;.string without opening quation mark
;illegal label begins with num
;illegal label with non-alphanumeric chars
;reg keyword label
;op keyword label
;jibrish statements

.extern externAndRegular
g
externAndRegular: stop


externAndRegular0: stop
rt
.extern externAndRegular0


MAIN: .data 5
rg
MAIN: .data 6


.string "012345678901234567890123456789012345678901234567890123456789012345678901"
gth
.extern 01234567890123456789012345678901


7rsrgsr: stop
FARSG$@%!$#%!SAGGGASG: stop
.entry
rwg
.extern
MAIN:
rh
.data
.string
.data5
thrt
.data 5 6
.data  , 7
rg
.data c
.string"hi"
gr
.string hi
add x x
d
.string "hi
.string hi"
r0: .data 5
thryj
dec: .data 7
add
