all: Codigo

Codigo: Proyecto1-EstructuraDeDatos.o
	g++ -Wall -o Codigo Proyecto1-EstructuraDeDatos.o
	
Proyecto1-EstructuraDeDatos.o: Proyecto1-EstructuraDeDatos.cpp
	g++ -c -Wall Proyecto1-EstructuraDeDatos.cpp

clean:
	rm *.o Codigo