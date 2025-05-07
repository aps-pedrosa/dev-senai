#include <stdio.h>

#define LEN 100

void ex34() {
  char livro [LEN];
  int opt;

  printf("Emprestar livro: ");
  scanf("%99s", livro);

  printf("[1] Aluno\n[2] Professor\nEscolha: ");
  scanf("%d", &opt);

  switch (opt) {
    case 1:
      printf("O livro %s devera ser devolvido a biblioteca dentro de 3 dias.\n", livro);
      break;
    case 2:
      printf("O livro %s devera ser devolvido a biblioteca dentro de 10 dias.\n", livro);
      break;
    default:
      printf("Cargo invalido!\n");
      break;
  }
}
