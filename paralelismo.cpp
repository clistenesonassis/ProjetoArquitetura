 #include <iostream>
#include <stdio.h>
#include <time.h>
#include <thread>


void sequentialProgram(int m, int n){

    int matriz1[m][n]; // Imagem 1;
    int matriz2[m][n]; // Imagem 2;
    int matrizResul[m][n]; // Imagem Final;
    int a[m][n];
    int b[m][n];
    int c[m][n];
    int d[n];

    int i, j;

    clock_t opts, opte;

    // ################################## //
    // ######### Fusão de Loops ######### //

    opts = clock();
    for ( i = 0 ; i < m ; i++ ) {
        for ( j = 0 ; j < n ; j++ ) {
            c[i][j] = a[i][j] + matriz1[i][j];
            matrizResul[i][j] = matriz1[i][j] + matriz2[i][j];
            d[j] = d[j] * matriz2[i][j] * 0;
        }
    }
    opte = clock();

    printf("Tempo gasto sem Paralelismo: %4.0f ms\n\n",1000*(double)(opte-opts)/(double)(CLOCKS_PER_SEC));


    // ######### Fusão de Loops ######### //
    // ################################## //

}

void parallelProgram(int m, int n) {

    int matriz1[m][n]; // Imagem 1;
    int matriz2[m][n]; // Imagem 2;
    int matrizResul[m][n]; // Imagem Final;
    int a[m][n];
    int b[m][n];
    int c[m][n];
    int d[n];

    int i, j;

    clock_t paras, parae;

    // ################################################ //
    // ######### Fusão de Loops + Paralelismo ######### //

    paras = clock();

    #pragma omp parallel
        for ( i = 0 ; i < m ; i++ ) {
            for ( j = 0 ; j < n ; j++ ) {
                c[i][j] = a[i][j] + matriz1[i][j];
                matrizResul[i][j] = matriz1[i][j] + matriz2[i][j];
                d[j] = d[j] * matriz2[i][j] * 0;
            }
        }

    parae = clock();

    printf("Tempo gasto Com Paralelismo: %4.0f ms\n\n",1000*(double)(parae-paras)/(double)(CLOCKS_PER_SEC));


    // ######### Fusão de Loops + Paralelismo ######### //
    // ################################################ //

}


int main(){

    sequentialProgram( 600 , 500 );

    parallelProgram( 600, 500 );

}