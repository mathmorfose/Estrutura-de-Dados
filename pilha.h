#ifndef PILHA_PILHA_H
#define PILHA_PILHA_H

#define TRUE 1
#define FALSE 0
#define ERRO -1
typedef int boolean;
typedef struct pilha_st PILHA;
PILHA *criar_pilha();
boolean pilha_vazia(PILHA *pilha);
int pilha_empilhar(PILHA *pilha, int elemento);
int pilha_topo(PILHA *pilha);
int pilha_desempilhar(PILHA *pilha);
boolean pilha_apagar(PILHA **pilha);
void pilha_remove_tudo(PILHA **pilha);
void pilha_remove_topo(PILHA **pilha);

#endif //PILHA_PILHA_H
