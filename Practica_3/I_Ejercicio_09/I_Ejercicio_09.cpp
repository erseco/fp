/* 
	2013 - Ernesto Serrano Collado
	------------------------------
	Programa que lee Horas Minutos y Segundos y los ajusta
	a lo que devolvería un calendario normal.

	Necesita: horas, minutos y segundos.

	Devuelve:  Los días, horas, minutos y segundos que hay en
	los datos introducidos
*/

#include <iostream>   // Inclusión de los recursos de E/S

using namespace std; 

int main(){                    // Programa Principal
	int horas;               // Declara variables para guardar los datos
	int minutos;               
	int segundos;   

	int dias = 0;

	//Obtenemos los datos necesarios
	cout << "Introduzca las horas: ";
	cin >> horas;
	cout << "Introduzca los minutos: ";
	cin >> minutos;
	cout << "Introduzca los segundos: ";
	cin >> segundos;

	//Hacemos los cálculos
	if (segundos > 59) {
		minutos += segundos / 60;	//Todo lo que sobrepase de 59 segundos lo agregamos a minutos
		segundos = segundos % 60;	//El resto lo agregamos a los segundos
	}

	if (minutos > 59) {
		horas += minutos / 60;		//Todo lo que sobrepase de 59 minutos lo agregamos a horas
		minutos = minutos % 60;		//El resto lo agregamos a los minutos
	}

	if (horas > 23) {
		dias += dias / 24; 			//Todo lo que sobrepase de 24 horas lo agregamos a dias
		horas = horas % 24; 		//El resto lo agregamos a las horas
	}


	//Pintamos los valores en la consola
	cout << "En total hay: " << dias << " dias\n";
	cout << "En total hay: " << horas << " horas\n";
	cout << "En total hay: " << minutos << " minutos\n";
	cout << "En total hay: " << segundos << " segundos\n";

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}
