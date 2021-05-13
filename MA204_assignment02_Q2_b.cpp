// BISWARUP ROY
// BTECH/10048/19
// SEC- A
// MECHANICAL ENGINEERING


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double ld;
typedef vector<ll> vi;

// Assuming epsilon to be 10^(-4) as nothing is mentioned in the question. 
#define EPSILON 0.0001

// Function given in the question
ld f(ld x){
  return (x*x*x) - (4*x*x) + (5*x) - 2;

}

// First derivative of the function
ld f_dash(ld x){
  return (3*x*x) - (8*x) + (5) ;
}

// Second derivative of the function 
ld f_double_dash(ld x){
  return (6*x) - 8;
}

void newtons(ld x)
{
    int n=0;
    // ld k = f(x) / f_dash(x);

    ld k =(f(x)*f_dash(x))/((f_dash(x))*(f_dash(x)) - f(x)*f_double_dash(x));

    if(f_dash(x)==0 or ((f_dash(x))*(f_dash(x)) - f(x)*f_double_dash(x))==0  ){
        cout<<"Mathematical error, first derivative = 0 \nchange initial root for newton's method.\n";
        return;
    }
    while (abs(k) >= EPSILON)
    {
        k =(f(x)*f_dash(x))/((f_dash(x))*(f_dash(x)) - f(x)*f_double_dash(x));
  
        // x(i+1) = x(i) - h(x) / h'(x) 
        x = x - k;
        n++;
    }
 
    printf("Root (using newton's method) = %.5f\n", x);
    cout << "No. of iterations = " << n << endl;
}




int main()
{
  
  ld x0; // initial values for newton's method
  x0 = 5;
  newtons(x0);

  
  return 0;
}