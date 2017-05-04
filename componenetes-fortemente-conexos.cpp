#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

enum cor{branco, cinza, preto};

vector <list <int> > adj;
vector <list <int> > adjT;
vector <int> cor, pi, d, f;
list <int> ord_topologica;
int tempo = 0;

void le_grafo_lst(){
   string linha;
   for (int u = 0; getline(cin,linha); u++) {
      const string s = linha;
      adj.push_back(list<int>());
      string::const_iterator ini = s.begin(), fim;
      if (ini == s.end()) continue;
      do {
         fim = find(ini,s.end(),' ');
         adj[u].push_back(atoi(string(ini,fim).c_str()));
         ini = fim + 1;
      } while (fim != s.end());
   }
}

bool dfs_visit(int u){
	list<int>::iterator it;
	cor[u] = cinza;
	tempo++;
	d[u] = tempo;
	for(it = adj[u].begin(); it != adj[u].end(); it++){
		if(cor[*it] == branco){
			pi[*it] = u;
			dfs_visit(*it);
		} if(cor[*it] == cinza){
			return false;
		}
	}
	cor[u] = preto;
	tempo++;
	f[u] = tempo;
	ord_topologica.push_front(u);
	return true;
}

bool dfs(){
	for (int u = 0; u < adj.size(); u++){
		cor[u] = branco;
		pi[u] = -1;
	}
	for(int u = 0; u < adj.size(); u++){
		if(cor[u] == branco){
			if(dfs_visit(u) == false)
				return false;
		}

	}
	return true;
}

void grafo_tranposto(){
	 for(int i = 0; i < adj.size(); i++){
        list<int>::iterator it;
        for(it = adj[i].begin(); it != adj[i].end(); it++){
            adjT[*it].push_back(i);
        }
    }
}

void dfs_visit_comp(int u){
	cout << u << " ";
	list<int>::iterator it;
	cor[u] = cinza;
	tempo++;
	d[u] = tempo;
	for(it = adjT[u].begin(); it != adjT[u].end(); it++){
		if(cor[*it] == branco){
			pi[*it] = u;
			dfs_visit_comp(*it);
			}
	}
	cor[u] = preto;
	tempo++;
	f[u] = tempo;
}

void dfs_comp(){
	for(int i = 0; i < adj.size(); i++){
		cor[i] = branco;
		pi[i] = -1;
	}
	tempo = 0;
	list<int>::iterator it;
	for(it = ord_topologica.begin(); it != ord_topologica.end(); it++){
		if(cor[*it] == branco){
			dfs_visit_comp(*it);
			cout << endl;
		}
	}
}

void componentes_fortemente_conexos(){
	dfs();
	cor.resize(adj.size(), 0), d.resize(adj.size(), 0), pi.resize(adj.size(), 0), f.resize(adj.size(), 0);
	grafo_tranposto();
	dfs_comp();

}

int main(){
	le_grafo_lst();
	adjT.resize(adj.size());
	cor.resize(adj.size(), 0), d.resize(adj.size(), 0), pi.resize(adj.size(), 0), f.resize(adj.size(), 0);
	componentes_fortemente_conexos();
	return 0;
}