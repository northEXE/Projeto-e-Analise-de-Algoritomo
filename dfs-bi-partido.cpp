#include <iostream>
#include <list>
#define N 9
using namespace std;

enum cores{branco, cinza, preto};

int cor[N];
int pi[N];
list<int> adj[N];
char conj[N];

void inicializa_grafo(){
	enum vertices {cueca, meia, calca, sapato, relogio, cinto, camisa, gravata, paleto};
	adj[cueca].push_back(calca);
	adj[cueca].push_back(sapato);
	adj[meia].push_back(sapato);
	adj[calca].push_back(sapato);
	adj[calca].push_back(cinto);
	adj[camisa].push_back(cinto);
	adj[camisa].push_back(gravata);
	adj[cinto].push_back(paleto);
	adj[gravata].push_back(paleto);

	// Transforma em não direcionado
	for (int u = 0; u < N; u++){
		for (list<int>::iterator v = adj[u].begin(); v != adj[u].end(); v++){
			adj[*v].push_back(u);
		}
	}
}

void imprimeCiclo(int u, int v){
	int w;
	cout << v << " ";
	w = u;
	while(w != v){
		cout << w << " ";
		w = pi[w];
	}
}

bool dfs_visit_bi_partido(int u){
	list<int>::iterator it;
	cor[u] = cinza;
	for(it = adj[u].begin(); it != adj[u].end(); it++){
		if(cor[*it] == branco){
			pi[*it] = u;
			conj[*it] = (conj[u] == 'A') ? 'B' : 'A';
			return dfs_visit_bi_partido(*it);
			} else if(conj[*it] == conj[u]){
				imprimeCiclo(u, *it);
				return false;
			}
	}
	return true;
}

bool dfs_bi_partido(){
	for(int u = 0; u < N; u++){
		cor[u] = branco;
		pi[u] = -1;
	}
	for(int u = 0; u < N; u++){
		if(cor[u] == branco){
			conj[u] = 'A';
			if(dfs_visit_bi_partido(u) == false) 
				return false;
		}
	}
	return true;
}

	int main(){
		inicializa_grafo();
		if(dfs_bi_partido()){
			cout << endl << "1" << endl;
		} else {
			cout << endl << "0" << endl;
		}

		for(int i = 0; i < N; i++){
			if(conj[i] != 'A' && conj[i] != 'B'){
				conj[i] = '_';
			}
			cout << conj[i];
		}
		
		return 0;
	}
