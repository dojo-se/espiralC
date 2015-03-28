#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//inicio uma tabela pra receber as espirais até 100x100
int tabela[101][101];

void imprime(int linhas,int colunas){
	int i=0,j=0;
	for(i=0;i<linhas;i++){
		for(j=0;j<colunas;j++){
			printf("%4d ",tabela[i][j]);
		}
		printf("\n");
	}
	return;
}

void gera_espiral(int linhas,int colunas){
	int i=0,j=0,k=0,l=0;
	int N=0,E=1,S=0,W=0;
	l=colunas*linhas;
	for(k=0;k<l;k++){
		tabela[i][j]=k+1;
		if(E==1){
			j++;
			if(tabela[i][j+1]!=0) {
				E=0;
				S=1;	
			}
		}else if(S==1){
			i++;
			if(tabela[i+1][j]!=0){
				S=0;
				W=1;
			}
		}else if(W==1){
			j--;
			if(tabela[i][j-1]!=0){
				W=0;
				N=1;
			}
		}else if(N==1){
			i--;
			if(tabela[i-1][j]!=0){
				N=0;
				E=1;
			}
		}
	}
	return;
}

int main(){
	int i=0,j=0,linhas=0,colunas=0;
	printf("Digite o numero de linhas e colunas\n");
	scanf("%d %d",&linhas,&colunas);
	memset(*tabela,0xff,sizeof(tabela));
	for(i=0;i<linhas;i++){
		for(j=0;j<colunas;j++){
			tabela[i][j]=0;
		}
	}	
	gera_espiral(linhas,colunas);
	imprime(linhas,colunas);
	return 0;
}
