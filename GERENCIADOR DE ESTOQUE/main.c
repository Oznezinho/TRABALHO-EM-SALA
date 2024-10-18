#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char descricao[50];
  float valor;
  int qtdd;
} Produto;

void cadastrarProduto(Produto c) {
  printf("\nCadastrar Produto: \n");
  printf("\nDescrição: \n");
  fgets(c.descricao, sizeof(c.descricao), stdin);
  c.descricao[strcspn(c.descricao, "\n")] = 0;

  printf("\nValor: \n");
  scanf("%f", &c.valor);

  printf("\nQuantidade: \n");
  scanf("%d", &c.qtdd);
  printf("\n");
}

void salvarProduto(Produto c) {
  FILE *arquivo = fopen("produtos.txt", "a");
  
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo !!!\n");
    return;
  }
  fprintf(arquivo, "Descrição: %s\nValor: %.2f\nQuantidade: %d\n\n", c.descricao, c.valor, c.qtdd);
  fclose(arquivo);
}

void listarProduto() {
  FILE *arquivo = fopen("produtos.txt", "r");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo !!!\n");
    return;
  }
  char linha[70];
  while (fgets(linha, sizeof(linha), arquivo)){
    printf("%s", linha);
  }
  fclose(arquivo);
}



int main() {
  Produto c;
  int opcao;

  do {
    printf("--- MENU DE OPÇÕES ---\n");
    printf("1. Cadastrar produto\n2. Listar produtos\n3. Sair...\nEscolha uma opção: ");
    scanf("%d", &opcao);
    getchar();

    switch(opcao){
      case 1:
      cadastrarProduto(c);
      salvarProduto(c);
      break;

      case 2:
      printf("\nLista de produtos:\n");
      listarProduto();
      break;

      case 3:
      printf("Saindo...\n");
      break;

      default:
      printf("\nOPÇÃO INVALIDA !!!\n");
    }
    
  } while (opcao != 3);
  
  return 0;
}