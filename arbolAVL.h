#ifndef ARBOLAVL_H_INCLUDED
#define ARBOLAVL_H_INCLUDED

typedef struct NODO{
    int dato;
    int fe;
    int *h;
    struct NODO *subDer;
    struct NODO *subIzq;
}nodo;

void insertar(nodo **raiz, int dato, int *h){
    if( (*raiz) ){
        if((*raiz)->dato>dato){
            insertar(&(*raiz)->subIzq, dato, h);
        }else{
            insertar(&(*raiz)->subDer, dato, h);
        }
    }else{
        nodo *nuevo = (*nuevo) malloc(sizeof(nuevo));
        nuevo->dato = dato;
        nuevo->subDer = NULL;
        nuevo->subIzq = NULL;
        (*raiz) = nuevo;
        *h = 1;
    }
}

#endif // ARBOLAVL_H_INCLUDED
