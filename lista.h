#ifndef LISTA_H
#define LISTA_H
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

struct echipa {
  int numar;
  char *nume;
};
struct Player {
  char *firstName;
  char *secondName;
  int points;
};
typedef struct Node {
  char *nume;

  float puncte, contor, numar;
  float nota;
  struct Node *next;
} Node;
void freeNode(Node* node);
Node *createNode(char *nume, float pct, float numar);
Node *createNodeStiva(char *nume, float nota);
void insertNode(Node **head, char *nume, int pct, int numar);
void traverse(FILE *pf, Node *head);
int Minimul(Node *nod);
void ElimMin(Node **nod, int i);
float Maximul(Node* nod);
#endif
