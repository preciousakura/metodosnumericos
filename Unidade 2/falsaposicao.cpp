#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#define E 2.7182
#define PI 3.1415

using namespace std;

double equacao(double valor){
  return (-1 * (pow(E, valor) / 2)) + 2 * cos(valor);
}

double falsaposicao(double a, double b) {
  double fa, fb, x, fx;
  double eps = 0.0001;
  
  cout << fixed << setprecision(4);
  
  if(fa * fb > 0) return -1;
  
  int i = 0;
  
  while(abs(b-a) > eps && i < 10000) {
    x = (a * equacao(a) - b * equacao(b)) / (equacao(a) - equacao(b));
    fx = equacao(x);
    fa = equacao(a);
    fb = equacao(b);
    
    if(abs(fx) < eps) return x;
    
    cout << i+1 << "ª Iteração" << endl;
    
    cout << "a: " << a << ", f(a): " << fa << endl;
    cout << "b: " << b << ", f(b): " << fb << endl;
    cout << "x: " << x << ", f(x): " << fx << endl;
    cout << endl;
    
    if(fa * fx > 0) {
      a = x;
    } else if(fb * fx > 0) {
      b = x;
    }
    
    i++;
  }
  return x;
}

int main() { 
  falsaposicao(0, PI/2);
  return 0;
}