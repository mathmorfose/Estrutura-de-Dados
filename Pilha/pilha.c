#include <stdlib.h>
#include "pilha.h"
typedef struct no_st NO;
struct no_st{
    int elemento;
    NO *anterior;
};

struct pilha_st{
    NO *topo;
    int tamanho;
};

PILHA *criar_pilha(){
    PILHA *pilha = (PILHA*) malloc(sizeof(PILHA));

    if(pilha != NULL){
        pilha->topo = NULL;
        pilha->tamanho = 0;
    }
    return pilha;
}

boolean pilha_vazia(PILHA *pilha){
    if(pilha != NULL)
        return pilha->tamanho == 0;
    return FALSE;
}

int pilha_empilhar(PILHA *pilha, int elemento){
    if(pilha != NULL){

        NO *novoNo = (NO*) malloc(sizeof(NO));
        if(novoNo != NULL){
            novoNo->elemento = elemento;
            novoNo->anterior = pilha->topo;
            pilha->topo = novoNo;
            pilha->tamanho++;
            return TRUE;
        }
    }
    return ERRO;
}

int pilha_topo(PILHA *pilha){
    if((pilha != NULL) && (!pilha_vazia(pilha)))
        return pilha->topo->elemento;

    return ERRO;
}

int pilha_desempilhar(PILHA *pilha){
    if ((pilha != NULL) && (!pilha_vazia(pilha))) {
        NO *desempilhado = pilha->topo;
        int elemento = pilha->topo->elemento;
        pilha->topo = pilha->topo->anterior;
        desempilhado->anterior = NULL;
        free(desempilhado);
        desempilhado = NULL;
        pilha->tamanho--;
        return elemento;
    }
    return ERRO;
}

boolean pilha_apagar(PILHA **pilha){
    if ((*pilha != NULL) && (!pilha_vazia(*pilha))){
        pilha_remove_tudo(pilha);
        free (*pilha);
        *pilha = NULL;
        return TRUE;
    }
    return FALSE;
}

void pilha_remove_tudo(PILHA **pilha) {
    while((*pilha)->topo != NULL){
        pilha_remove_topo(pilha);
    }
}

void pilha_remove_topo(PILHA **pilha) {
    NO *NoTemporario;
    NoTemporario = (*pilha)->topo;
    (*pilha)->topo = (*pilha)->topo->anterior;
    NoTemporario->anterior = NULL;
    free(NoTemporario);
    NoTemporario = NULL;
    (*pilha)->tamanho--;
}