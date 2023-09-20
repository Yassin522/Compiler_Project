#include "ast.h"

ASTNode *createASTNode(ASTNodeType type) {
  ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
  node->type = type;
  node->leftChild = NULL;
  node->rightSibling = NULL;
  return node;
}

void printAST(ASTNode *node, int indent) {
  if (node == NULL) {
    printf("AAAAAAAAAAAAAAAAAAA\n");
      return;

  }
  for (int i = 0; i < indent; i++) printf(" ");
  switch (node->type) {
    case NODE_PROGRAM:
      printf("Program\n");
      break;
    case NODE_DECLARATION_LIST:
      printf("Declaration List\n");
      break;
    case NODE_DECLARATION:
      printf("Declaration\n");
      break;
    case NODE_VARIABLE_DECLARATION:
      printf("Variable Declaration\n");
      break;
    case NODE_VARIABLE_DECLARATION_LIST:
      printf("Variable Declaration List\n");
      break;
    case NODE_VARIABLE_DECLARATION_IDENTIFIER:
      printf("Variable Declaration Identifier\n");
      break;
    case NODE_TYPE_SPECIFIER:
      printf("Type Specifier\n");
      break;
    case NODE_FUNCTION_DECLARATION:
      printf("Function Declaration\n");
      break;
        case NODE_PARAMETER_TYPE_LIST:
      printf("Parameter Type List\n");
      break;
    case NODE_PARAMETER_LIST:
      printf("Parameter List\n");
      break;
    case NODE_PARAMETER_DECLARATION:
      printf("Parameter Declaration\n");
      break;
    case NODE_COMPOUND_STATEMENT:
      printf("Compound Statement\n");
      break;
    case NODE_STATEMENT_LIST:
      printf("Statement List\n");
      break;
    case NODE_STATEMENT:
      printf("Statement\n");
      break;
    case NODE_EXPRESSION_STATEMENT:
      printf("Expression Statement\n");
      break;
    case NODE_SELECTION_STATEMENT:
      printf("Selection Statement\n");
      break;
    case NODE_ITERATION_STATEMENT:
      printf("Iteration Statement\n");
      break;
    case NODE_JUMP_STATEMENT:
      printf("Jump Statement\n");
      break;
    case NODE_EXPRESSION:
      printf("Expression\n");
      break;
    case NODE_ASSIGNMENT_EXPRESSION:
      printf("Assignment Expression\n");
      break;
    case NODE_ADDITION_EXPRESSION:
      printf("Addition Expression\n");
      break;

          case NODE_MULTIPLICATION_EXPRESSION:
      printf("Multiplication Expression\n");
      break;
    case NODE_PRIMARY_EXPRESSION:
      printf("Primary Expression\n");
      break;

    case NODE_D:
     printf("D rule");
     break; 
    case NODE_ID:
      printf("ID: %s\n", node->value.stringValue);
      break;
    // case NODE_CONSTANT:
    //   switch (node->value.intValue) {
    //     case INT:
    //       printf("INT: %d\n", node->value.intValue);
    //       break;
    //     case FLOAT:
    //       printf("FLOAT: %f\n", node->value.floatValue);
    //       break;
    //     case CHAR:
    //       printf("CHAR: %c\n", (char)node->value.intValue);
    //       break;
    //     case STRING:
    //       printf("STRING: %s\n", node->value.stringValue);
    //       break;
    //   }
    //   break;
  }
  printAST(node->leftChild, indent + 2);
  printAST(node->rightSibling, indent);
}


int eval(ASTNode *node) {
  if (node == NULL) return 0;
  switch (node->type) {
    case NODE_PROGRAM:
      return eval(node->leftChild);
      break;
    case NODE_DECLARATION_LIST:
      return eval(node->leftChild) + eval(node->rightSibling);
      break;
    case NODE_DECLARATION:
      return eval(node->leftChild);
      break;
    case NODE_VARIABLE_DECLARATION:
      return eval(node->leftChild) + eval(node->rightSibling);
      break;
    case NODE_VARIABLE_DECLARATION_LIST:
      return eval(node->leftChild) + eval(node->rightSibling);
      break;
    case NODE_VARIABLE_DECLARATION_IDENTIFIER:
      return eval(node->leftChild) + eval(node->rightSibling);
      break;
    case NODE_TYPE_SPECIFIER:
      return 0;
      break;
    case NODE_FUNCTION_DECLARATION:
      return eval(node->leftChild) + eval(node->rightSibling);
      break;
    case NODE_PARAMETER_TYPE_LIST:
      return eval(node->leftChild) + eval(node->rightSibling);
      break;
    case NODE_PARAMETER_LIST:
      return eval(node->leftChild) + eval(node->rightSibling);
      break;
    case NODE_PARAMETER_DECLARATION:
      return eval(node->leftChild);
      break;
    case NODE_COMPOUND_STATEMENT:
      return eval(node->leftChild);
      break;
    case NODE_STATEMENT_LIST:
      return eval(node->leftChild) + eval(node->rightSibling);
      break;
    case NODE_STATEMENT:
      return eval(node->leftChild);
      break;
    case NODE_EXPRESSION_STATEMENT:
      return eval(node->leftChild);
      break;
    case NODE_SELECTION_STATEMENT:
      return eval(node->leftChild) + eval(node->rightSibling);
      break;
    case NODE_ITERATION_STATEMENT:
      return eval(node->leftChild);
      break;
    case NODE_JUMP_STATEMENT:
      return eval(node->leftChild);
      break;
    case NODE_EXPRESSION:
      return eval(node->leftChild);
      break;
    case NODE_ASSIGNMENT_EXPRESSION:
      return eval(node->leftChild) + eval(node->rightSibling);
      break;
    case NODE_ADDITION_EXPRESSION:
      return eval(node->leftChild) + eval(node->rightSibling);
      break;
    case NODE_MULTIPLICATION_EXPRESSION:
      return eval(node->leftChild) * eval(node->rightSibling);
      break;
    case NODE_PRIMARY_EXPRESSION:
      return eval(node->leftChild);
      break;
    case NODE_ID:
      return 0;
      break;
    case NODE_CONSTANT:
      return node->value.intValue;
      break;
    default:
      return 0;
      break;

}
}



