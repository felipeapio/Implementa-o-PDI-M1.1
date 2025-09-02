#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace std;
using namespace cv;

int main()
{

    // https://www-baeldung-com.translate.goog/cs/image-histograms?_x_tr_sl=en&_x_tr_tl=pt&_x_tr_hl=pt&_x_tr_pto=tc
    // ==================== ATIVIDADE 5: HISTOGRAMA ====================

    // HISTOGRAMA PARA IMAGEM COLORIDA - CORREÇÃO
    // Para imagem colorida, precisamos de histogramas separados para cada canal
    Mat image = imread("../image/imagem_original.jpg");
    Mat grayImage = imread("../image/imagem_cinza_aritmetica.jpg");
    if (image.empty() || grayImage.empty())
    {
        cerr << "Erro ao carregar a imagem!" << endl;
        return 1;
    }

    int histB[256] = {0};
    int histG[256] = {0};
    int histR[256] = {0};

    // Contar pixels para cada canal da imagem colorida
    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            Vec3b pixel = image.at<Vec3b>(i, j);
            histB[pixel[0]]++; // Canal Blue
            histG[pixel[1]]++; // Canal Green
            histR[pixel[2]]++; // Canal Red
        }
    }

    // Criar imagem para histograma colorido
    int hist_w = 512;
    int hist_h = 400;
    int bin_w = cvRound((double)hist_w / 256);
    Mat histColoridaImagem(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255));

    // Normalizar e desenhar cada canal com cor diferente
    int max_val_B = *max_element(histB, histB + 256);
    int max_val_G = *max_element(histG, histG + 256);
    int max_val_R = *max_element(histR, histR + 256);

    for (int i = 0; i < 256; i++)
    {
        int normalized_B = ((double)histB[i] / max_val_B) * hist_h;
        int normalized_G = ((double)histG[i] / max_val_G) * hist_h;
        int normalized_R = ((double)histR[i] / max_val_R) * hist_h;

        line(histColoridaImagem, Point(bin_w * i, hist_h),
             Point(bin_w * i, hist_h - normalized_B),
             Scalar(255, 0, 0), 1, 8, 0); // Azul para canal B

        line(histColoridaImagem, Point(bin_w * i, hist_h),
             Point(bin_w * i, hist_h - normalized_G),
             Scalar(0, 255, 0), 1, 8, 0); // Verde para canal G

        line(histColoridaImagem, Point(bin_w * i, hist_h),
             Point(bin_w * i, hist_h - normalized_R),
             Scalar(0, 0, 255), 1, 8, 0); // Vermelho para canal R
    }

    // HISTOGRAMA PARA IMAGEM CINZA
    int histCinza[256] = {0};

    for (int i = 0; i < grayImage.rows; i++)
    {
        for (int j = 0; j < grayImage.cols; j++)
        {
            uchar pixel = grayImage.at<uchar>(i, j);
            histCinza[pixel]++;
        }
    }

    Mat histImagemCinza(hist_h, hist_w, CV_8UC1, Scalar(255));

    int max_val_cinza = *max_element(histCinza, histCinza + 256);
    for (int i = 0; i < 256; i++)
    {
        histCinza[i] = ((double)histCinza[i] / max_val_cinza) * hist_h;
    }

    for (int i = 0; i < 256; i++)
    {
        line(histImagemCinza, Point(bin_w * i, hist_h),
             Point(bin_w * i, hist_h - histCinza[i]),
             Scalar(0), 1, 8, 0);
    }

    imwrite("../image/histograma_colorido.jpg", histColoridaImagem);
    imwrite("../image/histograma_cinza.jpg", histImagemCinza);

    return 0; // Retorna 0, indicando que o programa terminou com sucesso
}