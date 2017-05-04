#include <iostream>
#include <stack>
#define N 9
using namespace std;
stack<int> pilha, aux;

int i;

int popular_pilha(){
	i = 0;
	while(i < N){
		pilha.push(i);
		i++;
	}
}

void mostrar_pilha(){
	int j = 0, atual;
	stack<int> aux1;
	while(j < pilha.size()){
		atual = pilha.top();
		aux1.push(pilha.top());
		pilha.pop();
		cout << atual << endl;
	}
	while(!aux1.empty()){
		pilha.push(aux1.top());
		aux1.pop();
	}
}

int retornar_menor_elemento(){
	int menor = pilha.top(); //1
	aux.push(pilha.top()); //1
	pilha.pop(); //1
	while(!pilha.empty()){ //n 
		if(pilha.top() < menor){ //n - 1
			menor = pilha.top(); //n - 1
			aux.push(pilha.top()); //n - 1
			pilha.pop(); //n - 1
		} else { //n - 1
			aux.push(pilha.top());//n - 1
			pilha.pop();//n - 1
		}
	}
	while(!aux.empty()){//n + 1
		pilha.push(aux.top());//n
		aux.pop();//n
	}
	return menor;//1
}

int main(){
	popular_pilha();
	mostrar_pilha();
	cout << endl << "O menor elemento da pilha é: " << retornar_menor_elemento() << endl;

}