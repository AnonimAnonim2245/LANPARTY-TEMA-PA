#include"lista.h"
#include"stiva.h"
#ifndef COADA_H
#define COADA_H

typedef struct Meci{
    float notaA,notaB;
    char *teamA,*teamB;
    struct Meci *next;

} Meci;
typedef struct {
    Meci* front;  // Primul element din coadă
    Meci* rear;   // Ultimul element din coadă
} Queue;
Meci* createNode2(Node* nod,Node* nod2);
Queue* initializeQueue();
int isQueueEmpty(Queue* queues);
void enqueue(Queue* queues, Node* nod, Node* nod2);
void dequeue(Queue* queues);
void printQueue(Queue* queues,FILE *f,Stack* win, Stack* lose);
Node* GasireNumere(Node* nod);
int clasement(int *numar);
int Caracter(char current);
int Caracter2(char current, char urmator);
int numarLitere(char* nume);
int PrimeleSpatii(FILE *f,int i);
void SpatiileUrmatoare(FILE *f,int i,int z);
void CitireLitere(FILE *f,char *nume);
void GasireEchipe(Queue* queues, Node* nod,FILE* f);
#endif
