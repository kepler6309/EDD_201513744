#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "DoublyQueue.h"
#include "systemport.h"
#include <iostream>
#include "objects.h"

using namespace std;

Dqueue *Plns;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Plns = wen();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Print(Plns);
}

void MainWindow::on_pushButton_2_clicked()
{
    InsertPlane(Plns);
}

void MainWindow::on_pushButton_3_clicked()
{
    node *aux = (node*)malloc(sizeof(node));
    aux = Plns->last;
    while(aux!=NULL)
    {
        cout<<aux->data->type <<"\n";
        aux = aux->next;
    }
    //free(aux);
}
