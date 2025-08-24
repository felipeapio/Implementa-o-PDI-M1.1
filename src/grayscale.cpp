#include <iostream> // Biblioteca para entrada e saída de dados
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace std; // Usado para evitar escrever "std::" antes de elementos da biblioteca padrão
using namespace cv;  // Usado para evitar escrever "cv::" antes de elementos da biblioteca OpenCV

int main()
{ // Função principal, onde o programa começa a execução
    // Código do seu programa vai aqui
    cout << "Ola, Mundo!" << endl;                      // Exibe uma mensagem na tela
    Mat image = imread("../image/imagem_original.jpg"); // Lê a imagem do arquivo "image.jpg"
    if (image.empty())
    {
        cerr << "Erro ao carregar a imagem!" << endl;
        return 1;
    }
    return 0; // Retorna 0, indicando que o programa terminou com sucesso
}