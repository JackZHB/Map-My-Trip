#ifndef MAPDIALOG_H
#define MAPDIALOG_H

#include <QDialog>
#include <QVariant>
#include "dbhelper.h"

namespace Ui {
class MapDialog;
}

class MapDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MapDialog(int userId, QWidget *parent = nullptr);
    ~MapDialog();

    /**
     * refresh all mark points on map
     * @brief updatePointList
     */
    void updatePointList();

signals:
    /**
     * notify map to add new mark point.
     * @brief doAddPoint
     * @param id
     * @param latitude
     * @param longitude
     */
    void doAddPoint(QVariant id, QVariant latitude, QVariant longitude);

private slots:
    /**
     * invoked by map when add point.
     * @brief addPoint
     * @param latitude
     * @param longitude
     */
    void addPoint(QVariant latitude, QVariant longitude);
    /**
     * invoked by map when mark point clicked.
     * @brief pointClicked
     * @param pointId
     */
    void pointClicked(QVariant pointId);

private:
    Ui::MapDialog *ui;
    DBHelper helper;
    /**
     * current userId
     * @brief userId
     */
    int userId;
};

#endif // MAPDIALOG_H
