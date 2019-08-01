#include <bits/stdc++.h>

using namespace std;

typedef struct lista {
    int info;
    struct lista *prox;
} Lista;

Lista *inicializa() {
    return NULL;
}

Lista *cria(int v) {
    Lista *p = (Lista*) malloc(sizeof(Lista));
    p -> info = v;
    return p;
}

int vazia(Lista *l) {
    if(l == NULL) {
        return 1;
    } else {
        return 0;
    }
}

Lista *insere(Lista* l, int i) {
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo -> info = i;
    novo -> prox = l;
    return novo;
}

Lista *insere_ordenado(Lista *l, int v) {
    Lista *novo = cria(v);
    Lista *ant = NULL;
    Lista *p = l;

    while(p != NULL && p -> info < v) {
        ant = p;
        p = p -> prox;
    }

    if(ant == NULL) {
        novo -> prox = l;
        l = novo;
    } else {
        novo -> prox = ant -> prox;
        ant -> prox = novo;
    }
    return l;
}

Lista *busca(Lista *l, int v) {
    Lista *p;
    for(p = l; p != NULL; p = p -> prox) {
        if(p -> info == v) return p;
    }
    return NULL;
}

Lista *retira(Lista *l, int v) {
    Lista *ant = NULL;
    Lista *p = l;

    while(p != NULL && p -> info != v) {
        ant = p;
        p = p -> prox;
    }

    if(p == NULL) return l;

    if(ant == NULL) {
        l = p -> prox;
    } else {
        ant -> prox = p -> prox;
    }
    free(p);

    return l;
}

void libera(Lista *l) {
    Lista *p = l;
    while(p != NULL) {
        Lista *t = p -> prox;

        free(p);
        p = t;
    }
}

void imprime(Lista *l) {
    Lista *p;
    cout << "INFO: ";
    for(p = l; p != NULL; p = p -> prox){
        cout << p -> info << " ";
    }
}

int main() {

    Lista *l;
    l = inicializa();
    
    l = insere(l, 23);
    l = insere(l, 45);
    l = insere(l, 56);
    l = insere(l, 78);
    imprime(l);
    
    l = retira(l, 78);
    cout << "\nREMOVEU 78" << endl;
    imprime(l);
    l = retira(l, 45);
    cout << "\nREMOVEU 45" << endl;
    imprime(l);

    libera(l);

    return 0;
}