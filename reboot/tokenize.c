#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "mycc.h"

char *read_text(char *file) {
	FILE *in = fopen(file, "r");
	fseek(in, 0, SEEK_END);
	long len = ftell(in);
	rewind(in);
	char *text = calloc(1, len);
	fread(text, len, 1, in);
	fclose(in);
	return text;
}

Token *tokenize(char *text) {
//	printf("text=[%s]\n", text);
	while (1) {
		char c = *text++;
		if (!c) {
			break;
		}
		if (isblank(c)) {
			continue;
		}
		printf("%c", c);
	}
	return 0;
}
