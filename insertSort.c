void insercao(int A[], int n)
{
   int chave, i, j;
   for (j = 1; j < n; j++) {
      chave = A[j];
      for (i = j - 1; (i >= 0) && (A[i] > chave); i--)
         A[i+1] = A[i];
      A[i+1] = chave;
   }
}

#define N 100000
   //int A[N], n = N;
   //for (int i = 0; i < N; i++) A[i] = i + 1; //Cescente
   //for (int i = 0; i < N; i++) A[i] = N - i; //Decrescente
   //insercao(A, n);


using namespace std;

#include<iostream>
int main(){
     clock_t begin = clock();

     int A[N], n = N;

     for (int i = 0; i < N; i++){
       A[i] = N-i;
     }

      insercao(A,100000);


     clock_t end = clock();

     cout << double(end-begin)/CLOCKS_PER_SEC
     << "segundos" << endl;

     return 0;
   }
