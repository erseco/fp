/* 
	2013 - Ernesto Serrano Collado
	------------------------------
	Programa para calcular el capital total dependiendo del interés
	Necesita: Capital e Interés.
	Calcula:  El Total, calculado como
                Total = Capital + (capital * (interes / 100))
*/

#include <iostream>   // Inclusión de los recursos de E/S

using namespace std; 

int main(){                    // Programa Principal
	double capital;               // Declara variables para guardar
	double interes;               // los valores de capital, interés y el total

	//Obtenemos los datos necesarios
	cout << "Introduzca el capital: " ;
	cin >> capital;
	cout << "Introduzca el interés: ";
	cin >> interes;

	//Hacemos los cálculos 
	//(lo almacenamos en la variable original capital tal y como sugiere el ejercicio)
	capital += capital * (interes / 100);     

	//Pintamos los valores en la consola
	cout << "\nEl total vale " << capital << "\n\n" ;

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}
