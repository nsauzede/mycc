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
void scanfile() {
	struct token T;
	while (scan(&T)) {
		printf("Token %s", tokstr[T.token]);
		if (T.token == T_INTLIT) {
			printf(", value %d", T.intvalue);
		}
		printf("\n");
	}
}

// Initialise global variables
static void init() {
  Line = 1;
  Putback = '\n';
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
		exit(0);
	}
	init();
	Infile = fopen(argv[1], "r");
	scan(&Token);
	struct ASTnode *n = binexpr();
	printf("Result=%d\n", interpretAST(n));
	return 0;
}
