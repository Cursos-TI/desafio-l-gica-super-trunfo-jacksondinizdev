#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar os dados do país
typedef struct {
  char nome_pais[50];
  unsigned long int populacao;
  float area;
  float pib;
  int pontos_turisticos;
  float densidade_demografica;
} Pais;

// Função para exibir o menu de Escolha de Dois Atributos
void exibirMenu(int atributo_escolhido) {
  printf("\nEscolha o atributo para comparação:\n");
  if (atributo_escolhido != 1)
    printf("1 - População\n");
  if (atributo_escolhido != 2)
    printf("2 - Área\n");
  if (atributo_escolhido != 3)
    printf("3 - PIB\n");
  if (atributo_escolhido != 4)
    printf("4 - Número de pontos turísticos\n");
  if (atributo_escolhido != 5)
    printf("5 - Densidade demográfica\n");
  printf("Opção: ");

  /*Explicação: se um atributo já foi escolhido antes, ele não aparece de novo
   no menu. Por exemplo, se o jogador escolheu "População" antes, essa opção
   não será mostrada na segunda escolha.*/
}

// Função para obter o valor de um atributo específico
float obterValorAtributo(Pais carta, int atributo) {
  switch (atributo) {
  case 1:
    return carta.populacao; // População
  case 2:
    return carta.area; // Área
  case 3:
    return carta.pib; // PIB
  case 4:
    return carta.pontos_turisticos; // Pontos turísticos
  case 5:
    return carta.densidade_demografica; // Densidade demográfica
  default:
    printf("Erro: Atributo inválido!\n");
    return 0; // Caso inválido
  }
}

// Função para comparar dois atributos escolhidos
int compararAtributo(Pais carta1, Pais carta2, int atributo) {
  float valor1 = obterValorAtributo(carta1, atributo);
  float valor2 = obterValorAtributo(carta2, atributo);

  if (atributo == 5) { // Regra especial: menor densidade demográfica vence
    if (valor1 < valor2)
      return 1;
    if (valor1 > valor2)
      return 2;
  } else { // Regra geral: maior valor vence
    if (valor1 > valor2)
      return 1;
    if (valor1 < valor2)
      return 2;
  }
  return 0; // Empate
}

int main() {
  // Duas cartas de exemplo
  Pais carta1 = {"Brasil", 213000000, 8515767.0, 1490000.0, 12, 25.0};
  Pais carta2 = {"Argentina", 45380000, 2780400.0, 450000.0, 8, 16.3};

  int atributo1, atributo2, vencedor1, vencedor2;
  float soma1 = 0, soma2 = 0;

  /*Explicação: O jogador escolhe dois atributos para comparar. As funções do
    rograma comparam os valores dos atributos para cada carta e definem qual
   delas venceu, carta 1 ou carta 2. Durante o cálculo, os valores dos dois
   atributos escolhidos são somados para cada carta para definir a vencedora.
 */

  // Escolha do primeiro atributo
  exibirMenu(0);
  scanf("%d", &atributo1);

  // Escolha do segundo atributo
  exibirMenu(atributo1);
  scanf("%d", &atributo2);

  // Comparação do primeiro atributo
  vencedor1 = compararAtributo(carta1, carta2, atributo1);
  soma1 += obterValorAtributo(carta1, atributo1);
  soma2 += obterValorAtributo(carta2, atributo1);

  // Comparação do segundo atributo
  vencedor2 = compararAtributo(carta1, carta2, atributo2);
  soma1 += obterValorAtributo(carta1, atributo2);
  soma2 += obterValorAtributo(carta2, atributo2);

  // Exibição dos resultados
  printf("\nResultado da comparação:\n");
  printf("Carta 1 (%s) - Soma dos atributos: %.2f\n", carta1.nome_pais, soma1);
  printf("Carta 2 (%s) - Soma dos atributos: %.2f\n", carta2.nome_pais, soma2);

  if (soma1 > soma2) {
    printf("Vencedor: Carta 1 (%s)\n", carta1.nome_pais);
  } else if (soma2 > soma1) {
    printf("Vencedor: Carta 2 (%s)\n", carta2.nome_pais);
  } else {
    printf("Resultado: Empate!\n");
  }

  return 0;
}
