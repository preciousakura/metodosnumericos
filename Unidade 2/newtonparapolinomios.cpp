#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#define E 2.7182
#define PI 3.1415

using namespace std;

double newtonparapolinomios(int coeficientes[], double valorInicial, int n) {
  double eps = 0.0001, b, c;
  cout << fixed << setprecision(4);

  for(int k = 0; k < 10000; k++) { 
    b = coeficientes[n];
    c = b;
    for(int i = n-1; i > 0; i--) {
      b = coeficientes[i] + b*valorInicial;
      c = b + c*valorInicial;
    }
    b = coeficientes[0] + b*valorInicial;
    
    cout << k+1 << "ª Iteração" << endl;
    cout << "a: " << valorInicial << ", f(a): " << b << endl << endl;
    
    if(abs(b) <= eps) return valorInicial;
    valorInicial = valorInicial - (b/c);
  }
  return valorInicial;
}

int main() { 
  int coeficientes[] = {3, -9, 0, 1};
  int n = 4; // numero de coeficientes na função (grau do polinomio)
  
  newtonparapolinomios(coeficientes, 2, n-1);

  return 0;
}