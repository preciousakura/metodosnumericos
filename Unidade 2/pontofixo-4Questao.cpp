#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#define E 2.718281
#define PI 3.141592

using namespace std;

// f(a) = a3 – 9a + 3
double funcao(double valor){
  return valor * (1 - (log(valor)/log(E)));
}

// a = sqtr() 
double ga(double valor) {
  return valor/(log(valor)/log(E));
}

double pontofixo(double aAnterior) {
 double aAtual;
  double eps = 0.00001;
  int k = 0;
  
  cout << fixed << setprecision(6);
  
  while(true) {
    cout << k+1 << "ª Iteração" << endl;
    cout << "a: " << aAnterior << ", f(a): " << funcao(aAnterior) << endl;
    cout << endl;
  
    aAtual = ga(aAnterior);
    if(abs(aAtual - aAnterior) < eps || abs(funcao(aAtual)) < eps || k >= 12) return funcao(aAtual);
    aAnterior = aAtual;
    ++k;
  }
}

int main() { 
  pontofixo(2);
  return 0;
}