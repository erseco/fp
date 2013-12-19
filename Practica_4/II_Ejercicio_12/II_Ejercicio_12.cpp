/* 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - Ernesto Serrano Collado
	------------------------------
	Programa que calcula intereses.

	Necesita: Capital e interés.

	Devuelve: El numero de años que necesitamos para doblar el capital.
*/

#include <iostream>   // Inclusión de los recursos de E/S

using namespace std; 

int main(){                    // Programa Principal
	double capital_inicial;
	double capital_total = 0;         // Declara variables para guardar
	double interes;               
	int anyo_actual = 0; 

	//Obtenemos los datos necesarios
	cout << "Introduzca el capital inicial: " ;
	cin >> capital_inicial;
	cout << "Introduzca el interés: ";
	cin >> interes;

	//Trabajamos sobre el capital total, ya que el inicial tenemos que 
	//guardarlo para usarlo posteriormente
	capital_total =capital_inicial;

	while (capital_total <= (capital_inicial * 2)) {

		//Hacemos los cálculos 
		capital_total += capital_total * (interes / 100);

		//Incrementamos los años
		anyo_actual++;
	}	
	
	//Pintamos los valores en la consola
	cout << "Se tarda " << anyo_actual << " años en duplicar el capital inicial\n\n" ;

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}
