/****************************************************************************** 
	Fundamentos de Programación
	Grado en Ingeniería Informática

	2014 - Ernesto Serrano Collado
	------------------------------
	Reescribid la solución al ejercicio 15 de la relación de problemas IV (Vectores) 
	para que use como dato miembro privado un vector de palabras. 
	Cada palabra será un objeto de la clase Palabra.

	Cread una clase Frase para almacenar un conjunto de caracteres. Internamente, 
	como dato miembro privado, se usará una variable cadena de tipo string que al- 
	macenará los caracteres.

	Añadid los siguientes métodos:

	• void EliminaBlancosIniciales() para borrar todos los blancos iniciales.
	• void EliminaBlancosFinales() para borrar todos los blancos finales.
	• int NumeroPalabras() que indique cuántas palabras hay en la frase (una 
		palabra está separada por otra por uno o más espacios en blanco)
	• void BorraPalabra(int k_esima) para que borre la palabra k-ésima.
	• string Palabra(int k_esima) que devuelva la k-ésima palabra de la ca-
		dena. Si hay menos de k palabras, devolverá la cadena vacía "".

******************************************************************************/
#include <iostream>	//Inclusión de los recursos de E/S
#include <vector> //Libreria para vectores de la STL
#include <string> //Libreria para vectores de la STL

using namespace std; 
/*****************************************************************************/
//Definicion de la clase Palabra
class Palabra {

private:
	//Definicion de atributos
    string palabra_privada;

public:
	//Constructor
	Palabra(string palabra) {

		palabra_privada = palabra;
	
	}

	/*********************************************************/
	//Esta función devuelve el tamaño de la palabra
	int Tamanio() {
	
		return palabra_privada.size();
	
	}

	/*********************************************************/
	//Esta función devuelve un elemento de la palabra
	char Elemento(int indice) {
	
		return palabra_privada.at(indice);
	
	}

	/*********************************************************/
	//Esta función comprueba si el vector pasado es igual
	bool EsIgual(Palabra palabra) {

		bool es_igual = false;

		//Comprobamos si las dos palabras tienen el mismo tamaño
		if (Tamanio() == palabra.Tamanio()) {
		
			//Comprobamos si la dos palabras empiezan por la misma letra
			if (Elemento(0) == palabra.Elemento(0)) {
		
				//Obtenemos la posicion de la ultima letra
				int posicion_ultima = Tamanio() -1;

				//Comprobamos si la dos palabras terminan por la misma letra
				if (palabra.Elemento(posicion_ultima) == Elemento(posicion_ultima)) {
				
					//Nos guardamos el numero de letras que debemos de buscar
					//para ir decrementandolas luego
					int contador_letras_a_buscar = posicion_ultima - 1;

					//Recorremos las letras desde la 2ª a la penultima
					for (int i = 1; i < posicion_ultima; i++) {

						//Establecemos una bandera por si la encontramos
						bool letra_encontrada = false;

						//Recorremos las letras de la palabra pasada
						for (int h = 1; !letra_encontrada && h < posicion_ultima; h++) {

							//Si coincide establecemos la bandera y decrementamos el contador
							if (Elemento(i) == palabra.Elemento(h)) {
							
								letra_encontrada = true;
								contador_letras_a_buscar--;
							
							}

						}

					}

					//Si el contador ha llegado a 0 es porque ha encontrado todo
					//NOTA: Esto puede dar lugar a errores, puesto que si hubieran letras
					//repetidas podrian haber errores, se debería de optimizar
					if (contador_letras_a_buscar == 0) {

						es_igual = true;

					}

				}
	
			}
		
		}

		//Devolvemos el resultado
		return es_igual;
	}

	/*********************************************************/
	//Este método pinta la palabra en la salida estándar
	void PintarPalabra() {
	
		cout << palabra_privada;
	}


	/*********************************************************/
	//Este método devuelve una subcadena a partir de la posicion indicada
	Palabra Subcadena(int posicion) {
	
		return Palabra(palabra_privada.substr(posicion));

	}

};

/*****************************************************************************/
//Definicion de la clase Frase
class Frase {

private:
	//Definicion de atributos
    vector<Palabra> frase_privada;

public:
	Frase(vector<Palabra> frase) {
		
		frase_privada = frase;
	
	}
	
	/*********************************************************/
	//Esta función elimina los blancos iniciales de la frase
	void EliminaBlancosIniciales() {
	
		//Declaracion de variables
		int numero_espacios = 0;
		bool fin_espacios = false;

		//Recorremos la frase hasta que encontramos algo distinto a un espacio
		for (int i = 0; !fin_espacios && i < (int)frase_privada.at(0).Tamanio(); i++) {
		
			if (frase_privada.at(0).Elemento(i) == ' ') {
			
				//Vamos contado los espacios que luego eliminaremos
				numero_espacios++;
			
			} else {
			
				//Ya no hay mas espacios
				fin_espacios = true;
			
			}

		}

		//Eliminamos los espacios iniciles con la funcion propia substr
		frase_privada[0] = frase_privada.at(0).Subcadena(numero_espacios);

	}

	/*********************************************************/
	//Esta función devuelve el número de palabras de la frase
	int NumeroPalabras() {
	
		//Devolvemos el numero de palabras
		return frase_privada.size();
	
	}

	/*********************************************************/
	//Este método borra la palabra k_esima de la frase
	void BorraPalabra(int k_esima) {

		frase_privada.erase(frase_privada.begin() + k_esima);
	
	}
	/*********************************************************/
	//Este método borra la palabra k_esima de la frase
	Palabra ObtenerPalabra(int k_esima) {
	
		//Obtenemos la palabra k_esima
		return frase_privada.at(k_esima);
	
	}
	

	/*********************************************************/
	//Este método pinta la frase en la salida estándar
	void PintarFrase() {
	
		//Pinto la frase con los | al principio y al final para que se 
		//vean los espacios (si los hay)
		cout << "|";

		//Recorremos la frase
		for (int i = 0; i < (int)frase_privada.size(); i++) {
		
			//La pintamos
			frase_privada.at(i).PintarPalabra();
			//Le agregamos un espacio (para separar)
			cout << " ";
		
		}

		cout << "|\n";

		
	}

};

/*****************************************************************************/
//Programa Principal 
int main() {    

	//Declara variables para guardar los datos   

	vector<Palabra> palabras;

	palabras.push_back(Palabra("  hola"));
	palabras.push_back(Palabra("mundo"));
	palabras.push_back(Palabra("mundial  "));

	Frase frase(palabras);

	//Pintamos la frase en la consola
	frase.PintarFrase();

	//Eliminamos los blancos iniciales
	frase.EliminaBlancosIniciales();


	//Pintamos la frase en la consola
	frase.PintarFrase();
	


	//Mandamos una pausa para que no se termine el programa hasta que pulsemos una tecla
	system("pause");

}