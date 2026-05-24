#include <iostream>

using namespace std;

struct Nodo {
    int dato;
    Nodo* izquierdo;
    Nodo* derecho;
};

Nodo* crearNodo(int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->izquierdo = NULL;
    nuevo->derecho = NULL;

    return nuevo;
}

Nodo* insertar(Nodo* raiz, int valor) {

    if (raiz == NULL) {
        return crearNodo(valor);
    }

    if (valor < raiz->dato) {
        raiz->izquierdo =insertar(raiz->izquierdo, valor);
    }
    else {
        raiz->derecho =insertar(raiz->derecho, valor);
    }

    return raiz;
}

void inOrden(Nodo* raiz) {

    if (raiz != NULL) {
        inOrden(raiz->izquierdo);
        cout << raiz->dato << " ";
        inOrden(raiz->derecho);
    }
}

void preOrden(Nodo* raiz) {

    if (raiz != NULL) {
        cout << raiz->dato << " ";
        preOrden(raiz->izquierdo);
        preOrden(raiz->derecho);
    }
}

void postOrden(Nodo* raiz) {

    if (raiz != NULL) {
        postOrden(raiz->izquierdo);
        postOrden(raiz->derecho);
        cout << raiz->dato << " ";
    }
}

void liberarMemoria(Nodo* raiz) {

    if (raiz != NULL) {
        liberarMemoria(raiz->izquierdo);
        liberarMemoria(raiz->derecho);
        delete raiz;
    }
}

int main() {

    Nodo* raiz = NULL;
    int opcion;
    int valor;

    do {

        cout << "\n=====================================\n";
        cout << " ARBOLES BST\n";
        cout << " Nombre: Sebastian Rodas\n";
        cout << "=====================================\n";
        cout << "1. Insertar valor\n";
        cout << "2. Mostrar InOrden\n";
        cout << "3. Mostrar PreOrden\n";
        cout << "4. Mostrar PostOrden\n";
        cout << "5. Mostrar todos los recorridos\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "Ingrese valor: ";
                cin >> valor;
                raiz = insertar(raiz, valor);
                cout << "Valor insertado.\n";
                
                break;

            case 2:

                if (raiz == NULL) {
                    cout << "El arbol esta vacio.\n";
                }
                else {
                    cout << "InOrden: ";
                    inOrden(raiz);
                    cout << endl;
                }

                break;

            case 3:

                if (raiz == NULL) {
                    cout << "El arbol esta vacio.\n";
                }
                else {
                    cout << "PreOrden: ";
                    preOrden(raiz);
                    cout << endl;
                }
                break;


            case 4:
                if (raiz == NULL) {
                    cout << "El arbol esta vacio.\n";
                }
                else {
                    cout << "PostOrden: ";
                    postOrden(raiz);
                    cout << endl;
                }

                break;
            case 5:
                if (raiz == NULL) {
                    cout << "El arbol esta vacio.\n";
                }
                else {
                    cout << "\nInOrden: ";
                    inOrden(raiz);
                    cout << "\nPreOrden: ";
                    preOrden(raiz);
                    cout << "\nPostOrden: ";
                    postOrden(raiz);
                    cout << endl;
                }
                break;
            case 6:
                break;
            default:

                cout << "Opcion invalida.\n";
        }

    } while(opcion != 6);

    liberarMemoria(raiz);

    return 0;
}
