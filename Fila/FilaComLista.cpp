#include <bits/stdc++.h>

using namespace std;

typedef struct no {
    float info;
    struct no *prox;
} No;

typedef struct fila {
    No *ini;
    No *fim;
} Fila;

Fila *cria() {
    Fila *f = (Fila *) malloc(sizeof(Fila));
    f -> ini = f -> fim = NULL;
    return f;
}

int vazia(Fila *f) {
    if(f == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void libera(Fila *f) {
    No *q = f -> ini;
    while(q != NULL) {
        No * t = q -> prox;
        free(q);
        q = t;
    }
    free(f);

}

void imprime(Fila *f) {
    No* q;
    for(q = f -> ini; q != NULL; q = q -> prox) {
        cout << q -> info <<  endl;
    }
}

No *ins_fim(No *fim, float v) {
    No *p = (No*) malloc(sizeof(No));
    p -> info = v;
    p -> prox = NULL;
    if(fim != NULL) fim -> prox = p;

    return p;
}

No *ret_ini(No *ini) {
    No *p = ini -> prox;
    free(ini);
    return p;
}

void insere(Fila *f, float v) {
    f -> fim = ins_fim(f -> fim, v);
    if(f -> ini == NULL) f -> ini = f -> fim;
}

float retira(Fila *f) {
    float v;
    if(vazia(f)) {
        cout << "Fila vazia!" << endl;
        exit(1);
    }
    v = f -> ini -> info;
    f -> ini = ret_ini(f -> ini);
    if(f -> ini == NULL) f -> fim = NULL;

    return v;
}

int main() {





    return 0;
}