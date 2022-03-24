
#include <iostream>//entrada y salida de datos
#include <cstdlib>//new y delete
#include <vector>
using namespace std;//imprimir algo en pantalla
class TablaReporte {
private:
    int posicionReporte;
    string nombreJugadorReporte;
    int punteoReporte;
    float tiempoPartidaReporte;
    //constructor
public:
    TablaReporte() {
        this->posicionReporte = 0;
        this->nombreJugadorReporte = "";
        this->punteoReporte = 0;
        this->tiempoPartidaReporte = 0;
    }
    void construirTabla(int posicionReporte, string nombreJugadorReporte, int punteoReporte, float tiempoPartidaReporte) {
        this->posicionReporte = posicionReporte;
        this->nombreJugadorReporte = nombreJugadorReporte;
        this->punteoReporte = punteoReporte;
        this->tiempoPartidaReporte = tiempoPartidaReporte;
    }
    int getPosicionReporte() {
        return this->posicionReporte;
    }
    void setPosicionReporte(int nuevaPosicion) {
        this->posicionReporte=nuevaPosicion;
    }
    int getPunteoReporte() {
        return this->punteoReporte;
    }
    float getTiempoPartida() {
        return this->tiempoPartidaReporte;
    }
    void mostrarTabla() {
        cout << "->Posicion: " << this->posicionReporte << "\n"
            "  ->Nombre de Jugador: " << this->nombreJugadorReporte << "\n"
            "  ->Punteo: " << this->punteoReporte << +"\n"
            "  ->Tiempo de partida: " << this->tiempoPartidaReporte << " s\n";
    }
};
void swap(TablaReporte& valor1, TablaReporte& valor2) {
    TablaReporte tmp = valor1;
    valor1 = valor2;
    valor2 = tmp;
}
void ordenarTabla(vector<TablaReporte>& tabla, int leftT, int rightT) {
    int empezar = leftT;
    int terminar = rightT;
    int base = tabla[(empezar+terminar) / 2].getPosicionReporte();
    do
    {
        while (tabla[empezar].getPosicionReporte()<base&&empezar<rightT)
        {
            ++empezar;
        }
        while (base< tabla[terminar].getPosicionReporte()&& terminar > leftT)
        {
            --terminar;
        }
        if (empezar<=terminar)
        {
            swap(tabla[empezar], tabla[terminar]);
            ++empezar;
            --terminar;
        }
    } while (empezar <= terminar);
    if (leftT<=terminar)
    {
        ordenarTabla(tabla, leftT, terminar);
    }
    if (rightT>empezar)
    {
        ordenarTabla(tabla, empezar, rightT);
    }
}