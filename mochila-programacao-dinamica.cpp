/*
Retorna valor ótimo da mochila, e grava em pred o vetor de predecessores.
- W: tamanho inicial da mochila.
- n: número de itens.
- P: vetor de pesos dos itens, do índice 1 até n (inclusive).
- V: vetor de valores dos itens, do índice 1 até n (inclusive).
- pred: vetor de predecessores (inicializado com -1). 
        Ou seja, pred[w] contém o índice do item escolhido quando mochila tem 
        capacidade w, ou -1 se nenhum item cabe na mochila.
*/
double mochila_prog_din(int W, int n, int P[], double V[], int pred[]){
	double matriz[W + 1][n - 1];
	for(int i = 0; i <= W; i++){
		for(int j = 0; j <= n; j++){
			matriz[j][i] = 0;
		}
	}	
	for(int i = 0; i <= W; i++){
		for(int j = 0; j <= n; j++){
			double maior = matriz[i][j-1];
			if(P[j] <= i){
				double v = V[j] + matriz[i - P[j]][j - 1];
				if(v > maior){
					maior = v;
					pred[i] = j;
				}
			}
			matriz[i][j] = maior;
		}
	}
	return matriz[W][n];

}