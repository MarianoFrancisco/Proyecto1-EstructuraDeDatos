// Proyecto1-EstructuraDeDatos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

#include <iostream>//entrada y salida de datos
#include "MatrizEstructura.h"
#include "TablaReportes.h"
#include <cstdlib>//new y delete
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;//imprimir algo en pantalla
//creacio de variables
int opcion, opcionJugar, opcionJugando, puntajeTotal = 0, pasosTotalesRealizados = 0, posicionAlcanzada = 0, valorI = 0;
int cantidadNiveles, contadorNumerosNiveles, x, y, capadidadTablaReporte, nivelActual = 0, nivelAnterior = 0, busquedaCero = 0;
int temporalTableroSize=0;
vector<vector<int>> valoresPunteo, valoresUsuarioPunteo;
int valorRecuperacionNivel = 0;
float tiempoPartida = 0;
bool cicloRepetir = true, cicloRepetirJugar = true, cicloRepetirJugando = true;
//tabla reportes
class TablaReporte;
vector<TablaReporte> tablaReporteArreglo;
string nombreJugador = "",nombreTemporal="";
//metodos usados
void menu();
void reportes();
void tablaResultados();
void opcionesJugar();
void jugando();
void localizarValorCero();
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
    srand(time_t(NULL));//que sean distintos cada vez los random
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
    matriz->completarAleatorioNivelesMas(y, x, contadorNumerosNiveles);
}
//llenar matriz aleatoria niveles mas
void llenarMatrizManualNivelesMas() {
    matriz = new matrizDinamica();
    matriz->completarManualNivelesMas(y, x, contadorNumerosNiveles);
}
//estructuramos menu
void menu() {

    while (cicloRepetir)
    {
        cin.exceptions(ios_base::failbit);
        cout << "****************** " << nombreJugador << ", selecciona una opcion para continuar ******************\n"
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
                while (x < 2)
                {
                    cout << "* La cantidad de filas tiene que tener minimo 2, ingrese nuevamente la cantidad *" << endl;
                    cin >> x;
                }
                cout << "->Ingresa la cantidad de columnas del tablero" << endl;
                cin >> y;
                while (y < 2)
                {
                    cout << "* La cantidad de columnas tiene que tener minimo 2, ingrese nuevamente la cantidad *" << endl;
                    cin >> y;
                }
                cout << "->Ingresa la cantidad de niveles que deseas, minimo 1" << endl;
                cin >> cantidadNiveles;
                while (cantidadNiveles < 1)
                {
                    cout << "* La cantidad de niveles tiene que tener minimo 1, ingrese nuevamente la cantidad *" << endl;
                    cin >> cantidadNiveles;
                }
                nivelActual = 0;
                opcionesJugar();
                break;
            case 2:
                reportes();
                break;
            case 3:
                if (tablaReporteArreglo.size() > 0) {
                    tablaResultados();
                }
                else {
                    cout << "* Aun no hay partidas jugadas *" << endl;
                }
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
            cout << "* No debes ingresar caracteres, unicamente una opcion de las mencionadas anteriormente *\n";
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
        "   ->Nombre de Jugador: " << nombreTemporal << "\n"
        "   ->Punteo: " << puntajeTotal << "\n"
        "   ->Tiempo de partida: " << tiempoPartida << " s\n";
    system("pause");

}
//opciones para jugar
void jugando() {
    //reinicio de valores
    pasosTotalesRealizados = 0;
    puntajeTotal = 0;
    posicionAlcanzada = 0;
    clock_t tiempo;
    tiempo = clock();
    TablaReporte agregarJuegoTabla = TablaReporte();
    cicloRepetirJugando = true;
    while (cicloRepetirJugando) {
        cout << "* El nivel en el que te encuentras es: " << (nivelActual + 1) << " *" << endl;
        tableros[nivelActual]->imprimir(x);
        cout << endl;
        cout << "-> Ingresa una opcion para continuar\n"
            "1) Intercambiar bloque vacio con bloque de arriba\n"
            "2) Intercambiar bloque vacio con bloque de abajo\n"
            "3) Intercambiar bloque vacio con bloque de la izquierda\n"
            "4) Intercambiar bloque vacio con bloque de la derecha\n"
            "5) Cambiar de nivel\n"
            "6) Visualizar todos los niveles\n"
            "7) Reiniciar el juego\n"
            "8) Terminar el juego\n";
        cin >> opcionJugando;
        switch (opcionJugando)
        {
        case 1:
            cout << "* Intercambio bloque vacio con bloque de arriba *" << endl;
            tableros[nivelActual]->imprimir(x);
            pasosTotalesRealizados = pasosTotalesRealizados + tableros[nivelActual]->intercambioVacioArriba(x);
            cout << endl;
            break;
        case 2:
            cout << "* Intercambio bloque vacio con bloque de abajo *" << endl;
            tableros[nivelActual]->imprimir(x);
            pasosTotalesRealizados = pasosTotalesRealizados + tableros[nivelActual]->intercambioVacioAbajo(x);
            cout << endl;
            break;
        case 3:
            cout << "* Intercambio bloque vacio con bloque de la izquierda *" << endl;
            tableros[nivelActual]->imprimir(x);
            pasosTotalesRealizados = pasosTotalesRealizados + tableros[nivelActual]->intercambioVacioIzquierda(x);
            cout << endl;
            break;
        case 4:
            cout << "* Intercambio bloque vacio con bloque de la derecha *" << endl;
            tableros[nivelActual]->imprimir(x);
            pasosTotalesRealizados = pasosTotalesRealizados + tableros[nivelActual]->intercambioVacioDerecha(x);
            cout << endl;
            break;
        case 5:
            nivelAnterior = nivelActual;
            cout << "->Ingresa el nivel al que quieres acceder, disponibles del 1-" << tableros.size() << endl;
            cin >> nivelActual;
            temporalTableroSize=static_cast<int>(tableros.size());
            while (nivelActual < 1 || nivelActual>temporalTableroSize)
            {
                cout << "* Ingresaste un valor que no se encuentra *" << endl;
                cin >> nivelActual;
            }
            nivelActual = nivelActual - 1;
            valorI = tableros[nivelAnterior]->posicionCero(x);
            busquedaCero = tableros[nivelAnterior]->cantidadMovimientosCero(x);
            valorRecuperacionNivel = tableros[nivelActual]->recuperarValorOtroNivel(valorI, busquedaCero);
            tableros[nivelAnterior]->actualizamosNivelAnterior(valorI, busquedaCero, valorRecuperacionNivel);
            tableros[nivelActual]->actualizamosNivelSiguiente(valorI, busquedaCero);
            cout << "* Nivel actualizado *" << endl;
            pasosTotalesRealizados++;
            break;
        case 6:
            for (size_t i = 0; i < tableros.size(); i++)
            {
                cout << "* Nivel: " << i + 1 << " *" << endl;
                tableros[i]->imprimir(x);
                cout << endl;
            }
            break;
        case 7:
            cout << "* Juego reiniciado *" << endl;
            tableros = tablerosReinicio;
            tiempo = clock();
            pasosTotalesRealizados = 0;
            nivelActual = 0;
            break;
        case 8:
            cicloRepetirJugando = false;
            cout << "* Juego terminado *" << endl;
            /*agregarJuegoTabla.construirTabla(2, "mariano2", 4, 5);
            tablaReporteArreglo.push_back(agregarJuegoTabla);*/
            //aca
            for (int i = 0; i < cantidadNiveles; i++)
            {
                valoresPunteo.push_back(tableros[i]->pasarValoresPunteo(x));
            }
            valoresUsuarioPunteo = valoresPunteo;
            for (size_t i = 0; i < valoresPunteo.size(); i++)
            {
                sort(valoresUsuarioPunteo[i].begin(), valoresUsuarioPunteo[i].end());
            }
            if (cantidadNiveles == 1) {
                for (size_t i = 0; i < valoresPunteo[0].size() - 1; i++)
                {
                    if (valoresPunteo[0][i] == valoresUsuarioPunteo[0][i + 1]) {
                        puntajeTotal = puntajeTotal + 2;
                    }
                }
            }
            else {
                for (size_t i = 0; i < valoresPunteo.size(); i++)
                {
                    bool contieneCero = find(valoresPunteo[i].begin(), valoresPunteo[i].end(), 0) != valoresPunteo[i].end();
                    if (contieneCero) {
                        for (size_t k = 0; k < valoresPunteo[i].size() - 1; k++)
                        {
                            if (valoresPunteo[i][k] == valoresUsuarioPunteo[i][k + 1]) {
                                puntajeTotal = puntajeTotal + 2;
                            }
                        }
                    }
                    else {
                        for (size_t j = 0; j < valoresPunteo[i].size(); j++)
                        {
                            if (valoresPunteo[i][j] == valoresUsuarioPunteo[i][j]) {
                                puntajeTotal = puntajeTotal + 2;
                            }
                        }
                    }
                }
            }
            tiempo = (clock() - tiempo);
            tiempoPartida = float(tiempo) / CLOCKS_PER_SEC;
            if (tablaReporteArreglo.size() == 0) {
                posicionAlcanzada = 1;
            }
            else {
                for (size_t i = 0; i < tablaReporteArreglo.size(); i++)
                {
                    if (puntajeTotal > tablaReporteArreglo[i].getPunteoReporte()) {
                        posicionAlcanzada = tablaReporteArreglo[i].getPosicionReporte();
                        for (size_t k = i; k < tablaReporteArreglo.size(); k++)
                        {
                            tablaReporteArreglo[k].setPosicionReporte(tablaReporteArreglo[k].getPosicionReporte() + 1);
                        }
                        break;
                    }
                    else if (puntajeTotal == tablaReporteArreglo[i].getPunteoReporte()) {
                        cout << tablaReporteArreglo[i].getTiempoPartida();
                        if (tiempoPartida < tablaReporteArreglo[i].getTiempoPartida()) {
                            posicionAlcanzada = tablaReporteArreglo[i].getPosicionReporte();
                            cout<< tablaReporteArreglo[i].getPosicionReporte();
                            for (size_t k = i; k < tablaReporteArreglo.size(); k++)
                            {
                                tablaReporteArreglo[k].setPosicionReporte(tablaReporteArreglo[k].getPosicionReporte() + 1);
                            }
                            break;
                        }
                        else {
                            posicionAlcanzada = 1+tablaReporteArreglo[tablaReporteArreglo.size() - 1].getPosicionReporte();
                        }
                    }
                    else {
                        posicionAlcanzada = 1 + tablaReporteArreglo[tablaReporteArreglo.size()-1].getPosicionReporte();
                    }
            }
        }
            nombreTemporal = nombreJugador;
            agregarJuegoTabla.construirTabla(posicionAlcanzada, nombreJugador, puntajeTotal, tiempoPartida);

            tablaReporteArreglo.push_back(agregarJuegoTabla);
            reportes();
            tableros.clear();
            tablerosReinicio.clear();
            valoresPunteo.clear();
            valoresUsuarioPunteo.clear();
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
            cout << "* Tablero nivel " << 1 << " creado * " << endl;
            matriz->imprimir(x);
            cout << endl;
            tableros.push_back(matriz);
            tablerosReinicio.push_back(matriz);
            for (int i = 1; i < cantidadNiveles; i++)
            {
                cout << "Llenar matriz de nivel: " << i + 1 << endl;
                llenarMatrizManualNivelesMas();
                cout << "* Tablero nivel " << i + 1 << " creado * " << endl;
                matriz->imprimir(x);
                cout << endl;
                tableros.push_back(matriz);
                tablerosReinicio.push_back(matriz);
                contadorNumerosNiveles++;
            }
            jugando();
            cicloRepetirJugar = false;
            break;
        case 2:
            cout << "Llenar matriz de nivel: " << +1 << endl;
            llenarMatrizAleatoria();
            cout << "* Tablero nivel " << 1 << " creado * " << endl;
            matriz->imprimir(x);
            cout << endl;
            tableros.push_back(matriz);
            tablerosReinicio.push_back(matriz);
            for (int i = 1; i < cantidadNiveles; i++)
            {
                cout << "Llenar matriz de nivel: " << i + 1 << endl;
                llenarMatrizAleatoriaNivelesMas();
                cout << "* Tablero nivel " << i + 1 << " creado * " << endl;
                matriz->imprimir(x);
                cout << endl;
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
    int enteroTemporal = tablaReporteArreglo.size();
    ordenarTabla(tablaReporteArreglo, 0, enteroTemporal - 1);
    for (size_t i = 0; i < tablaReporteArreglo.size(); i++)
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
