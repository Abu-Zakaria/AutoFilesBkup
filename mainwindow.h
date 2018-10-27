#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
};

#endif // MAINWINDOW_H
