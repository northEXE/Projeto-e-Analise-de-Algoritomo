#include <iostream>
#include <list>
#define N 8
using namespace std;

enum vertices {s,t,u,v,x,y,w,z};
enum cores{branco, cinza, preto};

int cor[N];
int d[N];
int f[N];
int pi[N];
list<int> adj[N];
int tempo = 0;

void inicializa_grafo(){
   adj[s].push_back(z);
   adj[s].push_back(w);
   adj[z].push_back(y);
   adj[z].push_back(w);
   adj[y].push_back(x);
   adj[x].push_back(z);
   adj[w].push_back(x);
   adj[t].push_back(v);
   adj[t].push_back(u);
   adj[v].push_back(w);
   adj[v].push_back(s);
   adj[u].push_back(v);
   adj[u].push_back(t);
}

void dfs_visit(int u){
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

void print_path(int s, int v){
	if(v==s){
		cout << s << endl;
	}else{
		if(pi[v] == -1){
			cout << s << " ";
		}else{
			print_path(s, pi[v]);
			cout << v << " ";
		}
	}
}
	int main(){
		inicializa_grafo();
		dfs();
		cout << endl;
		for(int i = 0; i < N; i++){
			cout << d[i] << " ";
		}

		cout << endl;

		for(int i = 0; i < N; i++){
			cout << f[i] << " ";
		}

		cout << endl;

		for(int i = 0; i < N; i++){
			cout << pi[i] << " ";
		}

		return 0;
	}
