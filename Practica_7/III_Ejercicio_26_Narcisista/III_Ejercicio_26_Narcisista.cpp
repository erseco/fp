/* 
	Fundamentos de Programaci�n
	Grado en Ingenier�a Inform�tica

	2013 - Ernesto Serrano Collado
	------------------------------
	Un n�mero entero de n d�gitos se dice que es narcisista si se puede 
	obtener como la suma de las potencias n-�simas de cada uno de sus 
	d�gitos. Por ejemplo 153 y 8208 son n�meros narcisistas porque 
		153 = 1^3 + 5^3 + 3^3  
		8208 = 8^4 + 2^4 + 0^4 + 8^4.

	Este programa nos indica si el n�mero es o no narcisista.

	Entradas: Un n�mero entero 
	Salidas:  Un mensaje, indicando si el n�mero introducido 
			  es o no narcisista.
*/

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

bool EsNarcisista(int n, int num_digitos) {
	
	// Comprobar si el n�mero es narcisista: 
	// Para cada cifra se calcular� su potencia de orden "num_digitos"
	// y se sumar�n. Si la suma de los "num_digitos" sumandos es "n" 
	// el n�mero es narcisista. 

	int i;
	int ultima_cifra;
	double suma = 0;
   
	for (i = 1 ; i <= num_digitos; i++){  // Usamos un ciclo for porque 
										  // sabemos el n�m. de iteraciones

		ultima_cifra = n % 10; // tomamos la cifra menos significativa

		suma = suma + pow (1.0 * ultima_cifra, num_digitos);

		n = n/10; // descartar la cifra menos significativa
	}

	return (suma == n);
}

int main()
{
	bool es_narcisista;

	int	n; // Entrada: n�mero para calcular la propiedad "narcisista"
	int num_digitos;

	cout << "\nIntroduzca un entero: ";
	cin >> n;
   
	num_digitos = NumDigitos (n);

	es_narcisista = EsNarcisista(n,num_digitos);
   
	if (es_narcisista)
		cout << "\nEs narcisista";
	else
		cout << "\nNo es narcisista";

	cout << "\n\n";
	
	system("pause");
}
