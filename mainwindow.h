#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QTableWidget>
#include "category.h"
#include "addteam.h"
#include "racewindow.h"
#include "resultswindow.h"
#include <QString>

/* glowne okno programu , przechowuje informacje o zespolach, czasach, ustala kolejnosc,
 * komunikuje sie z innymi oknami aplikacji
 * NIE LACZY SIE Z MASTEREM OD CZUJNIKOW (tylko przekazuje informacje o żadaniu polaczenia)
 * NIE TUTAJ ODBYWA SIE POMIAR CZASU
 * pliki byly zapisywane do xml przy uzyciu biblioteki pugixml - polecam*/

/*przyciski wyscigowe:
 * next - jesli ktos nie moze jechac mozna go przesunac w ten sposob na dol listy
 * ready - przesyla 1 zespol z listy do wyscigu, rozpoczyna pingowanie czujnikow
 * start - zaczyna wyscig (tylko jesli poprawnie zakonczono pingowanie!!
 * stop - awaryjne przerwanie wyscigu (powiedzmy ktos nie mogl ukonczyc)
 * walkover - usuniecie z kolejki do wyscigu (usuwa pierwszy zespol na gorze) */

/*przyciski obsugi danych
 * add, delete, save - nie trzeba tlumaczyc
 * load session- wczytuje pelen plik z ostatnich zawodow (zespoly + czasy)
 * load teams - wczytuje tylko zespoly */

/*tworzenie kolejnki
 * zaznacz kategorie jakie maja zostac dodane i dodaj przyciskiem add round

/*poza glownym okne istnieje jeszcze:
 * okno wyscigu (racewindow) ,
 * okno wynikow (resultswindow) ,
 * okno dodawania zespolu (addteam) */


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    /* w Qt funkcjonuje mechanizmy slotow i sygnalow , sygnaly sa emitowane poprzez "emit"
     * a odbierane w slotach, nalezy polaczyc slota z sygnalem poprzez "connect"
     * laczenie sygnalow ze slotami odbywa sie w konstruktorach
     * wiecej na stronie http://doc.qt.io/qt-4.8/signalsandslots.html */

    //slot odbierajacy dane z okna tworzenia nowego zespolu
   void receiveteamdata(const QString &team_name, const QString &car_name, const QString &category);

   //slot odbierajacy dane po skonczonym wyscigu
    void receive_results_of_race(const team &mTeam,const int &mseconds);

    //slot zwiazany z serial_portem , wykorzystywany do wykrywania bledow polaczenia
    void receive_serialport_status(const int &PortStatus);

signals:

    /*sygnal wysylajacy dane do okna wyscigowego
     * po kolei : kto teraz jedzie (pelne dane) ,
     *                      kto ma sie szykowac (tylko nazwa), ilosc aktywnych czujek, ile kolek */
   void sendRaceWindowData(const team &mTeam,
                           const QString &nextTeam, const int &mSensorCount , const int &mLapsCount);


   void send_final_position(const int &position);

   /*sygnal wysylajacy dane do okna wynikow : trzy nastepne zespoly, tabela 1 kategorii
    *                                   tabela 2 katerogii, tabela 3 kategorii */
   void send_results_for_Public(const QListWidget *nextTeamList,const QTableWidget *,
                                const QTableWidget*,const QTableWidget*);

   /*sygnal wysylajacy komentarz (informacje) do publicznosci/zespolow - do okna wynikow*/
   void send_comment_for_Public(const QString &comment);

   /*sygnal do okna wyscigu - rozpoczyna wyscig (tylko jesli pingowanie przy ready przebieglo poprawnie*/
   void begin_race();


private slots:


    void on_nextButton_clicked(); 
    void on_walkoverButton_clicked();
    void on_addteamButton_clicked();
    void on_addroundButton_clicked();

    void delete_team_from_waiting_list();


    void set_list_item_color(QListWidgetItem *); //odroznianie kategorii po kolorach
    void set_item_untouchable(QListWidgetItem *); //trzy pierwsze sa nietykalne (w kolejce)
    void load_session_teams();
    int get_position_of_last_team();

        void save_quele();
        void save_teams();
        void load_clear_teams();
        void load_quele();

    team get_team(QString);

    void on_readyButton_pressed();
    void on_deleteTeamButton_clicked();
    void on_loadteamsButton_clicked();
    void on_load_session_Button_clicked();
    void on_save_session_Button_clicked();
    void on_resultsWindowButton_clicked();
    void on_messageEdit_returnPressed();
    void on_startButton_pressed();
    void on_stopButton_pressed();
    void on_messageEdit_editingFinished();


private:
    Ui::MainWindow *ui;

    //trzy kategorie
    category RC_ST;
    category RC;
    category AUTONOM;

    //trzy podrzedne okna
    addteam *mDialog;
    racewindow *mRaceWindow=new racewindow(this);
    resultswindow *mResultsWindow=new resultswindow(this);

    //flagi
    bool is_race_started=false; //nie mozna dwa razy zaczac wyscigu (bez skonczenia)
    bool is_loading_enabled=true; //nie mozna dwa razy wczytac danych



};

#endif // MAINWINDOW_H
