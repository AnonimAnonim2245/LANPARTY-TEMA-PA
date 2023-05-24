#include"stiva.h"
#include"tree5.h"
#include"coada.h"
void freeTree(Tree* root) {
    if (root == NULL) {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

Tree* insertTree(Tree* root, Node* nod) {
    if (root == NULL) {
        root = createTree(nod);
    } else if(comparatieLexi(nod->nume, root->nume)==1  && (nod->nota == root->nota))
    {
      root->right = insertTree(root->right, nod);
    }
    else if ((nod->nota > root->nota)) {
        root->right = insertTree(root->right, nod);
    } else {
        root->left = insertTree(root->left, nod);
    }
    return root;
}
Tree* createTree(Node* nod) {
    Tree* newNode = (Tree*)malloc(sizeof(Tree));
    newNode->nume = (char*)malloc(100*sizeof(char));
    newNode->nume = strdup(nod->nume);
    newNode->nota = nod->nota;
    newNode->height = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Tree* rightRotate(Tree* y) {
    Tree* x = y->left;
    Tree* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = maxi(height(y->left), height(y->right)) + 1;
    x->height = maxi(height(x->left), height(x->right)) + 1;

    return x;
}

Tree* leftRotate(Tree* x) {
    Tree* y = x->right;
    Tree* T2 = y->left;

    y->left = x;
    x->right = T2;
    x->height = maxi(height(x->left), height(x->right)) + 1;
    y->height = maxi(height(y->left), height(y->right)) + 1;

    return y;
}
Tree * LRRotation (Tree *Z)
{
    Z->left = leftRotate(Z->left );
    return rightRotate(Z);
}

Tree * RLRotation ( Tree *Z)
{

    Z->right = rightRotate(Z->right );
    return leftRotate(Z);
}
Tree* insertAVL (Tree* root, Node* nod, FILE* fp)
{
    if(root==NULL)
        return createTree(nod);

    if ((nod->nota<root->nota) || (nod->nota==root->nota && strcmp(root->nume,nod->nume)>0))
    {
        root->left=insertAVL(root->left,nod,fp);
    }
    else if((nod->nota>root->nota) || (nod->nota==root->nota && strcmp(root->nume,nod->nume)<0))
    {
        root->right=insertAVL(root->right,nod,fp);
    }

    root->height = 1 + maxi(height(root->left), height(root->right));

    int height = getBalance(root);
    if (height>1){
        if((nod->nota<root->left->nota) || (nod->nota==root->left->nota && strcmp(root->left->nume,nod->nume)>0))
            return rightRotate(root);
        else if((nod->nota>root->left->nota) || (nod->nota==root->left->nota && strcmp(root->left->nume,nod->nume)<0))
            return LRRotation(root);

    }
    if (height<-1){
        if((nod->nota<root->right->nota) || (nod->nota==root->right->nota && strcmp(root->right->nume,nod->nume)>0))
            return RLRotation(root);
        else if((nod->nota>root->right->nota) || (nod->nota==root->right->nota && strcmp(root->right->nume,nod->nume)>0))
            return leftRotate(root);

    }
    return root;
}

void inorderTraversal(FILE *fp,Tree* root) {
    if (root == NULL) {
        return;

    }
    inorderTraversal(fp,root->right);

    int j=0;
    while(j!=strlen(root->nume)){

        if(Caracter(root->nume[j])){
            fprintf(fp,"%c",root->nume[j]);

        }
        else
            fprintf(fp," ");
        j++;
        }

        int i=j;
        while(i!=34)
        {
        fprintf(fp," ");
        i+=1;
        }
    fprintf(fp,"-");
    fprintf(fp,"  %.2f\n",root->nota);
    inorderTraversal(fp,root->left);
}
void inorderTraversal2(FILE *fp,Tree* root,Stack* stiva,int *z) {
    if (root == NULL) {
            return;
    }
    inorderTraversal2(fp,root->left,stiva,z);
    push(stiva,root->nume,root->nota);
    inorderTraversal2(fp,root->right,stiva,z);


}

void inorderAVL(FILE *fp,Tree* root,int nivel) {
    if(root==NULL) return;
    if(nivel==2)
    {
        fprintf(fp,"%s",root->nume);
    }
    else if(nivel<2)
    {
        inorderAVL(fp,root->right,nivel+1);
        inorderAVL(fp,root->left,nivel+1);
    }
}


int comparatieLexi(char *nume, char *nume2)
{
    int i=0;
    while(i<strlen(nume) && i<strlen(nume2))
    {
      if(nume[i]>nume2[i])
        return 1;
      if(nume[i]<nume2[i])
        return 0;
      i=i+1;
    }
    if(strlen(nume)>strlen(nume2))
      return 1;
    return 0;
}

int maxi(int a, int b) {
    return (a > b) ? a : b;
}

int height(Tree* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

int getBalance(Tree* node) {
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);
}
