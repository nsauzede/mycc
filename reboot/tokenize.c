#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "mycc.h"

static int is_ident0(char c) {
	return isalpha(c) || c == '_';
}

static int is_ident1(char c) {
	return isdigit(c) || is_ident0(c);
}

void tokenize(Context *ctx) {
//	printf("text=[%s]\n", text);
	Token head;
	memset(&head, 0, sizeof(head));
	char *p = ctx->text;
	while (*p) {
		if (*p == '#') {
			while (*p) {
				if (*p++ == '\n') {
					break;
				}
			}
			continue;
		}
		if (isblank(*p)) {
			p++;
			continue;
		}
		if (is_ident0(*p)) {
			char *ident = p;
			p++;
			while (*p) {
				if (!is_ident1(*p++)) {
					break;
				}
			}
			p--;
			char oldc = *p;
			*p = 0;
			printf("IDENT(%s) ", ident);
			*p = oldc;
			p++;
			continue;
		}
		printf("%c", *p);
		p++;
	}
	ctx->tokens = head.next;
}
