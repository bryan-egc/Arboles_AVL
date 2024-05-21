#include "avl_tree.h"
#include <iostream>

void showMenu() {
    std::cout << "1) Agregar nodo al árbol" << std::endl;
    std::cout << "2) Buscar un valor en el árbol" << std::endl;
    std::cout << "3) Eliminar un valor del árbol" << std::endl;
    std::cout << "4) Mostrar el árbol" << std::endl;
    std::cout << "5) Salir" << std::endl;
    std::cout << "Seleccione una opción: ";
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
            std::cout << "Árbol AVL:" << std::endl;
            tree.display();
            break;
        case 5:
            std::cout << "Saliendo..." << std::endl;
            break;
        default:
            std::cout << "Opción no válida." << std::endl;
            break;
        }
    } while (option != 5);

    return 0;
}

