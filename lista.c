#include"lista.h"

Node *createNode(char *nume, float pct, float numar) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("Alocarea memoriei a esuat\n");
    exit(1);
  }
  newNode->nume = (char *)malloc(100 * sizeof(char));
  strncpy(newNode->nume, nume, 100);
  newNode->puncte = pct;
  newNode->numar = numar;
  newNode->nota = (pct)/numar;
  newNode->next = NULL;
  return newNode;
}

Node *createNodeStiva(char *nume, float nota) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("Alocarea memoriei a esuat.\n");
    exit(1);
  }
  newNode->nume = (char *)malloc(100 * sizeof(char));
  strncpy(newNode->nume, nume, 100);
  newNode->nota = nota;
  newNode->next = NULL;
  return newNode;
}
void insertNode(Node **head, char *nume, int pct, int numar) {
  Node *newNode = createNode(nume, pct,numar);
  newNode->next = *head;
  *head = newNode;
}
void traverse(FILE *pf, Node *head) {
  if (head == NULL)
    return;

  fprintf(pf, "%s", head->nume);
  traverse(pf, head->next);
}
float Maximul(Node* nod)
{
  float maxim=0;
  while(nod!=NULL)
  {
    if(maxim<nod->nota)
    {
      maxim = nod->nota;
    }
    nod=nod->next;
  }
  return maxim;
}
int Minimul(Node *nod) {
  int mini = -1, index, i = 1;

  while (nod != NULL) {

    if ((mini == -1) || (mini > nod->puncte)){
      index = i;
      mini = nod->puncte;
    }
    nod = nod->next;
    i += 1;
  }
  return index;
}

void freeNode(Node* node) {
    Node* current = node;
    while (current != NULL) {
        Node* nod = current;
        current = current->next;
        free(nod);
    }
}
void ElimMin(Node** head, int i)
{
    if(*head==NULL)
      return;

    Node* headcopy;
    Node* prev;
    headcopy = *head;
    prev = *head;
    if (i == 1) {
            *head = (*head)->next;
            free(headcopy);
            return;
    }
    headcopy = headcopy->next;
    int j=2;
    while (j<=i) {

            if (j == i  && headcopy!=NULL) {
                prev->next = headcopy->next;
                free(headcopy);
                return;
            }
            else {
                prev = headcopy;
                headcopy = headcopy->next;
            }
            if (prev == NULL)
                    return;

        j+=1;
    }
}
