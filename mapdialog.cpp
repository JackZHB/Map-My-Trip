#include "mapdialog.h"
#include "ui_mapdialog.h"

#include <QQuickItem>
#include <QMenu>
#include <QAction>
#include <QPixmap>

#include "pointentity.h"
#include "picturedialog.h"



MapDialog::MapDialog( int userId, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MapDialog),
    userId(userId)
{
    ui->setupUi(this);
    QPixmap pix(":/information.png");
    ui->label_info->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));

    helper.open();

    QQuickItem *root = ui->quickWidget->rootObject();

    connect(root, SIGNAL(onAddPoint(QVariant, QVariant)), this, SLOT(addPoint(QVariant, QVariant)));
    connect(root, SIGNAL(onPointClicked(QVariant)), this, SLOT(pointClicked(QVariant)));
    connect(this, SIGNAL(doAddPoint(QVariant, QVariant, QVariant)), root, SLOT(doAddPoint(QVariant, QVariant, QVariant)));



    updatePointList();




}




MapDialog::~MapDialog()
{
    delete ui;
    helper.open();
}

void MapDialog::updatePointList()
{
    QList<PointEntity> list = helper.getPointList(userId);
    for(PointEntity entity : list) {
        emit doAddPoint(entity.getId(), entity.getLatitude(), entity.getLongitude());
    }
}

void MapDialog::addPoint(QVariant latitude, QVariant longitude)
{
    int pointId = helper.addPoint(userId, latitude.toDouble(), longitude.toDouble());
    PictureDialog dialog(pointId);
    dialog.setModal(true);
    //dialog.exec();

    emit doAddPoint(pointId, latitude, longitude);


}

void MapDialog::pointClicked(QVariant pointId)
{
    PictureDialog dialog(pointId.toInt());
    dialog.setModal(true);
    dialog.exec();
}


