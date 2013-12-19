/* 
	Fundamentos de Programaci�n
	Grado en Ingenier�a Inform�tica

	2013 - Ernesto Serrano Collado
	------------------------------
	Se dice que un n�mero natural es feliz si cumple que si sumamos 
	los cuadrados de sus d�gitos y seguimos el proceso con los resultados 
	obtenidos, finalmente obtenemos uno (1) como resultado. 
		Por ejemplo, 203 es un n�mero feliz ya que.
		203 --> 2^2 + 0^2 + 3^2 = 13 
 		13 --> 1^2 + 3^2 = 10 
		10 --> 1^2 + 0^2 = 1

	Se dice que un n�mero es feliz de grado k si es feliz en un m�ximo 
	de k iteraciones (una iteraci�n se produce cada vez que se elevan al 
	cuadrado los d�gitos del valor actual y se suman)
		Por ejemplo, 203 es un n�mero feliz de grado 3 (adem�s, es feliz 
		de cualquier grado mayor o igual

	Este programa indica si un n�mero natural "n" es feliz para un 
	grado "k" dado de antemano. 
	
	Entradas: Un n�mero entero "n", del que queremos saber si es "feliz"
			  Un n�mero entero "k", el grado tentativo. 
			
	Salidas:  Un mensaje, indicando si el "n" es (o no) feliz de grado "k"
*/
/*********************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int NumDigitos(int n) {
	
	// Calcular el n�mero de d�gitos de "n"
	// El algoritmo est� explicado en las transparencias de clase

	int num_digitos = 1;
	
	while (n > 9){
		n = n / 10;
		num_digitos++;
	}   

	return num_digitos;
   
}


int main()
{

	int	n; // Entrada: n�mero para calcular la propiedad "feliz"
	int	k; // Entrada: grado tentativo.


	cout << "\nTest: comprobar si un n�mero es feliz con un grado dado.";
	cout << "\n\n";
	cout << "Introduzca un n�mero para comprobar si es feliz: ";
	cin >> n;
	cout << "Introduzca el grado tentativo: ";
	cin >> k;



	int suma;			 // Para sumar los cuadrados de los d�gitos
	int	num_digitos;	 // Num. de d�gitos del valor que se comprueba 

 	int num_iteraciones; // Contador de iteraciones

   	int tmp; // Copia de un n�mero. Se usar� para trabajar sobre �l y no 
			 // perder el valor del n�mero.
	int act; // En cada iteraci�n, "act" contendr� el nuevo valor resultante 
			 // de la suma de la iteraci�n anterior  

	
	// Calcular el n�mero de d�gitos de "n"
	num_digitos = NumDigitos (n);	

	if (num_digitos == 1) { // Cuidado con los n�meros con un d�gito
		suma = n;
		num_iteraciones = 1;
	}
	else 
		num_iteraciones = 0; // Se va a empezar a iterar

	// Comprobar si el n�mero es feliz: 
	// Para cada cifra se calcular� su cuadrado y se sumar�n. 
	// Este proceso se repetir� hasta obtener un n�mero de una cifra
	// Si es 1, el n�mero es feliz.
	
	act = n; // inicialmente, "act" es el valor que se comprueba 

	while (num_digitos > 1) {

		suma = 0;

		tmp = act;

		// Suma de los d�gitos que forman el n�mero actual 

		int i;
		int	ultima_cifra;

		for (i = 1 ; i <= num_digitos; i++){  // sabemos el n�m. de iteraciones
			ultima_cifra = tmp % 10; // tomamos la cifra menos significativa
			suma = suma + ultima_cifra*ultima_cifra;
			tmp = tmp/10; // descartar la cifra menos significativa
		}
			
		num_iteraciones++; // Una iteraci�n m�s

//		cout << "suma de " << act << " (" 
//			 << num_digitos << " digs.) = " << suma << endl;


		// Preparar la siguiente iteraci�n: 

		act = suma; // Para la siguiente vuelta "act" ser� el valor a comprobar

		// Calcular el n�mero de d�gitos de "act"
		num_digitos = NumDigitos (act);	 

	} // while (num_digitos > 1)


	// Test finales

	bool es_feliz = (suma == 1); 
	bool es_feliz_grado_k = ((es_feliz) && (num_iteraciones <= k)); 
	

	cout << endl << endl; 

	if (es_feliz_grado_k) {
		cout << n << " es feliz de grado " << k << endl;
		if (num_iteraciones < k) 
			cout << "Realmente, " << n << " es feliz de grado " 
			     << num_iteraciones << endl;
	}
	else {
		cout << n << " no es feliz de grado " << k << endl;
		if (es_feliz)
			cout << n << " es feliz de grado " << num_iteraciones << endl;
		else
			cout << n << " no es feliz.";
	}

	cout << "\n\n";
	
	system("pause");
}
