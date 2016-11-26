#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Value->hide();
    ui->Value->display(0);
    ui->R_value->setText("255");
    ui->G_value->setText("255");
    ui->B_value->setText("255");
    ui->R_slider->setRange(0,255);
    ui->G_slider->setRange(0,255);
    ui->B_slider->setRange(0,255);
    ui->R_slider->setValue(255);
    ui->G_slider->setValue(255);
    ui->B_slider->setValue(255);
    ui->Dioda->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_On_Off_Button_clicked()
{
    if (ui->Value->value()==0)
    {
        ui->Value->display(1);
        ui->Dioda->show();
        ui->Dioda->setStyleSheet("background-color: rgb("
                                        + ui->R_value->text() + ","
                                        + ui->G_value->text() + ","
                                        + ui->B_value->text() + ");");
        ui->Dioda->update();
    }
    else {
        ui->Value->display(0);
        ui->Dioda->hide();
    };
}

void MainWindow::on_R_slider_sliderMoved(int position)
{
    QString str;
    ui->R_value->setText(str.setNum(position));
    ui->Dioda->setStyleSheet("background-color: rgb("
                                     + ui->R_value->text() + ","
                                     + ui->G_value->text() + ","
                                     + ui->B_value->text() + ");");
    ui->Dioda->update();
}

void MainWindow::on_G_slider_sliderMoved(int position)
{
    QString str;
    ui->G_value->setText(str.setNum(position));
    ui->Dioda->setStyleSheet("background-color: rgb("
                                    + ui->R_value->text() + ","
                                    + ui->G_value->text() + ","
                                    + ui->B_value->text() + ");");
    ui->Dioda->update();

}

void MainWindow::on_B_slider_sliderMoved(int position)
{
    QString str;
    ui->B_value->setText(str.setNum(position));
    ui->Dioda->setStyleSheet("background-color: rgb("
                                    + ui->R_value->text() + ","
                                    + ui->G_value->text() + ","
                                    + ui->B_value->text() + ");");
    ui->Dioda->update();
}
