/* 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - Ernesto Serrano Collado
	------------------------------
	Programa que lee los numeros introducidos hasta que se introduce 0.

	Necesita: Introducir numeros.

	Devuelve: El total de numeros introducidos y el menor de ellos.
*/
#include <iostream>   // Inclusión de los recursos de E/S
#include <string>   // Inclusión de las funciones de cadenas

using namespace std; 

int main(){                    // Programa Principal
	double dato;               // Declara variables para guardar los datos
	const string MENSAJE_INTRODUCCION = "\nIntroduzca un numero: "; 
	int contador_introducidos = 0;
	double minimo_introducido = 0;

	//Obtenemos los datos necesarios
	do {	
		cout << MENSAJE_INTRODUCCION;
		cin >> dato;

		//En el caso del 0 no hay que hacer los calculos
		if (dato != 0) {

			if (minimo_introducido == 0) {
				//La primera vez el minimo estara a 0, se asigna directamente
				minimo_introducido = dato;
			} else if (dato < minimo_introducido) {
				//Las siguientes veces habra que asignar el minimo solo si es menor
				minimo_introducido = dato;
			} 

			//Incrementamos el contador de numeros introducidos
			contador_introducidos++;
		}
	} while (dato != 0); //Comprobamos que el número sea distinto de 0


	//Pintamos los valores en la consola
	cout << "\nSe han introducido " << contador_introducidos << " numeros y el minimo valor \
	introducido es " << minimo_introducido << "\n";

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}
