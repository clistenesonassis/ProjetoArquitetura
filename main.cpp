 #include <iostream>
#include <stdio.h>
#include <time.h>
#include <thread>

//using namespace std;
#define Msize 5000
#define MsizeY 1000


int matriz1[Msize][MsizeY]; // Imagem 1;
int matriz2[Msize][MsizeY]; // Imagem 2;
int matrizResul[Msize][MsizeY]; // Imagem Final;
int a[Msize][MsizeY];
int b[Msize][MsizeY];
int c[Msize][MsizeY];
int d[MsizeY];


struct merge {
    int matriz1; // Imagem 1;
    int matriz2; // Imagem 2;
    int matrizResul; // Imagem Final;
    int a;
    int b;
    int c;
};

merge matriz[Msize][MsizeY];

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

    clock_t unopts, unopte,
            opts, opte,
            opt2s, opt2e,
            testS, testE;

    // ################################## //
    // ######### Sem otimização ######### //

    // captura tempo do inicio da execução do programa.
    unopts = clock();

    for ( i = 0 ; i < Msize ; i++ ) {
        for ( j = 0 ; j < MsizeY ; j++ ) {
            matrizResul[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }

    for ( i = 0 ; i < Msize ; i++ ) {
        for ( j = 0 ; j < MsizeY ; j++ ) {
            c[i][j] = a[i][j] + matriz1[i][j];
            d[j] = d[j] * matriz2[i][j] * 0;
            a[i][j];
        }
    }

    // captura tempo do final da execução do programa.
    unopte = clock();

    // ######### Sem otimização ######### //
    // ################################## //


    // ################################## //
    // ######### Fusão de Loops ######### //

    opts =clock();
    for ( i = 0 ; i < Msize ; i++ ) {
        for ( j = 0 ; j < MsizeY ; j++ ) {
            c[i][j] = a[i][j] + matriz1[i][j];
            matrizResul[i][j] = matriz1[i][j] + matriz2[i][j];
            d[j] = d[j] * matriz2[i][j] * 0;
        }
    }
    opte =clock();

    // ######### Fusão de Loops ######### //
    // ################################## //


    // paras =clock();
    // std::thread first(processo,a,b,c,d,matriz1,matriz2,matrizResul,0,Msize);
    // parae =clock();

    // Imprime tempo total de execução do programa.
    printf("Tempo gasto: %4.0f ms\n\n",1000*(double)(unopte-unopts)/(double)(CLOCKS_PER_SEC));
    printf("Tempo gasto apos Otimizar (Fusão de loops): %4.0f ms\n\n",1000*(double)(opte-opts)/(double)(CLOCKS_PER_SEC));
    // printf("Tempo gasto apos Otimizar: %4.0f ms\n\n",1000*(double)(parae-paras)/(double)(CLOCKS_PER_SEC));

    
    // MERGE //

    // ################################## //
    // ######### Sem otimização ######### //

    // captura tempo do inicio da execução do programa.
    testS = clock();

    for ( i = 0 ; i < Msize ; i++ ) {
        for ( j = 0 ; j < MsizeY ; j++ ) {
            matriz[i][j].matrizResul = matriz[i][j].matriz1 + matriz[i][j].matriz2; //matrizResul[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }

    for ( i = 0 ; i < Msize ; i++ ) {
        for ( j = 0 ; j < MsizeY ; j++ ) {
            matriz[i][j].c = matriz[i][j].a + matriz[i][j].matriz1;
            d[j] = d[j] * matriz[i][j].matriz2 * 0;
            matriz[i][j].a;
        }
    }

    // captura tempo do final da execução do programa.
    testE = clock();

    printf("Tempo gasto sem Otimizar (MERGE): %4.0f ms\n\n",1000*(double)(testE-testS)/(double)(CLOCKS_PER_SEC));


    // ######### Sem otimização ######### //
    // ################################## //

}