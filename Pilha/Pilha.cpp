#include <bits/stdc++.h>

using namespace std;

#define MAX 50;

typedef struct pilha {
    int n;
    float vet[MAX];
} Pilha;

Pilha *cria() {
    Pilha *p = (Pilha *) malloc(sizeof(Pilha));
    p -> n = 0;
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
    free(p);
}

void push (Pilha *p, float v) {
    if(p -> n == MAX) {
        cout << "Capacidade da pilha estorou!" << endl;
        exit(1);
    }
    p -> vet[p -> n] = v;
    p -> n++;
}

float pop (Pilha *p) {
    float v;
    if(vazia(p)) {
        cout << "Pilha vazia!" << endl;
        exit(1);
    }
    v = p -> vet[p -< n-1];
    p -> n--;
    return v;
}

int main() {



    return 0;
}