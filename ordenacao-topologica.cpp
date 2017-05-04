#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

enum cor{branco, cinza, preto};

vector <list <int> > adj;
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

int main(){
	le_grafo_lst();
	cor.resize(adj.size(), 0), d.resize(adj.size(), 0), pi.resize(adj.size(), 0), f.resize(adj.size(), 0);
	if(dfs() == true){
		cout << 1 << endl;
		list<int>::iterator it;
		for(it = ord_topologica.begin(); it!= ord_topologica.end(); it++){
			cout << *it << " ";
		}
	} else 
		cout << 0;
	return 0;
}