#include <stdio.h>
#include <string.h>

int matriz[301][301];
int visit[301];
char pessoas[301][30];
int count = 0;

void dfs(int v, int N){
	int i;
	visit[v] = 1; //Visita-se v marcando-o como visitado

	for(i=1;i<=N;i++)
		if (matriz[v][i]==1 && visit[i]==0)
			dfs(i, N);
}

// VERIFICA PESSOA JA FOI INSERIDA. ADD RELAÇÃO
int verificaPessoa(char *p1){
	int id = 0, j;
	for(j=1;j<=300;j++){
		if(strcmp(pessoas[j], p1) == 0) {id = j; break;}
	}

	if(id==0){
		strcpy(pessoas[++count], p1);
		return count;
	}

	return id;
}

int main(void) {
	int M, N; // M = Pessoas | N = numero ligações
    int i, j;
    int x, y;

	fscanf(stdin, "%d %d", &M, &N);

	// seta a matriz com 0
	for(i=1;i<=300;i++){
		 for(j=i;j<=300;j++){
			matriz[i][j] = matriz[j][i] = 0;
		}
	}

	char p1[50], rel[50], p2[50];
	int id;
	for(i = 1; i <= N; i++){
		// le nome pessoas
		fscanf(stdin, "%s %s %s", p1, rel, p2);

		x = verificaPessoa(p1);
		y = verificaPessoa(p2);

		matriz[x][y] = matriz[y][x] = 1;
	}

	int falta_visitar = 1, num_familias = 0;
	do{
		++num_familias;
		dfs(falta_visitar, M);

		for(j=1;j<=M;j++){
			if(visit[j] == 0) {falta_visitar = j; break;}
			else falta_visitar = 0;
		}
	}while(falta_visitar);


	printf("%d\n", num_familias);

//  debug
//	printf("\n");
//	for(i=1;i<=M;i++){
//		for(j=1;j<=M;j++){
//			printf("%d ", matriz[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//	for(j=1;j<=M;j++){
//		printf("%d ", visit[j]);
//	}

    return 0;
}
