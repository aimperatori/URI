#include <stdio.h>

#define INF 999999999

int matriz[501][501][501];

int min(int atual, int novo){
    if(atual < novo) return atual;
    else return novo;
}

void floydwarshall(int N){
    int k, i, j;

    for(k=1;k<=N;k++)
        for(i=1;i<=N;i++)
            for(j=1;j<=N;j++)
                matriz[k][i][j] = min(matriz[k-1][i][j], matriz[k-1][i][k] + matriz[k-1][k][j]);
}

int main(void) {
    int N, M;
    int i, j, k;

	// N = Cidades
	// M = Arrestas
    while (fscanf(stdin, "%d%d", &N, &M) != EOF) {

		// seta a matriz com INFINITO
		for(i=1;i<=500;i++){
			 for(j=i;j<=500;j++){
				matriz[0][i][j] = matriz[0][j][i] = INF;
			}
		}

		int U, V, W;
		for (i = 1; i <= M; ++i){
			// le cidades
			// D = distancia
			fscanf(stdin, "%d%d%d", &U, &V, &W);

			matriz[0][U][V] = matriz[0][V][U] = W;
		}

		floydwarshall(N);

		int Q, K;
		fscanf(stdin, "%d", &Q);
		while(Q--){
			fscanf(stdin, "%d%d%d", &U, &V, &K);

			if (U == V)
				printf("0\n");
			else if (matriz[K][U][V] == INF)
				printf("-1\n");
			else
				printf("%d\n", matriz[K][U][V]);
		}

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
