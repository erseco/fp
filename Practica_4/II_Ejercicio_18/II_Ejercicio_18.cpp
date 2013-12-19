/* 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - Ernesto Serrano Collado
	------------------------------
	Programa que obtiene la cantidad maxima de un producto vendido hasta que se introduce -1 como sucursal.

	Necesita: Sucursal, codigo y cantidad.

	Devuelve: La sucursal que mas ha vendido y la cantidad que ha vendido.
*/
#include <iostream>   // Inclusión de los recursos de E/S
#include <string>   // Inclusión de las funciones de cadenas

using namespace std; 

int main(){                    // Programa Principal 
	// Declara variables para guardar los datos
	const string MENSAJE_INTRODUCCION = "\nIntroduzca una sucursal, un codigo y una cantidad: "; 
	int sucursal = 0;
	int codigo = 0;
	int cantidad = 0;

	int sucursal_maxima = 0;
	int cantidad_maxima = 0;
	int sucursal_actual = 0;
	int cantidad_actual = 0;

	do {	
		//Obtenemos los datos necesarios
		cout << MENSAJE_INTRODUCCION;
		cin >> sucursal;
		cin >> codigo;
		cin >> cantidad;

		//Comprobamos si ha cambiado la sucursal
		if (sucursal != sucursal_actual) {
			
			//Si la cantidad previa es mayor a la guardada la 
			//guardamos como maxima, así como la sucursal
			if (cantidad_actual > cantidad_maxima) {
				sucursal_maxima = sucursal_actual;
				cantidad_maxima = cantidad_actual;
			}

			//Reseteamos la cantidad actual y asignamos la nueva sucursal
			sucursal_actual = sucursal;
			cantidad_actual = 0;
		
		}

		//Incrementamos la cantidad
		cantidad_actual += cantidad;


	} while (sucursal != -1); //Comprobamos que el número sea distinto de -1


	//Pintamos los valores en la consola
	cout << "\nSUCURSAL: " << sucursal_maxima;
	cout << "\nVENTAS: " << cantidad_maxima << "\n\n";

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}
