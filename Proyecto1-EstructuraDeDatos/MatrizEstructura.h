#include <iostream>
#include <cstdlib>
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
			/*
			nodoEncabezado* tmpDato = start;
			while (tmpDato != NULL) {
				cout << "valorX" << tmpDato->enX << endl;
				tmpDato = tmpDato->next;
			}*/
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
	void completarManual(int valorX, int valorY) {
		bool verificarDato[] = { false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false};
		int numero = 0;
		cout << "Nota: el valor 0 sera el espacio vacio"<<endl;
		for (int j = 0; j < valorY; j++)
		{
			
			for (int i = 0; i < valorX; i++)
			{
				cout << "Ingresa un numero que este entre 0 y 15, para la Fila: " << j+1 << ", Columna: " << i+1 << endl;
				cin >> numero;

				if (numero < 0 || numero> 15) {
					while (numero < 0 || numero>15) {
						cout << "Numero ingresado se encuentra fuera del rango 0-15, ingresa otro numero" << endl;
						cin >> numero;
					}
				}
				if (verificarDato[numero] == true) {
					while (verificarDato[numero] == true) {
						cout << "Numero ya ingresado anteriormente, introduzca otro numero entre 0 y 15" << endl;
						cin >> numero;
						if (numero > 15 || numero < 0) {
							while (numero < 0 || numero>15) {
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
	void completarAleatorio(int valorX, int valorY) {
		bool verificarRepitencia[] = { false,false,false,false,false,false,false,false,false,false,false,false,false,false,false };
		int almacenamiento = 0;
		int numeroAleatorio = 0;
		for (int j = 0; j < valorY; j++)
		{

			for (int i = 0; i < valorX; i++)
			{
				srand(time(NULL));//que sean distintos cada vez los random
				numeroAleatorio = 1 + rand() % 15;
				almacenamiento = numeroAleatorio - 1;
				if (i == 3 && j == 3) {
					ingresar(i, j, 0);
				}
				else {
					if (verificarRepitencia[almacenamiento] == true) {
						while (verificarRepitencia[almacenamiento] == true) {
							numeroAleatorio = 1 + rand() % 15;
							almacenamiento = numeroAleatorio - 1;
						}
					}
					ingresar(i, j, numeroAleatorio);
				}
				verificarRepitencia[almacenamiento] = true;
			}
		}
	}
	void imprimir() {
		for (int i = 0; i < 4; i++)
		{
			cout << this->lado->search(i)->row->start->valorData;
			if (this->lado->search(i)->row->start->valorData > 9) {
				cout << " |";
			}
			else {
				cout << "  |";
			}
			cout << this->lado->search(i)->row->start->right->valorData;
			if (this->lado->search(i)->row->start->right->valorData > 9) {
				cout << " |";
			}
			else {
				cout << "  |";
			}
			cout << this->lado->search(i)->row->start->right->right->valorData;
			if (this->lado->search(i)->row->start->right->right->valorData > 9) {
				cout << " |";
			}
			else {
				cout << "  |";
			}
			cout << this->lado->search(i)->row->start->right->right->right->valorData;
			if (this->lado->search(i)->row->start->right->right->right->valorData > 9) {
				cout << " |\n";
			}
			else {
				cout << "  |\n";
			}
		}
	}
	
};