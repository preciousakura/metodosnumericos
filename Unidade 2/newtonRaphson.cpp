#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#define E 2.7182
#define PI 3.1415

using namespace std;

double funcao(double valor){
  return (-1 * (pow(E, valor) / 2)) + 2 * cos(valor);
}

double funcaoDerivada(double valor){
  return ((-1 * 0.5) * pow(E, valor)) - 2 * sin(valor);
}

double newtonRaphson(double aAnterior) {
  double aAtual;
  double eps = 0.0001;
  int k = 0;
  
  cout << fixed << setprecision(4);
  
  while(true) {
      cout << k+1 << "ª Iteração" << endl;
    
    cout << "a: " << aAtual << ", f(a): " << funcao(aAtual) << endl;
    cout << endl;
    
    aAtual = aAnterior - (funcao(aAnterior)/funcaoDerivada(aAnterior));
    
    if(abs(aAtual - aAnterior) < eps || abs(funcao(aAtual)) < eps || k >= 12) return funcao(aAtual);
    aAnterior = aAtual;
    ++k;
  }
}

int main() { 
  newtonRaphson(0);
  return 0;
}