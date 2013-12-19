/* 
	2013 - Ernesto Serrano Collado
	------------------------------
	Programa para salir de la crisis económica.

	Necesita: Valores establecidos en el código tales como
				renta bruta, si es autónomo, si está casado o si es pensionista.
	
	Calcula:  La renta neta en base a la retención aplicada.
*/

#include <iostream>   // Inclusión de los recursos de E/S

using namespace std; 

int main(){                    // Programa Principal
	double renta_bruta; // Declara variables para guardar datos
	double renta_neta; 
	int retencion;
	bool es_autonomo;
	bool es_pensionista;
	bool es_casado;

	//Establecemos los datos necesarios
	renta_bruta = 100;
	retencion = 21;
	es_autonomo = true;
	es_pensionista = false;
	es_casado = false;

	//Hacemos los cálculos
	if (es_autonomo) {
		retencion -= 3;
	
	} else {

		if (es_pensionista) {
			retencion += 3;

		} else {
			
			retencion += 2;
			
			if (renta_bruta < 20000) {
				retencion += 6;
		
			} else if (es_casado) {
				retencion += 8;
		
			} else { //Es soltero
				retencion += 10;
		
			}
	
		}
	}

	//Calculamos la renta neta quitandole la retención a la renta bruta
	renta_neta = renta_bruta - (renta_bruta * retencion / 100);  

	//Pintamos los valores en la consola
	cout << "La renta neta será: " << renta_neta << "\n\n" ;

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");
}
