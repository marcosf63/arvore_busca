#include <stdio.h>
#include <stdlib.h>
#include "arvb.h"

int main() {

  ArvB * a = arvb_cria_vazia();

  a = arvb_insere(a, 4);
  a = arvb_insere(a, 3);
  a = arvb_insere(a, 6);
 


  arvb_imprime(a); 
  printf("\n");

  printf("Qtd de folhas primos da arvore: %d\n", folhas_primos(a));

  a = arvb_insere(a, 2);
  a = arvb_insere(a, 5);
  a = arvb_insere(a, 9);
  a = arvb_insere(a, 11);
  a = arvb_insere(a, 8);
  arvb_imprime(a);
  printf("\n");

  printf("Qtd de folhas primos da arvore: %d\n", folhas_primos(a));

  
  ArvB * b = arvb_cria_vazia();

  b = arvb_insere(b, 12);
  b = arvb_insere(b, 18);
  b = arvb_insere(b, 9);
  b = arvb_insere(b, 10);
  b = arvb_insere(b, 8);
  b = arvb_insere(b, 17);
  b = arvb_insere(b, 20);
  b = arvb_insere(b, 19);
  b = arvb_insere(b, 24);

  printf("Qtd de nos com dois filhos : %d\n", dois_filhos(b));

  return 0;
}