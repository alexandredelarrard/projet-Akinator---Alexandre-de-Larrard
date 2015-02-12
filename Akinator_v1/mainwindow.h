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
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_button_Oui_clicked();
    void on_button_Non_clicked();
    void on_button_Rejouer_clicked();
    void on_button_valider_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
