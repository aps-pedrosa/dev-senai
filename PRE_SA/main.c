#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 3

// Declaracao da estrutura
typedef struct {
  int id;
  time_t in, out;
  int elapsed;
  float price;
  bool state;
} VEHICLE;

// Funcao auxilixar para formatar tempo de estacionamento
void formatElapsedTime(int seconds) {
  int hours = (int)seconds / 3600;
  int minutes = ((int)seconds % 3600) / 60;
  int remainingSeconds = (int)seconds % 60;

  printf("\nO veiculo ficou no estacionamento por:\n %02d:%02d:%02d\n", hours, minutes, remainingSeconds);
}

// Funcao auxiliar para exportar banco de dados dos veiculos para uma planilha
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
  // Declaracao das variaveis
  int opNew, opId, tmp;
  int i = 0;
  int parked = 0;
  int numID = 0;
  bool found = false;

  // Definicao de um array dinamico para o banco de dados dos veiculos
  VEHICLE *car;
  car = (VEHICLE*)calloc(numID, sizeof(VEHICLE));

  // Loop do programa
  do {
    printf("\n[1] Estacionar veiculo\n[2] Retirar veiculo\n[3] Relatorio de veiculos\n[4] Sair\n");
    scanf("%d", &opNew);

    // Menus
    switch (opNew) {
      case 1:
        // Adiciona um veiculo estacionado
        // Aumentando o tamanho do array de veiculos
        // Adicionando um id e inicia um contador de tempo
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

      // Remove um carro do estacionamento mas ainda mantendo no banco de dados
      case 2:
        // Mostra o bando de dados
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

        // Pesquisa se o ID digitado existe
        for (i = 0; i < numID; i++) {
          if ((opId == car[i].id) && (car[i].state == true)) {
            // Finaliza o contador calculando o tempo que o veiculo ficou no estacionamento
            time(&car[i].out);
            car[i].elapsed = difftime(car[i].out, car[i].in);
            formatElapsedTime(car[i].elapsed);
            car[i].state = false;
            parked -= 1;
            // Calcula o preco a pagar R$ 0.01 por segundo estacionado
            // R$ 36 pela hora
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
        // Exporta o banco de dados para uma planilha
        exportToCSV(car, numID, "relatorio.csv");
        break;

      case 4:
        // Sae do programa
        printf("\nExiting...\n");
        break;

      default:
        printf("\n!=Invalid!=\n");
    }

  } while(opNew != 4);

  return 0;
}
