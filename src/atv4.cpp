#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace std; // Usado para evitar escrever "std::" antes de elementos da biblioteca padrão
using namespace cv;  // Usado para evitar escrever "cv::" antes de elementos da biblioteca OpenCV

int main()
{
    // atividade 4 Isolar Canais de Cores (colorida)
    Mat image = imread("../image/imagem_original.jpg"); // Lê a imagem do arquivo "image.jpg"
    if (image.empty())
    {
        cerr << "Erro ao carregar a imagem!" << endl;
        return 1;
    }

    Mat imageRed = image.clone();
    Mat imageGreen = image.clone();
    Mat imageBlue = image.clone();

    // isolando o canal vermelho
    for (int i = 0; i < imageRed.rows; i++)
    {
        for (int j = 0; j < imageRed.cols; j++)
        {
            imageRed.at<Vec3b>(i, j)[0] = 0; // Azul
            imageRed.at<Vec3b>(i, j)[1] = 0; // Verde
        }
    }

    // isolando o canal verde
    for (int i = 0; i < imageGreen.rows; i++)
    {
        for (int j = 0; j < imageGreen.cols; j++)
        {
            imageGreen.at<Vec3b>(i, j)[0] = 0; // Azul
            imageGreen.at<Vec3b>(i, j)[2] = 0; // Vermelho
        }
    }

    // isolando o canal azul
    for (int i = 0; i < imageBlue.rows; i++)
    {
        for (int j = 0; j < imageBlue.cols; j++)
        {
            imageBlue.at<Vec3b>(i, j)[1] = 0; // Verde
            imageBlue.at<Vec3b>(i, j)[2] = 0; // Vermelho
        }
    }

    imwrite("../image/imageRed.jpg", imageRed);
    imwrite("../image/imageGreen.jpg", imageGreen);
    imwrite("../image/imageBlue.jpg", imageBlue);
    return 0;
}