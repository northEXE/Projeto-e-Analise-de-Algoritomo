#include <algorithm>
using namespace std;

struct Tupla{
	float min;
	float max;
	float scm;
};

float scm_forca_bruta(float S[], int n){
	float maior = 0;
	for (int i = 0; i < n; i++){
		for(int j = 0; j < i + 1; j++){
			if(S[j]-S[i] > maior)
				maior = S[j]-S[i];
		}
	}
	return maior;
}

Tupla scm_dc_rec(float S[], int ini, int fim){
	if(ini + 1 == fim){
		Tupla tupla;
		t.min = min(S[ini], S[fim]);
		t.max = max(S[ini], S[fim]);
		t.scm = max(0.0f, S[ini], S[fim]);
		return tupla;
	}
	int meio = (ini + fim) / 2;
	Tupla t1 = scm_dc_rec(S, ini, meio);
	Tupla t2 = scm_dc_rec(S, meio, fim);

	Tupla tx;
	tx.min = min(t1.min, t2.min);
	tx.max = max(t1.max, t2.max);
	tx.scm = max(max(t1.scm, t2.scm), t2.max-t1.min);	
	return tx;
}

float scm_divisao_conquista(float S[], int n){
	Tupla tupla = scm(S[], 0, n);
	return scm
}

float scm_interativo(float S[], int n){
	Tupla tx;
	tx.min = 0;
	tx.scm - 0;
	for (int i = 0; i < n; i++){
		tx.scm = max(tx.scm, S[i] - tx.min);
		tx.min = min(tx.min, S[i]);
	}
	return tx.scm;
}