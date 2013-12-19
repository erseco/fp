/******************************************************************************
	Fundamentos de Programaci�n
	Grado en Ingenier�a Inform�tica

	2013 - Ernesto Serrano Collado
	------------------------------
	Dise�o e implementaci�n de la clase MiReal como indica el ejercicio III.22

******************************************************************************/
#include <iostream>   // Inclusi�n de los recursos de E/S
#include <cmath> //Inclusion de las librer�as matem�ticas

using namespace std; 

/*****************************************************************************/
//Definicion de la clase
class MiReal {

private: 

	//Atributos
	double value; 

public:
/*****************************************************************************/
	//Constructor
	MiReal(double pValue) {

		//Asignamos los atributos
		value = pValue;

	}
/*****************************************************************************/
	//M�todos
	double Valor() {
		return value;
	}
/*****************************************************************************/
	double Seno() {
		return sin(value);
	}
/*****************************************************************************/
	double ValorAbsoluto() {

		if (value < 0) {
			return -value;
		} else {
			return value;
		}
	}
};
/*****************************************************************************/
//Programa Principal 
int main(){    

	//Declara variables para guardar los valores	
    MiReal real(-6.5);


	//Pintamos los valores en la consola
	cout << "\nEl seno de: " << real.Valor() << " es: " << real.Seno(); 
	cout << "\nEl absoluto de: " << real.Valor() << " es: " << real.ValorAbsoluto(); 

	cout << "\n\n";


	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}