#include <stdio.h>
#include <stdlib.h>

struct arv {
  int info;
  struct arv* esq;
  struct arv* dir;
};

typedef struct arv Arv;

Arv* busca (Arv* r, int v)
{
  if (r == NULL) return NULL;
  else if (r->info > v) return busca(r->esq,v);
  else if (r->info < v) return busca(r->dir,v);
  else return r;
}


Arv* insere (Arv* a, int v)
{
  if (a==NULL) {
    a = (Arv*)malloc(sizeof(Arv));
    a->info = v;
    a->esq = a->dir = NULL;
  }
  else if (v < a->info)
    a->esq = insere(a->esq,v);
  else /* v < a->info */
    a->dir = insere(a->dir,v);
  return a;
}


Arv* libera (Arv* a){
  if (a != NULL){
    libera(a->esq); /* libera sae */
    libera(a->dir); /* libera sad */
    free(a); /* libera raiz */
  }
  return NULL;
}


void imprime_in (Arv* r)
{
   if (r != NULL) {
     imprime_in(r->esq);
     printf("%d ", r->info);
     imprime_in(r->dir);
  }

}



void main(void)
{
   Arv* arv = NULL;
   
   arv = insere(arv,43);
   arv = insere(arv,22);
   arv = insere(arv,21);
   arv = insere(arv,58);
   arv = insere(arv,45);
   arv = insere(arv,66);
   arv = insere(arv,31);
   arv = insere(arv,71);
   arv = insere(arv,59);
   arv = insere(arv,12);
   arv = insere(arv,35);
   imprime_in(arv);
   printf("\n");
   
   
   arv = insere(arv,1);
   imprime_in(arv);
   printf("\n");
   
   arv = insere(arv,2);
   imprime_in(arv);
   printf("\n");
   
   arv = insere(arv,3);
   imprime_in(arv);
   printf("\n");
   
   arv = insere(arv,5);
   imprime_in(arv);
   printf("\n");
   
   arv = insere(arv,15);
   imprime_in(arv);
   printf("\n");
   
   arv = insere(arv,7);
   imprime_in(arv);
   printf("\n");
   
   if (busca(arv, 2)){
      printf("2 Encontardo\n");
   }
   
   else {
       printf("2 Não encontrado\n");
   }
   
   if (busca(arv, 8)){
      printf("8 Encontrado\n");
   }
   
   else {
       printf("8 Não encontrado\n");
   }
   
   return 0;
   
   
   
   


}


























