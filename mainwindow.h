#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void GenerateImages();
    QPixmap recalculateResult();


private:
    Ui::MainWindow *ui;
    QImage sourceImg, desImg, resImg;
    QString FileRoot;
    int ascii_counter;
    int ascii_counter1;
    int ascii_counter2;

};

#endif // MAINWINDOW_H
