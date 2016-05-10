#include "arvore.hpp"

int main(){
  system("clear");
  int op, valor;
  ArvoreRaiz arvore;

  inicializaArvore(&arvore);
  printf("ARVORE AVL\n\n");
  printf("Pressione Enter\n\n");

  getchar();
  inicioprog();
  while (1) {
    system("clear");
    op = menu(op);

    switch (op) {
      case 1:{
        menuInsere();
        scanf("%d", &valor);
        inserirNaArvore(valor,&arvore);
        break;
      }
      case 2:{
        menuRemove();
        scanf("%d", &valor);
        removerDaArvore(valor,&arvore);
        break;
      }
      case 3:{
        system("clear");
        printf("\nElemento para buscar: ");
        scanf("%d", &valor);
        system("clear");
        buscarNaArvore(valor, &arvore);
        break;
      }
      case 4:{
        imprimir(&arvore, 1);
        printf("\n\n");
        fflush(stdin);
        getchar();
        getchar();
        break;
      }
      case 5:{
        imprimir(&arvore, 2);
        printf("\n\n");
        fflush(stdin);
        getchar();
        getchar();
        break;
      }
      case 6:{
        imprimir(&arvore, 3);
        printf("\n\n");
        fflush(stdin);
        getchar();
        getchar();
        break;
      }
      case 7:{
        system("clear");
        valor = calculaAltura(arvore.topo);
        printf("Altura: %d\n", valor);
        getchar();
        getchar();
        break;
      }
      case 0:{
        system("clear");
        printf("Bye Bye ;)\n\n");
        return 0;
        break;
      }
    }
  }


  getchar();
  return 0;
}
