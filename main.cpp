#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;


int a[1000][10000];
int matriz1[1000][10000]; // Imagem 1;
int matriz2[1000][10000]; // Imagem 2;
int matrizResul[1000][10000]; // Imagem Final;
int b[1000][10000];
int c[1000][10000];
int d[10000];

int main(){
    
    int i, j;

    clock_t end,start;

    // captura tempo do inicio da execução do programa.
    start = clock();
    
    // Somando matriz1 com a matriz2;
    for ( i = 0 ; i < 1000 ; i++ ) {
        for ( j = 0 ; j < 10000 ; j++ ) {
            matrizResul[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }

    for ( i = 0 ; i < 1000 ; i++ ) {
        for ( j = 0 ; j < 10000 ; j++ ) {
            c[i][j] = a[i][j] + matriz1[i][j];
            d[j] = d[j] * matriz2[i][j] * 0;
            a[i][j];
        }
    }

    // captura tempo do final da execução do programa.
    end = clock();

    // Imprime tempo total de execução do programa.
    printf("Tempo gasto: %4.0f ms\n\n",1000*(double)(end-start)/(double)(CLOCKS_PER_SEC));

}