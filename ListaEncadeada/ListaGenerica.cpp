#include <bits/stdc++.h>

using namespace std;

#define RET 0
#define TRI 1
#define CIR 2
#define PI 3.14159

typedef struct retangulo {
    float b;
    float h;
} Retangulo;

typedef struct triangulo {
    float b;
    float h;
} Triangulo;

typedef struct circulo {
    float r;
} Circulo;

typedef struct lista {
    Retangulo *info;
    struct lista *prox;
} Lista;

typedef struct listagen {
    int tipo;
    void *info;
    struct listagen *prox;
} ListaGen;

Lista *cria() {
    Retangulo *r = (Retangulo *) malloc(sizeof(Retangulo));
    Lista *p = (Lista *) malloc(sizeof(Lista));

    p -> info = r;
    p -> prox = NULL;

    return p;
}

ListaGen *cria_ret(float b, float h) {
    Retangulo *r;
    ListaGen *p;

    r = (Retangulo *) malloc(sizeof(Retangulo));
    r -> b = b;
    r -> h = h;

    p = (ListaGen *) malloc(sizeof(ListaGen));
    p -> tipo = RET;
    p -> info = r;
    p -> prox = NULL;

    return p;
}

ListaGen * cria_tri(float b, float h) {
    Triangulo *t;
    ListaGen *p;

    t = (Triangulo *) malloc(sizeof(Triangulo));
    t -> b = b;
    t -> h = h;

    p = (ListaGen *) malloc(sizeof(ListaGen));
    p -> tipo = TRI;
    p -> info = t;
    p -> prox = NULL;

    return p;
}

ListaGen *cria_cir(float r) {
    Circulo *c;
    ListaGen *p;

    r = (Circulo *) malloc(sizeof(Circulo));
    c -> r = r;

    p = (ListaGen *) malloc(sizeof(ListaGen));
    p -> tipo = CIR;
    p -> info = c;
    p -> prox = NULL;

    return p;
}

float area (ListaGen *p) {
    float a;
    switch(p -> tipo) {
        case RET: {
            Retangulo *r = (Retangulo*) p -> info;
            a = r -> b * r -> h;
        }
        break;

        case TRI: {
            Triangulo *t = (Triangulo*) p -> info;
            a = (t -> b * t -> h) / 2;
        }
        break;

        case CIR: {
            Circulo *c = (Circulo)p -> info;
            a = PI * c -> r * c -> r;
        }
        break;
    }
    return a;
}

float max_area(ListaGen *l) {
    float amax = 0.0;
    ListaGen *p;
    for(p = l; p != NULL; p = p -> prox) {
        float a = area(p);
        if(a > amax) amax = a;
    }
    return amax;
}

int main() {

    return 0;
}