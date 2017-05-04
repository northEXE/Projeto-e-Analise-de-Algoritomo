#include <algorithm>
using namespace std;

typedef struct Tupla{
    int qte;
    int valor;
};
 

int majoritario_forca_bruta(int A[], int n){
    for(int i = 0; i <= n/2; i++){
        int count = 0;
        for(int j = i; j <= n-1 ;j++){
            if(A[i] == A[j]){
                count = count + 1;
            }
            if(count > n/2){
                return A[i];
            }
        }
    }
    return -1;
}

int majoritario_ordenando(int A[], int n){
    std::sort(A,A+n);
    for(int i = 0; i <= (n-1)/2 ;i++){
        if(A[i] == A[i + (n/2)]){
            return A[i];
        }
    }
    return -1;
}

Tupla majoritario_rec(int A[], int inicio, int fim){
    Tupla resp;
    if(inicio == fim){
        resp.qte = 1;
        resp.valor = A[inicio];
        return resp;
    }
    int meio = (inicio + fim) / 2;

    Tupla valor1 = majoritario_rec(A,inicio,meio);
    Tupla valor2 = majoritario_rec(A,meio+1,fim);

    if(valor1.valor == valor2.valor){
        resp.qte = valor1.qte + valor2.qte;
        resp.valor = valor1.valor;
        return resp;
    }
    else if(valor1.qte > valor2.qte){
         resp.qte = valor1.qte - valor2.qte;
         resp.valor = valor1.valor;
         return resp;
    }
    else{
        resp.qte = valor2.qte - valor1.qte;
        resp.valor = valor2.valor;
            return resp;
    }

}

int majoritario_divisao_conquista(int A[], int n){
    Tupla x = majoritario_rec(A,0,n-1);
    int cont = 0;
    for(int i = 0; i < n; i++){

    if(A[i] == x.valor){
            cont++;
        }
    if(x.qte > 0 && cont > n/2){
            return x.valor;
        }
    }
    
    return -1;
}


int majoritario_iterativo(int A[], int n){
    int qte = 0;
    int valor = 0;
    int  cont = 0;
    for( int i = 0 ; i <= n-1; i++){
        if(qte == 0 ){
            qte = qte + 1;
            valor = A[i];
        }else{
            if(A[i] == valor){
                qte = qte + 1;
            }else{
                qte = qte - 1;
            }
        }
    }
    if(qte == 0){
        return -1;
    }


    for(int i = 0; i <= n ;i++){
        if(valor == A[i]){
            cont = cont + 1;
        }
    }

    if(cont > n/2){
        return valor;
    }
    return -1;

}

