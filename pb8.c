#include"lista.h"
#include"coada.h"
#include"stiva.h"
#include"tree5.h"



Node *CerI(FILE *pf, FILE *r, int *n) {

  int numar, numar_echipa, t = 0, i = 0, pct_total;
  struct echipa echipa;
  struct Player player;
  char caract;
  echipa.nume = (char *)malloc(100 * sizeof(char));
  player.firstName = (char *)malloc(100 * sizeof(char));
  player.secondName = (char *)malloc(100 * sizeof(char));
  fscanf(pf, "%d", &numar);
  *n = numar;
  Node *head = NULL;
  while (i != numar) {
    fscanf(pf, "%d", &numar_echipa);
    fscanf(pf, "%c", &caract);
    fgets(echipa.nume, 100, pf);
    t = 0, pct_total = 0;
    while (t != numar_echipa) {
      fscanf(pf, "%99s", player.firstName);
      fscanf(pf, "%99s", player.secondName);
      fscanf(pf, "%d", &player.points);
      pct_total += player.points;
      t += 1;
    }
    insertNode(&head, echipa.nume, pct_total,numar_echipa);

    i += 1;
  }
  free(player.firstName);
  free(player.secondName);
  fclose(pf);

  return head;
}


Node *CerII(FILE *pf, Node *nod, int *nr) {

  int i, j = 1, p = 1;
  while (p * 2 <= *nr) {
    p = p * 2;
  }
  while (j <= *nr - p) {
    i = Minimul(nod);
    ElimMin(&nod, i);
    j += 1;
  }
  *nr = p;
  return nod;
}


void CerIII(FILE *ge,Node *nod,int numar,Stack *top8){
  int i=1;
  Stack *winners, *losers;
  winners=createStack();
  losers = createStack();
  Queue* queue=initializeQueue();
  fprintf(ge,"\n--- ROUND NO:%d\n",i);
  GasireEchipe(queue,nod,ge);
  if(clasement(&numar))
    printQueue(queue,ge,top8,losers);

  printQueue(queue,ge,winners,losers);
  fprintf(ge,"\nWINNERS OF ROUND NO:%d\n",i);
  printStack(ge,winners);
  i+=1;
  while(winners->top->next!=NULL){
      while(!isEmpty(losers)){
        pop(losers);}
      while(!isQueueEmpty(queue)){
          dequeue(queue);}
      fprintf(ge,"\n--- ROUND NO:%d\n",i);
      GasireEchipe(queue,winners->top,ge);

      while(!isEmpty(winners))
            pop(winners);
      if(clasement(&numar))
      {
            printQueue(queue,ge,top8,losers);
      }

      printQueue(queue,ge,winners,losers);
      fprintf(ge,"\nWINNERS OF ROUND NO:%d\n",i);
      i+=1;
      printStack(ge,winners);
  }
  pop(winners);
  pop(losers);
  dequeue(queue);
}

Tree* CerIV(FILE *fp, Stack* top8)
{
    Tree* root = NULL;
    fprintf(fp,"\nTOP 8 TEAMS:\n");
    while(top8->top!=NULL)
    {
        root = insertTree(root, top8->top);
        top8->top=top8->top->next;
    }
    inorderTraversal(fp,root);
    freeStack(top8);
  //  freeNode(nod);

    return root;
}


void CerV(FILE* fp, Tree* top8)
{
    Tree* root = NULL;
    Stack* bst_ordonat=createStack();
    inorderTraversal2(fp,top8,bst_ordonat,0);
    fprintf(fp,"\nTHE LEVEL 2 TEAMS ARE:\n");
    while(bst_ordonat->top!=NULL)
    {
        root = insertAVL(root,bst_ordonat->top,fp);
        bst_ordonat->top=bst_ordonat->top->next;
    }
    inorderAVL(fp,root,0);

}
int main(int argc, char *argv[]) {
  int a, b, c, d, e, numar;
  Node *nod;
  Tree *BST = (Tree*)malloc(sizeof(Tree));
  Stack *top8;
  top8 = createStack();
  FILE *pf, *de, *ge;
  if ((de = fopen(argv[2], "r+t")) == NULL ||(ge = fopen(argv[3], "w+t")) == NULL || (pf = fopen(argv[1], "r+t")) == NULL) {
    printf("Unul sau ambele fisiere nu poate/pot fi deschis/e !\n");
  }
  if (pf == NULL) {
    printf("Failed to open the file");
    exit(1);
  }
  fscanf(pf, "%d %d %d %d %d", &a, &b, &c, &d, &e);
  fclose(pf);
  if (a == 1)
    nod = CerI(de, ge, &numar);
  if (b == 1)
    nod = CerII(ge, nod, &numar);
  traverse(ge, nod);
  if(c==1)
    CerIII(ge,nod,numar,top8);
  freeNode(nod);
  if(d==1)
  {
    BST = CerIV(ge,top8);
  }
  freeStack(top8);
  if(e==1)
  {
      CerV(ge,BST);
  }
  freeTree(BST);
  return 0;

}
