#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *left,*right;
    int ht;
}node;

node *insert(node *,int);
void  inorder(node *, FILE *f,int *d);
int   height( node *);
node *rotateright(node *);
node *rotateleft(node *);
node *RR(node *);
node *LL(node *);
node *LR(node *);
node *RL(node *);
int FE(node *);

node * insert(node *T,int x)
{
    if(T==NULL)
    {
        T=(node*)malloc(sizeof(node));
        T->data=x;
        T->left=NULL;
        T->right=NULL;
    }
    else
        if(x > T->data)                // insert in right subtree
        {
            T->right=insert(T->right,x);
            if(FE(T)==-2){
                if(x>T->right->data){
                    T=RR(T);
                }else{
                    T=RL(T);
                }
            }
        }
        else
            if(x<T->data)
            {
                T->left=insert(T->left,x);
                if(FE(T)==2){
                    if(x < T->left->data){
                        T=LL(T);
                    }else{
                        T=LR(T);
                    }
                }
            }
        T->ht=height(T);
    return(T);
}

int height(node *T)
{// Height off three
   int lh,rh;
   if(T==NULL)
      return(0);
   if(T->left==NULL)
      lh=0;
   else
      lh=1+T->left->ht;
   if(T->right==NULL)
      rh=0;
   else
      rh=1+T->right->ht;
   if(lh>rh)
      return(lh);
   return(rh);
}
node * rotateright(node *x)
{//Rotate Right
   node *y;
   y=x->left;
   x->left=y->right;
   y->right=x;
   x->ht=height(x);
   y->ht=height(y);
   return(y);
}
node * rotateleft(node *x)
{//Rotate Left
   node *y;
   y=x->right;
   x->right=y->left;
   y->left=x;
   x->ht=height(x);
   y->ht=height(y);
   return(y);
}
node * RR(node *T)
{
    T=rotateleft(T);
    return(T);
}
node * LL(node *T)
{
   T=rotateright(T);
   return(T);
}
node * LR(node *T)
{
   T->left=rotateleft(T->left);
   T=rotateright(T);
   return(T);
}
node * RL(node *T)
{
   T->right=rotateright(T->right);
   T=rotateleft(T);
   return(T);
}
int FE(node *T)
{
   int lh,rh;
   if(T==NULL)
   return(0);
   if(T->left==NULL)
      lh=0;
   else
      lh=1+T->left->ht;
   if(T->right==NULL)
      rh=0;
   else
      rh=1+T->right->ht;
   return(lh-rh);
}

void inorder(node *T, FILE *grafica2, int *d)
{
   if(T!=NULL)
   {
       clock_t inicio = clock();
       inorder(T->left, grafica2, d);

       printf("%d,",T->data);
       clock_t aux_f = clock();
       fprintf(grafica2, "%f %i \n", ((aux_f-inicio))/(float)CLOCKS_PER_SEC,(*d) );
       (*d)++;

       inorder(T->right, grafica2, d);
   }
}

void postorden(node *T)
{
    if(T!=NULL)
   {
      postorden(T->left);
      postorden(T->right);
      free(T);
   }
}

#endif // AVL_H_INCLUDED
