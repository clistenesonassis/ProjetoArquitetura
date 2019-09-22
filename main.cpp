 #include <iostream>
#include <stdio.h>
#include <time.h>
#include <thread>

//using namespace std;
#define Msize 9000


int a[Msize][Msize];
int matriz1[Msize][Msize]; // Imagem 1;
int matriz2[Msize][Msize]; // Imagem 2;
int matrizResul[Msize][Msize]; // Imagem Final;
int b[Msize][Msize];
int c[Msize][Msize];
int d[Msize];


void processo(int** a,int** b,int** c,int* d,int** matriz1,int** matriz2,int** matrizResul,int start,int finish){
    int i,j;
    for ( i = start ; i < finish ; i++ ) {
        for ( j = start ; j < finish ; j++ ) {
            c[i][j] = a[i][j] + matriz1[i][j];
            matrizResul[i][j] = matriz1[i][j] + matriz2[i][j];
            d[j] = d[j] * matriz2[i][j] * 0;
        }
    }
}
int main(){

    int i, j;

    clock_t unopts,unopte,opts,opte,paras,parae;

    // captura tempo do inicio da execução do programa.
    unopts = clock();

    // Somando matriz1 com a matriz2;
    for ( i = 0 ; i < Msize ; i++ ) {
        for ( j = 0 ; j < Msize ; j++ ) {
            matrizResul[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }

    for ( i = 0 ; i < Msize ; i++ ) {
        for ( j = 0 ; j < Msize ; j++ ) {
            c[i][j] = a[i][j] + matriz1[i][j];
            d[j] = d[j] * matriz2[i][j] * 0;
            a[i][j];
        }
    }

    // captura tempo do final da execução do programa.
    unopte = clock();
    opts =clock();
    for ( i = 0 ; i < Msize ; i++ ) {
        for ( j = 0 ; j < Msize ; j++ ) {
            c[i][j] = a[i][j] + matriz1[i][j];
            matrizResul[i][j] = matriz1[i][j] + matriz2[i][j];
            d[j] = d[j] * matriz2[i][j] * 0;
        }
    }
    opte =clock();
    paras =clock();
    std::thread first(processo,a,b,c,d,matriz1,matriz2,matrizResul,0,Msize);
    parae =clock();

    // Imprime tempo total de execução do programa.
    printf("Tempo gasto: %4.0f ms\n\n",1000*(double)(unopte-unopts)/(double)(CLOCKS_PER_SEC));
    printf("Tempo gasto apos Otimizar: %4.0f ms\n\n",1000*(double)(opte-opts)/(double)(CLOCKS_PER_SEC));
    printf("Tempo gasto apos Otimizar: %4.0f ms\n\n",1000*(double)(parae-paras)/(double)(CLOCKS_PER_SEC));
}
