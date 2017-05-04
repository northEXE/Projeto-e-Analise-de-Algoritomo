#include<string.h>
#include<iostream>

using namespace std;

void troca(char *x, char *y){
  char t;
  t = *x;
  *x = *y;
  *y = t;
}

void permuta(char *s, int ini, int fim){
  if(ini == fim); //cout<< s <<endl;
  else
  for(int i = ini; i <= fim; i++){
    troca(&s[ini], &s[i]);
    permuta(s, ini+1,fim);
    troca(&s[ini],&s[i]);
  }
}
