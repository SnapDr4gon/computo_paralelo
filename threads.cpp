#include <iostream>
#include <thread>
#include <vector>
#include <random>

// Función para llenar una fila de la matriz con valores aleatorios
void fillRow(int* row, int cols) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    for (int i = 0; i < cols; ++i) {
        row[i] = dis(gen);
    }
}

int main() {
    const int rows = 3;
    const int cols = 3;
    int matrix[rows][cols] = {0};

    std::vector<std::thread> threads;

    // Crear y ejecutar los hilos
    for (int i = 0; i < rows; ++i) {
        threads.push_back(std::thread(fillRow, matrix[i], cols));
    }

    // Esperar a que todos los hilos terminen
    for (auto& thread : threads) {
        thread.join();
    }

    // Imprimir la matriz resultante
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
