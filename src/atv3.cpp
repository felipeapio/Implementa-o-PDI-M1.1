#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace std;
using namespace cv;

int main()
{
    // Carregar imagens
    Mat image = imread("../image/imagem_original.jpg");
    Mat grayImage = imread("../image/imagem_cinza_aritmetica.jpg"); // Supondo que você já tem uma imagem em tons de cinza

    if (image.empty() || grayImage.empty())
    {
        cerr << "Erro ao carregar a imagem!" << endl;
        return 1;
    }

    // atividade 3 Limiarização (tons de cinza e colorida)
    Mat imageLimiarColorida(image.rows, image.cols, CV_8UC3);
    Mat imageGrayLimiar(grayImage.rows, grayImage.cols, CV_8UC1); // Deve ser CV_8UC1 para imagem cinza
    double limiar = 127.5;                                        // valor médio entre 0 e 255

    // Limiarização para imagem COLORIDA
    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            Vec3b pixel = image.at<Vec3b>(i, j); // Acessa o pixel (B, G, R)
            Vec3b novoPixel;

            for (int c = 0; c < 3; c++) // Correção: use 'c' em vez de 'i'
            {
                if (pixel[c] < limiar)
                {
                    novoPixel[c] = 0;
                }
                else
                {
                    novoPixel[c] = 255;
                }
            }

            imageLimiarColorida.at<Vec3b>(i, j) = novoPixel;
        }
    }

    // Limiarização para imagem em TONS DE CINZA
    for (int i = 0; i < grayImage.rows; i++)
    {
        for (int j = 0; j < grayImage.cols; j++)
        {
            uchar pixel = grayImage.at<uchar>(i, j);
            uchar novoPixel;

            if (pixel < limiar)
            {
                novoPixel = 0;
            }
            else
            {
                novoPixel = 255;
            }

            imageGrayLimiar.at<uchar>(i, j) = novoPixel;
        }
    }

    imwrite("../image/imageLimiarColorida.jpg", imageLimiarColorida);
    imwrite("../image/imageGrayLimiar.jpg", imageGrayLimiar);

    return 0;
}