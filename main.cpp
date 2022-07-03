#include <QGuiApplication>
#include <QString>
#include <QImage>
#include <QPixmap>
#include <QDebug>
#include <iostream>
#include <math.h>
#include <QMovie>
#include <QThread>
using namespace std;

void clearConsole()
{
    #ifdef WIN
        system("cls");
    #else
        system("clear");
    #endif
}

QString density = "@QB#NgWM8RufF]}{tx1zv7lciL/\\|?*>r^;:_\"~,'.-`";
void printImage(QImage image)
{
    // проверка изображения на доступность
    if(image.isNull())
    {
        throw std::bad_exception();
    }

    image = image.scaled(100, 100, Qt::IgnoreAspectRatio);
    for (int w = 0; w < image.rect().right(); w++)
    {
        for (int h = 0; h < image.rect().bottom(); h++)
        {
            QColor pixel = image.pixel(h, w);
            int index = (1 - pixel.lightnessF()) * (density.size() - 1);
            cout << density.at(index).toLatin1();
        }
    cout << endl;
  }

}

void processData(QString path)
{
    QMovie movie(path);

    //если удалось переключиться на следующий кадр, то выполнить тело цикла
    while (movie.jumpToNextFrame())
    {
      clearConsole();
      printImage(movie.currentImage());
      QThread::msleep(30);
    }
}

int main(int argc, char *argv[])
{
    QGuiApplication a(argc, argv);

    if(argc < 2)
    {
        qWarning("ERROR 01: No input file");
        return 0;
    }

    // выполнение главного кода
    try
    {
        processData(argv[1]);
    }
    catch (std::bad_exception &ex)
    {
        qWarning("ERROR 02: Format is not supported");
    }

    return 0;
}
