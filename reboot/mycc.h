
typedef struct Token Token;
struct Token {
	Token *next;
};

typedef struct ASTNode ASTNode;
struct ASTNode {
	ASTNode *next;
};

typedef struct Context {
	char *file;
} Context;

char *read_text(char *file);

Token *tokenize(char *text);

ASTNode *parse(Token *tokens);

void codegen(ASTNode *ast);

void parse_args(Context *ctx, int argc, char *argv[]);
