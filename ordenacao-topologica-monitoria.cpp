#include <iostream>
#include <algorithm>
#include <list>
#define N 8
using namespace std;

/*
01 - b, a, c, e, d1, f1, h, g
02 - A > B > C > D1 > E > F1 > G > H
03 - fontes: a, b; sorvedouros: g,h.
*/

enum vertices {a,b,c,d1,e,f1,g,h};
enum cores{branco, cinza, preto};

int cor[N];
int d[N];
int f[N];
int pi[N];
list<int> adj[N];
int tempo = 0;

void inicializa_grafo(){
   adj[a].push_back(c);
   adj[b].push_back(c);
   adj[c].push_back(d1);
   adj[c].push_back(e);
   adj[d1].push_back(f1);
   adj[e].push_back(f1);
   adj[f1].push_back(g);
   adj[f1].push_back(h);
}


int dfs_visit(int u){
	list<int>::iterator it;
	cor[u] = cinza;
	tempo++;
	d[u] = tempo;
	for(it = adj[u].begin(); it != adj[u].end(); it++){
		if(cor[*it] == branco){
			pi[*it] = u;
			dfs_visit(*it);
			}
	}
	cor[u] = preto;
	tempo++;
	f[u] = tempo;
}

void dfs(){
	for(int u = 0; u < N; u++){
		cor[u] = branco;
		pi[u] = -1;
	}
	tempo = 0;
	for(int u = 0; u < N; u++){
		if(cor[u] == branco)
			dfs_visit(u);
	}
}


bool comp_func(int a, int b){
	return f[b] < f[a];
}

	int main(){
		inicializa_grafo();
		int vet[N];
		for (int i = 0; i < N; i++)
			vet[i] = i;
		
		dfs();

		sort(vet, vet + N, comp_func);

		for (int i = 0; i < N; i++)
			cout << vet[i] << " ";		

		return 0;
	}
