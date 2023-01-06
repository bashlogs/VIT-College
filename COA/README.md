# COA - Computer Organization and Architecture

Command - nasm -f elf64 -o hello.o hello.asm && ld hello.o -o hello

To Create Object File : nasm -f elf64 -o hello.c hello.asm
To Create Executable file: ld hello.o -o hello

Complete overall program :- nasm -f elf64 -o add.o add.asm && ld add.o -o add

# Important Notes

An assembly program can be divided into three sections: 
    The data section
    The bss section
    The text section

## The data Section
The data section is used for declaring initialized data or constants. This data does not change at runtime. You can declare various constant values, file names, or buffer size, etc., in this section.

section.data

## The bss Section
The bss section is used for declaring variables. The syntax for declaring bss section is −

section.bss

## The text section
The text section is used for keeping the actual code. This section must begin with the declaration global _start, which tells the kernel where the program execution begins.

section.text
   global _start
_start:

## Comments ;

add rax, rbx     ; adds rbx to rax

# Memory Segments
A segmented memory model divides the system memory into groups of independent segments referenced by pointers located in the segment registers. Each segment is used to contain a specific type of data. One segment is used to contain instruction codes, another segment stores the data elements, and a third segment keeps the program stack.

Data segment − It is represented by .data section and the .bss. The .data section is used to declare the memory region, where data elements are stored for the program. This section cannot be expanded after the data elements are declared, and it remains static throughout the program.

The .bss section is also a static memory section that contains buffers for data to be declared later in the program. This buffer memory is zero-filled.

Code segment − It is represented by .text section. This defines an area in memory that stores the instruction codes. This is also a fixed area.

Stack − This segment contains data values passed to functions and procedures within the program.

# Assembly - Registers
Processor operations mostly involve processing data. This data can be stored in memory and accessed from thereon. However, reading data from and storing data into memory slows down the processor, as it involves complicated processes of sending the data request across the control bus and into the memory storage unit and getting the data through the same channel.

To speed up the processor operations, the processor includes some internal memory storage locations, called registers.
