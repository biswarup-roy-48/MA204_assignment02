// BISWARUP ROY
// BTECH/10048/19
// SEC- A
// MECHANICAL ENGINEERING

/*
    <!NOTE>
        *   First line of the input contains two numbers (double type) "a" and "b" that 
            are initial values for secant method.
        
        *   Second line of the input contain a single number (double type) "x0" i.e., 
            initial root for newton's method.
    
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double ld;
typedef vector<ll> vi;


#define EPSILON 0.0001

// Function given in the question
ld f(ld x){
  return (x*x*x) + (4.001*x*x) + (4.002*x) + 1.101;

}

// First derivative to the function
ld f_dash(ld x){
  return (3*x*x)-(8.002*x) + 4.002;
}
void secant(ld x1, ld x2) {
   ld n = 0, xm, x0, c;
   if (f(x1) * f(x2) < 0) {
      do {
         //calculating the intermediate value
         x0 = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
         c = f(x1) * f(x0);
         x1 = x2;
         x2 = x0;
         n++;
         if (c == 0)
         break;
         xm = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
      } while (fabs(xm - x0) >= EPSILON);
      
      printf("Root (using secant method) = %.5f\n", x0);
      cout << "No. of iterations = " << n << endl;
   } else
   cout << "Can not find a root in the given inteval\n";
}



void newtons(ld x)
{
    int n=0;
    ld h = f(x) / f_dash(x);
    if(!f_dash(x)){
        cout<<"Mathematical error, first derivative = 0 \nchange initial root for newton's method.\n";
        return;
    }
    while (abs(h) >= EPSILON)
    {
        h = f(x)/f_dash(x);
  
        // x(i+1) = x(i) - f(x) / f'(x) 
        x = x - h;
        n++;
    }
 
    printf("Root (using newton's method) = %.5f\n", x);
    cout << "No. of iterations = " << n << endl;
}




int main()
{
  ld a, b; //initial values for secant method
  ld x0; // initial values for newton's method
  
  cin>>a>>b>>x0;
  secant(a,b);
  newtons(x0);

  
  return 0;
}