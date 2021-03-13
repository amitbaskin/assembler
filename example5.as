;file example6.as
;fail example
;second parse errors
;declaring .entry without regular label declaration
;.extern and .entry clash
;using undeclared label
;registers with wrong numbers

add r8, r9
.entry entryAlone

.entry externAndEntryClash
.extern externAndEntryClash

dec undefinedLabel
