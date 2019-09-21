#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

int main(){
    
    int i, j;
    int matriz1[1000][1000]; // Imagem 1;
    int matriz2[1000][1000]; // Imagem 2;
    int matrizResul[1000][1000]; // Imagem Final;
    clock_t end,start;

    // captura tempo do inicio da execução do programa.
    start = clock();
    
    // Somando matriz1 com a matriz2;
    for ( i = 0 ; i < 1000 ; i++ ) {
        for ( j = 0 ; j < 1000 ; j++ ) {
            matriz1[i][j] = matriz2[i][j];
            matrizResul[i][j] = matriz2[i][j];
        }
    }

    // captura tempo do final da execução do programa.
    end = clock();

    // Imprime tempo total de execução do programa.
    printf("Tempo gasto: %4.0f ms\n\n",1000*(double)(end-start)/(double)(CLOCKS_PER_SEC));

}