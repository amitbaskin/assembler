;file example6.as
;fail example
;second parse errors
;declaring .entry without regular label declaration
;.extern and .entry clash
;using undeclared label


.entry entryAlone

.entry externAndEntryClash
.extern externAndEntryClash

dec undeclaredLabel
