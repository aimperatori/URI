#include <stdio.h>
#include <stdlib.h>

#define INF 999999
#define N 7

int vt[N];

int visit[N];
int x[N], y[N];

void dfs(int G[N][N], int v, int nivel, int soma, int *otima) {
	vt[nivel] = v;
	int i;
	if (nivel == N - 1 && G[v][0] > 0) {
		if (soma + G[v][0] < *otima) {
			*otima = soma + G[v][0];
			for (i = 0; i < N; i++)
				printf("%d ", vt[i]);
			printf("novaotima=%d\n", *otima);
		}
		return;
	}
	visit[v] = 1;
	for (i = 0; i < N; i++)
		if (G[v][i] > 0 && visit[i] == 0)
			dfs(G, i, nivel + 1, soma + G[v][i], otima);
	visit[v] = 0;
}

int main() {
	int G[N][N];
	int i, j;

	int C;

	fscanf(stdin, "%d", &C);

	while(C--){

		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				G[i][j] = rand()%100;
			}
		}

		for(j=0;j<N;j++){
			visit[i] = 0;
			x[i] = y[i] = INF;
		}


		for(i=1;i<=N;i++){
			fscanf(stdin, "%d %d", &x[i], &y[i]);
		}

		int otima = 1000000;
		dfs(G, 0, 0, 0, &otima);

		printf("Otima=%d\n", otima);


	}

	return 0;
}
