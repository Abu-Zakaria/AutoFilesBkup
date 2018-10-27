#include <iostream>
#include "QFileDialog"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

#include <auto_files_bkup/src/Transfer.hpp>
#include <auto_files_bkup/src/helpers.hpp>

#include <thread>
#include <chrono>
#include <exception>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(520, 465);
    ui->pushButton_start_backup->setText(push_button_start_backup_text);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_select_path_clicked()
{
    QString home_dir = QString::fromStdString(getenv("HOME"));

    QString choose_directory_path = QFileDialog::getExistingDirectory(this, "Select a directory",
                                      home_dir, QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    ui->lineEdit_select_path->setText(choose_directory_path);

    select_path = choose_directory_path;
}

void MainWindow::on_pushButton_backup_path_clicked()
{
    QString home_dir = QString::fromStdString(getenv("HOME"));

    QString backup_directory_path = QFileDialog::getExistingDirectory(this, "Select a directory where to backup",
                                      home_dir, QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    ui->lineEdit_backup_path->setText(backup_directory_path);

    backup_path = backup_directory_path;
}

void MainWindow::on_pushButton_start_backup_clicked()
{
    if(!first_backup && backup_working)
    {
        if(backing_up)
        {
            QMessageBox::warning(this, "Warning!", "The files are being backed up right now. Please, wait for a while and try again!");
            return;
        }
        backup_working = false;
        ui->pushButton_start_backup->setText(this->push_button_start_backup_text);
        ui->pushButton_start_backup->setStyleSheet(this->start_backup_styles);
        ui->textBrowser_backup_status->setText("");
        return;
    }
    ui->textBrowser_backup_status->setText("Processing...");

    if(select_path.size() == 0 || backup_path.size() == 0 || delay.size() == 0)
    {
        ui->textBrowser_backup_status->setText("Select all of the input fields and try again!");
        return;
    }
    ui->textBrowser_backup_status->setText("Starting your backup...");

    std::string select_path_str = select_path.toUtf8().constData();

    std::string backup_path_str = backup_path.toUtf8().constData();

    std::string selected_folder_name = helpers::explode('/', select_path_str).back();

    backup_path_str += "/" + selected_folder_name;

    int delay_str = std::stoi(delay.toUtf8().constData());

    Transfer* transfer = new Transfer(select_path_str);
    transfer->setTargetDir(backup_path_str);
    transfer->setDelay(delay_str);


    std::cout << "moving from " << transfer->getCurrentDir() << std::endl;
    std::cout << "moving to " << transfer->getTargetDir() << std::endl;

    try
    {
        backup_working = true;

        ui->pushButton_start_backup->setStyleSheet(cancel_backup_styles);
        ui->pushButton_start_backup->setText("Cancel Backup");
        ui->textBrowser_backup_status->setText("Backing up your files...");

        std::thread start_backup_thread(&MainWindow::start_backup, this, transfer);
        start_backup_thread.detach();
    } catch (std::exception& e)
    {
        std::cout << "Error occured: " << e.what() << std::endl;
    }
    first_backup = false;
}

void MainWindow::start_backup(Transfer* transfer)
{
    while(backup_working)
    {
        backing_up = true;
        transfer->move();
        backing_up = false;
        std::this_thread::sleep_for(std::chrono::minutes(delay.toUInt()));
    }

    std::cout << "Canceling backup process" << std::endl;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(backing_up)
    {
        QMessageBox::critical(this, "Hold on!", "Some files are being backed up right now. If you close this application, some of your data might be lost. Please, wait for a while and try again!");
        event->ignore();
    }
}

void MainWindow::on_lineEdit_delay_textChanged(const QString &delay)
{
    this->delay = delay;
}

void MainWindow::on_lineEdit_select_path_textChanged(const QString &path)
{
    this->select_path = path;
}

void MainWindow::on_lineEdit_backup_path_textChanged(const QString &path)
{
    this->backup_path = path;
}
