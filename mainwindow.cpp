#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextFormat>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this -> setCentralWidget(ui -> textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    currentFile.clear();
    ui -> textEdit -> setPlainText(QString());
}


void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,"open a file");
    QFile file(fileName);
    currentFile=fileName;
    if(!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this,"warning","cannot open file");
        return;
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text= in.readAll();
    ui -> textEdit -> setText(text);
    file.close();

}

void MainWindow::on_actionSave_As_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,"save as");
    QFile file(fileName);

    if(!file.open(QIODevice::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this,"warning","cannot save file");
        return;
    }
    currentFile=fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui -> textEdit -> toPlainText();
    out<<text;
    file.close();
}


void MainWindow::on_actionCut_triggered()
{
    ui -> textEdit -> cut();
}


void MainWindow::on_actionCopy_triggered()
{
    ui -> textEdit -> copy();
}


void MainWindow::on_actionPaste_triggered()
{
    ui -> textEdit -> paste();
}


void MainWindow::on_actionUndo_triggered()
{
    ui -> textEdit -> undo();
}


void MainWindow::on_actionRedo_triggered()
{
    ui -> textEdit -> redo();
}

void MainWindow::on_actionBold_2_triggered(bool checked)
{
    checked ? ui->textEdit->setFontWeight(QFont::Bold) :
              ui->textEdit->setFontWeight(QFont::Normal);
}



void MainWindow::on_actionSuperscript_triggered(bool checked)
{
    if(checked) {
        QTextCharFormat format;
        format.setVerticalAlignment(QTextCharFormat::AlignSuperScript);
        ui -> textEdit ->setCurrentCharFormat(format);
    }
    else {
        QTextCharFormat format;
        format.setVerticalAlignment(QTextCharFormat::AlignNormal);
        ui -> textEdit ->setCurrentCharFormat(format);
    }
}


void MainWindow::on_actionSubscript_triggered(bool checked)
{
    if(checked) {
        QTextCharFormat format;
        format.setVerticalAlignment(QTextCharFormat::AlignSubScript);
        ui -> textEdit ->setCurrentCharFormat(format);
    }
    else {
        QTextCharFormat format;
        format.setVerticalAlignment(QTextCharFormat::AlignNormal);
        ui -> textEdit ->setCurrentCharFormat(format);
    }
}


void MainWindow::on_actionAbout_Me_triggered()
{
    QString txt="Hi, My name is Lakshya and I'm currently in my final year of BTech. I've made this application in QTCreator and is learning to use QT to make applications";
    ui -> textEdit -> setText(txt);
}

