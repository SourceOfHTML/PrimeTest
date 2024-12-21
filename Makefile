C_FILES = $(wildcard *.c)
O_FILES = $(C_FILES:%.c=%.o)

PrimeTester: $(O_FILES)
