#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF 9999999

int matriz[501][501];

void dijkstra(int s, int t, int n){
    int i, u = 0, v, menor, T[501], L[501];

    // T = flags -> seta como 1 para nao percorrido
    // L = vetor das distancias
    for(i=1;i<=n;i++){
        L[i] = INF;
        T[i] = 1;
    }

    // seta primeiro elemento com distancia 0
    L[s]=0;

    int k;
    for (k = 1; k <= n; ++k){
        menor = INF;
        // pega vertice de menor L que ainda esta em T
        for (i = 1; i <= n; ++i){
            if(L[i]<menor && T[i]>0){
                menor = L[i];
                u=i;
            }
        }

        if(u==t) break;
        if(menor==INF) break;

        for(v=1;v<=n;v++)
            if(T[v]==1)
                if(L[v]>matriz[u][v]+L[u])
                    L[v]=matriz[u][v]+L[u];
        T[u]=0;
   }

   if(L[t]==INF) printf("Nao e possivel entregar a carta\n");
   else printf("%d\n", L[t]);
}

int main(void) {
    int N, E;
    int i, j;

     while(1){

        // N = Cidades
        // E = Arrestas
        fscanf(stdin, "%d %d", &N, &E);

        if(N == 0 && E == 0) break;

        // seta a matriz com INFINITO
        for(i=1;i<=500;i++){
             for(j=i;j<=500;j++){
                matriz[i][j] = matriz[j][i] = INF;
            }
        }

        int x, y, h;
        for (i = 1; i <= E; ++i){
            // le coordenadas
            // h = hora
            fscanf(stdin, "%d %d %d", &x, &y, &h);

            if(matriz[y][x] != INF){
                // seta como distancia 0
                matriz[x][y] = matriz[y][x] = 0;
            }else{
                // adiciona na matriz
                matriz[x][y] = h;
            }
        }

//      debug
//		for(i=1;i<E;i++){
//			for(j=1;j<E;j++){
//				printf("%d ", matriz[i][j]);
//			}
//			printf("\n");
//		}

        int k = 0;
        // k = numero de consultas
        fscanf(stdin, "%d", &k);

        int O, D;
        // le e calcula as consultas
        for (i = 0; i < k; ++i){
            fscanf(stdin, "%d %d", &O, &D);

            dijkstra(O, D, N);
        }

        printf("\n");
     }

    return 0;
}
