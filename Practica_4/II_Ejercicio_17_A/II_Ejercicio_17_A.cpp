/* 
	Fundamentos de Programaci�n
	Grado en Ingenier�a Inform�tica

	2013 - Ernesto Serrano Collado
	------------------------------
	Programa que lee un numero positivo e imprimer en pantalla todos
	sus divisores.

	Necesita: N�mero tope.

	Devuelve:  Todos sus divisores.
*/
#include <iostream>   // Inclusi�n de los recursos de E/S
#include <string>   // Inclusi�n de las funciones de cadenas

using namespace std; 

int main(){                    // Programa Principal
	int tope;               // Declara variables para guardar los datos
	const string MENSAJE_INTRODUCCION = "\nIntroduzca un n�mero positivo mayor que 0: "; 
	string resultado = "";
	int i = 0;

	//Obtenemos los datos necesarios
	/*
		NOTA: Esto es muy ineficiente, la solucion correcta seria con un do while
	*/
	cout << MENSAJE_INTRODUCCION;
	cin >> tope;
	while (tope < 1) { //Comprobamos que el n�mero sea positivo y mayor que 0
		cout << MENSAJE_INTRODUCCION;
		cin >> tope;
	} 

	//Hacemos los c�lculos
	i = tope;
	do {

		//Comprobamos si la division es entera
		if (tope % i == 0) {

			/*	
				NOTA: Lo correcto seria no escribir aqui el resultado, si no
				almacenarlo en una variable temporal stringstream y luego pintarla 
			*/

			//Es divisor, asi que pintamos los valores en la consola
			cout << "Los divisores de " << tope << " son: " << i << "\n";

		}

		//Decrementamos el iterador
		i--;
	} while (i > 0);


	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}
