#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    // Open a file dialog to get the file to open
    QString fileName = QFileDialog::getOpenFileName(this,
                                                     tr("開啟檔案"),
                                                     "",
                                                     tr("文字檔案 (*.txt);;所有檔案 (*)"));
    
    // If user cancelled the dialog, return
    if (fileName.isEmpty())
        return;
    
    // Create a file object
    QFile file(fileName);
    
    // Try to open the file for reading
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("無法開啟檔案"),
                             tr("無法開啟檔案進行讀取:\n%1").arg(file.errorString()));
        return;
    }
    
    // Create a text stream to read from the file
    QTextStream in(&file);
    
    // Read the entire file content
    QString content = in.readAll();
    
    // Set the content to the textEdit widget
    ui->textEdit->setPlainText(content);
    
    // File will be closed automatically
    QMessageBox::information(this, tr("開啟成功"),
                             tr("檔案已成功開啟:\n%1").arg(fileName));
}

void MainWindow::on_actionClose_triggered()
{
    // Clear the textEdit content
    ui->textEdit->clear();
    
    QMessageBox::information(this, tr("關閉檔案"),
                             tr("檔案已關閉"));
}

void MainWindow::on_actionASave_triggered()
{
    // Open a file dialog to get the save file path
    QString fileName = QFileDialog::getSaveFileName(this,
                                                     tr("另存新檔"),
                                                     "",
                                                     tr("文字檔案 (*.txt);;所有檔案 (*)"));
    
    // If user cancelled the dialog, return
    if (fileName.isEmpty())
        return;
    
    // Create a file object
    QFile file(fileName);
    
    // Try to open the file for writing
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, tr("無法儲存檔案"),
                             tr("無法開啟檔案進行寫入:\n%1").arg(file.errorString()));
        return;
    }
    
    // Create a text stream to write to the file
    QTextStream out(&file);
    
    // Get the text from the textEdit widget and write it to the file
    out << ui->textEdit->toPlainText();
    
    // Check for write errors
    if (out.status() != QTextStream::Ok) {
        QMessageBox::warning(this, tr("無法儲存檔案"),
                             tr("寫入檔案時發生錯誤"));
        return;
    }
    
    // Show a success message (file will be closed automatically)
    QMessageBox::information(this, tr("儲存成功"),
                             tr("檔案已成功儲存至:\n%1").arg(fileName));
}
