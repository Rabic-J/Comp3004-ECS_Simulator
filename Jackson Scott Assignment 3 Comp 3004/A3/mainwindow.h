#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ecs.h"
#include "floor.h"
#include "passenger.h"
#include "defs.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_comboBoxPassengers_activated(int index);

    void on_upButton_clicked();

    void on_downButton_clicked();

    void on_enterButton_clicked();

    void on_exitButton_clicked();

    void on_obstacleButton_clicked();

    void on_comboBoxFloors_activated(int index);

    void on_fireButton_clicked();

    void on_powerButton_clicked();

    void on_helpButton_clicked();

    void on_openButton_clicked();

    void on_closeButton_clicked();

private:
    Ui::MainWindow *ui;
    ECS ecs;
    Floor* floors[FLOOR_COUNT];
    Passenger* passengers[PASSENGER_COUNT];
    int currPassenger;
};
#endif // MAINWINDOW_H
