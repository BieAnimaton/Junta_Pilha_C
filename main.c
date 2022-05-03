/*---------------------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*--------------------------------------------------------------------------- */
#define tamanho 10  /* tamanho maximo da pilha */
/* -----------------------------------------------------------------------------
Estrutura PILHA ESTATICA
------------------------------------------------------------------------------*/

typedef struct pilha{
        int topo ;
        int item [tamanho] ;
} T_PILHA;



/* ---------------------------------------------------------------------------- */
int  inicializa (T_PILHA *p)
{
  (*p).topo = -1 ;
  return 0;
}


/* ---------------------------------------------------------------------------- */
int estado(T_PILHA p)
{
    if(p.topo == -1 )
       return 0;  /* pilha vazia */
    else {
       if (p.topo == tamanho-1 )
          return 1;   /* pilha cheia */
       else
          return 2;  /* pilha não vazia com capacidade de armazenamento */
    }
}



/* ---------------------------------------------------------------------------- */
int empilha(T_PILHA *p, int x) /* PUSH */
{
    int erro = estado (*p);
    if ((erro == 0) || (erro == 2))
    {
       (*p).topo++;
       (*p).item[(*p).topo]=x;/* empilhamento efetuado */
       return 0;
    }
    else
       return 1; /* impossivel empilhar. overflow */
}



/* ---------------------------------------------------------------------------- */
int desempilha(T_PILHA *p)   /* POP */
{
    int erro = estado (*p);
    if (erro != 0)
    {
      (*p).topo--;  /* desempilhamento efetuado */
       return 0;
    }
    else
       return 1; /* impossivel desempilhar. Underflow */
}



/* ---------------------------------------------------------------------------- */
int listar(T_PILHA p)
{  int i,erro;
    erro = estado (p);
    if ((erro == 1) || (erro ==2))
    {
       for (i=0; i<=p.topo; i++)
           printf("%d\\ ",p.item[i]);
       printf(" (Topo)\n");
       return 0;
    }
    else return 1;  /* nao possivel listar pois a pilha vazia */
}




/* ---------------------------------------------------------------------------- */
int obter_topo(T_PILHA p, int *dado)
{  int i;
    if(p.topo == -1 )
       return 1;   /* pilha vazia */
    else {
       *dado =  p.item[p.topo];
       return 0;
    }
}
/* ---------------------------------------------------------------------------- */



int transfere(T_PILHA p, T_PILHA *p2)
{
    int dado;
    T_PILHA paux;
    inicializa (&paux);

    /* transferir para pilha auxiliar */
    while (estado(p)!=0)
    {
      obter_topo(p, &dado);
      desempilha (&p);
      empilha (&paux, dado);
    }

    printf("\nLista da pilha auxiliar\n");
    listar (paux);
    printf("\n");



    /* transferir para pilha destino */
     while (estado(paux)!=0)
    {
      obter_topo(paux, &dado);
      desempilha (&paux);
      empilha (p2, dado);
    }
    return (0);
}
/* ---------------------------------------------------------------------------- */



int junta_pilhas (T_PILHA *P1, T_PILHA *P2, T_PILHA *P3)
{
    int dado;
    T_PILHA paux, paux2;

    inicializa (&paux);
    inicializa (&paux2);

    while (estado(*P2)!=0) {
      obter_topo (*P2, &dado);
      desempilha (P2);
      empilha (&paux2, dado);
    }

    while (estado(*P1)!=0) {
      obter_topo (*P1, &dado);
      desempilha (P1);
      empilha (&paux, dado);
    }




    while (estado(paux2)!=0) {
      obter_topo (paux2, &dado);
      desempilha (&paux2);
      empilha (P3, dado);
    }

    while (estado(paux)!=0) {
      obter_topo (paux, &dado);
      desempilha (&paux);
      empilha (P3, dado);
    }



    return (0);
}


int main(void)
{
    int info;
    int erro; /* valor de erro retornado pelas funcoes */
    T_PILHA p1, p2, p3;

    inicializa (&p1);
    inicializa (&p2);
    inicializa (&p3);

    //desempilha(&s);
    //obter_topo(s, &info);
    //transfere(s, &s2);
    //estado(s);

    empilha(&p1, 32);
    empilha(&p1, 2);
    empilha(&p1, 121);
    empilha(&p1, 5576);

    empilha(&p2, 8);
    empilha(&p2, 67);
    empilha(&p2, 43);
    empilha(&p2, 1);
    empilha(&p2, 6);

    printf("Pilha P1: ");
    listar(p1);

    printf("Pilha P2: ");
    listar(p2);

    junta_pilhas(&p1, &p2, &p3);

    printf("\n");
    printf("Pilha P3: ");
    listar(p3);
}
