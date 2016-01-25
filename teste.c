#include <stdio.h>
#include <stdlib.h>

int primo(int n) {
  int i, cont = 0;
  if (n == 2)
    return 1;
  else if (n > 2) {
    for (i = 1; i <= n; i++) {
      if (n % i == 0)
        cont++;
    }
    if (cont == 2)
      return 1;
  }
  return 0;
}


int main() {
  int i;
  for (i = 1; i <= 30; i++)
    if (primo(i))
      printf("%d\n", i);
  return 0;  
}