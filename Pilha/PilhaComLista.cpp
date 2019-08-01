#include <bits/stdc++.h>

using namespace std;

typedef struct no {
    float info;
    struct no *prox;
} No;

typedef struct pilha {
    No *prim;
} Pilha;

Pilha *cria() {
    Pilha *p = (Pilha *) malloc(sizeof(Pilha));
    p -> prim = NULL;
    return p;
}

int vazia(Pilha *p) {
    if(p == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void libera(Pilha *p) {
    No* q = p -> prim;
    while(q != NULL) {
        No *t = q -> prox;
        free(q);
        q = t;
    }
    free(p);
}

void imprime(Pilha *p) {
    No *q;
    for(q = p -> prim; q != NULL; q = q -> prox) {
        cout << q -> info << endl;
    }
}

No *ins_ini(No *l, float v) {
    No *p = (No *) malloc(sizeof(No));
    p -> info = v;
    p -> prox = l;
    return p;
}

No *ret_ini(No *l) {
    No *p = l -> prox;
    free(l);
    return p;
}

void push(Pilha *p, float v) {
    p -> prim = ins_ini(p -> prim, v);
}

float pop (Pilha *p) {
    float v;
    if(vazia(p)) {
        cout << "Pilha vazia!" << endl;
        exit(1);
    }
    v = p -> prim -> info;
    p -> prim = ret_ini(p -> prim);
    return v;
}

int main() {



    return 0;
}