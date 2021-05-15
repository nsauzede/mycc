#include <stdio.h>  // fopen, printf
#include <stdlib.h> // calloc, exit
#include <string.h> // memset

#include "mycc.h"

void parse_args(Context *ctx, int argc, char *argv[]) {
	memset(ctx, 0, sizeof(Context));
	int arg = 1;
	while (arg < argc) {
		ctx->file = argv[arg++];
	}
	if (!ctx->file) {
		printf("mycc: fatal error: no input files\n");
		printf("compilation terminated\n");
		exit(1);
	}
}
