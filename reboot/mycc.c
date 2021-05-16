#include "mycc.h"

int main(int argc, char *argv[]) {
  Context ctx;
  parse_args(&ctx, argc, argv);
  tokenize(&ctx);
  parse(&ctx);
  codegen(&ctx);
  return 0;
}
