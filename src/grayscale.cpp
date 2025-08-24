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

    // atividade 2 Operações Aritméticas (+ - * /)
    // coloridas e tons de cinza
    Mat plusImageOriginal(image.rows, image.cols, CV_8UC1);
    Mat subtractionImageOriginal(image.rows, image.cols, CV_8UC1);
    Mat multiplicationImageOriginal(image.rows, image.cols, CV_8UC1);
    Mat divisionImageOriginal(image.rows, image.cols, CV_8UC1);

    Mat plusImageCinza(grayImage.rows, grayImage.cols, CV_8UC1);
    Mat subtractionImageCinza(grayImage.rows, grayImage.cols, CV_8UC1);
    Mat multiplicationImageCinza(grayImage.rows, grayImage.cols, CV_8UC1);
    Mat divisionImageCinza(grayImage.rows, grayImage.cols, CV_8UC1);

    // Imagem com Imagem
    Mat plusImageComImagem(grayImage.rows, grayImage.cols, CV_8UC1);
    Mat subtractionImageComImagem(grayImage.rows, grayImage.cols, CV_8UC1);
    Mat multiplicationImageComImagem(grayImage.rows, grayImage.cols, CV_8UC1);
    Mat divisionImageComImagem(grayImage.rows, grayImage.cols, CV_8UC1);

    // Imagem Escalar
    Mat plusImageEscalar(grayImage.rows, grayImage.cols, CV_8UC1);
    Mat subtractionEscalar(grayImage.rows, grayImage.cols, CV_8UC1);
    Mat multiplicationEscalar(grayImage.rows, grayImage.cols, CV_8UC1);
    Mat divisionImageEscalar(grayImage.rows, grayImage.cols, CV_8UC1);
    Mat plusGrayImageCinza(grayImage.rows, grayImage.cols, CV_8UC1);
    Mat subtractionGrayImageCinza(grayImage.rows, grayImage.cols, CV_8UC1);
    Mat multiplicationGrayImageCinza(grayImage.rows, grayImage.cols, CV_8UC1);
    Mat divisionGrayImageCinza(grayImage.rows, grayImage.cols, CV_8UC1);

    // plusImageOriginal
    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            Vec3b pixel = image.at<Vec3b>(i, j); // Acessa o pixel (B, G, R)
            uchar blue = pixel[0];
            uchar green = pixel[1];
            uchar red = pixel[2];
            int plus = red + green + blue;
            if (plus > 255)
            {
                plus = 255;
            }
            if (plus < 0)
            {
                plus = 0;
            };

            plusImageOriginal.at<uchar>(i, j) = plus;
        }
    }

    // subtractionImageOriginal
    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            Vec3b pixel = image.at<Vec3b>(i, j); // Acessa o pixel (B, G, R)
            uchar blue = pixel[0];
            uchar green = pixel[1];
            uchar red = pixel[2];
            int subtraction = red - green - blue;
            if (subtraction > 255)
            {
                subtraction = 255;
            }
            if (subtraction < 0)
            {
                subtraction = 0;
            };
            subtractionImageOriginal.at<uchar>(i, j) = subtraction;
        }
    }

    // multiplicationImageOriginal
    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            Vec3b pixel = image.at<Vec3b>(i, j); // Acessa o pixel (B, G, R)
            uchar blue = pixel[0];
            uchar green = pixel[1];
            uchar red = pixel[2];
            int multiplication = red * green * blue;
            if (multiplication > 255)
            {
                multiplication = 255;
            }
            if (multiplication < 0)
            {
                multiplication = 0;
            };
            multiplicationImageOriginal.at<uchar>(i, j) = multiplication;
        }
    }

    // divisionImageOriginal
    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            Vec3b pixel = image.at<Vec3b>(i, j); // Acessa o pixel (B, G, R)
            uchar blue = pixel[0];
            uchar green = pixel[1];
            uchar red = pixel[2];
            double resultado = blue;
            if (green != 0)
            {
                resultado = resultado / green;
            }
            if (red != 0)
            {
                resultado = resultado / red;
            }
            divisionImageOriginal.at<uchar>(i, j) = resultado;
        }
    }

    // plusImageCinza
    for (int i = 0; i < grayImage.rows; i++)
    {
        for (int j = 0; j < grayImage.cols; j++)
        {
            Vec3b pixel = image.at<Vec3b>(i, j); // Acessa o pixel (B, G, R)
            uchar blue = pixel[0];
            uchar green = pixel[1];
            uchar red = pixel[2];
            int plus = red + green + blue;
            if (plus > 255)
            {
                plus = 255;
            }
            if (plus < 0)
            {
                plus = 0;
            };
            plusImageCinza.at<uchar>(i, j) = plus;
        }
    }

    // subtractionImageCinza
    for (int i = 0; i < grayImage.rows; i++)
    {
        for (int j = 0; j < grayImage.cols; j++)
        {
            Vec3b pixel = image.at<Vec3b>(i, j); // Acessa o pixel (B, G, R)
            uchar blue = pixel[0];
            uchar green = pixel[1];
            uchar red = pixel[2];
            int subtraction = red - green - blue;
            if (subtraction > 255)
            {
                subtraction = 255;
            }
            if (subtraction < 0)
            {
                subtraction = 0;
            };
            subtractionImageCinza.at<uchar>(i, j) = subtraction;
        }
    }

    // multiplicationImageCinza
    for (int i = 0; i < grayImage.rows; i++)
    {
        for (int j = 0; j < grayImage.cols; j++)
        {
            Vec3b pixel = image.at<Vec3b>(i, j); // Acessa o pixel (B, G, R)
            uchar blue = pixel[0];
            uchar green = pixel[1];
            uchar red = pixel[2];
            int multiplication = red * green * blue;
            if (multiplication > 255)
            {
                multiplication = 255;
            }
            if (multiplication < 0)
            {
                multiplication = 0;
            };
            multiplicationImageCinza.at<uchar>(i, j) = multiplication;
        }
    }

    // dvisionImageCinza
    for (int i = 0; i < grayImage.rows; i++)
    {
        for (int j = 0; j < grayImage.cols; j++)
        {
            Vec3b pixel = image.at<Vec3b>(i, j); // Acessa o pixel (B, G, R)
            uchar blue = pixel[0];
            uchar green = pixel[1];
            uchar red = pixel[2];
            double resultado = blue;
            if (green != 0)
            {
                resultado = resultado / green;
            }
            if (red != 0)
            {
                resultado = resultado / red;
            }

            if (resultado > 255)
            {
                resultado = 255;
            }
            if (resultado < 0)
            {
                resultado = 0;
            };

            if (resultado > 255)
            {
                resultado = 255;
            }
            if (resultado < 0)
            {
                resultado = 0;
            };
            divisionImageCinza.at<uchar>(i, j) = resultado;
        }
    }

    // imageComImagemOriginal
    // plusImageComImagemOriginal
    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            Vec3b pixel = image.at<Vec3b>(i, j); // Acessa o pixel (B, G, R)
            uchar gray = grayImage.at<uchar>(i, j);

            int plus = pixel[0] + pixel[1] + pixel[2] + gray;
            if (plus > 255)
            {
                plus = 255;
            }
            if (plus < 0)
            {
                plus = 0;
            };
            plusImageComImagem.at<uchar>(i, j) = plus;
        }
    }

    // subtractionImageComImagemOriginal
    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            Vec3b pixel = image.at<Vec3b>(i, j); // Acessa o pixel (B, G, R)
            uchar gray = grayImage.at<uchar>(i, j);

            int subtraction = pixel[0] - pixel[1] - pixel[2] - gray;
            if (subtraction > 255)
            {
                subtraction = 255;
            }
            if (subtraction < 0)
            {
                subtraction = 0;
            };
            subtractionImageComImagem.at<uchar>(i, j) = subtraction;
        }
    }

    // multiplicationImageComImagemOriginal
    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            Vec3b pixel = image.at<Vec3b>(i, j); // Acessa o pixel (B, G, R)
            uchar gray = grayImage.at<uchar>(i, j);

            int multiplication = pixel[0] * pixel[1] * pixel[2] * gray;
            if (multiplication > 255)
            {
                multiplication = 255;
            }
            if (multiplication < 0)
            {
                multiplication = 0;
            };
            multiplicationImageComImagem.at<uchar>(i, j) = multiplication;
        }
    }

    // divisionImageComImagemOriginal
    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            Vec3b pixel = image.at<Vec3b>(i, j); // Acessa o pixel (B, G, R)
            uchar gray = grayImage.at<uchar>(i, j);
            double resultado = pixel[0];
            if (pixel[1] != 0)
            {
                resultado = resultado / pixel[1];
            }
            if (pixel[2] != 0)
            {
                resultado = resultado / pixel[2];
            }
            if (gray != 0)
            {
                resultado = resultado / gray;
            }

            if (resultado > 255)
            {
                resultado = 255;
            }
            if (resultado < 0)
            {
                resultado = 0;
            };
            divisionImageComImagem.at<uchar>(i, j) = resultado;
        }
    }

    int escalar = 50;

    // plusImageEscalar
    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            Vec3b pixel = image.at<Vec3b>(i, j); // Acessa o pixel (B, G, R)
            uchar blue = pixel[0];
            uchar green = pixel[1];
            uchar red = pixel[2];
            int plus = red + green + blue + 50;
            if (plus > 255)
            {
                plus = 255;
            }
            if (plus < 0)
            {
                plus = 0;
            };

            plusImageEscalar.at<uchar>(i, j) = plus;
        }
    }

    // subtractionEscalar
    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            Vec3b pixel = image.at<Vec3b>(i, j); // Acessa o pixel (B, G, R)
            uchar blue = pixel[0];
            uchar green = pixel[1];
            uchar red = pixel[2];
            int subtraction = red - green - blue - 50;
            if (subtraction > 255)
            {
                subtraction = 255;
            }
            if (subtraction < 0)
            {
                subtraction = 0;
            };
            subtractionEscalar.at<uchar>(i, j) = subtraction;
        }
    }

    // multiplicationEscalar
    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            Vec3b pixel = image.at<Vec3b>(i, j); // Acessa o pixel (B, G, R)
            uchar blue = pixel[0];
            uchar green = pixel[1];
            uchar red = pixel[2];
            int multiplication = red * green * blue * 50;
            if (multiplication > 255)
            {
                multiplication = 255;
            }
            if (multiplication < 0)
            {
                multiplication = 0;
            };
            multiplicationEscalar.at<uchar>(i, j) = multiplication;
        }
    }

    // divisionImageEscalar
    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            Vec3b pixel = image.at<Vec3b>(i, j); // Acessa o pixel (B, G, R)
            uchar blue = pixel[0];
            uchar green = pixel[1];
            uchar red = pixel[2];
            double resultado = blue;
            if (green != 0)
            {
                resultado = resultado / green;
            }
            if (red != 0)
            {
                resultado = resultado / red;
            }
            resultado = resultado / 50;

            if (resultado > 255)
            {
                resultado = 255;
            }
            if (resultado < 0)
            {
                resultado = 0;
            };
            divisionImageEscalar.at<uchar>(i, j) = resultado;
        }
    }

    // plusImageEscalar
    for (int i = 0; i < grayImage.rows; i++)
    {
        for (int j = 0; j < grayImage.cols; j++)
        {
            Vec3b pixel = image.at<Vec3b>(i, j); // Acessa o pixel (B, G, R)
            uchar blue = pixel[0];
            uchar green = pixel[1];
            uchar red = pixel[2];
            int plus = red + green + +50;
            if (plus > 255)
            {
                plus = 255;
            }
            if (plus < 0)
            {
                plus = 0;
            };
            plusImageEscalar.at<uchar>(i, j) = plus;
        }
    }

    // subtractionEscalar
    for (int i = 0; i < grayImage.rows; i++)
    {
        for (int j = 0; j < grayImage.cols; j++)
        {
            Vec3b pixel = image.at<Vec3b>(i, j); // Acessa o pixel (B, G, R)
            uchar blue = pixel[0];
            uchar green = pixel[1];
            uchar red = pixel[2];
            int subtraction = red - green - blue - 50;
            if (subtraction > 255)
            {
                subtraction = 255;
            }
            if (subtraction < 0)
            {
                subtraction = 0;
            };
            subtractionEscalar.at<uchar>(i, j) = subtraction;
        }
    }

    // multiplicationEscalar
    for (int i = 0; i < grayImage.rows; i++)
    {
        for (int j = 0; j < grayImage.cols; j++)
        {
            Vec3b pixel = image.at<Vec3b>(i, j); // Acessa o pixel (B, G, R)
            uchar blue = pixel[0];
            uchar green = pixel[1];
            uchar red = pixel[2];
            int multiplication = red * green * blue * 50;
            if (multiplication > 255)
            {
                multiplication = 255;
            }
            if (multiplication < 0)
            {
                multiplication = 0;
            };
            multiplicationEscalar.at<uchar>(i, j) = multiplication;
        }
    }

    // divisionImageEscalar
    for (int i = 0; i < grayImage.rows; i++)
    {
        for (int j = 0; j < grayImage.cols; j++)
        {
            Vec3b pixel = image.at<Vec3b>(i, j); // Acessa o pixel (B, G, R)
            uchar blue = pixel[0];
            uchar green = pixel[1];
            uchar red = pixel[2];
            double resultado = blue;
            if (green != 0)
            {
                resultado = resultado / green;
            }
            if (red != 0)
            {
                resultado = resultado / red;
            }

            resultado = resultado / 50;

            if (resultado > 255)
            {
                resultado = 255;
            }
            if (resultado < 0)
            {
                resultado = 0;
            };

            if (resultado > 255)
            {
                resultado = 255;
            }
            if (resultado < 0)
            {
                resultado = 0;
            };
            divisionImageEscalar.at<uchar>(i, j) = resultado;
        }
    }

    // salvando as novas imagens ao qual alteramos
    imwrite("../image/imagem_somada_original.jpg", plusImageOriginal);
    imwrite("../image/imagem_subtraida_original.jpg", subtractionImageOriginal);
    imwrite("../image/imagem_multiplicada_original.jpg", multiplicationImageOriginal);
    imwrite("../image/imagem_divisao_original.jpg", divisionImageOriginal);

    imwrite("../image/imagem_somada_cinza.jpg", plusImageCinza);
    imwrite("../image/imagem_subtraida_cinza.jpg", subtractionImageCinza);
    imwrite("../image/imagem_multiplicada_cinza.jpg", multiplicationImageCinza);
    imwrite("../image/imagem_divisao_cinza.jpg", divisionImageCinza);

    imwrite("../image/imagem_somada_com_imagem.jpg", plusImageComImagem);
    imwrite("../image/imagem_subtraida_com_imagem.jpg", subtractionImageComImagem);
    imwrite("../image/imagem_multiplicada_com_imagem.jpg", multiplicationImageComImagem);
    imwrite("../image/imagem_divisao_com_imagem.jpg", divisionImageComImagem);

    imwrite("../image/imagem_somada_escalar.jpg", plusImageEscalar);
    imwrite("../image/imagem_subtraida_escalar.jpg", subtractionEscalar);
    imwrite("../image/imagem_multiplicada_escalar.jpg", multiplicationEscalar);
    imwrite("../image/imagem_divisao_escalar.jpg", divisionImageEscalar);
    imwrite("../image/grayImagem_somada_escalar.jpg", plusImageEscalar);
    imwrite("../image/grayImagem_subtraida_escalar.jpg", subtractionEscalar);
    imwrite("../image/grayImagem_multiplicada_escalar.jpg", multiplicationEscalar);
    imwrite("../image/grayImagem_divisao_escalar.jpg", divisionImageEscalar);

    // atividade 3 Limiarização (tons de cinza e colorida)
    // atividade 4 Isolar Canais de Cores (colorida)
    // atividade 5 Histograma (colorida e tons de cinza)
    // atividade 6 Inverso da imagem
    return 0; // Retorna 0, indicando que o programa terminou com sucesso
}