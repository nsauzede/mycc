#include <stdio.h>
#include <stdlib.h>

#include "defs.h"
#define extern
#include "data.h"
#undef extern
#include "decl.h"

// List of printable tokens
char *tokstr[] = { "+", "-", "*", "/", "intlit" };

// Loop scanning in all the tokens in the input file.
// Print out details of each token found;
static void scanfile() {
	struct token T;
	while (scan(&T)) {
		printf("Token %s", tokstr[T.token]);
		if (T.token == T_INTLIT) {
			printf(", value %d", T.intvalue);
		}
		printf("\n");
	}
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Usage: %s <input_file>\n", argv[0]);
		exit(0);
	}
	Line = 1;
	Infile = fopen(argv[1], "r");
	scanfile();
	return 0;
}
