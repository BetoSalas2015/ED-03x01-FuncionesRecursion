#include <stdio.h>			// para usar printf()
#include <stdlib.h>			// para usar system()

//   Factorial: n! = n * n-1 * n-2 * ... 3 * 2 * 1
int factoriali(int numero)
{
	int fact = 1, i;
	for(i = 1; i <= numero; ++i)
          fact = fact* i;
	return fact;
}

//  Modelo Matemático recursivo de n!
//			n! = 1					Si n = 1   Caso más simple
//          n! = n * (n - 1)!		Si n > 1	Aprox. al caso mas simple
int factorial(int n)
{
	if( n == 1 )						//  Criterio de paro (CMS)
		return 1;
	else								//   Aproximación al caso más simple
		return n * factorial(n - 1);	// Llamada recursiva
}

//   Ejercicio 1
//  
int multiplicacionI(int a , int b)
{
	int mult = 0, i;
	for(i = 1; i <= b; i++)
		mult = mult + a;
	return mult;
}

//     (a * b) = a					Si b = 1
//     (a * b) = a + (a * b-1)		Si b > 1
int multiplica( int a, int b)
{
	if(b == 1)
		return a;
	else
		return a + multiplica(a, b - 1);
}

//  Ejercicio 2

int potenciaI(int x , int y)
{
	int potencia = 1, i;
	for(i = 1; i <= y; i++)
		potencia = potencia * x;
	return potencia;
}

//		x^y = 1				si y = 0
//		x^y = x * x^y-1		Si y = 0
int potencia(int x, int y)
{
	if(y == 0)
		return 1;
	else
		return x * potencia(x, y - 1);
}

// Ejercicio 3
// Versión Iterativa

int fibonacciI(int i)
{
	int F1, F2, Fi, n;
	F1 = F2 = 1;
	if(i == 1 || i == 2)
		return 1;
	for(n = 3; n <= i; n++)
	{
		Fi = F1 + F2;
		F2 = F1;
		F1 = Fi;
	}
	return Fi;
}


//		Fi = 1						Si i = 1 o i = 2
//		Fi = Fi-1 + Fi-2			Si i > 2
int Fibonacci(int i)
{
	if(i == 1 || i == 2)
		return 1;
	else
		return ( Fibonacci(i - 1) + Fibonacci(i -2) );
}

//   Ejercicio 4
//  Versión Iterativa

float piI(int n)
{
	int i;
	float sum = 0.0;
	for(i = 1; i <= n; i++)
	{
		if(i % 2)
			sum = sum + (4.0/((2*i)-1)); 
		else
			sum = sum - (4.0/((2*i)-1)); 
	}
	return sum;
}

//		PIi = 4						Si i = 1
//		PIi = PIi-1 + 4.0 / (2*i-1)	Si i > 1 y i es par
//		PIi = PIi-1 - 4.0 / (2*i-1)	Si i > 1 y i es impar
float PI(int i)
{
	if(i == 1)			//  Criterio de  paro
		return 4.0;
	if(i > 1 && (i % 2) )
		return PI(i - 1) + 4.0 / (2 * i - 1);
	else
		return PI(i - 1) - 4.0 / (2 * i - 1);
}


int main()
{

   printf("Factorial iterativo de 5 es %d\n", factoriali(5) );
   printf("Factorial recursivo de 5 es %d\n", factorial(5) );
   printf("Multiplicación iterativo de 5 * 4 es %d\n", multiplicacionI(5, 4) );
   printf("Multiplicación recursivo de 5 * 4 es %d\n", multiplica(5, 4) );
   printf("Potencia iterativo de 5^3 es %d\n", potenciaI(5, 3) );
   printf("Potencia recursivo de 5^3 es %d\n", potencia(5, 3) );
   printf("Fibonacci iterativo de 5 es %d\n", fibonacciI(5) );
   printf("Fibonacci recursivo de 5 es %d\n", Fibonacci(5) );
   printf("Pi iterativo a 90 terminos es %8.6f\n", piI(900) );
   printf("Pi recursivo de 90 es %8.6f\n", PI(900) );
	
	system("pause");
	return 0;
}