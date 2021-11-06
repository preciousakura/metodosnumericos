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

double secante(double a, double b) {
  double aAtual;
  double eps = 0.0001;
  int k = 0;
  
  cout << fixed << setprecision(4);
  
  while(true) {
    aAtual = (a * funcao(b) - b * funcao(a)) / (funcao(b) - funcao(a));
    cout << k+1 << "ª Iteração" << endl;
    
    cout << "a: " << aAtual << ", f(a): " << funcao(aAtual) << endl;
    cout << endl;
    
    if(abs(aAtual - b) < eps || abs(funcao(aAtual)) < eps || k >= 12) return funcao(aAtual);
    a = b;
    b = aAtual;
    ++k;
  }
}

int main() { 
  secante(0.5, 1);
  return 0;
}