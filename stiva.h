#ifndef STIVA_H_INCLUDED
#define STIVA_H_INCLUDED
#include"stiva.h"
#include"lista.h"
typedef struct Stack {
    Node* top;
} Stack;
int isEmpty(Stack* stacke);
void freeStack(Stack* stacke);
void push(Stack* stacke, char* nod, double nota);
void pop(Stack* stacke);
Stack* createStack();
void printStack(FILE* fp, Stack* stacke);
#endif // STIVA_H_INCLUDED
