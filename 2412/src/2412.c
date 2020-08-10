#include <stdio.h>
#include <math.h>

#define INF 999999

double matriz[1001][1001];
int visit[1001];
int x[1001], y[1001];

void dfs(int v, int N, int D){
	int i;
	visit[v] = 1; // Visita-se v marcando-o como visitado

	for(i=1;i<=N;i++)
		if(matriz[v][i]<=D && visit[i]==0)
			dfs(i, N, D);
}

double dist(int i, int j){
    double DX = x[i] - x[j];
    double DY = y[i] - y[j];

    return sqrt(DX*DX+DY*DY);
}

int main(void) {
	int N, D;
    int i, j;

	fscanf(stdin, "%d %d", &N, &D);

	// seta a matriz com 0
	for(i=1;i<=1001;i++){
		 for(j=i;j<=1001;j++){
			matriz[i][j] = matriz[j][i] = 0;
		}
		x[i] = y[i] = INF;
	}

	for(i=1;i<=N;i++){
		fscanf(stdin, "%d %d", &x[i], &y[i]);
	}

	// cria matriz
	for(i=1;i<=N;i++){
		 for(j=i;j<=N;j++){
			matriz[i][j] = matriz[j][i] = dist(i, j);
		}
	}

	for(i=0;i<=N;i++) visit[i] = 0;

	dfs(1, N, D);

	char aux = 'S';
	for(i=1;i<=N;i++) {
		if(visit[i] == 0){
			aux = 'N';
			break;
		}
	}
	printf("%c\n", aux);


//      debug
//		for(i=1;i<=N;i++){
//			for(j=1;j<=N;j++){
//				printf("%.2lf ", matriz[i][j]);
//			}
//			printf("\n");
//		}
//		printf("\n");
//		for(j=1;j<=N;j++){
//			printf("%d ", visit[j]);
//		}


    return 0;
}
