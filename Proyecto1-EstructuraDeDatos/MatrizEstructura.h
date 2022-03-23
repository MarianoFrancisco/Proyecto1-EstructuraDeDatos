#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
struct crearNodo 
{
	//-> esto significa que hacemos uso del puntero, en lugar de poner (*dato).variable, hacemos dato->variable
	//creamos variables a utilizar de dato y x,y
	int valorData, valorX, valorY;
	//creamos nodos de redireccionamiento
	crearNodo* up;
	crearNodo* down;
	crearNodo* left;
	crearNodo* right;
	//constructor
	crearNodo(int valorData,int valorX,int valorY) {
		this->valorData = valorData;
		this->valorX = valorX;
		this->valorY = valorY;
		//inicializamos nulos nuestros redireccionamientos
		up = NULL;
		down = NULL;
		left = NULL;
		right = NULL;
	}
};
struct datoVertical
{
	crearNodo* start;
	crearNodo* end;
	//inicializamos
	datoVertical() {
		start = NULL;
		end = NULL;
	}
	//para insertar
	void ingresarDato(crearNodo* ingresado) {
		//verificamos si esta vacia
		if (emptyDato()) {
			start = end = ingresado;
		}
		else {
			if (ingresado->valorY<start->valorY) {
				ingresarDatoAdelante(ingresado);
			}
			else if (ingresado->valorY>end->valorY) {
				ingresarDatoEnd(ingresado);
			}
			else {
				ingresarDatoMitad(ingresado);
			}
		}
	}
	//ingresamos el siguiente dato
	void ingresarDatoAdelante(crearNodo* ingresado) {
		//relacionar arriba como el puntero principal
		start->up = ingresado;
		ingresado->down = start;
		start = start->up;
	}
	//ingresamos al final
	void ingresarDatoEnd(crearNodo* ingresado) {
		//relacionar abajo como el puntero final
		end->down = ingresado;
		ingresado->up = end;
		end = end->down;
	}
	void ingresarDatoMitad(crearNodo* ingresado) {
		//insertamos entre tmp y tmp2
		crearNodo* tmp;
		crearNodo* tmp2;
		tmp = start;
		while (tmp->valorY<ingresado->valorY)
		{
			tmp = tmp->down;
		}
		tmp2 = tmp->up;
		tmp2 -> down=ingresado;
		tmp->up = ingresado;
		ingresado->down = tmp;
		ingresado->up = tmp2;
	}

	//verificar si esta vacio o no
	bool emptyDato() {
		if (start == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
	void datosVertical() {
		if (!emptyDato()) {
			crearNodo* tmpDato=start;
			while (tmpDato != NULL) {
				cout<<"valorY"<<tmpDato->valorY<<endl;
				tmpDato=tmpDato->down;
			}
		}
	}
};
struct datoHorizontal
{
	crearNodo* start;
	crearNodo* end;
	//inicializamos
	datoHorizontal() {
		start = NULL;
		end = NULL;
	}
	//para insertar
	void ingresarDato(crearNodo* ingresado) {
		//verificamos si esta vacia
		if (emptyDato()) {
			start = end = ingresado;
		}
		else {
			if (ingresado->valorX < start->valorX) {
				ingresarDatoAdelante(ingresado);
			}
			else if (ingresado->valorX > end->valorX) {
				ingresarDatoEnd(ingresado);
			}
			else {
				ingresarDatoMitad(ingresado);
			}
		}
	}
	//ingresamos el siguiente dato
	void ingresarDatoAdelante(crearNodo* ingresado) {
		//relacionar arriba como el puntero principal
		start->left = ingresado;
		ingresado->right = start;
		start = start->left;
	}
	//ingresamos al final
	void ingresarDatoEnd(crearNodo* ingresado) {
		//relacionar abajo como el puntero final
		end->right = ingresado;
		ingresado->left = end;
		end = end->right;
	}
	void ingresarDatoMitad(crearNodo* ingresado) {
		//insertamos entre tmp y tmp2
		crearNodo* tmp;
		crearNodo* tmp2;
		tmp = start;
		while (tmp->valorX < ingresado->valorX)
		{
			tmp = tmp->right;
		}
		tmp2 = tmp->left;
		tmp2->right = ingresado;
		tmp->left = ingresado;
		ingresado->right = tmp;
		ingresado->left = tmp2;
	}

	//verificar si esta vacio o no
	bool emptyDato() {
		if (start == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
	void datosHorizontal() {
		if (!emptyDato()) {
			crearNodo* tmpDato = start;
			while (tmpDato != NULL) {
				cout << "valorX" << tmpDato->valorX << endl;
				tmpDato = tmpDato->right;
			}
		}
	}
};
//creamos lo que viene siendo fila de x x x x x
struct nodoEncabezado
{
	int enX;
	nodoEncabezado* next;
	nodoEncabezado* previous;
	datoVertical* column;
	nodoEncabezado(int enX) {
		this->enX = enX;
		column = new datoVertical();
		next = NULL;
		previous = NULL;
	}
};
struct encabezados
{
	nodoEncabezado* start;
	nodoEncabezado* end;
	//inicializamos
	encabezados() {
		start = NULL;
		end = NULL;
	}
	//para insertar
	void ingresarDato(nodoEncabezado* ingresado) {
		//verificamos si esta vacia
		if (emptyDato()) {
			start = end = ingresado;
		}
		else {
			if (ingresado->enX < start->enX) {
				ingresarDatoAdelante(ingresado);
			}
			else if (ingresado->enX > end->enX) {
				ingresarDatoEnd(ingresado);
			}
			else {
				ingresarDatoMitad(ingresado);
			}
		}
	}
	//ingresamos el siguiente dato
	void ingresarDatoAdelante(nodoEncabezado* ingresado) {
		//relacionar arriba como el puntero principal
		start->previous = ingresado;
		ingresado->next = start;
		start = start->previous;
	}
	//ingresamos al final
	void ingresarDatoEnd(nodoEncabezado* ingresado) {
		//relacionar abajo como el puntero final
		end->next = ingresado;
		ingresado->previous = end;
		end = end->next;
	}
	void ingresarDatoMitad(nodoEncabezado* ingresado) {
		//insertamos entre tmp y tmp2
		nodoEncabezado* tmp;
		nodoEncabezado* tmp2;
		tmp = start;
		while (tmp->enX < ingresado->enX)
		{
			tmp = tmp->next;
		}
		tmp2 = tmp->previous;
		tmp2->next = ingresado;
		tmp->previous = ingresado;
		ingresado->next = tmp;
		ingresado->previous = tmp2;
	}

	//verificar si esta vacio o no
	bool emptyDato() {
		if (start == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
	void datosEncabezado() {
		if (!emptyDato()) {
			nodoEncabezado* tmpDato = start;
			while (tmpDato != NULL) {
				cout << "valorX" << tmpDato->enX << endl;
				tmpDato = tmpDato->next;
			}
		}
	}
	//verificamos si existe
	bool exist(int enX) {
		if (emptyDato()) {
			//cout << "No existe" << endl;
			return false;
		}
		else {
			nodoEncabezado* tmp;
			tmp = start;
			while (tmp!=NULL) {
				if (tmp->enX==enX) {
					//cout << "Existe" << endl;
					return true;
				}
				else if (tmp->next==NULL) {
					//cout << "No existe" << endl;
					return false;
				} 
				tmp = tmp->next;
			}
		}
	}
	//hacemos busqueda
	nodoEncabezado* search(int enX) {
		if (exist(enX))
		{
			nodoEncabezado* tmp;
			tmp = start;
			while (tmp->enX!=enX)
			{
				tmp = tmp->next;
			}
		}
		else {
			cout << "No encontrado" << endl;
			return(new nodoEncabezado(-1));
		}
	}
};
//creamos columna que viene siendo y y y y y 
struct nodoLado
{
	int enY;
	nodoLado* next;
	nodoLado* previous;
	datoHorizontal* row;
	nodoLado(int enY) {
		this->enY = enY;
		row = new datoHorizontal();
		next = NULL;
		previous = NULL;
	}
};
struct lados
{
	nodoLado* start;
	nodoLado* end;
	//inicializamos
	lados() {
		start = NULL;
		end = NULL;
	}
	//para insertar
	void ingresarDato(nodoLado* ingresado) {
		//verificamos si esta vacia
		if (emptyDato()) {
			start = end = ingresado;
		}
		else {
			if (ingresado->enY < start->enY) {
				ingresarDatoAdelante(ingresado);
			}
			else if (ingresado->enY > end->enY) {
				ingresarDatoEnd(ingresado);
			}
			else {
				ingresarDatoMitad(ingresado);
			}
		}
	}
	//ingresamos el siguiente dato
	void ingresarDatoAdelante(nodoLado* ingresado) {
		//relacionar arriba como el puntero principal
		start->previous = ingresado;
		ingresado->next = start;
		start = start->previous;
	}
	//ingresamos al final
	void ingresarDatoEnd(nodoLado* ingresado) {
		//relacionar abajo como el puntero final
		end->next = ingresado;
		ingresado->previous = end;
		end = end->next;
	}
	void ingresarDatoMitad(nodoLado* ingresado) {
		//insertamos entre tmp y tmp2
		nodoLado* tmp;
		nodoLado* tmp2;
		tmp = start;
		while (tmp->enY < ingresado->enY)
		{
			tmp = tmp->next;
		}
		tmp2 = tmp->previous;
		tmp2->next = ingresado;
		tmp->previous = ingresado;
		ingresado->next = tmp;
		ingresado->previous = tmp2;
	}

	//verificar si esta vacio o no
	bool emptyDato() {
		if (start == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
	void datosEncabezado() {
		if (!emptyDato()) {
			nodoLado* tmpDato = start;
			while (tmpDato != NULL) {
				cout << "valorX" << tmpDato->enY << endl;
				tmpDato = tmpDato->next;
			}
		}
	}
	//verificamos si existe
	bool exist(int enY) {
		if (emptyDato()) {
			//cout << "No existe" << endl;
			return false;
		}
		else {
			nodoLado* tmp;
			tmp = start;
			while (tmp != NULL) {
				if (tmp->enY == enY) {
					//cout << "Existe" << endl;
					return true;
				}
				else if (tmp->next == NULL) {
					//cout << "No existe" << endl;
					return false;
				}
				tmp = tmp->next;
			}
		}
	}
	//hacemos busqueda
	nodoLado* search(int enY) {
		if (exist(enY))
		{
			nodoLado* tmp;
			tmp = start;
			while (tmp->enY != enY)
			{
				tmp = tmp->next;
			}
		}
		else {
			cout << "No encontrado" << endl;
			return(new nodoLado(-1));
		}
	}
};
//creamos matriz
struct matrizDinamica
{
	encabezados* encabezado;
	lados* lado;
	matrizDinamica() 
	{
		encabezado = new encabezados;
		lado = new lados;
	}
	void ingresar(int valorX, int valorY, int ingresado) {
		crearNodo* insertar;
		insertar = new crearNodo(ingresado, valorX, valorY);
		if (encabezado->exist(valorX)==false)
		{
			encabezado->ingresarDato(new nodoEncabezado(valorX));
		}
		if (lado->exist(valorY) == false)
		{
			lado->ingresarDato(new nodoLado(valorY));
		}
		nodoEncabezado* tmpE;
		nodoLado* tmpL;
		tmpE = encabezado->search(valorX);
		tmpL = lado->search(valorY);
		tmpE->column->ingresarDato(insertar);
		tmpL->row->ingresarDato(insertar);
		//cout << "insertando" << ingresado << " ubicado en (" << valorX << "," << valorY <<")\n";
	}
	//llenar nuestros datos manualmente
	void completarManual(int valorX, int valorY) {
		int limite = valorX * valorY;
		bool* verificarDato;
		verificarDato = new bool[limite];
		for (int i = 0; i < limite; i++)
		{
			verificarDato[i] = false;
		}
		int numero = 0;
		cout << "Nota: el valor 0 sera el espacio vacio"<<endl;
		for (int j = 0; j < valorY; j++)
		{
			
			for (int i = 0; i < valorX; i++)
			{
				cout << "Ingresa un numero que este entre 0 y "<< (limite - 1) <<", para la Fila: " << j+1 << ", Columna: " << i+1 << endl;
				cin >> numero;

				if (numero < 0 || numero> (limite - 1)) {
					while (numero < 0 || numero> (limite - 1)) {
						cout << "Numero ingresado se encuentra fuera del rango 0-" << (limite - 1) << ", ingresa otro numero" << endl;
						cin >> numero;
					}
				}
				if (verificarDato[numero] == true) {
					while (verificarDato[numero] == true) {
						cout << "Numero ya ingresado anteriormente, introduzca otro numero entre 0 y " << (limite - 1) << endl;
						cin >> numero;
						if (numero > (limite - 1) || numero < 0) {
							while (numero < 0 || numero>(limite - 1)) {
								cout << "Ingresa un numero que este entre 0 y 15, para la Fila: " << j + 1 << ", Columna: " << i + 1 << endl;
								cin >> numero;
							}
						}
					}
				}
				ingresar(i, j, numero);
				verificarDato[numero] = true;
			}
		}
	}
	//llenar nuestros datos aleatoriamente
	void completarAleatorio(int valorX, int valorY) {
		int limite = valorX * valorY;
		bool *verificarRepitencia;
		verificarRepitencia = new bool[limite];
		for (int i = 0; i < limite; i++)
		{
			verificarRepitencia[i] = false;
		}
		int almacenamiento = 0;
		int numeroAleatorio = 0;
		for (int j = 0; j < valorY; j++)
		{

			for (int i = 0; i < valorX; i++)
			{
				//srand(time(NULL));//que sean distintos cada vez los random
				numeroAleatorio = 1 + rand() % (limite -1);
				almacenamiento = numeroAleatorio - 1;
				if (i == valorX - 1 && j == valorY-1) {
					ingresar(i, j, 0);
				}
				else {
					if (verificarRepitencia[almacenamiento] == true) {
						while (verificarRepitencia[almacenamiento] == true) {
							numeroAleatorio = 1 + rand() % (limite - 1);
							almacenamiento = numeroAleatorio - 1;
						}
					}
					ingresar(i, j, numeroAleatorio);
				}
				verificarRepitencia[almacenamiento] = true;
			}
		}
	}
	//imprimir nuestros datos
	void imprimir(int valorX) {
		for (int i = 0; i < valorX; i++)
		{
			crearNodo* tmp = this->lado->search(i)->row->start;
			while (tmp != NULL)
			{
				cout << tmp->valorData;
				if (tmp->valorData > 9) {
					cout << " |";
				}
				else {
					cout << "  |";
				}
				tmp = tmp->right;
			}
			cout << "\n";
		}
	}
	//verificacion de punteo
	
	vector<int> pasarValoresPunteo(int valorX) {
		vector<int> valorPunteo;
		for (int i = 0; i < valorX; i++)
		{
			crearNodo* tmp = this->lado->search(i)->row->start;
			while (tmp != NULL)
			{
				valorPunteo.push_back(tmp->valorData);
				tmp = tmp->right;
			}
		}
		return valorPunteo;
	}
	//Inercambio hacia arriba
	int intercambioVacioArriba(int valorX) {
		int valorTemporal;
		int contadorPaso=0;
		for (int i = 0; i < valorX; i++)
		{
			crearNodo* tmp = this->lado->search(i)->row->start;
			while (tmp != NULL)
			{
				if (tmp->valorData==0) {
					if (tmp->up ==NULL) {
						cout << "* No hay ningun bloque existente arriba del espacio vacio *" << endl;
					}
					else {
						valorTemporal = tmp->up->valorData;
						tmp->up->valorData = 0;
						tmp->valorData = valorTemporal;
						contadorPaso = 1;
					}
				}
				tmp = tmp->right;
			}
		}
		return contadorPaso;
	}
	//intercambio hacia abajo
	int intercambioVacioAbajo(int valorX) {
		int valorTemporal;
		int contadorPaso = 0;
		int contadorTemporal = 0;
		for (int i = 0; i < valorX; i++)
		{
			crearNodo* tmp = this->lado->search(i)->row->start;
			while (tmp != NULL)
			{
				if (tmp->valorData == 0) {
					if (tmp->down == NULL) {
						if (contadorTemporal == 0) {
							cout << "* No hay ningun bloque existente abajo del espacio vacio *" << endl;
						}
					}
					else {
						if (contadorTemporal ==0 ) {
							cout << tmp->down->valorData;
							valorTemporal = tmp->down->valorData;
							tmp->down->valorData = 0;
							tmp->valorData = valorTemporal;
							contadorPaso = 1;
							contadorTemporal = 1;
							break;
						}
						
					}
				}
				tmp = tmp->right;
			}
		}
		return contadorPaso;
	}
	//Intercambio hacia la izquierda
	int intercambioVacioIzquierda(int valorX) {
		int contadorPaso = 0;
		int valorTemporal;
		for (int i = 0; i < valorX; i++)
		{
			crearNodo* tmp = this->lado->search(i)->row->start;
			while (tmp != NULL)
			{
				if (tmp->valorData == 0) {
					if (tmp->left == NULL) {
						cout << "* No hay ningun bloque existente a la izquierda del espacio vacio *" << endl;
					}
					else {
						valorTemporal = tmp->left->valorData;
						tmp->left->valorData = 0;
						tmp->valorData = valorTemporal;
						contadorPaso = 1;
					}
				}
				tmp = tmp->right;
			}
		}
		return contadorPaso;
	}
	//intercambio hacia la derecha
	int intercambioVacioDerecha(int valorX) {
		int valorTemporal;
		int contadorPaso=0;
		for (int i = 0; i < valorX; i++)
		{
			crearNodo* tmp = this->lado->search(i)->row->start;
			while (tmp != NULL)
			{
				if (tmp->valorData == 0) {
					if (tmp->right == NULL) {
						cout << "* No hay ningun bloque existente a la derecha del espacio vacio *" << endl;
					}
					else {
						valorTemporal = tmp->right->valorData;
						tmp->right->valorData = 0;
						tmp->valorData = valorTemporal;
						contadorPaso = 1;
						break;
					}
				}
				tmp = tmp->right;
			}
		}
		return contadorPaso;
	}
	//llenar nuestros datos manualmente para nivel 2 en adelante
	void completarManualNivelesMas(int valorX, int valorY, int contadorNumerosAleatorios) {
		int limite = valorX * valorY;
		int capacidadVerificar = valorX * valorY * contadorNumerosAleatorios;
		int inicioManual = capacidadVerificar - limite;
		bool* verificarDato;
		verificarDato = new bool[limite];
		for (int i = 0; i < limite; i++)
		{
			verificarDato[i] = false;
		}
		int numero = 0;
		for (int j = 0; j < valorY; j++)
		{

			for (int i = 0; i < valorX; i++)
			{
				cout << "Ingresa un numero que este entre "<< inicioManual <<" y " << (capacidadVerificar - 1) << ", para la Fila: " << j + 1 << ", Columna: " << i + 1 << endl;
				cin >> numero;

				if (numero < inicioManual || numero>(capacidadVerificar - 1)) {
					while (numero < inicioManual || numero>(capacidadVerificar - 1)) {
						cout << "Numero ingresado se encuentra fuera del rango " << inicioManual << "-" << (capacidadVerificar - 1) << ", ingresa otro numero" << endl;
						cin >> numero;
					}
				}
				if (verificarDato[numero] == true) {
					while (verificarDato[numero] == true) {
						cout << "Numero ya ingresado anteriormente, introduzca otro numero entre " << inicioManual << " y " << (capacidadVerificar - 1) << endl;
						cin >> numero;
						if (numero > (capacidadVerificar - 1) || numero < inicioManual) {
							while (numero < inicioManual || numero>(capacidadVerificar - 1)) {
								cout << "Ingresa un numero que este entre " << inicioManual << " y " << (capacidadVerificar - 1) << ", para la Fila: " << j + 1 << ", Columna: " << i + 1 << endl;
								cin >> numero;
							}
						}
					}
				}
				ingresar(i, j, numero);
				verificarDato[numero] = true;
			}
		}
	}
	//llenar nuestros datos aleatoriamente para nivel 2 en adelante
	void completarAleatorioNivelesMas(int valorX, int valorY,int contadorNumerosAleatorios) {
		
		int limite = valorX * valorY;
		int capacidadVerificar = valorX * valorY * contadorNumerosAleatorios;
		int inicioAleatorio = capacidadVerificar - limite;
		bool* verificarRepitencia;
		verificarRepitencia = new bool[limite];
		for (int i = 0; i < limite; i++)
		{
			verificarRepitencia[i] = false;
		}
		int almacenamiento = 0;
		int numeroAleatorio = 0;
		for (int j = 0; j < valorY; j++)
		{
			for (int i = 0; i < valorX; i++)
			{
				//srand(time(NULL));//que sean distintos cada vez los random
				numeroAleatorio = inicioAleatorio + (rand() % limite);
				almacenamiento = numeroAleatorio -inicioAleatorio;
				if (verificarRepitencia[almacenamiento] == true) {
					while (verificarRepitencia[almacenamiento] == true) {
						numeroAleatorio = inicioAleatorio + (rand() % limite);
						almacenamiento = numeroAleatorio - inicioAleatorio;
					}
				}
				ingresar(i, j, numeroAleatorio);
				verificarRepitencia[almacenamiento] = true;
			}
		}
	}
	//buscar posicion donde se encuentra el cero
	int posicionCero(int valorX) {
		int valorI = 0;
		int contador = 0;
		for (int i = 0; i < valorX; i++)
		{
			crearNodo* tmp = this->lado->search(i)->row->start;
			while (tmp != NULL)
			{
				if (tmp->valorData == 0) {
					valorI = contador;
				}
				tmp = tmp->right;
			}
			contador++;
		}
		return valorI;
	}
	//cantidad de movimientos para encontrar el cero
	int cantidadMovimientosCero(int valorX) {
		int contadorMovimientos = 0;
		for (int i = 0; i < valorX; i++)
		{
			contadorMovimientos = 0;
			crearNodo* tmp = this->lado->search(i)->row->start;
			while (tmp != NULL)
			{
				if (tmp->valorData == 0) {
					break;
				}
				tmp = tmp->right;
				contadorMovimientos++;
			}
		}
		return contadorMovimientos;
	}
	//buscar posicion donde se encuentra el cero
	int recuperarValorOtroNivel(int valorI, int contadorMovimientos) {
		int recuperarValor;
		crearNodo* tmp = this->lado->search(valorI)->row->start;
		if (contadorMovimientos == 0) {
			recuperarValor = tmp->valorData;
		}
		else {
			for (int i = 0; i < contadorMovimientos; i++)
			{
				tmp = tmp->right;
			}
			recuperarValor=tmp->valorData;
		}
		return recuperarValor;
	}
	//actualizar a valor del otro nivel donde estaba el bloque vacio
	void actualizamosNivelAnterior(int valorI, int contadorMovimientos,int valorRecuperado) {
		crearNodo* tmp = this->lado->search(valorI)->row->start;
		if (contadorMovimientos == 0) {
			tmp->valorData = valorRecuperado;
		}
		else {
			for (int i = 0; i < contadorMovimientos; i++)
			{
				tmp = tmp->right;
			}
			tmp->valorData = valorRecuperado;
		}
	}
	//actualizar a cero la posicion enlazada
	void actualizamosNivelSiguiente(int valorI,int contadorMovimientos) {
		crearNodo* tmp = this->lado->search(valorI)->row->start;
		if (contadorMovimientos == 0) {
			tmp->valorData = 0;
		}
		else {
			for (int i = 0; i < contadorMovimientos; i++)
			{
				tmp = tmp->right;
			}
			tmp->valorData = 0;
		}
	}
};