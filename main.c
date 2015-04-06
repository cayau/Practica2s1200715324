#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "AVL.h"

void ingresarArbol();
void ingresarLista();
void ordenamientoBurbuja(int a[]);
void quickSort(int x[], int f, int l);
void imprimirLista(int a[]);

clock_t ini1, ini2, ini3, ini4;
clock_t fin1, fin2, fin3, fin4;
float t1, t2, t3, t4;
FILE *file;
char *path;
int numDatos=0;
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
        printf(" 5) Reporte\n");
        printf(" 6) Salir\n");
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
                //postorden(raiz);
                if(!path){
                    printf(" INGRESE UN ARBOL!!");
                }else{
                    int lista[numDatos];
                    ingresarLista(&lista);
                    ini3 = clock();
                    ordenamientoBurbuja(&lista);
                    fin3 = clock();
                    t3 = (float)((fin3-ini3)/CLOCKS_PER_SEC);
                    printf("\n Ordenamiento Burbuja - %f segundos\n",t3);
                }
                system("pause");
                break;
            case 4:
                //postorden(raiz);
                if(!path){
                    printf(" INGRESE UN ARBOL!!");
                }else{
                    int lista[numDatos];
                    ingresarLista(lista);
                    ini4 = clock();
                    quickSort(lista,0,numDatos);
                    imprimirLista(lista);
                    fin4 = clock();
                    t4 = (float)((fin4-ini4)/CLOCKS_PER_SEC);
                    printf("\n Ordenamiento Quicksort - %f segundos\n",t4);
                }
                system("pause");
                break;
            case 5:
                printf("\n Ingresar arbol - %f segundos\n",t1);
                printf("\n Recorrido arbol - %f segundos\n",t2);
                printf("\n Ordenamiento Burbuja - %f segundos\n",t3);
                printf("\n Ordenamiento Quicksort - %f segundos\n",t4);
                system("pause");
                break;
        }// End switch
    }while(op!=6);
    return 0;
}

void ingresarArbol(){
    file = fopen(path,"r");
    if (file==NULL){
        printf(" Archivo no encontrado o no existe");
    }else{
        char buf[15]; numDatos=0;
        while (fgets(buf, sizeof buf, file) != NULL){
            int val = atoi(buf);
            raiz = insert(raiz, val);
            numDatos++;
        }
        fclose(file);
    }
}

void ingresarLista(int a[]){
    file = fopen(path,"r");
    if (file==NULL){
        printf(" Archivo no encontrado o no existe");
    }else{
        char buf[15];
        int i = 0;
        while (fgets(buf, sizeof buf, file) != NULL){
            int val = atoi(buf);
            a[i] = val;
            i++;
        }
        fclose(file);
    }
}

void imprimirLista(int a[]){
    int k=0;
    printf("\n");
    for(k=0;k<numDatos;k++){
        printf("%i,",a[k]);
    }
}

void ordenamientoBurbuja(int a[]){
    int i=0, j=0, auxI=0;
    for(i=0; i<(numDatos-1) ; i++){
        for(j=0; j<(numDatos-i-1) ; j++){
            if(a[j]>a[j+1]){
                auxI = a[j];
                a[j]=a[j+1];
                a[j+1] = auxI;
            }
        }
    }
    auxI=0;
}

void quickSort(int x[numDatos], int first, int last){
    int pivot, j, temp, i;

    if(first<last){
        pivot = first;
        i = first;
        j = last;

        while(i<j){
            while(x[i]<=x[pivot]&&i<last)
                i++;
            while(x[j]>x[pivot])
                j--;
            if(i<j){
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
        temp = x[pivot];
        x[pivot] = x[j];
        x[j] = temp;
        quickSort(x, first, j-1);
        quickSort(x, j+1, last);
    }
}
