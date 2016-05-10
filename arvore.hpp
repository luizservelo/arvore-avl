#include <stdio.h>
#include <stdlib.h>

typedef struct NoArvore{
    int dado;
    struct NoArvore *noEsquerdo;
    struct NoArvore *noDireito;
}NoArvore;

typedef struct ArvoreRaiz{
    NoArvore *topo;
}ArvoreRaiz;

void inicioprog();


void inicializaArvore(ArvoreRaiz *arvore);
NoArvore* criarNo(int numero);

//------------ROTACOES------------//
NoArvore* rotacaoSimplesEsquerda(NoArvore *raiz);
NoArvore* rotacaoSimplesDireita(NoArvore *raiz);

//------------BALANCEAMENTO------------//
NoArvore* balancearArvore(NoArvore *raiz);

int maior (int a, int b);

//------------ALTURA-------------------//
int calculaAltura(NoArvore *raiz);

int calculaFatorBalanceamento(NoArvore *raiz);

NoArvore* inserirElemento(int numero, NoArvore *raiz);

void inserirNaArvore(int numero, ArvoreRaiz* arvore);

void imprime_preordem(NoArvore *raiz);

void imprime_emordem(NoArvore *raiz);

void imprime_posordem(NoArvore *raiz);

void imprimir(ArvoreRaiz *arvore, int i);

NoArvore* maiorDosMenores(NoArvore *raiz);

NoArvore* menorDosMaiores(NoArvore *raiz);

int verificarFilhos(NoArvore *raiz);

NoArvore* excluirFilho(NoArvore *raiz);

NoArvore* removerElemento(int numero, NoArvore *raiz);

void removerDaArvore(int numero, ArvoreRaiz *arvore);

NoArvore* buscarElemento(int numero, NoArvore *raiz);

void buscarNaArvore(int numero, ArvoreRaiz *arvore);




int menu(int op);
void menuInsere();
void menuRemove();
