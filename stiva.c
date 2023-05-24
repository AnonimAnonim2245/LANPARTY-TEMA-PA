#include"stiva.h"
#include"lista.h"
#include"coada.h"


int isEmpty(Stack* stack) {
    return stack->top == NULL;
}
void freeStack(Stack* stack) {
    while (stack->top != NULL) {
        Node* temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
}
void push(Stack* stack, char* nod, double nota) {
    Node* newNode = createNodeStiva(nod,nota);
    newNode->next = stack->top;
    stack->top = newNode;
}

void pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Eroare: Stiva este goala.\n");
        exit(1);
    }
    Node* topNode = stack->top;
    stack->top = topNode->next;
    free(topNode);
}
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}
void printStack(FILE* fp, Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stiva este goala.\n");
        return;
    }
    Node* current = stack->top;
    while (current != NULL) {
        int i;
        int j=0;
        while(j!=strlen(current->nume)){

            if(Caracter(current->nume[j])){
                fprintf(fp,"%c",current->nume[j]);
            }
            else
                fprintf(fp," ");
            j++;
        }

        i=j;
        while(i!=34)
        {
        fprintf(fp," ");
        i+=1;
        }
        fprintf(fp,"-");
        fprintf(fp,"  %.2f\n",current->nota);
        current = current->next;
    }
}
