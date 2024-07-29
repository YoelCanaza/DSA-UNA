struct Nodo {
    int Clave;
    Nodo *Izquierda;
    Nodo *Derecha;
};

class ABB {
    Nodo *Raiz; // Referencia a la raiz del ABB
public:
    ABB(); // Constructor
    int NumeroNodosPares();
    int Altura();
};

int ABB::NumeroNodosPares() {
    Nodo* nodoActual = Raiz;
    if (nodoActual == nullptr) return 0;
    
    int contadorPares = 0;
    Nodo* pila[100];  // Asumimos una profundidad máxima de 100
    int tope = 0;
    
    while (nodoActual != nullptr || tope > 0) {
        while (nodoActual != nullptr) {
            pila[tope++] = nodoActual;
            nodoActual = nodoActual->Izquierda;
        }
        
        nodoActual = pila[--tope];
        if (nodoActual->Clave % 2 == 0) contadorPares++;
        nodoActual = nodoActual->Derecha;
    }
    
    return contadorPares;
}

int ABB::Altura() {
    if (Raiz == nullptr) return 0;
    
    int alturaMaxima = 0;
    Nodo* pila[100];  // Asumimos una profundidad máxima de 100
    int profundidades[100];
    int tope = 0;
    
    pila[tope] = Raiz;
    profundidades[tope] = 1;
    tope++;
    
    while (tope > 0) {
        Nodo* nodoActual = pila[--tope];
        int profundidadActual = profundidades[tope];
        
        if (profundidadActual > alturaMaxima) alturaMaxima = profundidadActual;
        
        if (nodoActual->Derecha) {
            pila[tope] = nodoActual->Derecha;
            profundidades[tope] = profundidadActual + 1;
            tope++;
        }
        if (nodoActual->Izquierda) {
            pila[tope] = nodoActual->Izquierda;
            profundidades[tope] = profundidadActual + 1;
            tope++;
        }
    }
    
    return alturaMaxima;
}

int main() {

    return 0;
}