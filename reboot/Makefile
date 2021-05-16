
TARGETS:=mycc

#export CC:=tcc

#CFLAGS:=-std=c89
CFLAGS:=-std=c99
CFLAGS+=-pedantic
CFLAGS+=-Wall -Werror
CFLAGS+=-g -O0

CFLAGS+=-D_POSIX_C_SOURCE=2

all: $(TARGETS)

mycc: mycc.o args.o tokenize.o parse.o codegen.o
	$(CC) -o $@ $^

include test.mk

clean:
	$(RM) $(TARGETS) *.o *.pp.c
