#include <stdio.h>
#include <ctype.h>

#include "mycc.h"

void tokenize(Context *ctx) {
//	printf("text=[%s]\n", text);
	while (1) {
		char c = *ctx->text++;
		if (!c) {
			break;
		}
		if (c == '#') {
			while (c != '\n') {
				c = *ctx->text++;
			}
			if (!c) {
				break;
			}
			continue;
		}
		if (isblank(c)) {
			continue;
		}
		printf("%c", c);
	}
}
