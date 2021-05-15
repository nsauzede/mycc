#include "mycc.h"

/*
tokenize
parse
optimize
codegen
*/

int main(int argc, char *argv[]) {
  Context ctx = {};
  parse_args(&ctx, argc, argv);
  char *text = read_text(ctx.file);
  Token *tokens = tokenize(text);
  ASTNode *ast = parse(tokens);
  codegen(ast);
  return 0;
}
