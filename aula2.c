#include<iostream>
#include<ctime>
#include"permutacao.c"
#include"subconjunto.c"

using namespace std;

int main(){
  clock_t begin = clock();
  int s[] = {0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1};
  char s1[] = "ABCDEFGH";
  //permuta(s1,0,strlen(s1)-1);


  seq_bits();
  //imprime_bits(s,30);
  clock_t end = clock();

  cout << double(end-begin)/CLOCKS_PER_SEC
  << "segundos" << endl;

  return 0;
}
