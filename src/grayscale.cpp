#include <iostream> // Biblioteca para entrada e saída de dados
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace std; // Usado para evitar escrever "std::" antes de elementos da biblioteca padrão
using namespace cv;  // Usado para evitar escrever "cv::" antes de elementos da biblioteca OpenCV

int main()
{
    // atividade 1 Conversão para Tons de Cinza
    Mat image = imread("../image/imagem_original.jpg"); // Lê a imagem do arquivo "image.jpg"
    if (image.empty())
    {
        cerr << "Erro ao carregar a imagem!" << endl;
        return 1;
    }

    // Cria uma nova imagem em tons de cinza com o mesmo tamanho, mas 1 canal
    Mat grayImage(image.rows, image.cols, CV_8UC1);

    // Aqui vamos percorre cada pixel (linha e coluna obviamente) da imagem original
    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            Vec3b pixel = image.at<Vec3b>(i, j); // Acessa o pixel (B, G, R)
            uchar blue = pixel[0];
            uchar green = pixel[1];
            uchar red = pixel[2];

            // Aplica a fórmula de conversão para tons de cinza
            uchar gray = static_cast<uchar>(0.299 * red + 0.587 * green + 0.114 * blue);

            // Define o valor na imagem em tons de cinza
            grayImage.at<uchar>(i, j) = gray;
        }
    }
    imwrite("../image/imagem_cinza.jpg", grayImage); // salvando a nova imagem ao qual alteramos para cinza

    return 0; // Retorna 0, indicando que o programa terminou com sucesso
}