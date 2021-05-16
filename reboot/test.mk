
test: mycc mycc.c
	./mycc mycc.c
	@echo "Ok"

%.pp.c: %.c
	$(CC) -E -o $@ $^
