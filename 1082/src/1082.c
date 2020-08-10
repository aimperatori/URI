#include <stdio.h>

int matriz[27][27];
int visit[27];

void dfs(int v, int N, int count){
	int i;
	visit[v] = count; //Visita-se v marcando-o como visitado

	for(i=1;i<=N;i++)
		if (matriz[v][i]==1 && visit[i]==0)
			dfs(i, N, count);
}

int main(void) {
    int N, gcont = 0; // quantidade testes
	int V, E; // V = vertices | E = arestas
    int i, j;

    fscanf(stdin, "%d", &N);

    while(++gcont <= N){

    	printf("Case #%d:\n", gcont);

		fscanf(stdin, "%d %d", &V, &E);

		// seta a matriz com 0
		for(i=1;i<=27;i++){
			 for(j=i;j<=27;j++){
				matriz[i][j] = matriz[j][i] = 0;
			}
		}

		char x, y;
		int x_int, y_int;
		for (i = 1; i <= E; ++i){
			// le coordenadas
			fscanf(stdin, "\n%c %c", &x, &y);

			// converte a-z para 1-26
			x_int = (int) (x - 96);
			y_int = (int) (y - 96);

			matriz[x_int][y_int] = matriz[y_int][x_int] = 1;
		}

		for(i=0;i<=V;i++) visit[i] = 0;

		int s = 1, count = 0, aux = 0;

		do{
			dfs(s, V, ++count);

			for(j=1;j<=V;j++){
				if(visit[j] == count) {printf("%c,", j+96);}
			}
			printf("\n");

			// procura se tem algum vertice nao visitado
			for(j=1;j<=V;j++)
				if(visit[j] == 0){
					s = j;
					aux = 1;
					break;
				}else{
					aux = 0;
				}
		}while(aux);

		printf("%d connected components\n", count);

//      debug
//		for(i=1;i<=V;i++){
//			for(j=1;j<=V;j++){
//				printf("%d ", matriz[i][j]);
//			}
//			printf("\n");
//		}
//		printf("\n");
//		for(j=1;j<=V;j++){
//			printf("%d ", visit[j]);
//		}

		printf("\n");
    }

    return 0;
}
