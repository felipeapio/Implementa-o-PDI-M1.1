#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// ==================== FUNÇÕES AUXILIARES ====================

// Função para limitar valores entre 0-255
uchar saturar(int valor)
{
    if (valor > 255)
        return 255;
    if (valor < 0)
        return 0;
    return valor;
}

// ==================== PONTO 1: COLORIDAS E TONS DE CINZA ====================

// Operações entre canais de imagem colorida
Mat operacaoEntreCanaisColorida(const Mat &image, const string &operacao, char canal1, char canal2)
{
    Mat result(image.rows, image.cols, CV_8UC3);

    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            Vec3b pixel = image.at<Vec3b>(i, j); // (B, G, R)

            // Definir índices dos canais
            int idx1, idx2;
            idx1 = (canal1 == 'B') ? 0 : (canal1 == 'G') ? 1
                                                         : 2;
            idx2 = (canal2 == 'B') ? 0 : (canal2 == 'G') ? 1
                                                         : 2;

            // Aplicar operação entre os dois canais
            int value;
            if (operacao == "soma")
            {
                value = pixel[idx1] + pixel[idx2];
            }
            else if (operacao == "subtracao")
            {
                value = pixel[idx1] - pixel[idx2];
            }
            else if (operacao == "multiplicacao")
            {
                value = pixel[idx1] * pixel[idx2];
            }
            else if (operacao == "divisao")
            {
                value = (pixel[idx2] != 0) ? pixel[idx1] / pixel[idx2] : pixel[idx1];
            }
            else
            {
                value = pixel[idx1];
            }

            // Limitar e colocar em todos os canais
            uchar valorFinal = saturar(value);
            Vec3b novoPixel(valorFinal, valorFinal, valorFinal);
            result.at<Vec3b>(i, j) = novoPixel;
        }
    }
    return result;
}

// Operações aritméticas para tons de cinza
Mat operacaoTonsCinza(const Mat &grayImage, const string &operacao, int valorEscalar)
{
    Mat result(grayImage.rows, grayImage.cols, CV_8UC1);

    for (int i = 0; i < grayImage.rows; i++)
    {
        for (int j = 0; j < grayImage.cols; j++)
        {
            uchar pixel = grayImage.at<uchar>(i, j);
            int value;

            if (operacao == "soma")
            {
                value = pixel + valorEscalar;
            }
            else if (operacao == "subtracao")
            {
                value = pixel - valorEscalar;
            }
            else if (operacao == "multiplicacao")
            {
                value = pixel * valorEscalar;
            }
            else if (operacao == "divisao")
            {
                value = (valorEscalar != 0) ? pixel / valorEscalar : pixel;
            }
            else
            {
                value = pixel;
            }

            result.at<uchar>(i, j) = saturar(value);
        }
    }
    return result;
}

// ==================== PONTO 2: IMAGEM COM IMAGEM ====================

// Operações entre duas imagens coloridas
Mat operacaoEntreImagensColoridas(const Mat &image1, const Mat &image2, const string &operacao)
{
    if (image1.size() != image2.size())
    {
        cerr << "Erro: Imagens com tamanhos diferentes!" << endl;
        return Mat();
    }

    Mat result(image1.rows, image1.cols, CV_8UC3);

    for (int i = 0; i < image1.rows; i++)
    {
        for (int j = 0; j < image1.cols; j++)
        {
            Vec3b pixel1 = image1.at<Vec3b>(i, j);
            Vec3b pixel2 = image2.at<Vec3b>(i, j);
            Vec3b novoPixel;

            for (int c = 0; c < 3; c++)
            {
                int value;
                if (operacao == "soma")
                {
                    value = pixel1[c] + pixel2[c];
                }
                else if (operacao == "subtracao")
                {
                    value = pixel1[c] - pixel2[c];
                }
                else if (operacao == "multiplicacao")
                {
                    value = pixel1[c] * pixel2[c];
                }
                else if (operacao == "divisao")
                {
                    value = (pixel2[c] != 0) ? pixel1[c] / pixel2[c] : pixel1[c];
                }
                else
                {
                    value = pixel1[c];
                }
                novoPixel[c] = saturar(value);
            }
            result.at<Vec3b>(i, j) = novoPixel;
        }
    }
    return result;
}

// Operações entre duas imagens em tons de cinza
Mat operacaoEntreImagensCinza(const Mat &image1, const Mat &image2, const string &operacao)
{
    if (image1.size() != image2.size())
    {
        cerr << "Erro: Imagens com tamanhos diferentes!" << endl;
        return Mat();
    }

    Mat result(image1.rows, image1.cols, CV_8UC1);

    for (int i = 0; i < image1.rows; i++)
    {
        for (int j = 0; j < image1.cols; j++)
        {
            uchar pixel1 = image1.at<uchar>(i, j);
            uchar pixel2 = image2.at<uchar>(i, j);
            int value;

            if (operacao == "soma")
            {
                value = pixel1 + pixel2;
            }
            else if (operacao == "subtracao")
            {
                value = pixel1 - pixel2;
            }
            else if (operacao == "multiplicacao")
            {
                value = pixel1 * pixel2;
            }
            else if (operacao == "divisao")
            {
                value = (pixel2 != 0) ? pixel1 / pixel2 : pixel1;
            }
            else
            {
                value = pixel1;
            }

            result.at<uchar>(i, j) = saturar(value);
        }
    }
    return result;
}

// ==================== PONTO 3: IMAGEM COM VALOR ESCALAR ====================

// Operações com valor escalar para imagem colorida
Mat operacaoEscalarColorida(const Mat &image, const string &operacao, int escalar)
{
    Mat result(image.rows, image.cols, CV_8UC3);

    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            Vec3b pixel = image.at<Vec3b>(i, j);
            Vec3b novoPixel;

            for (int c = 0; c < 3; c++)
            {
                int value;
                if (operacao == "soma")
                {
                    value = pixel[c] + escalar;
                }
                else if (operacao == "subtracao")
                {
                    value = pixel[c] - escalar;
                }
                else if (operacao == "multiplicacao")
                {
                    value = pixel[c] * escalar;
                }
                else if (operacao == "divisao")
                {
                    value = (escalar != 0) ? pixel[c] / escalar : pixel[c];
                }
                else
                {
                    value = pixel[c];
                }
                novoPixel[c] = saturar(value);
            }
            result.at<Vec3b>(i, j) = novoPixel;
        }
    }
    return result;
}

// Operações com valor escalar para tons de cinza
Mat operacaoEscalarCinza(const Mat &grayImage, const string &operacao, int escalar)
{
    Mat result(grayImage.rows, grayImage.cols, CV_8UC1);

    for (int i = 0; i < grayImage.rows; i++)
    {
        for (int j = 0; j < grayImage.cols; j++)
        {
            uchar pixel = grayImage.at<uchar>(i, j);
            int value;

            if (operacao == "soma")
            {
                value = pixel + escalar;
            }
            else if (operacao == "subtracao")
            {
                value = pixel - escalar;
            }
            else if (operacao == "multiplicacao")
            {
                value = pixel * escalar;
            }
            else if (operacao == "divisao")
            {
                value = (escalar != 0) ? pixel / escalar : pixel;
            }
            else
            {
                value = pixel;
            }

            result.at<uchar>(i, j) = saturar(value);
        }
    }
    return result;
}

// ==================== FUNÇÃO PRINCIPAL ====================

int main()
{
    // Carregar imagens
    Mat imageColorida = imread("../image/imagem_original.jpg");
    Mat grayAritmetica = imread("../image/imagem_cinza_aritmetica.jpg");
    Mat grayPonderada = imread("../image/imagem_cinza_ponderada.jpg");

    if (imageColorida.empty() || grayAritmetica.empty() || grayPonderada.empty())
    {
        cerr << "Erro ao carregar as imagens!" << endl;
        return 1;
    }

    // ==================== PONTO 1: COLORIDAS E TONS DE CINZA ====================
    cout << "Processando: Operações entre canais..." << endl;

    // Operações entre canais da imagem colorida
    Mat R_plus_G = operacaoEntreCanaisColorida(imageColorida, "soma", 'R', 'G');
    Mat B_minus_R = operacaoEntreCanaisColorida(imageColorida, "subtracao", 'B', 'R');
    Mat G_times_B = operacaoEntreCanaisColorida(imageColorida, "multiplicacao", 'G', 'B');
    Mat R_div_G = operacaoEntreCanaisColorida(imageColorida, "divisao", 'R', 'G');

    // Operações aritméticas para tons de cinza
    Mat somaAritmetica = operacaoTonsCinza(grayAritmetica, "soma", 50);
    Mat subAritmetica = operacaoTonsCinza(grayAritmetica, "subtracao", 50);
    Mat multiAritmetica = operacaoTonsCinza(grayAritmetica, "multiplicacao", 2);
    Mat divAritmetica = operacaoTonsCinza(grayAritmetica, "divisao", 2);

    Mat somaPonderada = operacaoTonsCinza(grayPonderada, "soma", 50);
    Mat subPonderada = operacaoTonsCinza(grayPonderada, "subtracao", 50);
    Mat multiPonderada = operacaoTonsCinza(grayPonderada, "multiplicacao", 2);
    Mat divPonderada = operacaoTonsCinza(grayPonderada, "divisao", 2);

    // ==================== PONTO 2: IMAGEM COM IMAGEM ====================
    cout << "Processando: Operações entre imagens..." << endl;

    // Operações entre duas imagens coloridas (usando a mesma imagem como exemplo)
    Mat somaImagensColorida = operacaoEntreImagensColoridas(imageColorida, imageColorida, "soma");
    Mat subImagensColorida = operacaoEntreImagensColoridas(imageColorida, imageColorida, "subtracao");
    Mat multiImagensColorida = operacaoEntreImagensColoridas(imageColorida, imageColorida, "multiplicacao");
    Mat divImagensColorida = operacaoEntreImagensColoridas(imageColorida, imageColorida, "divisao");

    // Operações entre duas imagens em tons de cinza
    Mat somaImagensCinza = operacaoEntreImagensCinza(grayAritmetica, grayPonderada, "soma");
    Mat subImagensCinza = operacaoEntreImagensCinza(grayAritmetica, grayPonderada, "subtracao");
    Mat multiImagensCinza = operacaoEntreImagensCinza(grayAritmetica, grayPonderada, "multiplicacao");
    Mat divImagensCinza = operacaoEntreImagensCinza(grayAritmetica, grayPonderada, "divisao");

    // ==================== PONTO 3: IMAGEM COM VALOR ESCALAR ====================
    cout << "Processando: Operações com valor escalar..." << endl;

    int escalar = 50;

    // Operações com escalar para imagem colorida
    Mat somaEscalarColorida = operacaoEscalarColorida(imageColorida, "soma", escalar);
    Mat subEscalarColorida = operacaoEscalarColorida(imageColorida, "subtracao", escalar);
    Mat multiEscalarColorida = operacaoEscalarColorida(imageColorida, "multiplicacao", escalar);
    Mat divEscalarColorida = operacaoEscalarColorida(imageColorida, "divisao", escalar);

    // Operações com escalar para tons de cinza
    Mat somaEscalarAritmetica = operacaoEscalarCinza(grayAritmetica, "soma", escalar);
    Mat subEscalarAritmetica = operacaoEscalarCinza(grayAritmetica, "subtracao", escalar);
    Mat multiEscalarAritmetica = operacaoEscalarCinza(grayAritmetica, "multiplicacao", escalar);
    Mat divEscalarAritmetica = operacaoEscalarCinza(grayAritmetica, "divisao", escalar);

    Mat somaEscalarPonderada = operacaoEscalarCinza(grayPonderada, "soma", escalar);
    Mat subEscalarPonderada = operacaoEscalarCinza(grayPonderada, "subtracao", escalar);
    Mat multiEscalarPonderada = operacaoEscalarCinza(grayPonderada, "multiplicacao", escalar);
    Mat divEscalarPonderada = operacaoEscalarCinza(grayPonderada, "divisao", escalar);

    // ==================== SALVAR RESULTADOS ====================
    cout << "Salvando resultados..." << endl;

    // Ponto 1
    imwrite("../image/R_plus_G.jpg", R_plus_G);
    imwrite("../image/B_minus_R.jpg", B_minus_R);
    imwrite("../image/G_times_B.jpg", G_times_B);
    imwrite("../image/R_div_G.jpg", R_div_G);

    imwrite("../image/soma_aritmetica.jpg", somaAritmetica);
    imwrite("../image/sub_aritmetica.jpg", subAritmetica);
    imwrite("../image/multi_aritmetica.jpg", multiAritmetica);
    imwrite("../image/div_aritmetica.jpg", divAritmetica);

    imwrite("../image/soma_ponderada.jpg", somaPonderada);
    imwrite("../image/sub_ponderada.jpg", subPonderada);
    imwrite("../image/multi_ponderada.jpg", multiPonderada);
    imwrite("../image/div_ponderada.jpg", divPonderada);

    // Ponto 2
    imwrite("../image/soma_imagens_colorida.jpg", somaImagensColorida);
    imwrite("../image/sub_imagens_colorida.jpg", subImagensColorida);
    imwrite("../image/multi_imagens_colorida.jpg", multiImagensColorida);
    imwrite("../image/div_imagens_colorida.jpg", divImagensColorida);

    imwrite("../image/soma_imagens_cinza.jpg", somaImagensCinza);
    imwrite("../image/sub_imagens_cinza.jpg", subImagensCinza);
    imwrite("../image/multi_imagens_cinza.jpg", multiImagensCinza);
    imwrite("../image/div_imagens_cinza.jpg", divImagensCinza);

    // Ponto 3
    imwrite("../image/soma_escalar_colorida.jpg", somaEscalarColorida);
    imwrite("../image/sub_escalar_colorida.jpg", subEscalarColorida);
    imwrite("../image/multi_escalar_colorida.jpg", multiEscalarColorida);
    imwrite("../image/div_escalar_colorida.jpg", divEscalarColorida);

    imwrite("../image/soma_escalar_aritmetica.jpg", somaEscalarAritmetica);
    imwrite("../image/sub_escalar_aritmetica.jpg", subEscalarAritmetica);
    imwrite("../image/multi_escalar_aritmetica.jpg", multiEscalarAritmetica);
    imwrite("../image/div_escalar_aritmetica.jpg", divEscalarAritmetica);

    imwrite("../image/soma_escalar_ponderada.jpg", somaEscalarPonderada);
    imwrite("../image/sub_escalar_ponderada.jpg", subEscalarPonderada);
    imwrite("../image/multi_escalar_ponderada.jpg", multiEscalarPonderada);
    imwrite("../image/div_escalar_ponderada.jpg", divEscalarPonderada);

    return 0;
}