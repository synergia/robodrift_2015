#ifndef CATEGORY_H
#define CATEGORY_H

#include <QVector>
#include <QString>
#include "team.h"

class category
{

public:
    category();

    //kategoria zawiera spis wszystkich zespolow
    QVector <team*> Teams;



};

#endif // CATEGORY_H
