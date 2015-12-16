#ifndef RESULTSWINDOW_H
#define RESULTSWINDOW_H

#include <QDialog>
#include <QListWidget>
#include <QTableWidget>
#include <QTimer>


/* okna do prezentacji wynikow
 * tabele dopasowuja sie do ilosci zespolow lub gdy jest ich bardzo duzo
 * to wtedy sa przewijane automatycznie
 * mozna wyswietlic komentarz dla publiki/zespolow
 * pokazuje trzy nastepne zespoly ktore powinny sie przygotowywac*/

namespace Ui {
class resultswindow;
}

class resultswindow : public QDialog
{
    Q_OBJECT

   public slots:

    //slot odbierajacy wyniki z okna glownego
   void receive_results_for_Public(const QListWidget *nextTeamList,const QTableWidget *RCSTrankingtable
                                   ,const QTableWidget *RCrankingtable,const QTableWidget *AUTONOMrankingtable);

   //slot odbierajacy komentarz z okna glowniego
   void receive_comment_for_Public(const QString &mComment);

private slots:

   // tick czasowy co jak nastepuje scrollowanie tabel
   void swapTimeTick();

public:
    explicit resultswindow(QWidget *parent = 0);
    ~resultswindow();


   QString mCommentPublic;
   int swapTimerTickCounter=0;

   //przelicza ms na min:sec:msec
   QString race_time_format(int mseconds);

   QTimer *swapTimer=new QTimer(this);
   int swap_seconds=0;

   int scrolled_value_RCST=0;
   int scrolled_value_RC=0;
   int scrolled_value_AUTONOM=0;


private:
    Ui::resultswindow *ui;
};

#endif // RESULTSWINDOW_H
