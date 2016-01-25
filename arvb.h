typedef struct arvb ArvB;

struct arvb{
   char info;
   ArvB *esq;
   ArvB *dir;
 };

ArvB* arvb_cria_vazia(void);       //Função que cria uma Árvore Binária de Busca Vazia.
int arvb_vazia(ArvB *a);           //Testa se uma Árvore Binária é vazia.
ArvB* arvb_busca(ArvB *a,int c);   //Função que busca a sub-árvore que contém um inteiro.
void arvb_imprime(ArvB *a);        //Função que imprime os elementos de uma Árvore.
ArvB* arvb_insere(ArvB *a, int c); //Função que insere um inteiro em uma Árvore.
ArvB* arvb_remove(ArvB *a, int c); //Função que remove um inteiro em uma Árvore.
void arvb_libera(ArvB *a);         //Libera o espaço alocado para uma Árvore.
int folhas_primos(ArvB* a);        //Função que retorne a quantidade de folhas de uma árvore binária de busca que possuem no campo info um número primo.
int dois_filhos(ArvB* a);          //Função que retorne a quantidade de nós de uma árvore binária de busca que possuem os dois filhos (campos dir e esq diferentes de NULL).
int nos_igual_altura(ArvB* a);     //Funçãoo que, dada uma árvore binária de busca, retorne a quantidade de nós cujas subávores esquerda e direita tenham igual altura.
int iguais(ArvB* a, ArvB* b);      //Função que compare se duas árvores binárias de busca são iguais.

ArvB* arvb_cria_vazia(void) { 
  return NULL;
}

int arvb_vazia(ArvB *a) {
  return a==NULL;
}

ArvB* arvb_busca(ArvB *a, int c) {
  if(arvb_vazia(a))
    return NULL;
  else if(a->info < c)
    return arvb_busca(a->dir,c);
  else if(a->info > c)
    return arvb_busca(a->esq,c); else //(a->info == c)
  return a; 
}

void arvb_imprime(ArvB *a) {
  if(!arvb_vazia(a)) {
    arvb_imprime(a->esq);
    printf("%d ",a->info);
    arvb_imprime(a->dir);
  }
}

ArvB* arvb_insere(ArvB *a, int c) {
  if (arvb_vazia(a))  {
    a = (ArvB*)malloc(sizeof(ArvB));
    a->info = c;
    a->esq = NULL;
     a->dir = NULL;
   }
   else
     if (a->info > c)
       a->esq = arvb_insere(a->esq, c);
     else
       if (a->info < c)
         a->dir = arvb_insere(a->dir, c);
       else
         printf("\nElemento Ja Pertence a Arvore\n");
  return a; 
}

ArvB* arvb_remove(ArvB *a, int c) {
  
  if (!arvb_vazia(a)){
    if (a->info > c)
      a->esq = arvb_remove(a->esq, c);
    else if (a->info < c)
      a->dir = arvb_remove(a->dir, c);
    else {
      ArvB * t;
      if (a->esq == NULL) {
        t = a;
        a = a->dir;
        free(t);
      } else if(a->dir == NULL) {
        t = a;
        a = a->esq;
        free(t);
      } else {
        t = a->esq;
        while (t->dir != NULL)
          t = t->dir;
        a->info = t->info;
        t->info = c;
        a->esq = arvb_remove(a->esq, c);
      }
    }
  }

  return a;
}

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

int folhas_primos (ArvB *a) {
  if (!arvb_vazia(a)) {
    
    if (a->esq == NULL && a->dir == NULL && primo(a->info))
      return 1;
    return folhas_primos(a->esq) + folhas_primos(a->dir);
  }
  return 0;
}

int dois_filhos(ArvB* a) {
  if (!arvb_vazia(a)) {
    if (a->esq != NULL && a->dir != NULL)
      return 1 + dois_filhos(a->esq) + dois_filhos(a->dir);
  }

  return 0;
}

