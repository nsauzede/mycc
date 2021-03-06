#ifndef DECL_H
#define DECL_H

int scan(struct token *t);
struct ASTnode *mkastnode(int op, struct ASTnode *left,
		struct ASTnode *right, int intvalue);
struct ASTnode *mkastleaf(int op, int intvalue);
struct ASTnode *mkuastunary(int op, struct ASTnode *left, int intvalue);
struct ASTnode *binexpr(void);
int interpretAST(struct ASTnode *n);

#endif/*DECL_H*/
