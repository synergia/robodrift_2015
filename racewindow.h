#ifndef RACEWINDOW_H
#define RACEWINDOW_H

#include <QDialog>
#include "team.h"
 #include <QTimer>
#include <QVector>
#include <QtMultimedia/QSound>
#include <QtSerialPort>


/*okno wyscigowe
 * tu odbywa sie pomiar czasu
 * tu odbywa sie komunikacja z masterem od czujnikow
 * odbiera dane przed wyscigiem
 * odsyla rezultaty po wyscigu
 * przechowuje informacje o najlepszych czasach i miedzyczasach w  kazdej kategorii
 * wyswietla obrazek (sponsorzy , organizatorzy etc)
*/

namespace Ui {
class racewindow;
}

class racewindow : public QDialog
{
    Q_OBJECT

public:
    explicit racewindow(QWidget *parent = 0);
    ~racewindow();

private slots:

    //odebranie finalowej pozycji, gdy mainwindow juz ja ustali - tylko w celu wyswietlenia
    void receive_final_position(const int &position);

    //slot odbierajacy dane o kolejnym uczestniku
    void receiveRaceWindowData(const team &mTeam, const QString &nextTeam, const int &rSensorCount, const int &rLapsCount);

    //timer od odliczania (5....4...3..2.1 a takze samego czasu przejazdu)
    void raceTimeTick();

    //przelicza ms na min:sec:msec
    QString race_time_format(int);

   void on_sensorButton_clicked();


    void race_has_began();//slot polaczony z oknem glownym
    void race_has_been_stopped();//slot polaczony z oknem glownym
    void race_safety();//slot polaczony z safety button (jakby czujnik nie zadzialal)

    //wczytuje z pliku najlepsze czasy i miedzyczasy
   void load_last_best_results();
   //zapisuje najlepsze czasy i miedzyczasy
   void save_last_best_results();

   //inicjalizacja komunikacji z masterem RX/TX
   void MasterSerialPort_init();

   //polaczenie z masterem
   void connect_with_master();

   //informacja w przypadku rozlaczenia
     void   master_serial_dc();

     //odebranie danych z mastera
     void master_serial_receive();

signals:
    void send_results_of_race(const team &mTeam ,const int &result);
    void  connect_with_master_return_Message(const int &PortStatus);



private:
    Ui::racewindow *ui;
public:

   int mseconds=0;
   int countdown_mseconds=0;


    int sensor_tick_count=0;
    int sensor_tick_count_MAX=0;
    int mSensorCount=0;
    int mLapsCount=0;

    int lap_number=0;
    int lap_sensor_iteration=0;


    QTimer *raceTimer=new QTimer(this);

    bool is_Mrace_started=false;
    bool is_countdown=false;
    bool is_ping_finished=false;
    bool is_pinging_began=false;

    bool is_falstarted=false;

    QVector <int> best_meanTime_RC_ST;
    QVector <int> best_meanTime_RC;
    QVector <int> best_meanTime_AUTONOM;

    QVector <int> current_meanTime_RC_ST;
    QVector <int> current_meanTime_RC;
    QVector <int> current_meanTime_AUTONOM;

    QVector <QString> current_Graph;
    int current_graph_number=0;


    QVector <int> vector_of_Working_Sensors;

    bool first_team_in_RC_ST=true;
    bool first_team_in_RC=true;
    bool first_team_in_AUTONOM=true;



    int working_sensor_count=0;

    team currentTeam;

    QString fonttemplate = tr("<font color='%1'>%2</font>");

     QSerialPort *MasterSerialPort = new QSerialPort(this);








};

#endif // RACEWINDOW_H
