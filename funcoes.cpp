#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Tupla{
	int qtd;
	int valor;
};

int majoritario_forca_bruta(int A[], int n){
	int cont;
	for(int i = 0; i < n/2; i++){
		cont = 0;
		for(int j = i; j < n - 1; j++){
			if(A[i] == A[j]) cont += 1;
			if(cont > n/2) return A[i];
		}
	}
	return -1;
}

Tupla majoritario_rec(int A[], int ini, int fim){
	Tupla tupla;
	if(ini == fim){
		tupla.qtd = 1;
		tupla.valor = A[ini];
		return tupla;
	}
	int meio  = (inicio + fim)/2;
	Tupla valor1 = majoritario_rec(A, ini, meio);
	Tupla valor2 = majoritario_rec(A, meio+1, fim);

	if(valor1.qtd == valor2.qtd){
		tupla.qtd = valor1.qtd + valor2.qtd;
		tupla.valor = valor1.valor;
		return tupla;

	}else if(valor1.qtd > valor2.qtd){
		tupla.qtd = valor1 - valor2.qtd;
		tupla.valor = valor1.valor;
		return tupla;

	} else{
		tupla.qtd = valor2.qtd - valor1.qtd;
		tupla.valor = valor2.valor
		return tupla;
	}
}

int majoritario_ordenando(int A[], int n){
	sort(A, A + n);
	for(int i = 0; i < (n-1)/2; i++){
		if(A[i] == A[i+n/2]) return A[i];
	}
	return -1;
}

int majoritario_divisao_conquista(int A[], int n){
	Tupla t = majoritario_rec(A, 0, n-1);
	int cont = 0;
	for(int i = 0; i < n; i++){
		if(A[i] == t.valor) cont++;
		if(t.qtd > 0 && cont > n/2) return t.valor;
	}
	return -1;
}

int majoritario_iterativo(int A[], int n){
	int qte = 0;
	int valor;
	for(int i = 0; i < n-1; i++){
		if(qte == 0){
			qte += 1;
			valor = A[i]
		}else if(A[i] == valor) qte += 1;
		else qte -= 1;
	}
	if(qte == 0) return -1
	if(valor > A[].size()/2) return valor;
	return -1;
}
