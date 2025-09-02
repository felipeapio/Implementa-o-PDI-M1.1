#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <vector>

using namespace std; // Usado para evitar escrever "std::" antes de elementos da biblioteca padrão
using namespace cv;  // Usado para evitar escrever "cv::" antes de elementos da biblioteca OpenCV

int main()
{
    // atividade 6 Inverso da imagem
    // https://wiki.portugal-a-programar.pt/dev_net/vb.net/inverter_cor/
    // https://www.reddit.com/r/askscience/comments/lamdi6/how_can_colors_be_inverted/?tl=pt-br
    // inverter a cor de uma imagem seria subtrair o valor de seu pixel de 255 dessa forma nos estariamos pegando o seu inverso no circulo cromatico
    Mat image = imread("../image/imagem_original.jpg");
    Mat grayImageAritmetica = imread("../image/imagem_cinza_aritmetica.jpg");
    Mat grayImagePonderada = imread("../image/imagem_cinza_ponderada.jpg");

    if (image.empty() || grayImageAritmetica.empty() || grayImagePonderada.empty())
    {
        cerr << "Erro ao carregar a imagem!" << endl;
        return 1;
    }

    Mat imageColoridaInvertida(image.rows, image.cols, CV_8UC3);
    Mat grayImageAritmeticaInvertida(grayImageAritmetica.rows, grayImageAritmetica.cols, CV_8UC1);
    Mat grayImagePonderadaInvertida(grayImagePonderada.rows, grayImagePonderada.cols, CV_8UC1);

    // invertendo a imagem colorida
    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            // Vec3b pois armazena os 3 canais que é o caso de imagens coloridas
            Vec3b pixel = image.at<Vec3b>(i, j); // Acessa o pixel (B, G, R)
            pixel[0] = 255 - pixel[0];           // blue
            pixel[1] = 255 - pixel[1];           // green
            pixel[2] = 255 - pixel[2];           // red

            imageColoridaInvertida.at<Vec3b>(i, j)[0] = pixel[0];
            imageColoridaInvertida.at<Vec3b>(i, j)[1] = pixel[1];
            imageColoridaInvertida.at<Vec3b>(i, j)[2] = pixel[2];
        }
    }

    // invertendo as imagens cinzas
    for (int i = 0; i < grayImageAritmetica.rows; i++)
    {
        for (int j = 0; j < grayImageAritmetica.cols; j++)
        {
            // uchar pois armazena apenas um valor que é o caso de imagens com tons de cinza
            uchar pixel = grayImageAritmetica.at<uchar>(i, j); // Acessa o pixel (B, G, R)

            grayImageAritmeticaInvertida.at<uchar>(i, j) = 255 - pixel;
        }
    }

    for (int i = 0; i < grayImagePonderada.rows; i++)
    {
        for (int j = 0; j < grayImagePonderada.cols; j++)
        {
            // uchar pois armazena apenas um valor que é o caso de imagens com tons de cinza
            uchar pixel = grayImagePonderada.at<uchar>(i, j); // Acessa o pixel (B, G, R)

            grayImagePonderadaInvertida.at<uchar>(i, j) = 255 - pixel;
        }
    }

    imwrite("../image/imageColoridaInvertida.jpg", imageColoridaInvertida);
    imwrite("../image/imageGrayAritmeticaInvertida.jpg", grayImageAritmeticaInvertida);
    imwrite("../image/imageGrayPonderadaInvertida.jpg", grayImagePonderadaInvertida);

    return 0; // Retorna 0, indicando que o programa terminou com sucesso
}