#include <stdio.h>  // fopen, printf
#include <stdlib.h> // calloc, exit, getenv
#include <string.h> // memset

#include "mycc.h"

void parse_args(Context *ctx, int argc, char *argv[]) {
	memset(ctx, 0, sizeof(Context));
	int error = 0;
	int arg = 1;
	while (arg < argc) {
		if (!strcmp("-E", argv[arg])) {
			arg++;
			ctx->preprocess_only = 1;
			continue;
		}
		if (!strcmp("-o", argv[arg])) {
			arg++;
			if (arg >= argc) {
				printf("mycc: error: missing filename after ‘-o’\n");
				error = 1;
				continue;
			}
			ctx->output_file = argv[arg++];
			continue;
		}
		ctx->input_file = argv[arg++];
	}
	if (!ctx->input_file) {
		printf("mycc: fatal error: no input files\n");
		printf("compilation terminated\n");
		error = 1;
	}
	if (error) {
		exit(1);
	}

	char *ppext = ".pp.c";
	long len = strlen(ctx->input_file) + strlen(ppext) + 1;
	char *ppfile = malloc(len);
	snprintf(ppfile, len, "%s%s", ctx->input_file, ppext);
//	printf("PREPROCESSING %s => %s\n", ctx->input_file, ppfile);
	char *cc = "cc";
	char *env = getenv("CC");
	if (env) {
		cc = env;
	}
//	printf("CC=%s\n", cc);
#define PP_FMT "%s -E -x c %s -o %s\n"
	len = snprintf(0, 0, PP_FMT, cc, ctx->input_file, ppfile);
	char *cmd = malloc(len + 1);
	snprintf(cmd, len, PP_FMT, cc, ctx->input_file, ppfile);
	FILE *p = popen(cmd, "r");
	while (!feof(p)) {
		char line[1000];
		memset(line, 0, sizeof(line));
		fgets(line, sizeof(line), p);
//		printf("%s\n", line);
	}
	pclose(p);
	if (ctx->preprocess_only) {
		exit(0);
	}

//	printf("READING %s\n", ppfile);
	FILE *in = fopen(ppfile, "r");
	fseek(in, 0, SEEK_END);
	len = ftell(in);
	rewind(in);
	ctx->text = calloc(1, len);
	fread(ctx->text, len, 1, in);
	fclose(in);
}
