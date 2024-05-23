#include <bits/stdc++.h>
#define MAX_ELE 10
using namespace std;


class Cola {
    int mElementos[MAX_ELE];
    int indiceInsertar;
    int primeroEnCola;
    bool llena;
    bool vacia;
public:
    Cola();
    void insertar(int val);
    int extraer();
    bool estaVacia();
    bool estaLlena();

    void imprimirCola();
    void imprimirArreglo();
};

Cola::Cola() {
    indiceInsertar = MAX_ELE - 1;
    primeroEnCola = MAX_ELE;
    llena = false;
    vacia = true;
}

void Cola::insertar(int val) {
    if(!estaLlena()) {
        vacia = false;
        if(primeroEnCola == MAX_ELE) primeroEnCola -= 1;

        mElementos[indiceInsertar] = val;
        indiceInsertar -= 1;
        if(indiceInsertar == -1) indiceInsertar = MAX_ELE - 1;

        if(indiceInsertar == primeroEnCola) llena = true;
    }
}

int Cola::extraer() {
    if(!estaVacia()) {
        llena = false;
        int tempReturn = mElementos[primeroEnCola];

        primeroEnCola -= 1;
        if(primeroEnCola == -1) primeroEnCola = MAX_ELE - 1;
        if(primeroEnCola == indiceInsertar) vacia = true;

        return tempReturn;
    } else {
        return 0;
    }
}

bool Cola::estaLlena() {
    return llena;
}

bool Cola::estaVacia() {
    return vacia;
}

void Cola::imprimirCola() {
    while(!estaVacia()) {
        cout <<extraer() << " ";
    }
    cout << endl;
}

void Cola::imprimirArreglo() {
    for(int i = 0; i < MAX_ELE; i++) {
        cout << mElementos[i] << " ";
    }
    cout << endl;
}


void test(void) {
    // Nuesto array está declarado con un tamaño máximo de 10 elementos
    Cola cola1;

    // LLenamos la cola de '1'
    while(!cola1.estaLlena()) cola1.insertar(1);
    // Extraemos 6 elementos de la cola
    for(int i = 0; i < 6; i++) cola1.extraer();
    // LLenamos los 3 espacios que ahora tenemos con '2'
    while(!cola1.estaLlena()) cola1.insertar(2);
    // Extraemos 2 elementos de la cola
    for(int i = 0; i < 2; i++) cola1.extraer();
    // LLenamos los espacios sobrantes con '3'
    while(!cola1.estaLlena()) cola1.insertar(3);

    cout << "Arreglo (impreso desde mElementos[0] hasta mElementos[MAX_ELE - 1]): " << endl;
    cola1.imprimirArreglo();
    cout << endl;
    cout << "Cola (impreso en el orden en el que fueron insertados los elementos): " << endl;
    cola1.imprimirCola();

    /* Para imprimir los elementos de la cola fuimos eliminando los elementos 
    de la cola, por lo que ahora la lista está vacía*/

    cout << endl << "Después de imprimir todos los elementos, ";
    if(cola1.estaVacia()) cout << "la cola está vacía" << endl;
    else cout << "la cola no está vacía" << endl;
}

int main(void) {
    test();
}
