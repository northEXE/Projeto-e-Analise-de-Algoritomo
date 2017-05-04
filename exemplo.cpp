#include <iostream>
#include <string>
using namespace std;

string frase = "Na minha fazenda, tenho um cachorro, um gato e um jumento", palavra;
int i = 0, j = 0;
int numeroOcorrenciasCachorro(){
	int numeroOcorrencias = 0;
	while(i != frase.length()){
		while(j != palavra.length()){
		if(frase[i] != ' '){
			palavra[j] = frase[i];
			j++;
			cout << palavra;
		}
		if(frase[i] == ' '){
			if(palavra == "cachorro"){
				numeroOcorrencias += 1;	
				palavra.erase();
				}
			} else if(palavra != "cachorro"){
				palavra.erase();
			}
			break;
		}
	i++;
	j = 0;
	palavra.resize(0);
		}
		return numeroOcorrencias;	
	}
	


int numeroOcorrenciasGato(){
	int numeroOcorrencias = 0;
	while(i != frase.length()){
		while(j != palavra.length()){
		if(frase[i] != ' '){
			palavra[j] = frase[i];
			j++;
			cout << palavra;
		}
		if(frase[i] == ' '){
			if(palavra == "cachorro"){
				numeroOcorrencias += 1;	
				palavra.erase();
				}
			} else if(palavra != "cachorro"){
				palavra.erase();
			}
			break;
		}
	i++;
	j = 0;
	palavra.resize(0);
		}
		return numeroOcorrencias;	
	}



int numeroOcorrenciasJumento(){
	int numeroOcorrencias = 0;
	while(i != frase.length()){
		while(j != palavra.length()){
		if(frase[i] != ' '){
			palavra[j] = frase[i];
			j++;
			cout << palavra;
		}
		if(frase[i] == ' '){
			if(palavra == "cachorro"){
				numeroOcorrencias += 1;	
				palavra.erase();
				}
			} else if(palavra != "cachorro"){
				palavra.erase();
			}
			break;
		}
	i++;
	j = 0;
	palavra.resize(0);
		}
		return numeroOcorrencias;	
	}

int main(){
	cout << 0 << " " << numeroOcorrenciasCachorro() << endl;
	cout << 1 << " " << numeroOcorrenciasGato() << endl;
	cout << 2 << " " << numeroOcorrenciasJumento() << endl;
}