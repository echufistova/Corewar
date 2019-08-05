.name "Only 10"
.comment "I can't count more than 10"

sti r1, %:live1, %1
sti r1, %:live2, %1
ld %1, r3
ld %1, r2

cycle:
add r2, r3, r2
xor r2, %9, r4
live1:	live %1
fork %:live2
zjmp %:quit
ld %0, r5
zjmp %:cycle

quit:
ld %0, r4
live2:
	live %1
	ld %0, r5
	zjmp %:live2
