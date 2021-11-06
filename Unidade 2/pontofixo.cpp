#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#define E 2.7182
#define PI 3.1415

using namespace std;

// f(a) = a3 – 9a + 3
double funcao(double valor) {
  return pow(valor,3) - 9 * valor + 3;
}
// a = sqtr() 
double ga(double valor) {
  return pow(3 * (3 * valor - 1), 1.0/3.0);
}

double pontofixo(double aAnterior) {
 double aAtual;
  double eps = 0.0001;
  int k = 0;
  
  cout << fixed << setprecision(4);
  
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