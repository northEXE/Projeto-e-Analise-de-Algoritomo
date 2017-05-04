#include <climits>
#include <list>
#include <iostream>

#define N 8
using namespace std;

enum vertices {s,w,r,t,x,v,u,y};
enum cores{branco, cinza, preto};

int cor[N];
int d[N];
int pi[N];
list<int> adj[N];
list<int> q;

void inicializa_grafo(){
   adj[s].push_back(w);
   adj[s].push_back(r);
   adj[r].push_back(s);
   adj[r].push_back(v);
   adj[v].push_back(r);
   adj[w].push_back(s);
   adj[w].push_back(t);
   adj[w].push_back(x);
   adj[t].push_back(w);
   adj[t].push_back(x);
   adj[t].push_back(u);
   adj[x].push_back(w);
   adj[x].push_back(t);
   adj[x].push_back(u);
   adj[x].push_back(y);
   adj[u].push_back(t);
   adj[u].push_back(x);
   adj[u].push_back(y);
   adj[y].push_back(x);
   adj[y].push_back(u);
}

void BFS(int s){
	
	for(int i = s + 1; i < N; i++){
		cor[i] = branco;
		d[i] = INT_MAX;
		pi[i] = - 1;
	}
	cor[s] = cinza;
	d[s] = 0;
	pi[s] = -1;
	q.push_back(s);
	
	while(!q.empty()){
		int aux = q.front();
		q.pop_front();
		list<int>::iterator i;
		for(i = adj[aux].begin(); i != adj[aux].end(); i++){
			if(cor[*i] == branco){
				cor[*i] = cinza;
				d[*i] = d[aux] + 1;
				pi[*i] = aux;
				q.push_back(*i);
			} 
		}
		cor[aux] = preto;
	}
}

int main(){
	inicializa_grafo();
	BFS(0);
	for(int i = 0; i < N; i++){
		cout << d[i] << " ";
	}
	cout << endl;
	for(int i = 0 ; i < N; i++){
		cout << pi[i] << " ";
	}
	return 0;
}
