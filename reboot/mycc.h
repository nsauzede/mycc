
typedef enum {
	TK_IDENT,
} TokenType;
typedef struct Token Token;
struct Token {
	TokenType type;
	Token *next;
};

typedef struct ASTNode ASTNode;
struct ASTNode {
	ASTNode *next;
};

typedef struct Context {
	char *input_file;
	char *output_file;
	int preprocess_only;

	char *text;
	Token *tokens;
	ASTNode *ast;
} Context;

void parse_args(Context *ctx, int argc, char *argv[]);
void tokenize(Context *ctx);
void parse(Context *ctx);
void codegen(Context *ctx);
