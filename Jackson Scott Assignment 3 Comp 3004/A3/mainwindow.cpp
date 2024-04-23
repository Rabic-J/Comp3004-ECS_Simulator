#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "elevator.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Sets up Passengers
    currPassenger=1;
    for(int i = 0; i < PASSENGER_COUNT; i++){
        passengers[i] = new Passenger(i+1);
        ui->comboBoxPassengers->addItem("Passenger "+QString::number(i+1));
    }
    //Sets up Floors
    for(int i = 0; i < FLOOR_COUNT; i++){
        floors[i] = new Floor(i+1);
        ui->comboBoxFloors->addItem("Floor "+QString::number(i+1));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBoxPassengers_activated(int index)
{
    currPassenger=index+1;
    std::cout<<"Now controlling Passenger "<<currPassenger<<std::endl;
}

void MainWindow::on_upButton_clicked()
{
    passengers[currPassenger-1]->callButton(floors[passengers[currPassenger-1]->getFloor()-1],UP,&ecs);
}

void MainWindow::on_downButton_clicked()
{
    passengers[currPassenger-1]->callButton(floors[passengers[currPassenger-1]->getFloor()-1],DOWN,&ecs);
}

void MainWindow::on_enterButton_clicked()
{
    passengers[currPassenger-1]->enterElevator(ecs.openElevator(passengers[currPassenger-1]->getFloor()));
}

void MainWindow::on_exitButton_clicked()
{
    passengers[currPassenger-1]->exitElevator(ecs.getElevator(passengers[currPassenger-1]->getElevator()));

}

void MainWindow::on_comboBoxFloors_activated(int index)
{
    passengers[currPassenger-1]->floorButton(ecs.getElevator(passengers[currPassenger-1]->getElevator()),index);
}

void MainWindow::on_openButton_clicked()
{
    passengers[currPassenger-1]->openButton(ecs.getElevator(passengers[currPassenger-1]->getElevator()));
}

void MainWindow::on_closeButton_clicked()
{
    passengers[currPassenger-1]->closeButton(ecs.getElevator(passengers[currPassenger-1]->getElevator()));
}

void MainWindow::on_fireButton_clicked()
{
    if(passengers[currPassenger-1]->getElevator()==0){
        ecs.fire();
    }else{
        passengers[currPassenger-1]->fireButton(ecs.getElevator(passengers[currPassenger-1]->getElevator()));
    }

}

void MainWindow::on_powerButton_clicked()
{
    ecs.powerOutage();
}

void MainWindow::on_helpButton_clicked()
{
    passengers[currPassenger-1]->helpButton(&ecs,ecs.getElevator(passengers[currPassenger-1]->getElevator()));
}

void MainWindow::on_obstacleButton_clicked()
{
    if(ecs.openElevator(passengers[currPassenger-1]->getFloor())!=nullptr){
        ecs.openElevator(passengers[currPassenger-1]->getFloor())->setObstacle();
    }else{
        cout<<"No open door to obstruct"<<endl;
    }
}










