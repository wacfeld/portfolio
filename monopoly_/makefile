monopoly: monopoly.o random.o convert.o
	ld -o monopoly monopoly.o random.o convert.o
monopoly.o: monopoly.asm
	nasm -f elf -g -F dwarf monopoly.asm -l monopoly.lst
random.o: random.asm
	nasm -f elf -g -F dwarf random.asm -l random.lst
convert.o: convert.asm
	nasm -f elf -g -F dwarf convert.asm -l convert.lst
