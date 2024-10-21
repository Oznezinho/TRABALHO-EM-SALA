#include <stdio.h>

// Função da opção 1
void transformandoFC(double *resultado, double *t1) {
  (*resultado) = 1.8 * (*t1) + 32;
  printf("A conversão para Fahrenhei é %.2lf\n", (*resultado));
}

// Função da opção 2
void transformandoCF(double *resultado, double *t1) {
  (*resultado) = (*t1 - 32) / 1.8;
  printf("A conversão para Celsius é %.2lf\n", (*resultado));
}

int main(void) {
  int opcao;
  double t1;

  printf("Escolha o tipo de conversão:\n");
  printf("1- Fahrenheit para Celsius \n");
  printf("2- Celsius para Fahrenheit \n");
  printf("3- Sair \n");

  do {
    printf("Escolha sua opção: ");
    scanf("%d", &opcao);
    printf("\n");
    getchar();

    switch (opcao) {

    case 1:
      printf("Transformando fahrenheit para Celsius\n");
      printf("Digite a temperatura: ");
      scanf("%lf", &t1);

      double resultado = 0;
      transformandoFC(&resultado, &t1);
      printf("\n");
      break;

    case 2:
      printf("Transformando Celsius para fahrenheit\n");
      printf("Digite a temperatura: ");
      scanf("%lf", &t1);
      double resultado2 = 0;
      transformandoCF(&resultado2, &t1);
      printf("\n");
      break;

    case 3:
      printf("Saindo... \n");
      break;

    default:
      printf("Opção inválida! \n");
    }
  } while (opcao != 3);
  return 0;
}