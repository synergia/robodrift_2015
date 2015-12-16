#include "resultswindow.h"
#include "ui_resultswindow.h"
#include <QListWidget>
#include <QScrollBar>

resultswindow::resultswindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::resultswindow)
{
    ui->setupUi(this);


    connect(this->swapTimer, SIGNAL(timeout()), this, SLOT(swapTimeTick()));
    swapTimer->start(2000); //co 2 sekudny aktualizacja



     ui->label->setStyleSheet(" background-color: white; border-image: url(background_2.png); background-attachment: scroll;");
     ui->label_2->setStyleSheet(" background-color: white; border-image: url(background_2.png); background-attachment: scroll;");
     ui->label_3->setStyleSheet(" background-color: white; border-image: url(background_2.png); background-attachment: scroll;");

     ui->frame->setStyleSheet(" background-color: white; border-image: url(background_1.png); background-attachment: scroll;");
     ui->comment_Label->setStyleSheet(" background-color: white; border-image: url(background_2.png); background-attachment: scroll;");
     ui->next_teams_Label->setStyleSheet(" background-color: white; border-image: url(background_2.png); background-attachment: scroll;");
     this->setStyleSheet(" background-color: white; background-image: url(background_cross.png);");
     ui->comment_Label->setAlignment(Qt::AlignCenter);
     ui->next_teams_Label->setAlignment(Qt::AlignCenter);
      ui->label->setAlignment(Qt::AlignCenter);
       ui->label_2->setAlignment(Qt::AlignCenter);
        ui->label_3->setAlignment(Qt::AlignCenter);

 //RCST

      for(int c = 0; c < ui->tableWidget->horizontalHeader()->count(); c++) //rozciaganie kazdej kolumny
      {
          ui->tableWidget->horizontalHeader()->setSectionResizeMode(
              c, QHeaderView::Stretch);
      }
       ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
       ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section { border-image: url(background_2.png)}");
      ui->tableWidget->setStyleSheet("QHeaderView::section { border-image: url(background_2.png)};");

       QFont font ; //TEN SAM DLA WSZYSTKICH TABEL
      font.setPointSize(22);
      font.setBold(true);
      ui->tableWidget->setFont(font);
       ui->tableWidget->horizontalHeader()->setFont(font);
       ui->tableWidget->verticalHeader()->setFont(font);
       ui->tableWidget->horizontalHeader()->setMinimumWidth(200);
       ui->tableWidget->setCornerButtonEnabled(false);
       //RC

       for(int c = 0; c < ui->tableWidget_2->horizontalHeader()->count(); c++) //rozciaganie kazdej kolumny
       {
           ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(
               c, QHeaderView::Stretch);
       }
        ui->tableWidget_2->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableWidget_2->horizontalHeader()->setStyleSheet("QHeaderView::section { border-image: url(background_2.png)}");
       ui->tableWidget_2->setStyleSheet("QHeaderView::section { border-image: url(background_2.png)};");


       ui->tableWidget_2->setFont(font);
        ui->tableWidget_2->horizontalHeader()->setFont(font);
        ui->tableWidget_2->verticalHeader()->setFont(font);
        ui->tableWidget_2->horizontalHeader()->setMinimumWidth(200);
        ui->tableWidget_2->setCornerButtonEnabled(false);


        //AUTONOM

        for(int c = 0; c < ui->tableWidget_3->horizontalHeader()->count(); c++) //rozciaganie kazdej kolumny
        {
            ui->tableWidget_3->horizontalHeader()->setSectionResizeMode(
                c, QHeaderView::Stretch);
        }
         ui->tableWidget_3->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
         ui->tableWidget_3->horizontalHeader()->setStyleSheet("QHeaderView::section { border-image: url(background_2.png)}");
        ui->tableWidget_3->setStyleSheet("QHeaderView::section { border-image: url(background_2.png)};");


        ui->tableWidget_3->setFont(font);
         ui->tableWidget_3->horizontalHeader()->setFont(font);
         ui->tableWidget_3->verticalHeader()->setFont(font);
         ui->tableWidget_3->horizontalHeader()->setMinimumWidth(200);
         ui->tableWidget_3->setCornerButtonEnabled(false);


    ui->comment_Label->setText("ROBODRIFT 2015");



}

resultswindow::~resultswindow()
{
    delete ui;
}

void resultswindow:: receive_results_for_Public(const QListWidget *nextTeamList, const QTableWidget *RCSTrankingtable,
                                                const QTableWidget *RCrankingtable, const QTableWidget *AUTONOMrankingtable)
{
    QString mNext_Tems_Label_Text;
    QString mPart_of_Text;

 //resetowanie scrolli
    this->scrolled_value_RCST=0;

//labele
    while (ui->tableWidget->rowCount() > 0)
    {
       ui->tableWidget->removeRow(0);
    }

    while (ui->tableWidget_2->rowCount() > 0)
    {
       ui->tableWidget_2->removeRow(0);
    }

    while (ui->tableWidget_3->rowCount() > 0)
    {
       ui->tableWidget_3->removeRow(0);
    }

    for(int i=0;i<nextTeamList->count();i++)
    {
        mPart_of_Text=nextTeamList->item(i)->text();
       QStringList mStringList=mPart_of_Text.split("_");

        if(i==nextTeamList->count()-1) mNext_Tems_Label_Text+=mStringList.at(0);
        else mNext_Tems_Label_Text+=mStringList.at(0)+" >> ";
    }

    ui->next_teams_Label->setText(mNext_Tems_Label_Text);

//tabele
    for(int i=0;i<RCSTrankingtable->rowCount();i++)
    {
        if(RCSTrankingtable->item(i,1)->text().toInt()!=3600000)
        {
        QString mTeamName=RCSTrankingtable->item(i,0)->text();
        int mResultValue=RCSTrankingtable->item(i,1)->text().toInt();
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
       QTableWidgetItem *itm=new QTableWidgetItem;
       ui->tableWidget->setItem(i,0,itm);
      ui->tableWidget->item(i,0)->setText(mTeamName);
    ui->tableWidget->item(i,0)->setTextAlignment(Qt::AlignCenter);
    itm->setFlags(itm->flags() ^ Qt::ItemIsEditable);
       QTableWidgetItem *itm2=new QTableWidgetItem;
            ui->tableWidget->setItem(i,1,itm2);
     ui->tableWidget->item(i,1)->setText(race_time_format(mResultValue));
     ui->tableWidget->item(i,1)->setTextAlignment(Qt::AlignCenter);
     itm->setFlags(itm->flags() ^ Qt::ItemIsEditable);
        }
    }

    for(int i=0;i<RCrankingtable->rowCount();i++)
       {
           if(RCrankingtable->item(i,1)->text().toInt()!=3600000)
           {
           QString mTeamName=RCrankingtable->item(i,0)->text();
           int mResultValue=RCrankingtable->item(i,1)->text().toInt();
           ui->tableWidget_2->insertRow(ui->tableWidget_2->rowCount());
          QTableWidgetItem *itm=new QTableWidgetItem;
          ui->tableWidget_2->setItem(i,0,itm);
         ui->tableWidget_2->item(i,0)->setText(mTeamName);
       ui->tableWidget_2->item(i,0)->setTextAlignment(Qt::AlignCenter);
       itm->setFlags(itm->flags() ^ Qt::ItemIsEditable);
          QTableWidgetItem *itm2=new QTableWidgetItem;
               ui->tableWidget_2->setItem(i,1,itm2);
        ui->tableWidget_2->item(i,1)->setText(race_time_format(mResultValue));
        ui->tableWidget_2->item(i,1)->setTextAlignment(Qt::AlignCenter);
        itm->setFlags(itm->flags() ^ Qt::ItemIsEditable);
           }
       }

    for(int i=0;i<AUTONOMrankingtable->rowCount();i++)
       {
           if(AUTONOMrankingtable->item(i,1)->text().toInt()!=3600000)
           {
           QString mTeamName=AUTONOMrankingtable->item(i,0)->text();
           int mResultValue=AUTONOMrankingtable->item(i,1)->text().toInt();
           ui->tableWidget_3->insertRow(ui->tableWidget_3->rowCount());
          QTableWidgetItem *itm=new QTableWidgetItem;
          ui->tableWidget_3->setItem(i,0,itm);
         ui->tableWidget_3->item(i,0)->setText(mTeamName);
       ui->tableWidget_3->item(i,0)->setTextAlignment(Qt::AlignCenter);
       itm->setFlags(itm->flags() ^ Qt::ItemIsEditable);
          QTableWidgetItem *itm2=new QTableWidgetItem;
               ui->tableWidget_3->setItem(i,1,itm2);
        ui->tableWidget_3->item(i,1)->setText(race_time_format(mResultValue));
        ui->tableWidget_3->item(i,1)->setTextAlignment(Qt::AlignCenter);
        itm->setFlags(itm->flags() ^ Qt::ItemIsEditable);
           }
       }

}

void resultswindow:: receive_comment_for_Public(const QString &mComment)
{

    if(mComment.isEmpty()) this->mCommentPublic="ROBODRIFT 2015";
     else this->mCommentPublic=mComment;

}

QString resultswindow::race_time_format(int mseconds)
{
    int minutes=(mseconds-mseconds%60000)/60000;
    int seconds=((mseconds-mseconds%1000)/1000)%60;
    int miliseconds=mseconds%1000;
      if(seconds==60) seconds=0;

    QString mMinutes;
    QString mSeconds;
    QString mMiliseconds;

   // if(minutes<10) mMinutes="0"+QString::number(minutes);
        // else
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

void resultswindow::swapTimeTick()
{

  if(ui->comment_Label->text()=="ROBODRIFT 2015"
          && !this->mCommentPublic.isEmpty() ) ui->comment_Label->setText(this->mCommentPublic);
  else ui->comment_Label->setText("ROBODRIFT 2015");

  this->swapTimerTickCounter++;

  if(this->swapTimerTickCounter==3)
  {

    if(this->scrolled_value_RCST<ui->tableWidget->rowCount()-12) //"-12" do dopasowania do ilosci wyswietlanych wierszy
    {
    ui->tableWidget->verticalScrollBar()->setValue(this->scrolled_value_RCST+=10); // "+=10" do dopasowania podobnie
    }
    else
    {
        ui->tableWidget->scrollToTop();
        this->scrolled_value_RCST=0;
    }

    if(this->scrolled_value_RC<ui->tableWidget_2->rowCount()-12) //"-12" do dopasowania do ilosci wyswietlanych wierszy
    {
    ui->tableWidget_2->verticalScrollBar()->setValue(this->scrolled_value_RC+=10); // "+=10" do dopasowania podobnie
    }
    else
    {
        ui->tableWidget_2->scrollToTop();
        this->scrolled_value_RC=0;
    }

    if(this->scrolled_value_AUTONOM<ui->tableWidget_3->rowCount()-12) //"-12" do dopasowania do ilosci wyswietlanych wierszy
    {
    ui->tableWidget_3->verticalScrollBar()->setValue(this->scrolled_value_AUTONOM+=10); // "+=10" do dopasowania podobnie
    }
    else
    {
        ui->tableWidget_3->scrollToTop();
        this->scrolled_value_AUTONOM=0;
    }

    this->swapTimerTickCounter=0;
  }
}
