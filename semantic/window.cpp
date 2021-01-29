#include "window.hpp"
#include "ui_window.h"
#include <iostream>
#include <QTextStream>

Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
    setupEditor();
}

Window::~Window()
{
    delete ui;
}

void Window::setupEditor()
{
    QFont font;
    font.setFamily("Courier");
    font.setFixedPitch(true);
    font.setPointSize(10);

    ui->textEdit->setFont(font);

    highliter = new text_highlighter(ui->textEdit->document());

    QFile file("program.lulu");
    if (file.open(QFile::ReadOnly | QFile::Text))
        ui->textEdit->setPlainText(file.readAll());
}

void Window::on_pushButton_clicked()
{
    ui->textEdit_2->clear();
    ui->tableWidget_1->setRowCount(0);
    QString s = ui->textEdit->toPlainText();
    QStringList d = s.split(QRegExp("[\n]"),QString::SkipEmptyParts);

    QFile file("code.txt");
    file.open(QFile::Text | QFile::WriteOnly);
   if(file.isOpen())
   {
       QTextStream f (&file);
       for(int i = 0; i < d.size(); i++)
       {
           f << d[i] << endl;
       }
   }
   file.close();
   system("./untitled2 code.txt");
   system("rm -r code.txt");
   QFile files ("error.txt");
   files.open(QFile::Text | QFile::ReadOnly);
   if(!files.isOpen())
   {
       throw "file not open";
   }

   QTextStream fst(&files);
   while(!fst.atEnd())
   {
       QString sl = fst.readLine();
       if(sl == "syntax error occured")
       {
           ui->tableWidget_1->insertRow(ui->tableWidget_1->rowCount());
           ui->tableWidget_1->setItem(ui->tableWidget_1->rowCount()-1, 0, new QTableWidgetItem("syntax error occured"));
           break;
       }
       if(sl == "no error")
       {
           ui->tableWidget_1->insertRow(ui->tableWidget_1->rowCount());
           ui->tableWidget_1->setItem(ui->tableWidget_1->rowCount()-1, 0, new QTableWidgetItem("no error"));
           break;
       }

       else
       {
           ui->tableWidget_1->insertRow(ui->tableWidget_1->rowCount());
           ui->tableWidget_1->setItem(ui->tableWidget_1->rowCount() - 1, 0 , new QTableWidgetItem(sl));
       }
   }
   files.close();
//   system("rm -r error.txt");
   QFile fil("scopeTree.txt");
   fil.open(QFile::Text | QFile::ReadOnly);
   QTextStream fsts(&fil);
   ui->textEdit_2->setText(fst.readAll());
   fil.close();
//   system("rm -r scopeTree.txt");
}
