#include <iostream>
using namespace std;

int random(int n){
    static bool primera_vez= true;
    if(primera_vez){
        srand(time(0));
        primera_vez = false;
    }
    return (rand() % n) +1;
}

void esperar(int n){
    long tiempo = clock() + n;
    while (clock() < tiempo);
}

void tomarMuestraTipoA(int *n){

    *n = random(10);
    for (int i=0;i<*n;i++){
        cout<< "Tomando muestra tipo A\n";
        esperar(500);
    }
}

void tomarMuestraTipoB(int *n){
    *n = random(20);
    for(int i=0;i<*n;i++){
        cout<<"Tomando muestra tipo B \n";
        esperar(500);
    }
}

void resultados(int n,int m){
    cout <<"Muestras de tipo A:"<<n<<endl;
    cout<<"Muestras de tipo B:"<<m<<endl;
    cout<<"Total:"<<n+m<<endl;
}

int main(void){
    int nMuestrasTipoA=0;
    int nMuestrasTipoB=0;

    tomarMuestraTipoA(&nMuestrasTipoA);
    tomarMuestraTipoB(&nMuestrasTipoB);
    resultados(nMuestrasTipoA,nMuestrasTipoB);
}