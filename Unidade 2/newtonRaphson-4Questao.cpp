#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#define E 2.718281
#define PI 3.141592

using namespace std;

double funcao(double valor){
  return valor * (1 - (log(valor)/log(E)));
}

double funcaoDerivada(double valor){
  return -1 * (log(valor)/log(E));
}

double newtonRaphson(double aAnterior) {
  double aAtual;
  double eps = 0.00001;
  int k = 0;
  
  cout << fixed << setprecision(6);
  
  while(true) {
    cout << k+1 << "ª Iteração" << endl;
    
    cout << "a: " << aAnterior << ", f(a): " << funcao(aAnterior) << endl;
    cout << endl;
    
    aAtual = aAnterior - (funcao(aAnterior)/funcaoDerivada(aAnterior));

    
    if(abs(aAtual - aAnterior) < eps || abs(funcao(aAtual)) < eps || k >= 12) return funcao(aAtual);
    aAnterior = aAtual;
    ++k;
  }
}

int main() { 
  newtonRaphson(2);
  return 0;
}