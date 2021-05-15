
TARGETS:=mycc

CC:=tcc

#CFLAGS:=-std=c89
CFLAGS:=-std=c99
CFLAGS+=-pedantic
CFLAGS+=-Wall -Werror

all: $(TARGETS)

mycc: mycc.o args.o tokenize.o parse.o codegen.o
	$(CC) -o $@ $^

include test.mk

clean:
	$(RM) $(TARGETS) *.o
