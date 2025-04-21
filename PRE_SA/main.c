#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 3

typedef struct {
  int id;
  time_t in, out;
  int elapsed;
  float price;
  bool state;
} VEHICLE;


void formatElapsedTime(int seconds) {
    int hours = (int)seconds / 3600;
    int minutes = ((int)seconds % 3600) / 60;
    int remainingSeconds = (int)seconds % 60;
    
    printf("\nO veiculo ficou no estacionamento por:\n %02d:%02d:%02d\n", hours, minutes, remainingSeconds);
}

void exportToCSV(VEHICLE *car, int totalVehicles, const char *filename) {
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    perror("Erro ao abrir o arquivo");
    return;
  }

  fprintf(file, "ID,Tempo (s),Preco,Estado\n");

  for (int i = 0; i < totalVehicles; i++) {
    if (car[i].elapsed == 0) {
      time(&car[i].out);
      car[i].elapsed = difftime(car[i].out, car[i].in);
    }
    fprintf(file, "%d,%d,%.2f,%s\n",
            car[i].id,
            car[i].elapsed,
            car[i].price,
            car[i].state ? "Estacionado" : "Saiu"
            );
  }

  fclose(file);
  printf("\nRelatório exportado para '%s'\n", filename);
}

int main() {
  int opNew, opId, tmp;
  int i = 0;
  int parked = 0;
  int numID = 0;
  bool found = false;
  VEHICLE *car;

  car = (VEHICLE*)calloc(numID, sizeof(VEHICLE));

  do {
    printf("\n[1] Estacionar veiculo\n[2] Retirar veiculo\n[3] Relatorio de veiculos\n[4] Quit\n");
    scanf("%d", &opNew);

    switch (opNew) {
      case 1:
        if (parked < MAX){
          parked += 1;
          numID += 1;
          car = realloc(car, numID * sizeof(VEHICLE));
          tmp = numID-1;
          car[tmp].id = tmp;
          time(&car[tmp].in);
          printf("Veiculo de ID: %d entrou no estacionamento.\n", tmp);
          car[tmp].state = true;

        } else {
          printf("\nEstacionamento cheio!\n");
        }
        break;

      case 2:
        for (i = 0; i < numID; i++) {
          if ((car[i].state == true) && (parked != 0)) {
            printf("Veiculo: %d\n", car[i].id);
          }
        }
        if (parked == 0) {
          printf("Nenhum carro no estacionamento\n");
          goto exit_switch;
        }

        printf("Digite o ID do veiculo\n");
        scanf("%d", &opId);
        
        found = false;

        for (i = 0; i < numID; i++) {
          if ((opId == car[i].id) && (car[i].state == true)) {
            time(&car[i].out);
            car[i].elapsed = difftime(car[i].out, car[i].in);
            formatElapsedTime(car[i].elapsed);
            car[i].state = false;
            parked -= 1;
            // Calculate price 0.01 per sec (36 per hour)
            car[i].price = car[i].elapsed * 0.01;
            printf("Preço a pagar: R$ %.2f\n", car[i].price);
            // car[i].id = NULL;
            found = true;
          }
        }
        if (!found) {
          printf("ID invalido!\n");
        }
      exit_switch:
        break;

      case 3:
        exportToCSV(car, numID, "relatorio.csv");
        break;

      case 4:
        printf("\nExiting...\n");
        break;

      default:
        printf("\n!=Invalid!=\n");
    }

  } while(opNew != 4);

  return 0;
}
