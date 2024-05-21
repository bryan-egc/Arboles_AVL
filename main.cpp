#include "avl_tree.h"
#include <iostream>

void showMenu() {
    std::cout << "1) Agregar nodo al �rbol" << std::endl;
    std::cout << "2) Buscar un valor en el �rbol" << std::endl;
    std::cout << "3) Eliminar un valor del �rbol" << std::endl;
    std::cout << "4) Mostrar el �rbol" << std::endl;
    std::cout << "5) Salir" << std::endl;
    std::cout << "Seleccione una opci�n: ";
}

int main() {
    AVLTree tree;
    int option, value;

    do {
        showMenu();
        std::cin >> option;

        switch (option) {
        case 1:
            std::cout << "Ingrese el valor a agregar: ";
            std::cin >> value;
            tree.insert(value);
            std::cout << "Valor agregado." << std::endl;
            break;
        case 2:
            std::cout << "Ingrese el valor a buscar: ";
            std::cin >> value;
            if (tree.search(value))
                std::cout << "Valor encontrado." << std::endl;
            else
                std::cout << "Valor no encontrado." << std::endl;
            break;
        case 3:
            std::cout << "Ingrese el valor a eliminar: ";
            std::cin >> value;
            tree.remove(value);
            std::cout << "Valor eliminado." << std::endl;
            break;
        case 4:
            std::cout << "�rbol AVL:" << std::endl;
            tree.display();
            break;
        case 5:
            std::cout << "Saliendo..." << std::endl;
            break;
        default:
            std::cout << "Opci�n no v�lida." << std::endl;
            break;
        }
    } while (option != 5);

    return 0;
}

