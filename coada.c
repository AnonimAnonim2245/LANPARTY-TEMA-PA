
#include"coada.h"
#include"lista.h"
Meci* createNode2(Node* nod,Node* nod2) {
    Meci* newNode = (Meci*)malloc(sizeof(Meci));

    if (newNode == NULL) {
    printf("Alocarea memoriei a esuat\n");
    exit(1);
    }
    newNode->teamA = (char *)malloc(100 * sizeof(char));
    newNode->teamB = (char *)malloc(100 * sizeof(char));
    newNode->teamA = strdup(nod->nume);
    newNode->teamB = strdup(nod2->nume);

    newNode->notaA=nod->nota;
    newNode->notaB=nod2->nota;
    newNode->next = NULL;
    return newNode;
}
// Inițializează o coadă goală
Queue* initializeQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("A esuat alocarea memoriei pentru crearea cozii.\n");
        exit(EXIT_FAILURE);
    }

    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Verifică daca coada este goala
int isQueueEmpty(Queue* queue) {
    return queue->front == NULL;
}
// Updateaza coada
void enqueue(Queue* queue, Node* nod, Node* nod2) {

    Meci* newNode = createNode2(nod,nod2);
    if (isQueueEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Elimina un element din coada si il returneaza
void dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Eroare: coada este goala!\n");
        return;  // Valoare invalida pentru a indica o eroare
    }

    // Muta front la următorul nod si eliberează memoria pentru fostul prim nod
    Meci* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);

    // Verifica dacă coada a devenit goala si updateaza rear-ul
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
}
void printQueue(Queue* queue,FILE *f,Stack* win, Stack* lose) {

    if (isQueueEmpty(queue)) {
        printf("Coada este goala!\n");
        return;
    }
    Meci* current = queue->front;
    while (current != NULL) {
        if(current->teamA==NULL || current->teamB==NULL)
            return;
        float a = current->notaA;
        float b = current->notaB;
        if(a>b)
        {
            push(win,current->teamA,a+1);
            push(lose,current->teamB,b);
        }
        else
        {
            push(win,current->teamB,b+1);
            push(lose,current->teamA,a);
        }
        current = current->next;
    }

    if(current==NULL)
        return;

}
int clasement(int *numar)
{
    if(*numar==16)
    {
        *numar = *numar/2;
        return 1;
    }
    *numar=*numar/2;
    return 0;

}

int Caracter(char current)
{
    if((current!='\n') && (current!='\r') && (current!='\0'))
        return 1;
    return 0;
}
int Caracter2(char current, char urmator)
{
    if((current!='\n') && (current!='\0') && (current!='\r') && (current!='\r'))
    {
        if(current==' ')
        {

        if((urmator=='\n') || (urmator=='\0') || (urmator=='\r') || (urmator==' '))
            return 0;
        else
            return 1;
        }
        else
            return 1;

    }
    return 0;
}
int numarLitere(char* nume)
{
    int j=0;
    int z=0;
    while(j!=strlen(nume))
    {
      if(Caracter2(nume[j],nume[j+1]))
        z=j+1;
      j++;
    }
    return z;
}
int PrimeleSpatii(FILE *f,int i)
{
    while(i!=33)
    {
        fprintf(f," ");
        i+=1;
    }
    return i;
}
void SpatiileUrmatoare(FILE *f,int i,int z)
{
    while(i!=67-z)
    {
        fprintf(f," ");
        i+=1;
    }
}
void CitireLitere(FILE *f,char *nume)
{
    int j=0;
    while(j!=strlen(nume)){
       if(Caracter2(nume[j],nume[j+1]))
          fprintf(f,"%c",nume[j]);
       j++;
    }
}

void GasireEchipe(Queue* queue, Node* nod,FILE* f)
{
    if(nod==NULL)
        return;
    int j=0;
    while(j!=strlen(nod->nume)){
      if(Caracter(nod->nume[j]))
         fprintf(f,"%c",nod->nume[j]);
      else
          fprintf(f," ");
      j++;
    }

    int i=j;
    i=PrimeleSpatii(f,i);
    fprintf(f,"-");
    int z = numarLitere(nod->next->nume);

    SpatiileUrmatoare(f,i+1,z);
    CitireLitere(f,nod->next->nume);
    fprintf(f,"\n");
    enqueue(queue, nod, nod->next);
    GasireEchipe(queue,nod->next->next,f);
}
