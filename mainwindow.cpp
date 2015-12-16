#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QWindow>
#include <QTime>
#include "sstream"

#include "pugiconfig.hpp"
#include "pugixml.hpp"

using namespace pugi;
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
       setWindowTitle("RoboDrift 2015");




       QObject::connect(mRaceWindow, SIGNAL(send_results_of_race(const team&,const int&)),
                       this, SLOT(receive_results_of_race(const team&,const int&)));

       QObject::connect(mRaceWindow, SIGNAL(connect_with_master_return_Message(const int&)),
                       this, SLOT(receive_serialport_status(const int&)));


       QObject::connect(this,SIGNAL(begin_race()),
                       mRaceWindow, SLOT(race_has_began()));

       QObject::connect(ui->stopButton,SIGNAL(pressed()),
                       mRaceWindow, SLOT(race_has_been_stopped()));

       QObject::connect(ui->pushButton,SIGNAL(pressed()),
                       mRaceWindow, SLOT(race_safety()));

       QObject::connect(ui->save_session_Button,SIGNAL(clicked()),
                       mRaceWindow,SLOT(save_last_best_results()));

       QObject::connect(ui->load_session_Button,SIGNAL(clicked()),
                       mRaceWindow,SLOT(load_last_best_results()));


       QObject::connect(ui->ConnectWithMasterButton,SIGNAL(clicked()),
                       mRaceWindow,SLOT(connect_with_master()));

       QObject::connect(this,SIGNAL(send_comment_for_Public(const QString&)),
                       mResultsWindow,SLOT(receive_comment_for_Public(const QString&)));










       QObject::connect(this,SIGNAL(send_final_position(const int&)),
                       mRaceWindow, SLOT(receive_final_position(const int&)));


       for(int c = 0; c < ui->RC_STrankingTable->horizontalHeader()->count(); c++) //rozciaganie kazdej kolumny
       {
           ui->RC_STrankingTable->horizontalHeader()->setSectionResizeMode(
               c, QHeaderView::Stretch);
       }
       ui->RC_STrankingTable->setStyleSheet("QHeaderView::section { background-color:red }");

       for(int c = 0; c < ui->RCrankingTable->horizontalHeader()->count(); c++) //rozciaganie kazdej kolumny
       {
           ui->RCrankingTable->horizontalHeader()->setSectionResizeMode(
               c, QHeaderView::Stretch);
       }
        ui->RCrankingTable->setStyleSheet("QHeaderView::section { background-color:blue }");

        for(int c = 0; c < ui->AUTONOMrankingTable->horizontalHeader()->count(); c++) //rozciaganie kazdej kolumny
        {
            ui->AUTONOMrankingTable->horizontalHeader()->setSectionResizeMode(
                c, QHeaderView::Stretch);
        }
        ui->AUTONOMrankingTable->setStyleSheet("QHeaderView::section { background-color:green}");




}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_nextButton_clicked()
{
if(is_race_started==false)
{
    if(ui->nextteamList->count()!=0 && ui->laterteamList->count()!=0)
    {
    QListWidgetItem *newnextItem = new QListWidgetItem;
    QListWidgetItem *newlaterItem = new QListWidgetItem;

    newnextItem->setText(ui->laterteamList->item(0)->text());
    newlaterItem->setText(ui->nextteamList->item(0)->text());

    set_list_item_color(newnextItem);
    set_list_item_color(newlaterItem);


    set_item_untouchable(newnextItem);

    ui->laterteamList->addItem(newlaterItem);
    ui->nextteamList->addItem(newnextItem);

    delete ui->laterteamList->item(0);
   delete ui->nextteamList->item(0);
    emit send_results_for_Public(ui->nextteamList,ui->RC_STrankingTable,ui->RCrankingTable,ui->AUTONOMrankingTable);

    }
   else if(ui->nextteamList->count()!=0 && ui->laterteamList->count()==0)
    {
    QListWidgetItem *newnextItem = new QListWidgetItem;


    newnextItem->setText(ui->nextteamList->item(0)->text());
    set_list_item_color(newnextItem);


    set_item_untouchable(newnextItem);


    ui->nextteamList->addItem(newnextItem);
   delete ui->nextteamList->item(0);

     emit send_results_for_Public(ui->nextteamList,ui->RC_STrankingTable,ui->RCrankingTable,ui->AUTONOMrankingTable);
    }
}
}

void MainWindow::set_item_untouchable(QListWidgetItem *mItem)
{
    mItem->setFlags(Qt::ItemIsSelectable);

}

void MainWindow::on_walkoverButton_clicked()
{
 if(is_race_started==false)
 {
    if(ui->nextteamList->count()!=0)
    {
        QMessageBox::StandardButton reply;
        reply=QMessageBox::question(this,"WALKOVER","Do you really want to remove team: "+ui->nextteamList->item(0)->text()+" from the list?",
                               QMessageBox::Yes|QMessageBox::No);
        if(reply==QMessageBox::Yes)
          {
        delete_team_from_waiting_list();
         emit send_results_for_Public(ui->nextteamList,ui->RC_STrankingTable,ui->RCrankingTable,ui->AUTONOMrankingTable);
    }

}
 }
}

void MainWindow::on_addteamButton_clicked()
{

  mDialog= new addteam(this);
  QObject::connect(mDialog, SIGNAL(sendteamdata(const QString&, const QString&,const QString&)),
                  this, SLOT(receiveteamdata(const QString&,const QString&,const QString&)));
   mDialog->show();
}


void MainWindow::receiveteamdata(const QString &team_name,const QString &car_name,const QString &category)
{
  if(category=="RC-ST")
  {
      team *mTeam=new team;
      mTeam->Car_Name=car_name;
      mTeam->Team_Name=team_name;
      mTeam->Category_Name="RC-STANDARD";
      mTeam->Best_Race_Time=3600000;
      this->RC_ST.Teams.push_back(mTeam);

      ui->RC_STrankingTable->insertRow(ui->RC_STrankingTable->rowCount());
     QTableWidgetItem *itm=new QTableWidgetItem;
      itm->setFlags(itm->flags() ^ Qt::ItemIsEditable);
     ui->RC_STrankingTable->setItem(ui->RC_STrankingTable->rowCount()-1,0,itm);
    ui->RC_STrankingTable->item(ui->RC_STrankingTable->rowCount()-1,0)->setText(team_name);


     QTableWidgetItem *itm2=new QTableWidgetItem;
      // itm2->setFlags(itm2->flags() ^ Qt::ItemIsEditable);
     int a=3600000;
    itm2->setData(Qt::DisplayRole,a);

   ui->RC_STrankingTable->setItem(ui->RC_STrankingTable->rowCount()-1,1,itm2);

   ui->RC_STrankingTable->item(ui->RC_STrankingTable->rowCount()-1,0)->setTextAlignment(Qt::AlignCenter);
   ui->RC_STrankingTable->item(ui->RC_STrankingTable->rowCount()-1,1)->setTextAlignment(Qt::AlignCenter);



  }
  if(category=="RC")
  {
      team *mTeam=new team;
      mTeam->Car_Name=car_name;
      mTeam->Team_Name=team_name;
      mTeam->Category_Name="RC-ROBODRIFT";
      mTeam->Best_Race_Time=3600000;
      this->RC.Teams.push_back(mTeam);

      ui->RCrankingTable->insertRow(ui->RCrankingTable->rowCount());
     QTableWidgetItem *itm=new QTableWidgetItem;
     itm->setFlags(itm->flags() ^ Qt::ItemIsEditable);
     ui->RCrankingTable->setItem(ui->RCrankingTable->rowCount()-1,0,itm);
    ui->RCrankingTable->item(ui->RCrankingTable->rowCount()-1,0)->setText(team_name);
     QTableWidgetItem *itm2=new QTableWidgetItem;
     //itm2->setFlags(itm2->flags() ^ Qt::ItemIsEditable);
     int a=3600000;
    itm2->setData(Qt::DisplayRole,a);

   ui->RCrankingTable->setItem(ui->RCrankingTable->rowCount()-1,1,itm2);

   ui->RCrankingTable->item(ui->RCrankingTable->rowCount()-1,0)->setTextAlignment(Qt::AlignCenter);
   ui->RCrankingTable->item(ui->RCrankingTable->rowCount()-1,1)->setTextAlignment(Qt::AlignCenter);

  }
  if(category=="AUTONOM")
  {
      team *mTeam=new team;
      mTeam->Car_Name=car_name;
      mTeam->Team_Name=team_name;
      mTeam->Category_Name="AUTONOM-ROBODRIFT";
      mTeam->Best_Race_Time=3600000;
      this->AUTONOM.Teams.push_back(mTeam);
      ui->AUTONOMrankingTable->insertRow(ui->AUTONOMrankingTable->rowCount());
           QTableWidgetItem *itm=new QTableWidgetItem;
           itm->setFlags(itm->flags() ^ Qt::ItemIsEditable);
           ui->AUTONOMrankingTable->setItem(ui->AUTONOMrankingTable->rowCount()-1,0,itm);
          ui->AUTONOMrankingTable->item(ui->AUTONOMrankingTable->rowCount()-1,0)->setText(team_name);
           QTableWidgetItem *itm2=new QTableWidgetItem;
           //  itm2->setFlags(itm2->flags() ^ Qt::ItemIsEditable);
           int a=3600000;
          itm2->setData(Qt::DisplayRole,a);

         ui->AUTONOMrankingTable->setItem(ui->AUTONOMrankingTable->rowCount()-1,1,itm2);

         ui->AUTONOMrankingTable->item(ui->AUTONOMrankingTable->rowCount()-1,0)->setTextAlignment(Qt::AlignCenter);
         ui->AUTONOMrankingTable->item(ui->AUTONOMrankingTable->rowCount()-1,1)->setTextAlignment(Qt::AlignCenter);
  }
   ui->save_session_Button->setStyleSheet("* { background-color: rgb(255,100,100) }");


}

void MainWindow::on_addroundButton_clicked()
{

    if(ui->rcstCheck->isChecked())
    {
        for(int i=0;i<this->RC_ST.Teams.size();i++)
        {
            QListWidgetItem *mItem= new QListWidgetItem;

            mItem->setText(this->RC_ST.Teams.at(i)->Team_Name+"_rcst");
            set_list_item_color(mItem);


            if(ui->nextteamList->count()<3)
            {
               set_item_untouchable(mItem);

                ui->nextteamList->addItem(mItem);
            }
            else
            {
                 ui->laterteamList->addItem(mItem);
            }
             ui->save_session_Button->setStyleSheet("* { background-color: rgb(255,100,100) }");
        }
    }
    if(ui->rcCheck->isChecked())
    {
        for(int i=0;i<this->RC.Teams.size();i++)
        {
            QListWidgetItem *mItem= new QListWidgetItem;
            mItem->setText(this->RC.Teams.at(i)->Team_Name+"_rcrd"); // koncowka dla operatora w celu rozrozniania kategorii
            set_list_item_color(mItem);


            if(ui->nextteamList->count()<3)
            {
               set_item_untouchable(mItem);

                ui->nextteamList->addItem(mItem);
            }
            else
            {
                 ui->laterteamList->addItem(mItem);
            }
             ui->save_session_Button->setStyleSheet("* { background-color: rgb(255,100,100) }");
        }
    }
    if(ui->autoCheck->isChecked())
    {
        for(int i=0;i<this->AUTONOM.Teams.size();i++)
        {
            QListWidgetItem *mItem= new QListWidgetItem;
            mItem->setText(this->AUTONOM.Teams.at(i)->Team_Name+"_aurd");
            set_list_item_color(mItem);


            if(ui->nextteamList->count()<3)
            {
               set_item_untouchable(mItem);

                ui->nextteamList->addItem(mItem);
            }
            else
            {
                 ui->laterteamList->addItem(mItem);
            }
             ui->save_session_Button->setStyleSheet("* { background-color: rgb(255,100,100) }");
        }
    }
}

void MainWindow::delete_team_from_waiting_list()
{
    if(ui->laterteamList->count()!=0)
    {
    QListWidgetItem *newnextItem = new QListWidgetItem;
    newnextItem->setText(ui->laterteamList->item(0)->text());
    set_item_untouchable(newnextItem);
    set_list_item_color(newnextItem);

    ui->nextteamList->addItem(newnextItem);
    delete ui->laterteamList->item(0);
    }
    delete ui->nextteamList->item(0);
     ui->save_session_Button->setStyleSheet("* { background-color: rgb(255,100,100) }");

}

void MainWindow::on_readyButton_pressed()
{

    ui->RC_STrankingTable->clearSelection();
     ui->RCrankingTable->clearSelection();
      ui->AUTONOMrankingTable->clearSelection();

    if(ui->nextteamList->count()!=0)
    {

    QObject::connect(this, SIGNAL(sendRaceWindowData(const team&,const QString&,const int &,const int &)),
                    mRaceWindow, SLOT(receiveRaceWindowData(const team &, const QString &, const int&, const int&)));
mResultsWindow->hide();
    mRaceWindow->showFullScreen();





            if(ui->nextteamList->count()>1)
             {
               emit this->sendRaceWindowData(get_team(ui->nextteamList->item(0)->text()),get_team(ui->nextteamList->item(1)->text()).Team_Name,
                                             ui->number_of_sensorsEdit->text().toInt(),ui->number_of_lapsEdit->text().toInt());
               }
            else emit this->sendRaceWindowData(get_team(ui->nextteamList->item(0)->text())
                                               ,"END OF QUEUE",ui->number_of_sensorsEdit->text().toInt(),ui->number_of_lapsEdit->text().toInt());

    this->is_race_started=true;
    }

}




team MainWindow:: get_team(QString mTeam)
{
    team *tTeam=new team ;
    QString tempName;
    for(int i=0;i<this->RC_ST.Teams.size();i++)
    {
        tempName=this->RC_ST.Teams.at(i)->Team_Name+"_rcst";
        if(tempName.compare(mTeam)==0)
        {
         tTeam=this->RC_ST.Teams.at(i);
        }
    }
    for(int i=0;i<this->RC.Teams.size();i++)
       {
        tempName=this->RC.Teams.at(i)->Team_Name+"_rcrd";
          if(tempName.compare(mTeam)==0)
           {
              tTeam=this->RC.Teams.at(i);
           }
       }
    for(int i=0;i<this->AUTONOM.Teams.size();i++)
       {
          tempName=this->AUTONOM.Teams.at(i)->Team_Name+"_aurd";
        if(tempName.compare(mTeam)==0)
           {
             tTeam=this->AUTONOM.Teams.at(i);
           }
       }



  return *tTeam;
}

void MainWindow::receive_results_of_race(const team &mTeam, const int &mseconds)
{

        for(int i=0;i<this->RC_ST.Teams.size();i++)
        {
            if(mTeam.Team_Name.compare(this->RC_ST.Teams.at(i)->Team_Name)==0
                  &&  mTeam.Category_Name.compare("RC-STANDARD")==0 )
            {
                this->RC_ST.Teams.at(i)->Race_Time.push_front(mseconds);


                for(int j=0;j<ui->RC_STrankingTable->rowCount();j++)
                {
                    if(mTeam.Team_Name.compare(ui->RC_STrankingTable->item(j,0)->text())==0)
                    {
                        if(ui->RC_STrankingTable->item(j,1)->text().toDouble()==3600000 || this->RC_ST.Teams.at(i)->Race_Time.at(0)<this->RC_ST.Teams.at(i)->Best_Race_Time)
                          this->RC_ST.Teams.at(i)->Best_Race_Time=this->RC_ST.Teams.at(i)->Race_Time.at(0);
                           ui->RC_STrankingTable->item(j,1)->setData(Qt::DisplayRole,this->RC_ST.Teams.at(i)->Best_Race_Time);
                            ui->save_session_Button->setStyleSheet("* { background-color: rgb(255,100,100) }");

                    }
                }

            }
        }
        for(int i=0;i<this->RC.Teams.size();i++)
           {
            if(mTeam.Team_Name.compare(this->RC.Teams.at(i)->Team_Name)==0
                    &&mTeam.Category_Name.compare("RC-ROBODRIFT")==0 )
            {
                   this->RC.Teams.at(i)->Race_Time.push_front(mseconds);



                   for(int j=0;j<ui->RCrankingTable->rowCount();j++)
                   {
                      if(mTeam.Team_Name.compare(ui->RCrankingTable->item(j,0)->text())==0)
                       {
                           if(ui->RCrankingTable->item(j,1)->text().toDouble()==3600000 || this->RC.Teams.at(i)->Race_Time.at(0)<this->RC.Teams.at(i)->Best_Race_Time)
                             this->RC.Teams.at(i)->Best_Race_Time=this->RC.Teams.at(i)->Race_Time.at(0);
                              ui->RCrankingTable->item(j,1)->setData(Qt::DisplayRole,this->RC.Teams.at(i)->Best_Race_Time);
                               ui->save_session_Button->setStyleSheet("* { background-color: rgb(255,100,100) }");
                       }
                   }

               }
           }
        for(int i=0;i<this->AUTONOM.Teams.size();i++)
           {
                               if(mTeam.Team_Name.compare(this->AUTONOM.Teams.at(i)->Team_Name)==0
                                       && mTeam.Category_Name.compare("AUTONOM-ROBODRIFT")==0 )
                               {
                   this->AUTONOM.Teams.at(i)->Race_Time.push_front(mseconds);



                   for(int j=0;j<ui->AUTONOMrankingTable->rowCount();j++)
                   {
                       if(mTeam.Team_Name.compare(ui->AUTONOMrankingTable->item(j,0)->text())==0)
                       {
                           if(ui->AUTONOMrankingTable->item(j,1)->text().toDouble()==3600000 || this->AUTONOM.Teams.at(i)->Race_Time.at(0)<this->AUTONOM.Teams.at(i)->Best_Race_Time)
                             this->AUTONOM.Teams.at(i)->Best_Race_Time=this->AUTONOM.Teams.at(i)->Race_Time.at(0);
                              ui->AUTONOMrankingTable->item(j,1)->setData(Qt::DisplayRole,this->AUTONOM.Teams.at(i)->Best_Race_Time);
                               ui->save_session_Button->setStyleSheet("* { background-color: rgb(255,100,100) }");
                       }
                   }

               }
           }

        this->is_race_started=false;
             ui->RC_STrankingTable->sortItems(1,Qt::AscendingOrder);
             ui->RCrankingTable->sortItems(1,Qt::AscendingOrder);
                ui->AUTONOMrankingTable->sortItems(1,Qt::AscendingOrder);


                   emit send_final_position(get_position_of_last_team());

        delete_team_from_waiting_list();




}



int MainWindow::get_position_of_last_team()
{
    int position=0;
    for(int i=0;i<this->RC_ST.Teams.size();i++)
    {
        if(ui->nextteamList->item(0)->text().compare(this->RC_ST.Teams.at(i)->Team_Name+"_rcst")==0)
        {

            for(int j=0;j<ui->RC_STrankingTable->rowCount();j++)
            {
                if(ui->nextteamList->item(0)->text().compare(ui->RC_STrankingTable->item(j,0)->text()+"_rcst")==0)
                {
                  position=j+1;
                }
            }

        }
    }
    for(int i=0;i<this->RC.Teams.size();i++)
       {
           if(ui->nextteamList->item(0)->text().compare(this->RC.Teams.at(i)->Team_Name+"_rcrd")==0)
           {



               for(int j=0;j<ui->RCrankingTable->rowCount();j++)
               {
                   if(ui->nextteamList->item(0)->text().compare(ui->RCrankingTable->item(j,0)->text()+"_rcrd")==0)
                   {
                      position=j+1;
                   }
               }

           }
       }
    for(int i=0;i<this->AUTONOM.Teams.size();i++)
       {
           if(ui->nextteamList->item(0)->text().compare(this->AUTONOM.Teams.at(i)->Team_Name+"_aurd")==0)
           {




               for(int j=0;j<ui->AUTONOMrankingTable->rowCount();j++)
               {
                   if(ui->nextteamList->item(0)->text().compare(ui->AUTONOMrankingTable->item(j,0)->text()+"_aurd")==0)
                   {
                           position=j+1;
                   }
               }

           }
       }
    return position;
}






void MainWindow::on_deleteTeamButton_clicked()
{
QString team_to_delete;



    if(ui->RC_STrankingTable->selectedItems().count()>0)
    {
        QMessageBox::StandardButton reply;
        reply=QMessageBox::question(this,"DELETE TEAM","Do you really want to delete selected team from RC-STANDARD?",
                               QMessageBox::Yes|QMessageBox::No);
        if(reply==QMessageBox::Yes)
          {

            team_to_delete=ui->RC_STrankingTable->selectedItems().at(0)->text();

            for(int i=0;i<this->RC_ST.Teams.count();i++)
            {

                if(this->RC_ST.Teams.at(i)->Team_Name.compare(team_to_delete)==0)
                {
                    this->RC_ST.Teams.removeAt(i);
                break;
                }
            }

    ui->RC_STrankingTable->removeRow(ui->RC_STrankingTable->selectedItems().at(0)->row());
    ui->RC_STrankingTable->clearSelection();
        }
        else ui->RC_STrankingTable->clearSelection();
    }
    if(ui->RCrankingTable->selectedItems().count()>0)
    {
        QMessageBox::StandardButton reply;
        reply=QMessageBox::question(this,"DELETE TEAM","Do you really want to delete selected team from RC-ROBODRIFT?",
                               QMessageBox::Yes|QMessageBox::No);
        if(reply==QMessageBox::Yes)
          {
            team_to_delete=ui->RCrankingTable->selectedItems().at(0)->text();


            for(int i=0;i<this->RC.Teams.count();i++)
            {

                if( this->RC.Teams.at(i)->Team_Name.compare(team_to_delete)==0)
                {

                    this->RC.Teams.removeAt(i);
                break;
                }
            }
    ui->RCrankingTable->removeRow(ui->RCrankingTable->selectedItems().at(0)->row());
    ui->RCrankingTable->clearSelection();
        }
        else ui->RCrankingTable->clearSelection();
    }
    if(ui->AUTONOMrankingTable->selectedItems().count()>0)
    {
        QMessageBox::StandardButton reply;
        reply=QMessageBox::question(this,"DELETE TEAM","Do you really want to delete selected team from AUTONOM-ROBODRIFT?",
                               QMessageBox::Yes|QMessageBox::No);
        if(reply==QMessageBox::Yes)
          {
            team_to_delete=ui->AUTONOMrankingTable->selectedItems().at(0)->text();

            for(int i=0;i<this->AUTONOM.Teams.count();i++)
            {

                if(this->AUTONOM.Teams.at(i)->Team_Name.compare(team_to_delete)==0)
                {
                    this->AUTONOM.Teams.removeAt(i);
                break;
                }

            }
            ui->AUTONOMrankingTable->removeRow(ui->AUTONOMrankingTable->selectedItems().at(0)->row());
            ui->AUTONOMrankingTable->clearSelection();
        }
           else ui->AUTONOMrankingTable->clearSelection();
        }
    ui->save_session_Button->setStyleSheet("* { background-color: rgb(255,100,100) }");
}

void MainWindow::save_teams()
{
    xml_document doc;
            xml_node RC_ST = doc.append_child("RC_ST");
            RC_ST.append_attribute("Tytul")="RC_STANDARD";

            for(int i=0; i<this->RC_ST.Teams.size();i++)
                    {
                        xml_node team = RC_ST.append_child("team");

                        team.append_attribute("Team_Name")=this->RC_ST.Teams.at(i)->Team_Name.toStdString().c_str();
                        team.append_attribute("Car_Name")=this->RC_ST.Teams.at(i)->Car_Name.toStdString().c_str();
                        team.append_attribute("Best_Race_Time")=this->RC_ST.Teams.at(i)->Best_Race_Time;
                    }
            xml_node RC = doc.append_child("RC");
            RC.append_attribute("Tytul")="RC_ROBODRIFT";

            for(int i=0; i<this->RC.Teams.size();i++)
                    {
                        xml_node team = RC.append_child("team");

                        team.append_attribute("Team_Name")=this->RC.Teams.at(i)->Team_Name.toStdString().c_str();

                        team.append_attribute("Car_Name")=this->RC.Teams.at(i)->Car_Name.toStdString().c_str();
                        team.append_attribute("Best_Race_Time")=this->RC.Teams.at(i)->Best_Race_Time;
                    }
            xml_node AUTONOM = doc.append_child("AUTONOM");
            AUTONOM.append_attribute("Tytul")="AUTONOM_ROBODRIFT";

            for(int i=0; i<this->AUTONOM.Teams.size();i++)
                    {
                        xml_node team = AUTONOM.append_child("team");

                        team.append_attribute("Team_Name")=this->AUTONOM.Teams.at(i)->Team_Name.toStdString().c_str();

                        team.append_attribute("Car_Name")=this->AUTONOM.Teams.at(i)->Car_Name.toStdString().c_str();
                        team.append_attribute("Best_Race_Time")=this->AUTONOM.Teams.at(i)->Best_Race_Time;
                    }

            doc.save_file("teams_clear.xml");
             ui->save_session_Button->setStyleSheet("* { background-color: Button}");
}

void MainWindow::load_clear_teams()
{
    xml_document doc;
        if(doc.load_file("teams_clear.xml"))
        {
            xml_node RC_ST = doc.child("RC_ST");
            for(xml_node newTeam=RC_ST.child("team");newTeam;newTeam=newTeam.next_sibling("team"))
            {
                team *mTeam=new team;
                mTeam->Car_Name=newTeam.attribute("Car_Name").value();
                mTeam->Team_Name=newTeam.attribute("Team_Name").value();
                mTeam->Category_Name="RC-STANDARD";
                mTeam->Best_Race_Time=3600000;
                this->RC_ST.Teams.push_back(mTeam);

                ui->RC_STrankingTable->insertRow(ui->RC_STrankingTable->rowCount());
               QTableWidgetItem *itm=new QTableWidgetItem;
                itm->setFlags(itm->flags() ^ Qt::ItemIsEditable);
               ui->RC_STrankingTable->setItem(ui->RC_STrankingTable->rowCount()-1,0,itm);
              ui->RC_STrankingTable->item(ui->RC_STrankingTable->rowCount()-1,0)->setText(mTeam->Team_Name);
               QTableWidgetItem *itm2=new QTableWidgetItem;
            //     itm2->setFlags(itm2->flags() ^ Qt::ItemIsEditable);
               int a=3600000;
              itm2->setData(Qt::DisplayRole,a);

             ui->RC_STrankingTable->setItem(ui->RC_STrankingTable->rowCount()-1,1,itm2);

             ui->RC_STrankingTable->item(ui->RC_STrankingTable->rowCount()-1,0)->setTextAlignment(Qt::AlignCenter);
             ui->RC_STrankingTable->item(ui->RC_STrankingTable->rowCount()-1,1)->setTextAlignment(Qt::AlignCenter);
            }

            xml_node RC = doc.child("RC");
            for(xml_node newTeam=RC.child("team");newTeam;newTeam=newTeam.next_sibling("team"))
            {
                team *mTeam=new team;
                mTeam->Car_Name=newTeam.attribute("Car_Name").value();
                mTeam->Team_Name=newTeam.attribute("Team_Name").value();
                mTeam->Category_Name="RC-ROBODRIFT";
                mTeam->Best_Race_Time=3600000;
                this->RC.Teams.push_back(mTeam);

                ui->RCrankingTable->insertRow(ui->RCrankingTable->rowCount());
               QTableWidgetItem *itm=new QTableWidgetItem;
                itm->setFlags(itm->flags() ^ Qt::ItemIsEditable);
               ui->RCrankingTable->setItem(ui->RCrankingTable->rowCount()-1,0,itm);
              ui->RCrankingTable->item(ui->RCrankingTable->rowCount()-1,0)->setText(mTeam->Team_Name);
               QTableWidgetItem *itm2=new QTableWidgetItem;
             //    itm2->setFlags(itm2->flags() ^ Qt::ItemIsEditable);
               int a=3600000;
              itm2->setData(Qt::DisplayRole,a);

             ui->RCrankingTable->setItem(ui->RCrankingTable->rowCount()-1,1,itm2);

             ui->RCrankingTable->item(ui->RCrankingTable->rowCount()-1,0)->setTextAlignment(Qt::AlignCenter);
             ui->RCrankingTable->item(ui->RCrankingTable->rowCount()-1,1)->setTextAlignment(Qt::AlignCenter);
            }

            xml_node AUTONOM = doc.child("AUTONOM");
            for(xml_node newTeam=AUTONOM.child("team");newTeam;newTeam=newTeam.next_sibling("team"))
            {
                team *mTeam=new team;
                mTeam->Car_Name=newTeam.attribute("Car_Name").value();
                mTeam->Team_Name=newTeam.attribute("Team_Name").value();
                mTeam->Category_Name="AUTONOM-ROBODRIFT";
                mTeam->Best_Race_Time=3600000;
                this->AUTONOM.Teams.push_back(mTeam);

                ui->AUTONOMrankingTable->insertRow(ui->AUTONOMrankingTable->rowCount());
               QTableWidgetItem *itm=new QTableWidgetItem;
                itm->setFlags(itm->flags() ^ Qt::ItemIsEditable);
               ui->AUTONOMrankingTable->setItem(ui->AUTONOMrankingTable->rowCount()-1,0,itm);
              ui->AUTONOMrankingTable->item(ui->AUTONOMrankingTable->rowCount()-1,0)->setText(mTeam->Team_Name);
               QTableWidgetItem *itm2=new QTableWidgetItem;
             //    itm2->setFlags(itm2->flags() ^ Qt::ItemIsEditable);
               int a=3600000;
              itm2->setData(Qt::DisplayRole,a);

             ui->AUTONOMrankingTable->setItem(ui->AUTONOMrankingTable->rowCount()-1,1,itm2);

             ui->AUTONOMrankingTable->item(ui->AUTONOMrankingTable->rowCount()-1,0)->setTextAlignment(Qt::AlignCenter);
             ui->AUTONOMrankingTable->item(ui->AUTONOMrankingTable->rowCount()-1,1)->setTextAlignment(Qt::AlignCenter);
            }



}
}

void MainWindow::load_session_teams()
{
    xml_document doc;
        if(doc.load_file("teams_clear.xml"))
        {
            xml_node RC_ST = doc.child("RC_ST");
            for(xml_node newTeam=RC_ST.child("team");newTeam;newTeam=newTeam.next_sibling("team"))
            {
                team *mTeam=new team;
                mTeam->Car_Name=newTeam.attribute("Car_Name").value();
                mTeam->Team_Name=newTeam.attribute("Team_Name").value();
                mTeam->Category_Name="RC-STANDARD";
                stringstream ss;
                ss<<newTeam.attribute("Best_Race_Time").value();
                int  best_time=0;
                ss>>best_time;
                mTeam->Best_Race_Time=best_time;
                this->RC_ST.Teams.push_back(mTeam);

                ui->RC_STrankingTable->insertRow(ui->RC_STrankingTable->rowCount());
               QTableWidgetItem *itm=new QTableWidgetItem;
                itm->setFlags(itm->flags() ^ Qt::ItemIsEditable);
               ui->RC_STrankingTable->setItem(ui->RC_STrankingTable->rowCount()-1,0,itm);
              ui->RC_STrankingTable->item(ui->RC_STrankingTable->rowCount()-1,0)->setText(mTeam->Team_Name);
               QTableWidgetItem *itm2=new QTableWidgetItem;
             //    itm2->setFlags(itm2->flags() ^ Qt::ItemIsEditable);

              itm2->setData(Qt::DisplayRole,this->RC_ST.Teams.last()->Best_Race_Time);

             ui->RC_STrankingTable->setItem(ui->RC_STrankingTable->rowCount()-1,1,itm2);

             ui->RC_STrankingTable->item(ui->RC_STrankingTable->rowCount()-1,0)->setTextAlignment(Qt::AlignCenter);
             ui->RC_STrankingTable->item(ui->RC_STrankingTable->rowCount()-1,1)->setTextAlignment(Qt::AlignCenter);
            }

            xml_node RC = doc.child("RC");
            for(xml_node newTeam=RC.child("team");newTeam;newTeam=newTeam.next_sibling("team"))
            {
                team *mTeam=new team;
                mTeam->Car_Name=newTeam.attribute("Car_Name").value();
                mTeam->Team_Name=newTeam.attribute("Team_Name").value();
                mTeam->Category_Name="RC-ROBODRIFT";
                stringstream ss;
                ss<<newTeam.attribute("Best_Race_Time").value();
                int  best_time=0;
                ss>>best_time;
                mTeam->Best_Race_Time=best_time;
                this->RC.Teams.push_back(mTeam);

                ui->RCrankingTable->insertRow(ui->RCrankingTable->rowCount());
               QTableWidgetItem *itm=new QTableWidgetItem;
              itm->setFlags(itm->flags() ^ Qt::ItemIsEditable);
               ui->RCrankingTable->setItem(ui->RCrankingTable->rowCount()-1,0,itm);
              ui->RCrankingTable->item(ui->RCrankingTable->rowCount()-1,0)->setText(mTeam->Team_Name);
               QTableWidgetItem *itm2=new QTableWidgetItem;
                // itm2->setFlags(itm2->flags() ^ Qt::ItemIsEditable);

            itm2->setData(Qt::DisplayRole,this->RC.Teams.last()->Best_Race_Time);

             ui->RCrankingTable->setItem(ui->RCrankingTable->rowCount()-1,1,itm2);

             ui->RCrankingTable->item(ui->RCrankingTable->rowCount()-1,0)->setTextAlignment(Qt::AlignCenter);
             ui->RCrankingTable->item(ui->RCrankingTable->rowCount()-1,1)->setTextAlignment(Qt::AlignCenter);
            }

            xml_node AUTONOM = doc.child("AUTONOM");
            for(xml_node newTeam=AUTONOM.child("team");newTeam;newTeam=newTeam.next_sibling("team"))
            {
                team *mTeam=new team;
                mTeam->Car_Name=newTeam.attribute("Car_Name").value();
                mTeam->Team_Name=newTeam.attribute("Team_Name").value();
                mTeam->Category_Name="AUTONOM-ROBODRIFT";
                stringstream ss;
                ss<<newTeam.attribute("Best_Race_Time").value();
                int  best_time=0;
                ss>>best_time;
                mTeam->Best_Race_Time=best_time;
                this->AUTONOM.Teams.push_back(mTeam);

                ui->AUTONOMrankingTable->insertRow(ui->AUTONOMrankingTable->rowCount());
               QTableWidgetItem *itm=new QTableWidgetItem;
                itm->setFlags(itm->flags() ^ Qt::ItemIsEditable);
               ui->AUTONOMrankingTable->setItem(ui->AUTONOMrankingTable->rowCount()-1,0,itm);
              ui->AUTONOMrankingTable->item(ui->AUTONOMrankingTable->rowCount()-1,0)->setText(mTeam->Team_Name);
               QTableWidgetItem *itm2=new QTableWidgetItem;
               //  itm2->setFlags(itm2->flags() ^ Qt::ItemIsEditable);

         itm2->setData(Qt::DisplayRole,this->AUTONOM.Teams.last()->Best_Race_Time);

             ui->AUTONOMrankingTable->setItem(ui->AUTONOMrankingTable->rowCount()-1,1,itm2);

             ui->AUTONOMrankingTable->item(ui->AUTONOMrankingTable->rowCount()-1,0)->setTextAlignment(Qt::AlignCenter);
             ui->AUTONOMrankingTable->item(ui->AUTONOMrankingTable->rowCount()-1,1)->setTextAlignment(Qt::AlignCenter);
            }

            ui->RC_STrankingTable->sortItems(1,Qt::AscendingOrder);
            ui->RCrankingTable->sortItems(1,Qt::AscendingOrder);
               ui->AUTONOMrankingTable->sortItems(1,Qt::AscendingOrder);


}
}

void MainWindow::save_quele()
{
    xml_document doc;
            xml_node mQuele = doc.append_child("QUELE");
           mQuele.append_attribute("Tytul")="QUELE";

            for(int i=0; i<ui->nextteamList->count();i++)
                    {
                xml_node team = mQuele.append_child("team");
                team.append_attribute("Team_Name")=ui->nextteamList->item(i)->text().toStdString().c_str();
                    }
            for(int i=0; i<ui->laterteamList->count();i++)
                    {
                xml_node team = mQuele.append_child("team");
                team.append_attribute("Team_Name")=ui->laterteamList->item(i)->text().toStdString().c_str();
                    }

            doc.save_file("teams_quele.xml");
}

void MainWindow::load_quele()
{
    team tempTeam;
    xml_document doc;
        if(doc.load_file("teams_quele.xml"))
        {
            xml_node mQuele = doc.child("QUELE");
            for(xml_node newTeam=mQuele.child("team");newTeam;newTeam=newTeam.next_sibling("team"))
            {
                QListWidgetItem *mItem= new QListWidgetItem;
                mItem->setText(newTeam.attribute("Team_Name").value());

                set_list_item_color(mItem);



                if(ui->nextteamList->count()<3)
                {
                   set_item_untouchable(mItem);
                    ui->nextteamList->addItem(mItem);
                }
                else
                {
                     ui->laterteamList->addItem(mItem);
                }

       }
}
}

void MainWindow::on_loadteamsButton_clicked()
{
    if(this->is_loading_enabled)
    {
        load_clear_teams();
        this->is_loading_enabled=false;
    }

}


void MainWindow::on_load_session_Button_clicked()
{
    if(this->is_loading_enabled)
    {
        load_session_teams();
    load_quele();
    this->is_loading_enabled=false;
    }
}


void MainWindow::on_save_session_Button_clicked()
{

    save_teams();
    save_quele();
}

void MainWindow::on_resultsWindowButton_clicked()
{
    QObject::connect(this,SIGNAL(send_results_for_Public(const QListWidget*,const QTableWidget*,const QTableWidget*,const QTableWidget*)),
                    mResultsWindow,SLOT(receive_results_for_Public
                                        (const QListWidget*,const QTableWidget*,const QTableWidget*,const QTableWidget*)));

    mResultsWindow->showFullScreen();
    mRaceWindow->hide();



    emit send_results_for_Public(ui->nextteamList,ui->RC_STrankingTable,ui->RCrankingTable,ui->AUTONOMrankingTable);
    is_race_started=false;
}

void MainWindow::on_messageEdit_returnPressed()
{
     emit send_comment_for_Public(ui->messageEdit->text());
}

void MainWindow::  set_list_item_color(QListWidgetItem *mItem) //musi miec item podany nazwe teamu wczejniej!!!
{
    team tempTeam;
    tempTeam=get_team(mItem->text());
    if(tempTeam.Category_Name=="RC-STANDARD")
    {
    mItem->setBackgroundColor(Qt::red);
    mItem->setTextColor(Qt::white);
    }
    else if(tempTeam.Category_Name=="RC-ROBODRIFT")
    {
    mItem->setBackgroundColor(Qt::blue);
    mItem->setTextColor(Qt::white);
    }
    else if(tempTeam.Category_Name=="AUTONOM-ROBODRIFT")
    {
    mItem->setBackgroundColor(Qt::green);
    mItem->setTextColor(Qt::black);
    }
}


void MainWindow::on_startButton_pressed()
{
if(is_race_started==true) emit begin_race();

}

void MainWindow::on_stopButton_pressed()
{
    is_race_started=false;
}

void MainWindow::on_messageEdit_editingFinished()
{
     emit send_comment_for_Public(ui->messageEdit->text());
}


void MainWindow::receive_serialport_status(const int &PortStatus)
{
    if(PortStatus==0)
    {
        ui->ConnectWithMasterButton->setStyleSheet("* { background-color: rgb(255,100,100) }");
    }
    else if(PortStatus==1)
    {
        ui->ConnectWithMasterButton->setStyleSheet("* { background-color: rgb(100,255,100) }");
    }

}


