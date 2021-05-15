
test: mycc mycc.pp.c
	./mycc mycc.pp.c
	@echo "Ok"

%.pp.c: %.c
	$(CC) -E -o $@ $^