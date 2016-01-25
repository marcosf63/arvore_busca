#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubblesort(int v[], int tamanho);

int main() {
  int i, j;
  int tamanho[4] = {100, 1000, 10000, 100000};
  int v[1000000];
  float tempo;
  clock_t t0, t1;

  srand(time(0));

 
  for (j = 0; j < 4; j++)
    for (i = 0; i < tamanho[i]; i++) {
      v[i] = rand() % 100 + 1;

      printf("Calculando o tempo...\n");
      t0  = clock();
      bubblesort(v, tamanho[i]);
      t1 = clock();
      tempo = (t1 - t0) * 1000 / CLOCKS_PER_SEC;
      printf("Tempo em milisegundos %.2f\n", tempo); 
  }

  return 0;
}

void bubblesort(int v[], int tamanho) {
  int i, j, aux;
  for (i = tamanho - 1; i > 0; i--)
     for (j = 0; j < i; j++)
       if (v[j] > v[j + 1]) {
         aux = v[j];
	       v[j] = v[j + 1];
	       v[j + 1] = aux;
       } 
}
