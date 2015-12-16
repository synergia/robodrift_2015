#ifndef ADDTEAM_H
#define ADDTEAM_H


/*okno dodawania zespolu*/

#include <QDialog>

namespace Ui {
class addteam;
}

class addteam : public QDialog
{
    Q_OBJECT

public:
    explicit addteam(QWidget *parent = 0);
    ~addteam();


signals:
void sendteamdata(const QString &team_name, const QString &car_name, const QString &category);

private slots:
 void on_buttonBox_accepted();

private:
    Ui::addteam *ui;
};

#endif // ADDTEAM_H
