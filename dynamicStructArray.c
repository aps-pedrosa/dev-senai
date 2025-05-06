#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  int id;
  bool state;
} test;

int main() {
  test *num;
  int size = 0;
  int op, tmp;
  int j = 0;
  //int *id = num;

  num = (test*)calloc(size, sizeof(test));
  if (num == NULL) {
    printf("NOP\n");
  } else {
    printf("YEP\n");
  }

  while (op != 3) {
    printf("Add / Remove: ");
    scanf("%d", &op);

    switch (op) {
      case 1:
        size += 1;
        num = realloc(num, size * sizeof(test));

        if (num == NULL) {
          printf("NOP\n");
        } else {
          printf("YEP\n");
        }

        tmp = size-1;
        num[tmp].id = tmp;
        printf("Added ID: %d\n", num[tmp].id);
        num[tmp].state = true;
        break;

      case 2:
        printf("\n===\n");
        for (int i=0; i < size; i++) {
          if (num[i].state == true) {
            printf("%d\n", num[i].id);
          }
        }
        printf("\nID: ");
        scanf("%d", &tmp);

        num[tmp].state = false;

        break;

      default:
        break;
    }
  }

  printf("\n===\n");
  for (int i=0; i < size; i++) {
    printf("%d\n", num[i].id);
  }

  return 0;
}
