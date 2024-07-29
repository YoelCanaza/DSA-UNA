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
private:
    int NumeroNodosParesRecursivo(Nodo* nodo);
    int AlturaRecursiva(Nodo* nodo);
};

int ABB::NumeroNodosPares() {
    return NumeroNodosParesRecursivo(Raiz);
}

int ABB::NumeroNodosParesRecursivo(Nodo* nodo) {
    if (nodo == nullptr) {
        return 0;
    }
    
    int contadorPares = (nodo->Clave % 2 == 0) ? 1 : 0;
    return contadorPares + NumeroNodosParesRecursivo(nodo->Izquierda) + NumeroNodosParesRecursivo(nodo->Derecha);
}

int ABB::Altura() {
    return AlturaRecursiva(Raiz);
}

int ABB::AlturaRecursiva(Nodo* nodo) {
    if (nodo == nullptr) {
        return 0;
    }
    
    int alturaIzquierda = AlturaRecursiva(nodo->Izquierda);
    int alturaDerecha = AlturaRecursiva(nodo->Derecha);
    
    return 1 + (alturaIzquierda > alturaDerecha ? alturaIzquierda : alturaDerecha);
}


int main(void) {
    
}