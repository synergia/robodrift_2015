#include "racewindow.h"
#include "ui_racewindow.h"
#include "pugixml.hpp"
#include "sstream"
#include <QByteArray>


using namespace pugi;
using namespace std;

#include <QDebug>

racewindow::racewindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::racewindow)
{
    ui->setupUi(this);

    //inicjalizacja portu szeregowego
    this->MasterSerialPort_init();

    //laczenie sygnalow ze slotami
     connect(this->MasterSerialPort,SIGNAL(error(QSerialPort::SerialPortError)),this,SLOT(master_serial_dc()));
     connect(this->MasterSerialPort,SIGNAL(readyRead()),this,SLOT(master_serial_receive()));

    //ustalenie grafik w tle
      this->setStyleSheet(" background-color: white; border-image: url(background_1.png); background-attachment: scroll;");
    ui->labelTimeDiffrence->setStyleSheet(" background-color: white; border-image: url(background_dtime.png); background-attachment: scroll;");
   this->setStyleSheet(" background-color: white; border-image: url(background_1.png); background-attachment: scroll;");
     ui->labelCategory->setStyleSheet(" background-color: white; border-image: url(background_2.png); background-attachment: scroll;");
     ui->labelInfo->setStyleSheet(" background-color: white; border-image: url(background_info.png); background-attachment: scroll;");
    ui->frame->setStyleSheet(" background-color: white; border-image: url(logo.png); background-attachment: scroll;");
    ui->labelCarName->setStyleSheet(" background-color: white; border-image: url(background_car.png); background-attachment: scroll;");
    ui->labelTeamName->setStyleSheet(" background-color: white; border-image: url(background_team.png); background-attachment: scroll;");
    ui->labelTime->setStyleSheet(" background-color: white; border-image: url(background_time.png); background-attachment: scroll;");
    ui->sensorButton->setStyleSheet(" background-color: white;border-image: url(red.png); background-attachment: scroll;");
    ui->labelNextTeam->setStyleSheet("background-color: white; border-image: url(background_next.png); background-attachment: scroll;");

    //wektor zawierajacy odwolania do grafik do wyswietlenia, ida po kolei co wyscig
       this->current_Graph.push_back(" background-color: white; border-image: url(logo.png); background-attachment: scroll;");
      this->current_Graph.push_back("background-color: white; border-image: url(organizatorzy.png); background-attachment: scroll;");
      this->current_Graph.push_back("background-color: white; border-image: url(sponsorzy.png); background-attachment: scroll;");
      this->current_Graph.push_back("background-color: white; border-image: url(wspolpraca.png); background-attachment: scroll;");



    ui->labelCategory->setAlignment(Qt::AlignCenter);
     ui->labelTime->setAlignment(Qt::AlignCenter);
      ui->labelInfo->setAlignment(Qt::AlignCenter);
       ui->labelTimeDiffrence->setAlignment(Qt::AlignCenter);
        ui->labelTeamName->setAlignment(Qt::AlignCenter);
         ui->labelCarName->setAlignment(Qt::AlignCenter);
          ui->labelNextTeam->setAlignment(Qt::AlignCenter);

        //timer mierzacy czas
          connect(this->raceTimer, SIGNAL(timeout()), this, SLOT(raceTimeTick()));

          //mierzyl tak naprawde co 9ms
          raceTimer->start(9);




}

racewindow::~racewindow()
{
    MasterSerialPort->close();

    delete ui;
}


void racewindow::raceTimeTick()
{

  //NALEZY PAMIETAC ZE CZAS ROSNIE O 9MS NA TICK!!!

    if(!is_countdown)//jesli juz po obliczaniu
    {
    if(this->is_Mrace_started==true)//i wysig rozpoczety
    {
        this->mseconds+=9;//mierz czas
        ui->labelTime->setText(race_time_format(this->mseconds));//wyswietlaj go
    }
    }
    else //jesli wyscig jeszcze sie nie zaczal
    {
    this->is_falstarted=true; //jesli teraz przejedzie zawodnik to bedzie falstart
        countdown_mseconds++;

        if(countdown_mseconds==5) //wyslij masterowi info o tym ze zacznie sie wyscig
        {
            char send;
            send=(0b00110000+this->vector_of_Working_Sensors[this->lap_sensor_iteration]);
             MasterSerialPort->flush();
             MasterSerialPort->write(&send,1);
        }
        else if(countdown_mseconds==20) // 5.....
        {

            char send;
            send=(0b11000000+5);
            MasterSerialPort->flush();
             MasterSerialPort->write(&send,1);
              MasterSerialPort->flush();

            QSound::play(":/sounds/short_beep.wav");

           ui->labelInfo->setText( fonttemplate.arg( "black","5!"  ) );


        }
        else if(countdown_mseconds==100 ) //4.....
        {
            char send;
            send=(0b11000000+4);
             MasterSerialPort->flush();
             MasterSerialPort->write(&send,1);
               MasterSerialPort->flush();
            QSound::play(":/sounds/short_beep.wav");

           ui->labelInfo->setText("READY!");
             ui->labelInfo->setText( fonttemplate.arg( "darkBlue","4!"  ) );


              qDebug()<<this->vector_of_Working_Sensors[0]<<this->vector_of_Working_Sensors[1]<<this->vector_of_Working_Sensors[2]<<this->vector_of_Working_Sensors[3]<<this->vector_of_Working_Sensors[4]
                      <<this->vector_of_Working_Sensors[5]<<this->vector_of_Working_Sensors[6]<<this->vector_of_Working_Sensors[7]<<this->vector_of_Working_Sensors[8];

        }
        else if(countdown_mseconds==200 ) //3....
        {
            char send;
            send=(0b11000000+3);
             MasterSerialPort->flush();
             MasterSerialPort->write(&send,1);
               MasterSerialPort->flush();
            QSound::play(":/sounds/short_beep.wav");

             ui->labelInfo->setText( fonttemplate.arg( "blue","3!"  ) );

        }
        else if(countdown_mseconds==300 ) //2.....
        {
            char send;
            send=(0b11000000+2);
             MasterSerialPort->flush();
             MasterSerialPort->write(&send,1);
               MasterSerialPort->flush();

            QSound::play(":/sounds/short_beep.wav");

             ui->labelInfo->setText( fonttemplate.arg( "yellow","2!"  ) );

        }
        else if(countdown_mseconds==400 ) //1.....
        {

            char send;
            send=(0b11000000+1);
             MasterSerialPort->flush();
             MasterSerialPort->write(&send,1);
               MasterSerialPort->flush();
            QSound::play(":/sounds/short_beep.wav");

             ui->labelInfo->setText( fonttemplate.arg( "yellow","1!"  ) );

        }
        else if(countdown_mseconds==500) //START!!
        {
            QSound::play(":/sounds/long_beep.wav");
             ui->labelInfo->setText( fonttemplate.arg( "green","GO!"  ) );
            is_countdown=false; //odliczanie skonczone
        this->is_Mrace_started=true; //wyscig sie zaczal
        this->is_falstarted=false; // falstartu nie bedzie
        countdown_mseconds=0;
        mseconds=0;

        //przeliczana jest wartosci ile razy maja przyjsc POPRAWNE
        //dane z sensorow zanim wyscig sie skonczy,
        //(ma przejechac przez 4 czujke - oczekuje czworki na wejsciu)
        //zaleza od ilosci dzialajacych sensorow, liczby okrazen)
        this->sensor_tick_count=this->working_sensor_count*this->mLapsCount;
                this->sensor_tick_count_MAX=this->working_sensor_count*this->mLapsCount;

        }
    }

}

void racewindow::receiveRaceWindowData(const team &mTeam, const QString &nextTeam,const int &rSensorCount, const int &rLapsCount)
{
//dane przychodza przy wcisnieciu przycisku ready
    if(this->is_Mrace_started==false) //bez zastopowania/zakonczenia wyscigu nie mozna uzyc ready ponownie
    {

        if(this->is_pinging_began==false) //zacznij pingowanie, zmien grafike
        {
            this->vector_of_Working_Sensors.clear();
             ui->frame->setStyleSheet(this->current_Graph.at(this->current_graph_number));
             this->current_graph_number++;
             if(this->current_graph_number==this->current_Graph.size()) this->current_graph_number=0;

        //info do mastera o pingowaniu
        char send;
        send=(0b10000000);
        MasterSerialPort->flush();
         MasterSerialPort->write(&send,1);
           MasterSerialPort->flush();
           this->is_pinging_began=true;
        }


         ui->sensorButton->setStyleSheet(" background-color: white;border-image: url(red.png); background-attachment: scroll;");

    ui->frame_2->resize(this->size());

    //obecnie jadacy zespol i inne dane do wyswietlania
    this->currentTeam=mTeam;


    ui->labelCategory->setText(mTeam.Category_Name);
     ui->labelTime->setText(race_time_format(this->mseconds));

        ui->labelInfo->setText( fonttemplate.arg( "black","-"  ) );

        ui->labelTimeDiffrence->setText( fonttemplate.arg( "black",race_time_format(0)  ) );

        ui->labelTeamName->setText(mTeam.Team_Name);
         ui->labelCarName->setText(mTeam.Car_Name);
          ui->labelNextTeam->setText(nextTeam);

          //czyszczenie starych danych
          mseconds=0;
          this->mSensorCount=rSensorCount;
         this->mLapsCount=rLapsCount;

           this->working_sensor_count=0;
            is_ping_finished=false;

}





    }



QString racewindow::race_time_format(int mseconds)
{
    int minutes=(mseconds-mseconds%60000)/60000;
    int seconds=((mseconds-mseconds%1000)/1000)%60;
    int miliseconds=mseconds%1000;
      if(seconds==60) seconds=0;

    QString mMinutes;
    QString mSeconds;
    QString mMiliseconds;


    mMinutes=QString::number(minutes);

    if(seconds<10) mSeconds="0"+QString::number(seconds);
         else mSeconds=QString::number(seconds);

    if(miliseconds<10) mMiliseconds="00"+QString::number(miliseconds);
        else if (miliseconds<100) mMiliseconds="0"+QString::number(miliseconds);
            else mMiliseconds=QString::number(miliseconds);


    QString mString=(mMinutes+":"+mSeconds+":"
                     +mMiliseconds);
    return mString;
}

void racewindow::on_sensorButton_clicked()
{

}

void racewindow::race_has_began()
{
    if(!this->is_Mrace_started && is_ping_finished) //start dziala tylko jesli skonczono pingowanie
    {
    mseconds=0;
    this->is_countdown=true;

    ui->labelInfo->setText( fonttemplate.arg( "black","-" ) );

    }
}

void racewindow::race_safety()
{
    //przycisk awaryjny z mainwindow (gdyby czujnik nie zlapal
    //lub program mial zle ustalone dane
    //wykonuje DOKLADNIE to samo co fukncja do odbierania danych w trakcie trwania wyscigu

    if(this->is_Mrace_started==true)
    {
    if(ui->labelCategory->text()=="RC-STANDARD")
    {
        if(this->first_team_in_RC_ST==true)
        {

            this->best_meanTime_RC_ST.push_back(mseconds);
            this->current_meanTime_RC_ST.push_back(mseconds);
            int diffrence=0 ;
            ui->labelTimeDiffrence->setText(race_time_format(diffrence));
        }
        else
        {
            qDebug()<<this->lap_number*this->mSensorCount+this->vector_of_Working_Sensors[this->lap_sensor_iteration]-1;
           int diffrence=abs(mseconds-this->best_meanTime_RC_ST.at(this->lap_number*this->mSensorCount+this->vector_of_Working_Sensors[this->lap_sensor_iteration]-1));
            this->current_meanTime_RC_ST.replace(this->lap_number*this->mSensorCount+this->vector_of_Working_Sensors[this->lap_sensor_iteration]-1,mseconds);
        //    ui->labelTimeDiffrence->setText(race_time_format(diffrence));
                    if(mseconds-this->best_meanTime_RC_ST.at(this->lap_number*this->mSensorCount+this->vector_of_Working_Sensors[this->lap_sensor_iteration]-1)>0)
                        ui->labelTimeDiffrence->setText( fonttemplate.arg( "red",race_time_format(diffrence) ) );
                    if(mseconds-this->best_meanTime_RC_ST.at(this->lap_number*this->mSensorCount+this->vector_of_Working_Sensors[this->lap_sensor_iteration]-1)<=0)
                        ui->labelTimeDiffrence->setText( fonttemplate.arg( "green",race_time_format(diffrence) ) );
        }
    }
    if(ui->labelCategory->text()=="RC-ROBODRIFT")
    {
        if(this->first_team_in_RC==true)
        {

            this->best_meanTime_RC.push_back(mseconds);
            this->current_meanTime_RC.push_back(mseconds);
            int diffrence=0 ;
            ui->labelTimeDiffrence->setText(race_time_format(diffrence));
        }
        else
        {
            qDebug()<<this->lap_number*this->mSensorCount+this->vector_of_Working_Sensors[this->lap_sensor_iteration]-1;
           int diffrence=abs(mseconds-this->best_meanTime_RC.at(this->lap_number*this->mSensorCount+this->vector_of_Working_Sensors[this->lap_sensor_iteration]-1));
            this->current_meanTime_RC.replace(this->lap_number*this->vector_of_Working_Sensors[this->lap_sensor_iteration]-1,mseconds);
           // ui->labelTimeDiffrence->setText(race_time_format(diffrence));
                    if(mseconds-this->best_meanTime_RC.at(this->lap_number*this->mSensorCount+this->vector_of_Working_Sensors[this->lap_sensor_iteration]-1)>0)
                        ui->labelTimeDiffrence->setText( fonttemplate.arg( "red",race_time_format(diffrence)  ) );
                    if(mseconds-this->best_meanTime_RC.at(this->lap_number*this->mSensorCount+this->vector_of_Working_Sensors[this->lap_sensor_iteration]-1)<=0)
                        ui->labelTimeDiffrence->setText( fonttemplate.arg( "green",race_time_format(diffrence)  ) );
        }
    }
    if(ui->labelCategory->text()=="AUTONOM-ROBODRIFT")
    {
        if(this->first_team_in_AUTONOM==true)
        {

            this->best_meanTime_AUTONOM.push_back(mseconds);
            this->current_meanTime_AUTONOM.push_back(mseconds);
            int diffrence=0 ;
            ui->labelTimeDiffrence->setText(race_time_format(diffrence));
        }
        else
        {
            qDebug()<<this->lap_number*this->mSensorCount+this->vector_of_Working_Sensors[this->lap_sensor_iteration]-1;
           int diffrence=abs(mseconds-this->best_meanTime_AUTONOM.at(this->lap_number*this->mSensorCount+this->vector_of_Working_Sensors[this->lap_sensor_iteration]-1));
            this->current_meanTime_AUTONOM.replace(this->lap_number*this->mSensorCount+this->vector_of_Working_Sensors[this->lap_sensor_iteration]-1,mseconds);
           // ui->labelTimeDiffrence->setText(race_time_format(diffrence));
                    if(mseconds-this->best_meanTime_AUTONOM.at(this->lap_number*this->mSensorCount+this->vector_of_Working_Sensors[this->lap_sensor_iteration]-1)>0)
                        ui->labelTimeDiffrence->setText( fonttemplate.arg( "red",race_time_format(diffrence) ) );
                    if(mseconds-this->best_meanTime_AUTONOM.at(this->lap_number*this->mSensorCount+this->vector_of_Working_Sensors[this->lap_sensor_iteration]-1)<=0)
                        ui->labelTimeDiffrence->setText( fonttemplate.arg( "green",race_time_format(diffrence) ) );
        }
    }



     sensor_tick_count--;
     lap_sensor_iteration++;
     if(lap_sensor_iteration==working_sensor_count)
        {
    lap_number++;
    lap_sensor_iteration=0;
     }

   //  char send;
     //    send=(0b00110000+this->vector_of_Working_Sensors[this->lap_sensor_iteration]);
       //   MasterSerialPort->flush();
        //  MasterSerialPort->write(&send,1);
         //   MasterSerialPort->flush();




    if(this->sensor_tick_count==0)
    {

        this->is_Mrace_started=false;



      if(ui->labelCategory->text()=="RC-STANDARD" && mseconds<this->best_meanTime_RC_ST.last())
      {
        for(int i=0;i<this->best_meanTime_RC_ST.count();i++)
        {
           // if(this->best_meanTime_RC_ST.at(i)>this->current_meanTime_RC_ST.at(i))
                  this->best_meanTime_RC_ST.replace(i,this->current_meanTime_RC_ST.at(i));
        }
      }
      if(ui->labelCategory->text()=="RC-ROBODRIFT" && mseconds<this->best_meanTime_RC.last())
      {
        for(int i=0;i<this->best_meanTime_RC.count();i++)
        {
           // if(this->best_meanTime_RC.at(i)>this->current_meanTime_RC.at(i))
                  this->best_meanTime_RC.replace(i,this->current_meanTime_RC.at(i));
        }
      }
      if(ui->labelCategory->text()=="AUTONOM-ROBODRIFT" && mseconds<this->best_meanTime_AUTONOM.last())
      {
        for(int i=0;i<this->best_meanTime_AUTONOM.count();i++)
        {
           // if(this->best_meanTime_AUTONOM.at(i)>this->current_meanTime_AUTONOM.at(i))
                  this->best_meanTime_AUTONOM.replace(i,this->current_meanTime_AUTONOM.at(i));
        }
      }
       if(ui->labelCategory->text()=="RC-STANDARD") this->first_team_in_RC_ST=false;
       if(ui->labelCategory->text()=="RC-ROBODRIFT") this->first_team_in_RC=false;
      if(ui->labelCategory->text()=="AUTONOM-ROBODRIFT") this->first_team_in_AUTONOM=false;

         emit send_results_of_race(currentTeam,mseconds);

      char send;
        send=(0b00100000);
       MasterSerialPort->flush();
       MasterSerialPort->write(&send,1);
         MasterSerialPort->flush();

       lap_sensor_iteration=0;
       lap_number=0;
            this->vector_of_Working_Sensors.clear();
         is_pinging_began=false;
          this->is_falstarted=false;


    }
    }
}

void racewindow::race_has_been_stopped()
{
    //AWARYJNY STOP - czyszczenie danych

    mseconds=0;
    countdown_mseconds=0;
    ui->labelTime->setText(race_time_format(mseconds));
    ui->labelInfo->setText( fonttemplate.arg( "red","STOPPED"  ) );

    this->is_Mrace_started=false;
    is_countdown=false;
    is_ping_finished=false;
    is_pinging_began=false;
    this->is_falstarted=false;
    lap_sensor_iteration=0;
     this->vector_of_Working_Sensors.clear();
    lap_number=0;
    working_sensor_count=0;

    if(this->first_team_in_RC_ST)
    {
        this->best_meanTime_RC_ST.clear();
        this->current_meanTime_RC_ST.clear();
    }

    if(this->first_team_in_RC)
    {
        this->best_meanTime_RC.clear();
        this->current_meanTime_RC.clear();
    }
    if(this->first_team_in_AUTONOM)
    {
        this->best_meanTime_AUTONOM.clear();
        this->current_meanTime_AUTONOM.clear();
    }



    char send;
   send=(0b00100000);
     MasterSerialPort->flush();
    MasterSerialPort->write(&send,1);
      MasterSerialPort->flush();




    //this->sensor_tick_count=this->sensor_tick_count_MAX;


}

void racewindow::receive_final_position(const int &position)
{
    ui->labelInfo->setText("#"+QString::number(position));
}

 void racewindow::load_last_best_results()
 {

     xml_document doc;
         if(doc.load_file("teams_best_results.xml"))
         {

             xml_node RC_ST = doc.child("RC_ST");
             for(xml_node newCheckpoint=RC_ST.child("checkpoint")
                 ;newCheckpoint;newCheckpoint=newCheckpoint.next_sibling("checkpoint"))
             {

                 stringstream ss;
                 ss<<newCheckpoint.attribute("checkpoint").value();
                    int mCheckpoint=0;
                 ss>>mCheckpoint;
                  this->best_meanTime_RC_ST.push_back(mCheckpoint);
                  this->current_meanTime_RC_ST.push_back(mCheckpoint);


             }

             xml_node RC = doc.child("RC");
             for(xml_node newCheckpoint=RC.child("checkpoint")
                 ;newCheckpoint;newCheckpoint=newCheckpoint.next_sibling("checkpoint"))
             {

                 int mCheckpoint=0;

                 stringstream ss;
                 ss<<newCheckpoint.attribute("checkpoint").value();

                 ss>>mCheckpoint;
                  this->best_meanTime_RC.push_back(mCheckpoint);
                  this->current_meanTime_RC.push_back(mCheckpoint);

             }

             xml_node AUTONOM = doc.child("AUTONOM");
             for(xml_node newCheckpoint=AUTONOM.child("checkpoint")
                 ;newCheckpoint;newCheckpoint=newCheckpoint.next_sibling("checkpoint"))
             {

                 int mCheckpoint=0;

                 stringstream ss;
                 ss<<newCheckpoint.attribute("checkpoint").value();

                 ss>>mCheckpoint;
                  this->best_meanTime_AUTONOM.push_back(mCheckpoint);
                  this->current_meanTime_AUTONOM.push_back(mCheckpoint);

             }
            if(!this->best_meanTime_RC_ST.isEmpty()) this->first_team_in_RC_ST=false;
             if(!this->best_meanTime_RC.isEmpty())  this->first_team_in_RC=false;
                      if(!this->best_meanTime_AUTONOM.isEmpty()) this->first_team_in_AUTONOM=false;

 }
 }

 void racewindow::save_last_best_results()
 {
     xml_document doc;
             xml_node RC_ST = doc.append_child("RC_ST");
             RC_ST.append_attribute("Tytul")="RC_STANDARD";

             for(int i=0; i<this->best_meanTime_RC_ST.size();i++)
                     {
                         xml_node checkpoint = RC_ST.append_child("checkpoint");


                         checkpoint.append_attribute("checkpoint")=this->best_meanTime_RC_ST.at(i);
                     }

             xml_node RC = doc.append_child("RC");
             RC.append_attribute("Tytul")="RC_ROBODRIFT";

             for(int i=0; i<this->best_meanTime_RC.size();i++)
                     {
                         xml_node checkpoint = RC.append_child("checkpoint");


                         checkpoint.append_attribute("checkpoint")=this->best_meanTime_RC.at(i);
                     }

             xml_node AUTONOM = doc.append_child("AUTONOM");
             AUTONOM.append_attribute("Tytul")="AUTONOM_ROBODRIFT";

             for(int i=0; i<this->best_meanTime_AUTONOM.size();i++)
                     {
                         xml_node checkpoint = AUTONOM.append_child("checkpoint");


                         checkpoint.append_attribute("checkpoint")=this->best_meanTime_AUTONOM.at(i);
                     }

               doc.save_file("teams_best_results.xml");
 }

void racewindow::MasterSerialPort_init() //Qt pozwala na szybka konfiguracje portu
{
    this->MasterSerialPort->setPortName("com3");
     this->MasterSerialPort->setBaudRate(QSerialPort::Baud2400);
     this->MasterSerialPort->setDataBits(QSerialPort::Data8);
     this->MasterSerialPort->setParity(QSerialPort::NoParity);
     this->MasterSerialPort->setStopBits(QSerialPort::TwoStop);
    this->MasterSerialPort->setFlowControl(QSerialPort::NoFlowControl);
    this->MasterSerialPort->setReadBufferSize(1);

}

void racewindow::connect_with_master()
{
    //jesli z jakiegokolwiek powodu nie polaczylo sie z masterem to trzeba taka informacje wyslac
    //do mainwindow
    this->MasterSerialPort->open(QIODevice::ReadWrite);
    if(!this->MasterSerialPort->isOpen())
    {
        emit connect_with_master_return_Message(0);

    }
    else
    {
        emit connect_with_master_return_Message(1);

    }
}

void racewindow::master_serial_dc()
{
    //jesli z jakiegokolwiek powodu zerwalo komunikacje master-pc
    if(MasterSerialPort->isOpen())
     {
         MasterSerialPort->close();
    emit connect_with_master_return_Message(0);
     }
}


//obieranie danych z mastera
void racewindow::master_serial_receive()
{

    //JESLI SZUKAC GDZIES FAILA Z OSTATNIEGO ROKU TO TU - W PRZEKOMBINOWANYM SYSTEMIE KTORY
    //MIAL SOBIE RADZIC NAWET Z USZKODZENIEM CZUJNIKA
    //na testach nie bylo problemu , w trakcie zawodow , nie wiem - moze zaklocenia komunikacji
    //zwiazane z pojazdami RC

    //pobierz daną
    QByteArray mArray;
    int data;
      mArray=this->MasterSerialPort->readAll();
    data=mArray.at(0);


    if(!this->is_Mrace_started) //ready , jeszcze nie zaczal sie wyscig
    {
        //zaczyna sie pingowanie
        //kazda czujka wysyla swoj sygnal gotowosci (1,2,3,4,5)
        //jesli ktoras by nie dzialala program przeliczy co powinno byc nastepne itp.
        //dopoki nie przyjdzie 255, zbiera sie info z czujek
        if(this->is_falstarted==false) //jesli nie ma falstartu
        {
       if((unsigned char)data!=255) //pingowanie
       {
           this->working_sensor_count++;
           this->vector_of_Working_Sensors.push_back(data); //kolejnosc danych jakie maja przyjsc
           //na bazie tego ktore czujniki dzialaja
       }
       if((unsigned char)data==255) //koniec pingowania
       {
           ui->sensorButton->setStyleSheet(" background-color: white;border-image: url(green.png); background-attachment: scroll;");
          if(!this->isHidden()) is_ping_finished=true;
       }
        }
        //PO PINGOWANIU , PRZED SKONCZENIEM ODLICZANIA
        else if(this->is_falstarted==true)//jesli teraz przyjdzie info z czujek to byl falstart
        {
            this->is_Mrace_started=false;
            is_countdown=false;

            char send;
            send=(0b01000000+15);
            MasterSerialPort->flush();
             MasterSerialPort->write(&send,1);
               MasterSerialPort->flush();

            countdown_mseconds=0;
             ui->labelInfo->setText( fonttemplate.arg( "red","FALSTART"  ) );

             QSound::play(":/sounds/glass.WAV");
            ui->labelTime->setText(race_time_format(mseconds));

        }

    }
    else if(this->is_Mrace_started) //po skonczeniu odliczania
    {

        //jesli dane odebrane pokrywaja sie z oczekiwanymi to zapisz czas w odpowiedniej kategorii
        if(this->is_Mrace_started==true  && data==this->vector_of_Working_Sensors[this->lap_sensor_iteration])
        {
        if(ui->labelCategory->text()=="RC-STANDARD")
        {
            //jesli to pierwszy przejazd w kategorii to po prosu zapisz
            if(this->first_team_in_RC_ST==true)
            {

                this->best_meanTime_RC_ST.push_back(mseconds);
                this->current_meanTime_RC_ST.push_back(mseconds);
                int diffrence=0 ;
                ui->labelTimeDiffrence->setText(race_time_format(diffrence));
            }
            else //jesli to kolejny zawodnik
            {
                //sprawdz roznice
               int diffrence=abs(mseconds-this->best_meanTime_RC_ST.at(this->lap_number*this->mSensorCount+this->vector_of_Working_Sensors[this->lap_sensor_iteration]-1));
                this->current_meanTime_RC_ST.replace(this->lap_number*this->mSensorCount+this->vector_of_Working_Sensors[this->lap_sensor_iteration]-1,mseconds);
                //ui->labelTimeDiffrence->setText(race_time_format(diffrence));

                        //lepszy od najlepszego to na zielono i wyswietl
                        if(mseconds-this->best_meanTime_RC_ST.at(this->lap_number*this->mSensorCount+this->vector_of_Working_Sensors[this->lap_sensor_iteration]-1)>0)
                            ui->labelTimeDiffrence->setText( fonttemplate.arg( "red",race_time_format(diffrence) ) );
                        //gorszy od najlepszego to na czerwono i wyswietl
                        if(mseconds-this->best_meanTime_RC_ST.at(this->lap_number*this->mSensorCount+this->vector_of_Working_Sensors[this->lap_sensor_iteration]-1)<=0)
                            ui->labelTimeDiffrence->setText( fonttemplate.arg( "green",race_time_format(diffrence) ) );
            }
        }
        if(ui->labelCategory->text()=="RC-ROBODRIFT") //analogicznie jak dla powyzszej kategorii
        {
            if(this->first_team_in_RC==true)
            {

                this->best_meanTime_RC.push_back(mseconds);
                this->current_meanTime_RC.push_back(mseconds);
                int diffrence=0 ;
                ui->labelTimeDiffrence->setText(race_time_format(diffrence));
            }
            else
            {

               int diffrence=abs(mseconds-this->best_meanTime_RC.at(this->lap_number*this->mSensorCount+this->vector_of_Working_Sensors[this->lap_sensor_iteration]-1));
                this->current_meanTime_RC.replace(this->lap_number*this->vector_of_Working_Sensors[this->lap_sensor_iteration]-1,mseconds);
               // ui->labelTimeDiffrence->setText(race_time_format(diffrence));
                        if(mseconds-this->best_meanTime_RC.at(this->lap_number*this->mSensorCount+this->vector_of_Working_Sensors[this->lap_sensor_iteration]-1)>0)
                            ui->labelTimeDiffrence->setText( fonttemplate.arg( "red",race_time_format(diffrence)  ) );
                        if(mseconds-this->best_meanTime_RC.at(this->lap_number*this->mSensorCount+this->vector_of_Working_Sensors[this->lap_sensor_iteration]-1)<=0)
                            ui->labelTimeDiffrence->setText( fonttemplate.arg( "green",race_time_format(diffrence)  ) );
            }
        }
        if(ui->labelCategory->text()=="AUTONOM-ROBODRIFT")
        {
            if(this->first_team_in_AUTONOM==true)
            {

                this->best_meanTime_AUTONOM.push_back(mseconds);
                this->current_meanTime_AUTONOM.push_back(mseconds);
                int diffrence=0 ;
                ui->labelTimeDiffrence->setText(race_time_format(diffrence));
            }
            else
            {

               int diffrence=abs(mseconds-this->best_meanTime_AUTONOM.at(this->lap_number*this->mSensorCount+this->vector_of_Working_Sensors[this->lap_sensor_iteration]-1));
                this->current_meanTime_AUTONOM.replace(this->lap_number*this->mSensorCount+this->vector_of_Working_Sensors[this->lap_sensor_iteration]-1,mseconds);
                //ui->labelTimeDiffrence->setText(race_time_format(diffrence));
                        if(mseconds-this->best_meanTime_AUTONOM.at(this->lap_number*this->mSensorCount+this->vector_of_Working_Sensors[this->lap_sensor_iteration]-1)>0)
                            ui->labelTimeDiffrence->setText( fonttemplate.arg( "red",race_time_format(diffrence) ) );
                        if(mseconds-this->best_meanTime_AUTONOM.at(this->lap_number*this->mSensorCount+this->vector_of_Working_Sensors[this->lap_sensor_iteration]-1)<=0)
                            ui->labelTimeDiffrence->setText( fonttemplate.arg( "green",race_time_format(diffrence) ) );
            }
        }


        //co kazda dana w czasie wyscigu
         sensor_tick_count--; //ilosc pozostalych tickow w dol
         lap_sensor_iteration++; //ilosc tickow w okrazeniu w gore
         if(lap_sensor_iteration==working_sensor_count) //cale okrazenie
            {
        lap_number++;
        lap_sensor_iteration=0;
         }

       //  char send;
         //    send=(0b00110000+this->vector_of_Working_Sensors[this->lap_sensor_iteration]);
          //    MasterSerialPort->flush();
           //   MasterSerialPort->write(&send,1);
             //   MasterSerialPort->flush();




        if(this->sensor_tick_count==0) //KONIEC WYSCIGU
        {

            this->is_Mrace_started=false; //koniec wyscigu


          //dla kazdej kategorii osobno
          //jesli czas byl najlepszy(koncowy czas) to zapisz miedzyczasy zawodnika jako najlepsze
          if(ui->labelCategory->text()=="RC-STANDARD" && mseconds<this->best_meanTime_RC_ST.last())
          {
            for(int i=0;i<this->best_meanTime_RC_ST.count();i++)
            {
               // if(this->best_meanTime_RC_ST.at(i)>this->current_meanTime_RC_ST.at(i))
                      this->best_meanTime_RC_ST.replace(i,this->current_meanTime_RC_ST.at(i));
            }
          }
          if(ui->labelCategory->text()=="RC-ROBODRIFT" && mseconds<this->best_meanTime_RC.last())
          {
            for(int i=0;i<this->best_meanTime_RC.count();i++)
            {
               // if(this->best_meanTime_RC.at(i)>this->current_meanTime_RC.at(i))
                      this->best_meanTime_RC.replace(i,this->current_meanTime_RC.at(i));
            }
          }
          if(ui->labelCategory->text()=="AUTONOM-ROBODRIFT" && mseconds<this->best_meanTime_AUTONOM.last())
          {
            for(int i=0;i<this->best_meanTime_AUTONOM.count();i++)
            {
               // if(this->best_meanTime_AUTONOM.at(i)>this->current_meanTime_AUTONOM.at(i))
                      this->best_meanTime_AUTONOM.replace(i,this->current_meanTime_AUTONOM.at(i));
            }
          }
           if(ui->labelCategory->text()=="RC-STANDARD") this->first_team_in_RC_ST=false;
           if(ui->labelCategory->text()=="RC-ROBODRIFT") this->first_team_in_RC=false;
          if(ui->labelCategory->text()=="AUTONOM-ROBODRIFT") this->first_team_in_AUTONOM=false;

             emit send_results_of_race(currentTeam,mseconds); //WYSLIJ REZULATAT DO GLOWNEGO OKNA

          //wyslij masterowi info o skonczonym wyscigu
          char send;
            send=(0b00100000);
           MasterSerialPort->flush();
           MasterSerialPort->write(&send,1);
             MasterSerialPort->flush();

           lap_sensor_iteration=0;
           lap_number=0;
                this->vector_of_Working_Sensors.clear();
             is_pinging_began=false;
              this->is_falstarted=false;
        }
        }
        }



}


