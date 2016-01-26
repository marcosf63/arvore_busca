#include <stdio.h>
#include <stdlib.h>
#include "arvb.h"

int main() {

  ArvB * arvA = arvb_cria_vazia();

  arvA = arvb_insere(arvA, 3);
  arvA = arvb_insere(arvA, 5);
  arvA = arvb_insere(arvA, 2);
  arvA = arvb_insere(arvA, 4);
  arvA = arvb_insere(arvA, 7);
  arvA = arvb_insere(arvA, 0);
  arvA = arvb_remove(arvA, 4); 
  
  printf("Alturar da arvore %d\n", arvb_altura(arvA));
  printf("Qtd de folhas primos %d\n", folhas_primos(arvA));
  printf("Qtd de nos com dois filhos %d\n", dois_filhos(arvA));

  ArvB * arvB = arvb_cria_vazia();
  
  arvB = arvb_insere(arvB, 8);
  arvB = arvb_insere(arvB, 9);
  arvB = arvb_insere(arvB, 11);

  arvb_imprime(arvA);
  printf("\n");
  arvb_imprime(arvB);
  printf("\n");
  
  arvb_libera(arvA);
  arvb_libera(arvB);

  return 0;
}
