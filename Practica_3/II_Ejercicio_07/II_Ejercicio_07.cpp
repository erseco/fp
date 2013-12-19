/* 
	2013 - Ernesto Serrano Collado
	------------------------------
	Programa para calcular el precio de un vuelo dependiendo de la distancia recorrida.

	Necesita: Distancia y si es cliente previo.
	
	Calcula: El precio aplicando los descuentos ofertados por la compañía.
*/

#include <iostream>   // Inclusión de los recursos de E/S

using namespace std; 

int main(){                    // Programa Principal
	int const TARIFA_BASE = 150;      	// Declara variables para guardar
	int distancia = 0;					// Inicializamos las variables
	bool cliente_previo = false;
	double precio = 0;
	int rebaja = 0;


	//Obtenemos los datos necesarios
	cout << "Introduzca la distancia (km): " ;
	cin >> distancia;
	cout << "¿Es un cliente previo (1/0)?";
	cin >> cliente_previo;

	//Hacemos los cálculos
	if (distancia <= 200) {
		precio = TARIFA_BASE;
	} else {
	
		precio = TARIFA_BASE + (distancia - 200) * 0.1;
	}

	if (cliente_previo) {
		rebaja = 5;
	} 

	 if (distancia > 1100) {
		rebaja += 4;
	} else if (distancia > 600) {
		rebaja += 3;
	}

	//Aplicamos la rebaja calculada según los criterios
	precio -= precio * rebaja / 100.0;

	//Pintamos los valores en la consola
	cout << "\nEl viaje sale por " << precio << " euros\n\n" ;

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}
