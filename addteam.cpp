#include "addteam.h"
#include "ui_addteam.h"
#include <QMessageBox>

addteam::addteam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addteam)
{
    ui->setupUi(this);
     setWindowTitle("ADD TEAM");
}

addteam::~addteam()
{
    delete ui;
}

void addteam::on_buttonBox_accepted()
{
    if(!ui->teamnamelineEdit->text().isEmpty() && !ui->carnamelineEdit->text().isEmpty())
       emit this->sendteamdata(ui->teamnamelineEdit->text(),ui->carnamelineEdit->text(),ui->categorycomboBox->currentText());
    else QMessageBox::warning(this,"WARNING","EMPTY PARAMETER - ADD TEAM AGAIN");
}
