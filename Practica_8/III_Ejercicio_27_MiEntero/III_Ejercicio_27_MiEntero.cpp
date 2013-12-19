/******************************************************************************
	Fundamentos de Programaci�n
	Grado en Ingenier�a Inform�tica

	2013 - Ernesto Serrano Collado
	------------------------------
	Dise�o e implementaci�n de la clase MiEntero como pide el ejercicio III.27

******************************************************************************/
#include <iostream>   // Inclusi�n de los recursos de E/S
#include <cmath> //Inclusion de las librer�as matem�ticas

using namespace std; 

/*****************************************************************************/
//Definicion de la clase
class MiEntero {

private: 

	//Atributos
	int value; 

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

public:
/*****************************************************************************/
	//Constructor
	MiEntero(int pValue) {

		//Asignamos los atributos
		value = pValue;

	}
/*****************************************************************************/
	//M�todos
	double Valor() {
		return value;
	}
/*****************************************************************************/
	double Factorial() {
		//Asignamos el valor por defecto a 1
		int resultado = 1;
	
		//Hacemos los calculos
		for (int i = 2; i <= value; i++)
			resultado *= i;

		//Devolvemos el valor
		return resultado;
	}
/*****************************************************************************/
	bool EsNarcisista() {

		// Comprobar si el n�mero es narcisista: 
		// Para cada cifra se calcular� su potencia de orden "num_digitos"
		// y se sumar�n. Si la suma de los "num_digitos" sumandos es "n" 
		// el n�mero es narcisista. 

		int i;
		int ultima_cifra;
		double suma = 0;
		int num_digitos = NumDigitos(value);
		int n = value;
   
		for (i = 1 ; i <= num_digitos; i++){  // Usamos un ciclo for porque 
											  // sabemos el n�m. de iteraciones
			ultima_cifra = n % 10; // tomamos la cifra menos significativa

			suma = suma + pow (1.0 * ultima_cifra, num_digitos);

			n = n/10; // descartar la cifra menos significativa
		}

		return (suma == value);
	}
/*****************************************************************************/
	bool EsFeliz() {

		int suma = 0;			 // Para sumar los cuadrados de los d�gitos
		int	num_digitos;	 // Num. de d�gitos del valor que se comprueba 

		int num_iteraciones; // Contador de iteraciones

		int tmp; // Copia de un n�mero. Se usar� para trabajar sobre �l y no 
					// perder el valor del n�mero.
		int act; // En cada iteraci�n, "act" contendr� el nuevo valor resultante 
					// de la suma de la iteraci�n anterior  

			int n = value;
	
		// Calcular el n�mero de d�gitos de "n"
		num_digitos = NumDigitos (n);	

		if (num_digitos == 1) { // Cuidado con los n�meros con un d�gito
			suma = n;
			num_iteraciones = 1;
		}
		else 
			num_iteraciones = 0; // Se va a empezar a iterar

		// Comprobar si el n�mero es feliz: 
		// Para cada cifra se calcular� su cuadrado y se sumar�n. 
		// Este proceso se repetir� hasta obtener un n�mero de una cifra
		// Si es 1, el n�mero es feliz.
	
		act = value; // inicialmente, "act" es el valor que se comprueba 

		while (num_digitos > 1) {

			suma = 0;

			tmp = act;

			// Suma de los d�gitos que forman el n�mero actual 

			int i;
			int	ultima_cifra;

			for (i = 1 ; i <= num_digitos; i++){  // sabemos el n�m. de iteraciones
				ultima_cifra = tmp % 10; // tomamos la cifra menos significativa
				suma = suma + ultima_cifra*ultima_cifra;
				tmp = tmp/10; // descartar la cifra menos significativa
			}
			
			num_iteraciones++; // Una iteraci�n m�s

		//		cout << "suma de " << act << " (" 
		//			 << num_digitos << " digs.) = " << suma << endl;


			// Preparar la siguiente iteraci�n: 

			act = suma; // Para la siguiente vuelta "act" ser� el valor a comprobar

			// Calcular el n�mero de d�gitos de "act"
			num_digitos = NumDigitos (act);	 

		} // while (num_digitos > 1)


		return (suma == 1); 
	}
};
/*****************************************************************************/
//Programa Principal 
int main(){    

	//Declara variables para guardar los valores	
     MiEntero entero(153);


	//Pintamos los valores en la consola
	cout << "\nEl factorial de: " << entero.Valor() << " es: " << entero.Factorial(); 
	cout << "\nEl numero: " << entero.Valor() << " �es narcisista?: " << entero.EsNarcisista(); 
	cout << "\nEl numero: " << entero.Valor() << " �es feliz?: " << entero.EsFeliz(); 

	cout << "\n\n";


	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}