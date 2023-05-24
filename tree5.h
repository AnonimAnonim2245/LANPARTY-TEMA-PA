#ifndef TREE5_H_INCLUDED
#define TREE5_H_INCLUDED

#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include"tree5.h"
#include"stiva.h"
typedef struct Tree {
    char* nume;
    int height;
    float nota;
    struct Tree* left;
    struct Tree* right;
} Tree;
Tree* rightRotate(Tree* y);
Tree* leftRotate(Tree* x);
Tree* LRRotation(Tree *Z);
Tree* RLRotation(Tree *Z);
Tree* insertAVL(Tree* root, Node* nod, FILE* fp);
Tree* insertTree(Tree* root, Node* nod);
void inorderTraversal(FILE *fp,Tree* root);
void inorderTraversal2(FILE *fp,Tree* root,Stack* nod,int *z);
void inorderAVL(FILE *fp,Tree* root,int nivel);
Tree* createTree(Node* nod);
void freeTree(Tree* root);
int comparatieLexi(char *nume, char *nume2);
int maxi(int a, int b);
int height(Tree* node);
int getBalance(Tree* node);
#endif

#endif // TREE5_H_INCLUDED
