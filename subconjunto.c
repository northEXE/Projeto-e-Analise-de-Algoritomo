#include<iostream>

using namespace std;

void imprime_bits(int b[], int n)
{
   for (int i = 0; i < n; i++)
      cout<<b[i]<<endl;
}

#define N 30
void seq_bits()
{
   int b[N] = {0}, i;
   while (1) {
      //imprime_bits(b,N);
      for (i = N-1; (i >= 0) && (b[i] == 1); i--)
         b[i] = 0;
      if (i < 0) break;
      b[i] = 1;
   }
}
