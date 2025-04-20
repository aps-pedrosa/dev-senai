#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "test2.c"

int main() {
  Elementos pessoa[NUM];
  int opcao;
  char tmp[LEN];
  bool achado = false;

  // Loop variaveis vazias
  for (int i = 0; i < NUM; i++){
    pessoa[i].cep = 0;
    pessoa[i].cell = 0;
  }

  // Loop de declaração e organização dos nomes
  for (int i = 0; i < NUM; i++) {
    printf("Digite o nome: ");
    scanf("%99s", tmp);
    tratarString(tmp);

    int j = i;

    while ((j != 0) && (strcmp(tmp, pessoa[j - 1].nome) < 0)) {
      /*
            Caso o nome digitado seja alfabeticamente menor que o anterior
            no array espaço é liberado, e checa-se novamente, até que 
            esteja na posição correta.
            Esse processo é realizado do ultimo nome indexado até o primeiro
            (decrescente)
            */
      strcpy(pessoa[j].nome, pessoa[j - 1].nome);
      j--;
    }

    // O nome atual é anexado ao "slot" disponibilizado pelo loop anterior
    strcpy(pessoa[j].nome, tmp);
  }

  printf("\n=== Nome Organizados ===\n");
  for (int i = 0; i < NUM; i++) {
    printf("%s\n", pessoa[i].nome);
  } 

  while (opcao != 3) {
    printf("\n[1] Adicionar dados\n[2] Mostrar Banco de Dados\n[3] Sair do programa\n");
    scanf("%d", &opcao);

    if (opcao == 1) {
      printf("\n=== Banco de Dados ===\n");
      for (int i = 0; i < NUM; i++) {
        printf("%s | %s | %d | %d\n", pessoa[i].nome, pessoa[i].endereco, pessoa[i].cep, pessoa[i].cell);
      } 

      printf("\nDigite o nome: ");
      scanf("%99s", tmp);
      tratarString(tmp);

      for (int i = 0; i < NUM; i++) {
        if (strcmp(tmp, pessoa[i].nome) == 0) { 
          printf("Digite o endereço: ");
          scanf("%99s", pessoa[i].endereco);
          printf("Digite o CEP: ");
          scanf("%d", &pessoa[i].cep);
          printf("Digite o telefone: ");
          scanf("%d", &pessoa[i].cell);

          achado = true;
        }
      }

      if (achado == false) {
        printf("\nNome Invalido!\n");
      }
    } else if (opcao == 2) {
      printf("\n=== Banco de Dados ===\n");
      for (int i = 0; i < NUM; i++) {
        printf("%s | %s | %d | %d\n", pessoa[i].nome, pessoa[i].endereco, pessoa[i].cep, pessoa[i].cell);
      } 
    }
  }

  return 0;
}
