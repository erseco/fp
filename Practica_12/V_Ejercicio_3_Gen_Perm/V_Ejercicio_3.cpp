/****************************************************************************** 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2013 - Ernesto Serrano Collado
	------------------------------
	Se pide crear la clase GeneradorPermutaciones para generar permutaciones 
	aleatorias de un conjunto de enteros entre un valor mínimo y un valor máximo
	La clase tendrá un único método con la siguiente cabecera:
	
		Permutacion Genera(int primero, int ultimo)
	
	dónde la clase Permutacion es la vista en el problema 12 de la Relación de 
	Problemas IV. Por ejemplo, si mínimo = 1 y máximo = 6, una permutación 
	válida sería {3,1,6,4,5,2}. Como puede observarse, no pueden aparecer 
	elementos repetidos y deben estar todos los valores entre 1 y 6.

******************************************************************************/
#include <iostream>	//Inclusión de los recursos de E/S
#include <string>	//Inclusión de los recursos de cadenas
#include <vector>	
#include <cstdlib>
#include <ctime>

using namespace std; 

/*****************************************************************************/
//Definicion de la clase MyRandom
#include <ctime>
class MyRandom {
private:
	int minVal;
	int maxVal;
	void InitMyRandom (void) {
		time_t t;
		srand ((int) time(&t));
	}
public:
	MyRandom (int el_minimo, int el_maximo) : minVal(el_minimo), maxVal(el_maximo) {
		InitMyRandom();
		
		Next(); // desecho el primero
	}
	int Next() {
		int rango = (maxVal - minVal)+1;
		int v1 = (int)(rango * (rand() / (RAND_MAX*1.0)));
		int v2 = (int)(minVal + (v1 % rango));
		return v2; 
	}
	int Min() {
		return minVal;
	}
	int Max() {
		return maxVal;
	}
};
/*****************************************************************************/
//Definicion de la clase Permutacion
class Permutacion {
private:
	vector <int> vector_privado;
public:

	/*****************************************************************/
	//Comprueba si el valor existe previamente en la permutación. 
	bool Contiene(int valor) {

		//Declaracion de variables
		bool contiene = false;

		//Recorremos el vector hasta el final o hasta encontrar valor
		for (int i = 0; !contiene && i < (int)vector_privado.size(); i++) {
		
			//Si valor existe...
			if (vector_privado[i] == valor) {
			
				//...decaramos esta variable a true
				contiene = true;

			}

		}

		//Devolvemos el resultado
		return contiene;
	}	
	/*****************************************************************/
	//Agrega un valor a la permutacion. 
	void Aniade(int valor) {
		vector_privado.push_back(valor);
	}
	/*****************************************************************/
	//Pinta la permutacion concatenada en la salida estandar. 
	void PintarPermutacion() {
		
		for (int i = 0; i < (int)vector_privado.size(); i++) {
		
			cout << vector_privado[i] << ",";

		}

		cout << "\n";

	}
	/*****************************************************************/
	// Devuelve el número de elementos de la permutación. 
	int NumElementos() {
		return (vector_privado.size());
	}
	/*****************************************************************/
	// Devuelve el mínimo de la permutación. 
	// PRE: al menos hay un elemento 
	int Minimo() {
		int min = vector_privado[0];
		int tope = (int)vector_privado.size();

		for (int i=1; i<tope; i++) 
			if (vector_privado[i] < min) 
				min = vector_privado[i];

		return (min);
	}
	/*****************************************************************/
	// Devuelve el máximo de la permutación. 
	// PRE: al menos hay un elemento 
	int Maximo() {
		int max = vector_privado[0];
		int tope = vector_privado.size();

		for (int i=1; i<tope; i++) 
			if (vector_privado[i] > max) 
				max = vector_privado[i];

		return (max);
	}
	/*****************************************************************/
	// Devuelve el elemento de la casilla "indice" 
	// PRE: la posición dada por "indice" es correcta.
	int Elemento(int indice) {
		return vector_privado[indice];
	}

	/*********************************************************/
	//Esta función devuelve el numero de lecturas que necesitamos hacer para leer
	//todos los numeros del vector.
	int NumeroLecturas() {

		//Declaracion de variables

		//En este contador iremos almacenando el numero de lecturas
		int n_lecturas = 0;
		//En este contador almacenamos los leidos tiene que llegar a vector_privado.size()
		int n_leidos = 1; 

		//Bucle while con forma de for, recorrerá el vector hasta que esten todos los numeros leidos
		for (int i = 0; n_leidos < (int)vector_privado.size() && i < (int)vector_privado.size(); i++) {

			//Recorremos el vector para leer los numeros inferiores al actual
			for (int h = i+1; h < (int)vector_privado.size(); h++) {

				//Si el valor es inferior al actual...
				if (vector_privado[i] > vector_privado[h]) {

					//...incrementamos el contador de leidos
					n_leidos++;

				}

			}

			//Incrementamos el contador de lecturas
			n_lecturas++;

		}

		//Devolvemos el numero de lecturas
		return n_lecturas;
	}

};
/*****************************************************************************/
//Definicion de la clase GeneradorPermutaciones
class GeneradorPermutaciones {
public:

	/*********************************************************/
	//Esta función genera una permutacion de los numeros entre primero y ultimo
	Permutacion Genera(int primero, int ultimo) {

		//Declaramos las variables necesarias
		Permutacion perm;

		MyRandom generador_aleatorio(primero+1, ultimo-1);
		perm.Aniade(primero);
		bool permutacion_completa = false;

		//No terminamos hasta que la permutacion esté completa
		while (!permutacion_completa) {
	
			//Generamos un nuevo valor aleatorio
			int valor = generador_aleatorio.Next();

			//Si valor es distinto del ultimo y no esta en la lista...
			if (valor != ultimo && !perm.Contiene(valor)) {
			
				//..añadimos el valor
				perm.Aniade(valor);

			}

			//Comprobamos si la permutacion esta completa (el tamaño tien que ser el mismo
			if (perm.NumElementos() == ultimo - primero) {
			
				permutacion_completa = true;
			}

		}


		//Añadimos el ultimo
		perm.Aniade(ultimo);

		//Devolvemos la permutación
		return perm;



	}
};
/*****************************************************************************/
//Programa Principal 
int main() {    

	//Declara variables para guardar los datos   
	GeneradorPermutaciones generador;
	Permutacion perm;
	//Hacemos los calculos
	perm = generador.Genera(4,20);


	//Pintamos los valores en la consola
	cout << "Ha generado la permutacion: \n";
	perm.PintarPermutacion();
	cout << "\n";

	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}