// Proyecto1-EstructuraDeDatos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

#include <iostream>//entrada y salida de datos
#include "MatrizEstructura.h"
#include "TablaReportes.h"
#include <cstdlib>//new y delete
#include <vector>
#include <ctime>
using namespace std;//imprimir algo en pantalla
//creacio de variables
int opcion;
int opcionJugar;
int opcionJugando;
int puntajeTotal=0;
int pasosTotalesRealizados=0;
float tiempoPartida=0;
int posicionAlcanzada = 0;
int cantidadNiveles = 0;
int contadorNumerosNiveles = 0;
bool repetirNumeroNivel = 0;
int x = 0;
int y = 0;
bool cicloRepetir = true;
bool cicloRepetirJugar = true;
bool cicloRepetirJugando = true;
int capacidadTablaReporte;
//tabla reportes
class TablaReporte;
vector<TablaReporte> tablaReporteArreglo;
string nombreJugador="";
//metodos usados
void menu();
void reportes();
void tablaResultados();
void opcionesJugar();
void jugando();
void localizarValorCero();
//void ordenarTabla(vector<TablaReporte> tabla, int start, int end);
//matrices
void llenarMatrizAleatoria();
void llenarMatrizManual();
void llenarMatrizAleatoriaNivelesMas();
void llenarMatrizManualNivelesMas();
matrizDinamica* matriz;
matrizDinamica* matrizReinicio;
vector<matrizDinamica*> tableros;
vector<matrizDinamica*> tablerosReinicio;
int main()
{
    srand(time(NULL));//que sean distintos cada vez los random
    cout << "****************** Bienvenido al juego de 15 ****************** \n"
        "-> Ingresa tu nombre " << endl;
    cin >> nombreJugador;
    menu();
    return 0;
}

//llenar matriz aleatoria
void llenarMatrizAleatoria() {
    matriz = new matrizDinamica();
    matriz->completarAleatorio(y, x);
}
//llenar matriz aleatoria
void llenarMatrizManual() {
    matriz = new matrizDinamica();
    matriz->completarManual(y, x);
}
//llenar matriz aleatoria niveles mas
void llenarMatrizAleatoriaNivelesMas() {
    matriz = new matrizDinamica();
    matriz->completarAleatorioNivelesMas(y, x,contadorNumerosNiveles);
}

//llenar matriz aleatoria niveles mas
void llenarMatrizManualNivelesMas() {
    matriz = new matrizDinamica();
    matriz->completarManualNivelesMas(y, x, contadorNumerosNiveles);
}

void localizarValorCero() {

}
//estructuramos menu
void menu(){
    while (cicloRepetir)
    {
        cin.exceptions(ios_base::failbit);
        cout << "****************** "<<nombreJugador<<", selecciona una opcion para continuar ******************\n"
            "1) Jugar\n"
            "2) Ultimo reporte realizado\n"
            "3) Tabla de resultados\n"
            "4) Cambiar nombre\n"
            "5) Salir" << endl;
        try {
            cin >> opcion;
            switch (opcion)
            {
            case 1:
                cout << "->Ingresa la cantidad de filas del tablero" << endl;
                cin >> x;
                while (x < 1)
                {
                    cout << "* La cantidad de filas tiene que tener minimo 1, ingrese nuevamente la cantidad *" << endl;
                    cin >> x;
                }
                cout << "->Ingresa la cantidad de columnas del tablero" << endl;
                cin >> y;
                while (y < 1)
                {
                    cout << "* La cantidad de columnas tiene que tener minimo 1, ingrese nuevamente la cantidad *" << endl;
                    cin >> y;
                }
                cout << "->Ingresa la cantidad de niveles que deseas, minimo 1" << endl;
                cin >> cantidadNiveles;
                while (cantidadNiveles<1)
                {
                    cout << "* La cantidad de niveles tiene que tener minimo 1, ingrese nuevamente la cantidad *" << endl;
                    cin >> cantidadNiveles;
                }
                opcionesJugar();
                break;
            case 2:
                reportes();
                break;
            case 3:
                tablaResultados();
                break;
            case 4:
                cout << "-> Ingresa tu nombre " << endl;
                cin >> nombreJugador;
                cout << "* Nombre cambiado exitosamente *" << endl;
                break;
            case 5:
                cout << "****************** Saliendo ******************\n";
                cicloRepetir = false;
                break;
            default:
                cout << "* Ingresa una opcion correcta *\n";
                break;
            }
        }
        catch (ios_base::failure& error) {
            cout << "* No debes ingresar caracteres, unicamente una opcion de las mencionadas anteriormente *\n",error;
            break;
        }
    }
}
//ultimo reporte que se realizo
void reportes() {
    cout << "Reportes:\n"
        "->Pasos totales realizados: " << pasosTotalesRealizados << "\n"
        "->Tiempo de partida: " << tiempoPartida << " s\n"
        "->Puntaje total: " << puntajeTotal << "\n"
        "->Posicion alcanzada " << posicionAlcanzada << "\n"
        "   ->Nombre de Jugador: " << nombreJugador << "\n"
        "   ->Punteo: " << puntajeTotal << "\n"
        "   ->Tiempo de partida: " << tiempoPartida << " s\n";
    system("pause");
    
}
//opciones para jugar
void jugando() {
    clock_t tiempo;
    tiempo = clock();
    TablaReporte agregarJuegoTabla = TablaReporte();
    cicloRepetirJugando = true;
    while (cicloRepetirJugando) {
        cout << "Jugando\n"
            "-> Ingresa una opcion para continuar\n"
            "1) Intercambiar bloque vacio con bloque de arriba\n"
            "2) Intercambiar bloque vacio con bloque de abajo\n"
            "3) Intercambiar bloque vacio con bloque de la izquierda\n"
            "4) Intercambiar bloque vacio con bloque de la derecha\n"
            "5) Reiniciar el juego\n"
            "6) Terminar el juego\n";
        cin >> opcionJugando;
        switch (opcionJugando)
        {
        case 1:
            cout << "* arriba *" << endl;
            matriz->imprimir(x);
            break;
        case 2:
            cout << "* abajo *" << endl;
            matriz->imprimir(x);
            break;
        case 3:
            cout << "* izquierda *" << endl;
            matriz->imprimir(x);
            break;
        case 4:
            cout << "* derecha *" << endl;
            matriz->imprimir(x);
            break;
        case 5:
            cout << "* Juego reiniciado *" << endl;
            tableros = tablerosReinicio;
            tiempo = clock();
            pasosTotalesRealizados = 0;
            break;
        case 6:
            cicloRepetirJugando = false;
            cout << "* Juego terminado *" << endl;
            /*agregarJuegoTabla.construirTabla(2, "mariano2", 4, 5);
            tablaReporteArreglo.push_back(agregarJuegoTabla);*/
            tiempo = (clock() - tiempo);
            tiempoPartida = float(tiempo) / CLOCKS_PER_SEC;
            agregarJuegoTabla.construirTabla(posicionAlcanzada, nombreJugador, puntajeTotal, tiempoPartida);
            tablaReporteArreglo.push_back(agregarJuegoTabla);
            reportes();
            menu();
            break;
        default:
            cout << "* Ingresa una opcion correcta *\n";
            break;
        }
    }
}
//Jugar
void opcionesJugar() {
    cicloRepetirJugar = true;
    contadorNumerosNiveles = 2;
    while (cicloRepetirJugar) {
        cout << "Jugando\n"
            "-> Ingresa una opcion para continuar\n"
            "1) Llenar tabla manualmente\n"
            "2) Llenar tabla con numeros aleatorios\n"
            "3) Regresar\n";
        cin >> opcionJugar;
        switch (opcionJugar)
        {
        case 1:
            cout << "Llenar matriz de nivel: " << 1 << endl;
            llenarMatrizManual();
            cout << "* Tablero nivel "<<1<<" creado * " << endl;
            matriz->imprimir(x);
            tableros.push_back(matriz);
            tablerosReinicio.push_back(matriz);
            for (int i = 1; i < cantidadNiveles; i++)
            {
                cout << "Llenar matriz de nivel: " << i+1 << endl;
                llenarMatrizManualNivelesMas();
                cout << "* Tablero nivel " << i+1 << " creado * " << endl;
                matriz->imprimir(x);
                tableros.push_back(matriz);
                tablerosReinicio.push_back(matriz);
                contadorNumerosNiveles++;
            }
            jugando();
            cicloRepetirJugar = false;
            break;
        case 2:
            cout << "Llenar matriz de nivel: " << + 1 << endl;
            llenarMatrizAleatoria();
            cout << "* Tablero nivel " << 1 << " creado * " << endl;
            matriz->imprimir(x);
            tableros.push_back(matriz);
            tablerosReinicio.push_back(matriz);
            for (int i = 1; i < cantidadNiveles; i++)
            {
                cout << "Llenar matriz de nivel: " << i + 1 << endl;
                llenarMatrizAleatoriaNivelesMas();
                cout << "* Tablero nivel " << i+1 << " creado * " << endl;
                matriz->imprimir(x);
                tableros.push_back(matriz);
                tablerosReinicio.push_back(matriz);
                contadorNumerosNiveles++;
            }
            jugando();
            cicloRepetirJugar = false;
            break; 
        case 3:
            menu();
            break;
        default:
            cout << "* Ingresa una opcion correcta *\n";
            break;
        }
    }
}
//tabla resultados

void tablaResultados() {
    ordenarTabla(tablaReporteArreglo, 0, tablaReporteArreglo.size() - 1);
    for (int i = 0; i < tablaReporteArreglo.size(); i++)
    {
        tablaReporteArreglo[i].mostrarTabla();
    }
    system("pause");
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
