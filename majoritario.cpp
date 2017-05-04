#include <algorithm>
using namespace std;
// Encontrar elemento majoritário.
// Recebe um vetor A contendo n elementos não negativos.
// Retorna o valor que aparece em mais da metade dos elementos de A, ou -1 se
// não existe este valor. Obs.: Não assume que o vetor A está ordenado.

typedef struct {
    int qte;
    int valor;
   
    
}tupla;
 

//MAJORITARIO_FORCA_BRUTA(A,n): pior caso
//1   para i de 0 até n/2           n/2+2
//2      cont <- 0                  n/2+1
//3      para j de i até n-1        n-i+1
//4         se A[i] == A[j]         n-i
//5            cont <- cont + 1     n-i
//6         se cont > n/2           n-i
//7            retorne A[i]         0
   retorne -1                    1

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


//MAJORITARIO_ORDENANDO(A,n):
//   ordene o vetor A              n log n
//   para i de 0 até (n-1)/2       (n-1)/2+2
//      se A[i] == A[i+n/2]        (n-1)/2+1
//         retorne A[i]            0
//   retorne -1

int majoritario_ordenando(int A[], int n){
    std::sort(A,A+n);
    for(int i = 0; i <= (n-1)/2 ;i++){
        if(A[i] == A[i + (n/2)]){
            return A[i];
        }
    }
    return -1;
}


// Após cancelar pares de elementos distintos, resta apenas 'qte' elementos com o mesmo valor ('valor').
//(qte,valor) <- MAJORITÁRIO_REC(A,ini,fim):
//   se ini == fim, retorne (1, A[ini])                    1
//   meior <- (ini+fim)/2                                  1
//   (qte1,valor1) <- MAJORITÁRIO_REC(A,ini,meio)          T(n/2)
//   (qte2,valor2) <- MAJORITÁRIO_REC(A,meio,fim)         T(n/2)
//   se valor1 == valor2                                   1
//      retorne (qte1+qte2, valor1)
//   senão, se qte1 > qte2                                 1
//      retorne (qte1-qte2, valor1)
//   senão
//      retorne (qte2-qte1, valor2)                        1

//MAJORITARIO_DIVISAO_CONQUISTA(A,n):
//   (qte,valor) <- MAJORITÁRIO_REC(A,0,n-1)               T(n)
//   se qte > 0 e 'valor' ocorre em mais da metade de A    O(n)
//      retorne valor
//   retorne -1



tupla MAJORITARIO_REC(int A[], int inicio, int fim){
    tupla resp;
    if(inicio == fim){
        resp.qte = 1;
        resp.valor = A[inicio];
        return resp;
    }
    int meio = (inicio + fim) / 2;

    tupla valor1 = MAJORITARIO_REC(A,inicio,meio);
    tupla valor2 = MAJORITARIO_REC(A,meio+1,fim);

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
    tupla x = MAJORITARIO_REC(A,0,n-1);
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

