#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <auto_files_bkup/src/Transfer.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_select_path_clicked();

    void on_pushButton_backup_path_clicked();

    void on_pushButton_start_backup_clicked();

    void on_lineEdit_delay_textChanged(const QString &arg1);

    void on_lineEdit_select_path_textChanged(const QString &arg1);

    void on_lineEdit_backup_path_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;

    QString select_path;
    QString backup_path;
    QString delay;

    bool first_backup = true;
    bool backing_up = false;
    bool backup_working = false;

    QString push_button_start_backup_text = "Start Backup";
    const QString start_backup_styles = "background-color: rgb(93, 31, 157); color: #fefefe;";
    const QString cancel_backup_styles = "background-color: rgb(217, 38, 49); color: #fefefe;";

    void start_backup(Transfer* transfer);

    void closeEvent(QCloseEvent* event);
};

#endif // MAINWINDOW_H
