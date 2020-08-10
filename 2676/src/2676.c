#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF 9999999

int matriz[501][501];

int min(int atual, int novo){
    if(atual < novo) return atual;
    else return novo;
}

void floydwarshall(int N){
    int k, i, j;

    for(k=1;k<=N;k++)
        for(i=1;i<=N;i++)
            for(j=1;j<=N;j++)
                matriz[i][j] = min(matriz[i][j], matriz[i][k] + matriz[k][j]);
}

int main(void) {
    int N, R;
    int i, j;

    while(1){
        // N = Cidades
        // R = Arrestas
        fscanf(stdin, "%d %d", &N, &R);

        if(N == 0 && R == 0) break;

        // seta a matriz com INFINITO
        for(i=1;i<=500;i++){
             for(j=i;j<=500;j++){
                if(i != j) matriz[i][j] = matriz[j][i] = INF;
                else matriz[i][j] = 0;
            }
        }

        int A, B, D;
        for (i = 1; i <= R; ++i){
            // le cidades
            // D = distancia
            fscanf(stdin, "%d %d %d", &A, &B, &D);

            matriz[A][B] = matriz[B][A] = D;
        }

        floydwarshall(N);

        // calcula a cidade que tem menor distancia para as outras
        int soma, cont = 0, menor = 0;
        int indices[N];

        for(j=1;j<=N;j++){
            menor+=matriz[1][j];
        }
        indices[cont]=1;

        for(i=2;i<=N;i++){
            soma = 0;
            for(j=1;j<=N;j++){
                soma+=matriz[i][j];
            }

            if(soma < menor) {
                cont=0;
                indices[cont]=i;
                menor = soma;
            }else if(soma == menor) {
                indices[++cont]=i;
            }
        }

        for(i=0;i<=cont;i++) printf("%d ", indices[i]);

        printf("\n");

        // debug
        // for(i=1;i<=N;i++){
        //      for(j=1;j<=N;j++){
        //         printf("%d ", matriz[i][j]);
        //     }
        //     printf("\n");
        // }
    }

    return 0;
}
