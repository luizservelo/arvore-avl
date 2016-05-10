#include "arvore.hpp"

void inicioprog(){
  system("clear");
};

void inicializaArvore(ArvoreRaiz *arvore){
    arvore->topo = NULL;
};

NoArvore* criarNo(int numero){
    NoArvore* aux;
    aux = (NoArvore *) malloc (sizeof(NoArvore));
    aux->dado = numero;
    aux->noEsquerdo = NULL;
    aux->noDireito = NULL;
    return aux;
};

NoArvore* rotacaoSimplesEsquerda(NoArvore *raiz){
    NoArvore *aux = raiz->noDireito;

    raiz->noDireito = aux->noEsquerdo;
    aux->noEsquerdo = raiz;
    return aux;
};

NoArvore* rotacaoSimplesDireita(NoArvore *raiz){
    NoArvore *aux = raiz->noEsquerdo;

    raiz->noEsquerdo = aux->noDireito;
    aux->noDireito = raiz;
    return aux;
};

NoArvore* balancearArvore(NoArvore *raiz){
    if (raiz == NULL){
        return raiz;
    }
    if(calculaFatorBalanceamento(raiz) == 2){
        if(calculaFatorBalanceamento(raiz->noEsquerdo) == -1){
            raiz->noEsquerdo = rotacaoSimplesEsquerda(raiz->noEsquerdo);
        }
        raiz = rotacaoSimplesDireita(raiz);
    } else if(calculaFatorBalanceamento(raiz) == -2){
        if (calculaFatorBalanceamento(raiz->noDireito) == 1){
            raiz->noDireito = rotacaoSimplesDireita(raiz->noDireito);
        }
        raiz = rotacaoSimplesEsquerda(raiz);
    }
    return raiz;
};

int maior (int a, int b){
  if (a > b) {
    return a;
  }
  else {
    return b;
  }
}

int calculaAltura(NoArvore *raiz){
    if(raiz == NULL){
        return -1;
    } else {
        return (maior(calculaAltura(raiz->noEsquerdo),calculaAltura(raiz->noDireito)) + 1);
    }
}

int calculaFatorBalanceamento(NoArvore *raiz){
    if(raiz == NULL){
        return 0;
    }
    return (calculaAltura(raiz->noEsquerdo) - calculaAltura(raiz->noDireito));
}

NoArvore* inserirElemento(int numero, NoArvore *raiz){
    if(raiz == NULL){
        return criarNo(numero);
    }

    if (numero == raiz->dado) {
      printf("Dado existente\n");
      getchar();
      getchar();
      inicioprog();
    }

    if(numero < raiz->dado){
        raiz->noEsquerdo = inserirElemento(numero, raiz->noEsquerdo);
    }else if (numero > raiz->dado){
        raiz->noDireito = inserirElemento(numero, raiz->noDireito);
    }
    return balancearArvore(raiz);
}

void inserirNaArvore(int numero, ArvoreRaiz* arvore){
    arvore->topo = inserirElemento(numero, arvore->topo);
}

void imprime_preordem(NoArvore *raiz){
    if(raiz != NULL){
        printf("%d ", raiz->dado);
        imprime_preordem(raiz->noEsquerdo);
        imprime_preordem(raiz->noDireito);

    }
}

void imprime_emordem(NoArvore *raiz){
    if(raiz != NULL){

        imprime_emordem(raiz->noEsquerdo);
        printf("%d ", raiz->dado);
        imprime_emordem(raiz->noDireito);

    }
}


void imprime_posordem(NoArvore *raiz){
    if(raiz != NULL){

        imprime_posordem(raiz->noEsquerdo);
        imprime_posordem(raiz->noDireito);
        printf("%d ", raiz->dado);

    }
}


void imprimir(ArvoreRaiz *arvore, int i){
    system("clear");
    switch (i) {
      case 1:{
        printf("Arvore AVL em Pre Ordem:\n\n");
        imprime_preordem(arvore->topo);
        break;
      }
      case 2:{
        printf("Arvore AVL em Ordem:\n\n");
        imprime_emordem(arvore->topo);
        break;
      }
      case 3:{
        printf("Arvore AVL em Pos Ordem:\n\n");
        imprime_posordem(arvore->topo);
        break;
      }
    }
};

NoArvore* maiorDosMenores(NoArvore *raiz){
    if (raiz != NULL){
        if(raiz->noDireito != NULL){
            return maiorDosMenores(raiz->noDireito);
        }
    }
    return raiz;
}

NoArvore* menorDosMaiores(NoArvore *raiz){
    if(raiz != NULL){
        if(raiz->noEsquerdo != NULL){
            return menorDosMaiores(raiz);
        }
    }
    return raiz;
}

int verificarFilhos(NoArvore *raiz){
    if ((raiz->noEsquerdo == NULL && raiz->noDireito == NULL) || (raiz->noEsquerdo == NULL) || (raiz->noDireito == NULL))
        return 1;
    else return 0;
}

NoArvore* excluirFilho(NoArvore *raiz){
    if(raiz->noEsquerdo == NULL && raiz->noDireito == NULL){
        free(raiz);
        raiz = NULL;
    }else if(raiz->noEsquerdo == NULL) {
        NoArvore *aux = raiz;
        raiz = raiz->noDireito;
        free(aux);
    }else if(raiz->noDireito == NULL) {
        NoArvore *aux = raiz;
        raiz = raiz->noEsquerdo;
        free(aux);
    }
    return raiz;
}

NoArvore* removerElemento(int numero, NoArvore *raiz){
    if(raiz == NULL) {
        return raiz;
    }
    if (numero < raiz->dado){
        raiz->noEsquerdo = removerElemento(numero, raiz->noEsquerdo);
    }
    if (numero > raiz->dado){
        raiz->noDireito = removerElemento(numero, raiz->noDireito);
    }
    if (numero == raiz->dado) {
        if(verificarFilhos(raiz)){
            raiz = excluirFilho(raiz);
        }else{
            NoArvore *aux = raiz->noEsquerdo;
            aux = maiorDosMenores(aux);
            raiz->dado = aux->dado;
            aux->dado = numero;
            raiz->noEsquerdo = removerElemento(numero, raiz->noEsquerdo);
        }
    }
    return balancearArvore(raiz);
}

void removerDaArvore(int numero, ArvoreRaiz *arvore){
    arvore->topo = removerElemento(numero, arvore->topo);
}

NoArvore* buscarElemento(int numero, NoArvore *raiz){

	if (raiz != NULL){
		if (numero == raiz->dado ) {
			printf("Dado existente\n");
			getchar();
			getchar();
			inicioprog();
		}

		else if(numero < raiz->dado) {
		  buscarElemento(numero, raiz->noEsquerdo);
		}
		else if (numero > raiz->dado){
		  buscarElemento(numero, raiz->noDireito);
		}
	}
	else{
			printf("Dado Inexistente \n");
			getchar();
			getchar();
			inicioprog();
	}
}



void buscarNaArvore(int numero, ArvoreRaiz *arvore){

    ArvoreRaiz *aux = arvore;
    buscarElemento(numero, aux->topo);

}



int menu(int op){

	printf("1 - Inserir Elemento\n");
	printf("2 - Remover Elemento\n");
	printf("3 - Verifica Elemento\n");
	printf("4 - Imprimir Pre Ordem\n");
	printf("5 - Imprimir Em Ordem\n");
	printf("6 - Imprimir Pos Ordem\n");
	printf("7 - Mostrar Altura\n");
	printf("0 - Sair do Programa\n");

	printf("\n\nOpcao: ");
	scanf("%d", &op);

	return op;

};

void menuInsere(){
  int valor;
  system("clear");
  printf("Inserir Numero: ");


};

void menuRemove(){
  int valor;
  system("clear");
  printf("Remover Numero: ");


};
