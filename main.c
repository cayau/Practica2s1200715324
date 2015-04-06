#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "AVL.h"

void ingresarArbol();
void ingresarLista();

clock_t ini1, ini2, ini3, ini4;
clock_t fin1, fin2, fin3, fin4;
float t1, t2, t3, t4;
FILE *file;
char *path;
node *raiz = NULL;

int main()
{
    int op;

    do{
        system("cls");
        printf("********************* PRACTICA 2 ********************\n");
        printf(" \nSeleccione una Opcion\n");
        printf(" 1) Ingresar arbol\n");
        printf(" 2) Recorrer arbol\n");
        printf(" 3) Ordenamiento Burbuja\n");
        printf(" 4) Ordenamiento Quicksort\n");
        printf(" 5) Salir\n");
        printf(" Ingrese el numero de la opcion deceada:");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                printf("Ingrese la direccion del archivo con los datos: \n");
                path = (char *)malloc(128 *sizeof(char));
                scanf("%s", path);
                ini1 = clock();
                ingresarArbol();
                fin1 = clock();
                t1 = (float)((fin1-ini1)/CLOCKS_PER_SEC);
                printf("\n Ingresar arbol - %f segundos\n",t1);
                system("pause");
                break;
            case 2:
                ini2 = clock();
                if(raiz==NULL){
                    printf(" ARBOL VACIO!!");
                }else{
                    inorder(raiz);
                }
                fin2 = clock();
                t2 = (float)((fin2-ini2)/CLOCKS_PER_SEC);
                printf("\n Recorrido arbol - %f segundos\n",t2);
                system("pause");
                break;
            case 3:
                system("pause");
                break;
            case 4:
                system("pause");
                break;
        }// End switch
    }while(op!=5);
    return 0;
}

void ingresarArbol(){
    file = fopen(path,"r");
    if (file==NULL){
        printf(" Archivo no encontrado o no existe");
    }else{
        char buf[15];
        while (fgets(buf, sizeof buf, file) != NULL){
            int val = atol(buf);
            raiz = insert(raiz, val);
            printf(".");
        }
        fclose(file);
    }
}
