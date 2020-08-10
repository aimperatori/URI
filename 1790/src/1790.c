#include <stdio.h>

int matriz[51][51];
int low[51];
int nivel[51];

int dfs(int v, int niv, int N){
	nivel[v] = niv;
	int i;
	for(i=1;i<=N;i++)
		if (matriz[v][i] == 1 && nivel[i] == -1){
			matriz[v][i] = 2;
			matriz[i][v] = 0;
			dfs(i, niv+1, N);
		}
}

int lowpt(int v, int N){
	if (low[v]!=-1)
		return low[v]; // se low[v] ja esta definido, retorna
	low[v]=v; // valor inicial  ́e o proprio v
	int i;
	for(i=1;i<=N;i++)
		if(matriz[v][i] == 2 && nivel[lowpt(i, N)] < nivel[low[v]])
			low[v]=low[i]; // se lowpt do filho e menor, atualiza lowpt do pai
		else if(matriz[v][i] == 1 && nivel[i] < nivel[low[v]])
			low[v] = i; // se tem aresta de retorno para cima, atualiza lowpt
	return low[v];
}

int main(void) {
	int C, P; // C = Cidades | P = Pontes
    int i, j;

    while(fscanf(stdin, "%d %d", &C, &P) != EOF){
//    	fscanf(stdin, "%d %d", &C, &P);

		// seta a matriz com 0
		for(i=1;i<=50;i++){
			 for(j=i;j<=50;j++){
				matriz[i][j] = matriz[j][i] = 0;
			}
		}

		int x, y;
		for(i=1;i<=P;i++){
			fscanf(stdin, "%d %d", &x, &y);

			matriz[x][y] = matriz[y][x] = 1;
		}

		// inicializa
		for(i=1;i<=C;i++) nivel[i] = -1;
		for(i=1;i<=C;i++) low[i] = -1;

		dfs(1, 1, C);

		// calcula lowpt
		lowpt(1, C);

		int count = 0;
		for(i=2;i<=C;i++){
			if(nivel[i] == low[i]) count++;
		}
		printf("%d\n", count);
    }

    return 0;
}
