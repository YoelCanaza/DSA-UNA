#include <bits/stdc++.h>

using namespace std;

class matrizCSR
{
private:
    vector<float> aa; 
    vector<size_t> ja; 
    vector<size_t> ia; 

public:
    matrizCSR() {

    }

    void pedirAA(void) {
        float valorNn;
        cout << "Ingrese los valores no nulos de la matriz introducidos por filas. Escribe 0 para terminar de insertar: ";
        cin >> valorNn;

        while(valorNn != 0) {
            aa.push_back(valorNn);
            cin >> valorNn;
        }
    }

    void pedirJA(void) {
        int valorNn;
        cout << "Ingrese los indices de columna de los elementos (Escribe -1 para terminar de insertar): ";
        cin >> valorNn;

        while(valorNn != -1) {
            ja.push_back(static_cast<size_t>(valorNn)); 
            cin >> valorNn;
        }
    }

    void pedirIA(void) {
        int valorNn;
        cout << "Ingrese los indices de inicio de cada fila (Escribe -1 para terminar de insertar): ";
        cin >> valorNn;

        while(valorNn != -1) {
            ia.push_back(static_cast<size_t>(valorNn));
            cin >> valorNn;
        }
    }

    void imprimirMatriz(size_t numFilas, size_t numColumnas) {
        
        cout << "aa: ";
        for (float val : aa) {
            cout << val << " ";
        }
        cout << endl;

        cout << "ja: ";
        for (size_t val : ja) {
            cout << val << " ";
        }
        cout << endl;

        cout << "ia: ";
        for (size_t val : ia) {
            cout << val << " ";
        }
        cout << endl;

        
        for (size_t i = 0; i < numFilas; i++) {
            if (i < ia.size() - 1) {
                size_t start = ia[i];
                size_t end = ia[i + 1];
                for (size_t j = 0; j < numColumnas; j++) {
                    bool encontrado = false;
                    for (size_t k = start; k < end; k++) {
                        if (ja[k] == j) { 
                            cout << aa[k] << " ";
                            encontrado = true;
                            break;
                        }
                    }
                    if (!encontrado) {
                        cout << "0 ";
                    }
                }
            } else {
                for (size_t j = 0; j < numColumnas; j++) {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }

    matrizCSR transpuesta(size_t numFilas, size_t numColumnas) {
        matrizCSR transpuesta;
        vector<size_t> columnCount(numColumnas, 0); 

        for (size_t col : ja) {
            columnCount[col]++;
        }

        transpuesta.ia.push_back(0);
        for (size_t count : columnCount) {
            transpuesta.ia.push_back(transpuesta.ia.back() + count);
        }

        transpuesta.aa.resize(aa.size());
        transpuesta.ja.resize(ja.size());

        vector<size_t> nextPosition = transpuesta.ia;

        for (size_t i = 0; i < numFilas; ++i) {
            for (size_t j = ia[i]; j < ia[i + 1]; ++j) {
                size_t col = ja[j];
                size_t pos = nextPosition[col]++;
                transpuesta.aa[pos] = aa[j];
                transpuesta.ja[pos] = i;
            }
        }

        return transpuesta;
    }
};

int main(void) {
    matrizCSR m1;
    m1.pedirAA();
    m1.pedirJA();
    m1.pedirIA();
    cout << endl;
    m1.imprimirMatriz(5, 5); 
    cout << endl;

    cout << "Matriz Transpuesta:" << endl;
    matrizCSR m2 = m1.transpuesta(5, 5);
    cout << endl;

    m2.imprimirMatriz(5, 5); 

    return 0;
}
