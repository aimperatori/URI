#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF 999999999

double matriz[500][500];
int x[500], y[500];

double prim(int n) {
    int i;
    int U[n];
    double d[n];
    // inicialmente nenhum vértice está em U
    for (i=0;i<n;i++) {U[i]=0;d[i]=INF;}

    d[0]=0; // montagem da árvore vai iniciar no vértice 0
    for (i=0;i<n;i++){
        double menor=INF;
        int j,u; // encontra o vértice u ainda não selecionado
        for (j=0;j<n;j++)  // mais próximo a U
            if (U[j]==0 && d[j]<menor) {menor=d[j];u=j;}
        U[u]=1; // acrescenta o vértice u ao conjunto U
        for (j=0;j<n;j++) // atualiza a distância de cada vértice
            if (U[j]==0 && matriz[u][j]<d[j])  // adjacente a u
               d[j]=matriz[u][j];
    }
    double soma=0; // calcula soma das arestas selecionadas
    for (i=0;i<n;i++) soma+=d[i];

    return soma;
}

double dist(int i, int j){
    double DX = x[i] - x[j];
    double DY = y[i] - y[j];

    return sqrt(DX*DX+DY*DY);
}

int main(void) {
    int C, n;

    // le quantidade de testes
    fscanf(stdin, "%d", &C);

    int test;
    for (test = 0; test < C; ++test){
        // le quantas pessoas tem
        fscanf(stdin, "%d", &n);

        // le as coordenadas
        int i, j;
        for(i=0;i<n;i++){
            fscanf(stdin, "%d %d", &x[i], &y[i]);
        }

        // cria matriz
        for(i=0;i<n;i++){
             for(j=i;j<n;j++){
                matriz[i][j] = matriz[j][i] = dist(i, j);
            }
        }

        printf("%.2f\n", prim(n) / 100);
    }

    return 0;
}
