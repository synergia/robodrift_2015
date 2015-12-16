#ifndef TEAM_H
#define TEAM_H

#include <QString>
#include <QVector>
#include <QImage>
#include <QTime>

#include <QObject>

class team
{


public:

    team();
    QString Team_Name;
    QString Car_Name;
    QVector <QString*> Team_Members; //nieuzywane
    QImage Car_Image; //nieuzywane
    int Best_Race_Time;
    QVector <int> Race_Time;
    QString Category_Name;
};

#endif // TEAM_H
