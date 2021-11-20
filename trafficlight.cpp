#include "trafficlight.h"
#include <QWidget>
#include <QLayout>
#include <QRadioButton>
#include <QApplication>

TrafficLight::TrafficLight(QWidget * parent): QWidget(parent){

    //Creatign the widgets
    createWidgets();

    //place Widgets
    placeWidgets();
    //ajouter les feus

    lights.append(redlight);
    lights.append(yellowlight);
    lights.append(greenlight);
    index=0;


    //Demarer le Timer
    startTimer(1000);
    //temps actuel
    currentTime=0;
}

void TrafficLight::createWidgets()
{

  redlight = new QRadioButton;
  redlight->setEnabled(false);
  redlight->toggle();
  redlight->setStyleSheet("QRadioButton::indicator:checked { background-color: red;}");

  yellowlight = new QRadioButton;
  yellowlight->setEnabled(false);
  yellowlight->setStyleSheet("QRadioButton::indicator:checked { background-color: yellow;}");

  greenlight = new QRadioButton;
  greenlight->setEnabled(false);
  greenlight->setStyleSheet("QRadioButton::indicator:checked { background-color: green;}");
}


void TrafficLight::placeWidgets()
{

  // Placing the widgets
  auto layout = new QVBoxLayout;
  layout->addWidget(redlight);
  layout->addWidget(yellowlight);
  layout->addWidget(greenlight);
  setLayout(layout);
}
void TrafficLight::timerEvent(QTimerEvent *e){


        /* index = ( index + 1)% 3;
        lights[index]->toggle();


        //si le Red est activé == Activer le Yellow

        if(redlight->isChecked())
            yellowlight->toggle();



        //si le Yellow est activé == Activer le green

        else if(yellowlight->isChecked())
            greenlight->toggle();

        //si le Green est activé == Activer le Red
        else if(greenlight->isChecked())
          redlight->toggle();*/
}


/*void TrafficLight::timerEvent(QTimerEvent *e){


        currentTime++;
        if(redlight->isChecked()&&currentTime ==4){
            yellowlight->toggle();
            currentTime =0;}
  // Vérifier si je dois passer du jaunne au vert
        else if(yellowlight->isChecked()&& currentTime == 1){
            greenlight->toggle();
            currentTime=0;}
  // Vérifier si je dois passer du vert au rouge
        else if(greenlight->isChecked()&& currentTime == 2){
           redlight->toggle();
           currentTime=0;}

}*/
void TrafficLight:: keyPressEvent(QKeyEvent *e){
   if (e->key() == Qt::Key_Escape)
        qApp->exit();
    if (e->key() == Qt::Key_R)
    {
        index=0;
        lights[index]->toggle();
       // yellowlight->toggle();
    }

    if (e->key() == Qt::Key_Y)
    {
        index=1;
        lights[index]->toggle();

    }

    if (e->key() == Qt::Key_G)
    {
        index=2;
        lights[index]->toggle();

    }
    }


