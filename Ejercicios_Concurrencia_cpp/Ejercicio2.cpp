/*

Enunciado:

Escribe una función contar(string nombre, int hasta, int ms) que cuente de 1 hasta hasta,
y en cada número muestre nombre: EJECUCION, numero n y luego duerma ms milisegundos 
mostrando nombre: BLOQUEADO.
En main crea tres hilos: A (hasta 4, 300 ms), B (hasta 3, 500 ms) y C (hasta 2, 1000 ms).
Muestra joinable() de los tres justo después de crearlos.
Haz join a A y B, pero a C hazle detach. Muestra joinable() de C después del detach.
Al final de main, agrega una pausa de 2500 ms (sleep_for) para darle tiempo a C de terminar.
*/
#include <iostream>
#include <thread>
#include <chrono>
#include <string>
using namespace std;
using namespace std::chrono_literals;

void contar(string nombre,int hasta,int ms){
    for (int i=1;i<=hasta;i++){
        cout << nombre << ": EJECUCION Conteo " << i << "\n";
        cout << nombre << ": BLOQUEADO dormido " << ms << " ms\n";
        this_thread::sleep_for(chrono::milliseconds(ms));
    }
    cout << nombre << ": TERMINADO\n";
}

int main(void){

    cout << "main: creando hilos\n";
    /*Creamos los hilos y les asignamos sus diferentes 
    argumentos de la tarea correspondiente*/
    thread h1(contar, "Conteo-1", 4, 300);
    thread h2(contar, "Conteo-2", 3, 500);
    thread h3(contar, "Conteo-3", 2,1000);

    /*Detectamos si es un hilo de ejecución valido */
    cout << "main: h1.joinable() = " << h1.joinable() << "\n";
    cout << "main: h2.joinable() = " << h2.joinable() << "\n";
    cout << "main: h3.joinable() = " << h3.joinable() << "\n";

    // join: main SÍ se bloquea hasta que el hilo termina
cout << "main: BLOQUEADO esperando a Conteo-1 (join)\n";
h1.join();
cout << "main: BLOQUEADO esperando a Conteo-2 (join)\n";
h2.join();

// detach: main NO se bloquea, el hilo sigue solo en segundo plano
cout << "main: separando Conteo-3 (detach), main sigue sin esperarlo\n";
h3.detach();

cout << "main: h1.joinable() = " << h1.joinable() << "\n";
cout << "main: h2.joinable() = " << h2.joinable() << "\n";
cout << "main: h3.joinable() = " << h3.joinable() << "\n";

cout << "main: pausa de 2500 ms para darle tiempo a Conteo-3\n";
this_thread::sleep_for(chrono::milliseconds(2500));

cout << "main: fin del programa\n";


}