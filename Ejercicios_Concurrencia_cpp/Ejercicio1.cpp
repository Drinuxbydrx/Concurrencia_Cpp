#include <iostream>
#include <thread>
#include <chrono>
#include <string>
using namespace std;
using namespace std::chrono_literals;

void tarea(string nombre, int veces, int ms)
{
    for (int i = 1; i <= veces; ++i)
    {
        cout << nombre << ": EJECUCION (iteracion " << i << ")\n";
        cout << nombre << ": BLOQUEADO (dormido " << ms << " ms)\n";
        this_thread::sleep_for(chrono::milliseconds(ms));
    }
    cout << nombre << ": TERMINADO\n";
}

int main()
{   
    cout << "main: creando hilos\n";
    /*Creamos los hilos y les asignamos sus diferentes 
    argumentos de la tarea correspondiente*/
    thread h1(tarea, "Hilo1", 3, 500);
    thread h2(tarea, "Hilo2", 3, 800);

    /*Detectamos si es un hilo de ejecución valido */
    cout << "main: h1.joinable() = " << h1.joinable() << "\n";
    cout << "main: h2.joinable() = " << h2.joinable() << "\n";

    /*Se ejecutan ambas tareas a la vez la primera sobre 500ms y la segunda sobre 800ms*/
    cout << "main: BLOQUEADO esperando a Hilo1\n";
    h1.join();
    cout << "main: BLOQUEADO esperando a Hilo2\n";
    h2.join();
    /*Volvemos a detectar si es un hilo de ejecución valido*/
    cout << "main: h1.joinable() = " << h1.joinable() << "\n";
    cout << "main: h2.joinable() = " << h2.joinable() << "\n";
    cout << "main: fin del programa\n";
}