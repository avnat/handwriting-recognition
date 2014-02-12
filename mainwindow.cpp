#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    FileRoot = "C:\\Data\\Images\\En\\";

    ascii_counter = 65;
    ascii_counter1 = 97;
    ascii_counter2=48;

    desImg= QImage(FileRoot + "SavedImage");
    desImg = desImg.scaled(20,20);
    desImg.save(FileRoot + "SavedImage.bmp");

    GenerateImages();

    QPixmap genPix;

   for(int i = ascii_counter; i<91; i++)
    {
        sourceImg= QImage(FileRoot + "img_" +QString::number(i)+".bmp");
        resImg = QImage(20, 20, QImage::Format_ARGB32_Premultiplied);
        genPix = recalculateResult();
        genPix.save(FileRoot+"resImg\\"+QString::number(i)+".bmp");
    }
    for(int i = ascii_counter1; i<123;i++)
    {
        sourceImg= QImage(FileRoot + "img_" +QString::number(i)+".bmp");
        resImg = QImage(20, 20, QImage::Format_ARGB32_Premultiplied);
        genPix = recalculateResult();
        genPix.save(FileRoot+"resImg\\"+QString::number(i)+".bmp");
    }
    for(int i = ascii_counter2; i<58;i++)
    {
        sourceImg= QImage(FileRoot + "img_" +QString::number(i)+".bmp");
        resImg = QImage(20, 20, QImage::Format_ARGB32_Premultiplied);
        genPix = recalculateResult();
        genPix.save(FileRoot+"resImg\\"+QString::number(i)+".bmp");
    }


    QImage countImg;
    int lowest_white=20*20;
    int highest_black=0;
    int index;
    int index_b;

    for(int i = ascii_counter; i<91; i++)
    {
        countImg = QImage(FileRoot + "resImg\\" +QString::number(i)+".bmp");
        int white=0;
        int black=0;
        for (int j=0; j<countImg.width(); j++)
        {
            for (int k=0; k<countImg.height(); k++)
            {
                QRgb getRgb = countImg.pixel(j,k);
                if (qRed(getRgb)>=200 &&
                        qGreen(getRgb)>=200 &&
                        qBlue(getRgb)>=200)
                {
                    white++;
                }

                if (qRed(getRgb)<=20 &&
                       qGreen(getRgb)<=20 &&
                       qBlue(getRgb)<=20)
                {
                    black++;
                }

            }

        }
        if (white<=lowest_white)
        {
            lowest_white = white;
            index = i;
        }

        if (black>=highest_black)
        {
            highest_black = black;
            index_b = i;
        }
    }
    for(int i = ascii_counter1; i<123;i++)
    {
        countImg = QImage(FileRoot + "resImg\\" +QString::number(i)+".bmp");
        int white=0;
        int black=0;
        for (int j=0; j<countImg.width(); j++)
        {
            for (int k=0; k<countImg.height(); k++)
            {
                QRgb getRgb = countImg.pixel(j,k);
                int a = qRed(getRgb);
                if (qRed(getRgb)>=200 &&
                        qGreen(getRgb)>=200 &&
                        qBlue(getRgb)>=200)
                {
                    white++;
                }

                if (qRed(getRgb)<=20 &&
                       qGreen(getRgb)<=20 &&
                       qBlue(getRgb)<=20)
                {
                    black++;
                }

            }

        }
        if (white<=lowest_white)
        {
            lowest_white = white;
            index = i;
        }

        if (black>=highest_black)
        {
            highest_black = black;
            index_b = i;
        }
    }
    for(int i = ascii_counter2; i<58;i++)
    {
        countImg = QImage(FileRoot + "resImg\\" +QString::number(i)+".bmp");
        //qdebug()<<"FILE"<<QString::number(i);
        int white=0;
        int black=0;
        for (int j=0; j<countImg.width(); j++)
        {
            for (int k=0; k<countImg.height(); k++)
            {
                QRgb getRgb = countImg.pixel(j,k);
                //qdebug()<<"RED"<<qRed(getRgb)<<
//                          "GREEN"<<qGreen(getRgb)<<
//                          "BLUE"<<qBlue(getRgb);
                if (qRed(getRgb)>=200 &&
                        qGreen(getRgb)>=200 &&
                        qBlue(getRgb)>=200)
                {
                    white++;
                }

                if (qRed(getRgb)<=20 &&
                       qGreen(getRgb)<=20 &&
                       qBlue(getRgb)<=20)
                {
                    black++;
                }
            }

        }

        if (white<=lowest_white)
        {
            lowest_white = white;
            index = i;
        }

        if (black>=highest_black)
        {
            highest_black = black;
            index_b = i;
        }
    }

    qDebug()<<"WHITE"<<index<<QString(QChar(index))<<lowest_white;
    qDebug()<<"BLACK"<<index_b<<QString(QChar(index_b))<<highest_black;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::GenerateImages()
{
    QFont font("Mangal",12, QFont::Bold, false);

    for(int i = ascii_counter; i<91; i++)
    {
        QPixmap pix(20,20);
        pix.fill(Qt::white);
        QPainter p(&pix);
        p.setPen(QColor(0,0,0));
        p.setFont(font);
        p.drawText(QPoint(5,20), QString(QChar(i)));
        pix.toImage().convertToFormat(QImage::Format_Mono);
        pix.save(FileRoot+ "img_"+ QString::number(i) +".bmp");
    }

    for(int i = ascii_counter1; i<123;i++)
    {
        QPixmap pix(20,20);
        pix.fill(Qt::white);
        QPainter p(&pix);
        p.setPen(QColor(0,0,0));
        p.setFont(font);
        p.drawText(QPoint(3,18), QString(QChar(i)));
        pix.toImage().convertToFormat(QImage::Format_Mono);
        pix.save(FileRoot+ "img_"+ QString::number(i) +".bmp");
    }

    for(int i = ascii_counter2; i<58;i++)
    {
        QPixmap pix(20,20);
        pix.fill(Qt::white);
        QPainter p(&pix);
        p.setPen(QColor(0,0,0));
        p.setFont(font);
        p.drawText(QPoint(3,18), QString(QChar(i)));
        pix.toImage().convertToFormat(QImage::Format_Mono);
        pix.save(FileRoot+ "img_"+ QString::number(i) +".bmp");
    }

}


QPixmap MainWindow::recalculateResult()
{
    QPainter::CompositionMode mode = QPainter::CompositionMode_Screen;

    QPainter painter(&resImg);
    painter.setCompositionMode(QPainter::CompositionMode_Source);
    painter.fillRect(resImg.rect(), Qt::transparent);
    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter.drawImage(0, 0, desImg);
    painter.setCompositionMode(mode);
    painter.drawImage(0, 0, sourceImg);
    painter.setCompositionMode(QPainter::CompositionMode_DestinationOver);
    painter.fillRect(resImg.rect(), Qt::white);
    painter.end();

    return QPixmap::fromImage(resImg);
}
