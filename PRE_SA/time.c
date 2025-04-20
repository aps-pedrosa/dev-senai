#include <stdio.h>
#include <time.h>

void formatElapsedTime(int seconds) {
    int hours = (int)seconds / 3600;
    int minutes = ((int)seconds % 3600) / 60;
    int remainingSeconds = (int)seconds % 60;
    
    printf("%02d:%02d:%02d passed\n", hours, minutes, remainingSeconds);
}

void timing() {
  time_t start, end;

  time(&start);
  printf("Press\n");
  getchar();
  time(&end);

  int elapsed = difftime(end, start);

  formatElapsedTime(elapsed);
}

int main() {
  for (int i = 0; i < 2; i++) {
    timing();
  }

  return 0;
}
