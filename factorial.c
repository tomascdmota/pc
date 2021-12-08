#define _CTR_SECURE_NO_WARNINGS
#include <stdio.h>


long factorial(int n)  {  
  if (n == 0)  
    return 1;  
  else  
    return(n * factorial(n-1));  
}


long comb(int n, int p) {
    if (p == 0 && n == 0) 
        return 1;
    
     else  
        return (factorial(n)/ factorial(p) * factorial(n-p));
}

void main()
{  
  int n;  
  int p;
  long fact, combo; 

  printf("Enter n: ");  
  scanf("%d", &n);   

  printf("Enter p: ");
  scanf("%d", &p);
   
  fact = factorial(n);  

  combo = comb(n, p);

  printf("The combination of %d and %d is %ld \n", n, p, combo);
  printf("Factorial of %d is %ld\n", n, fact);  
}  