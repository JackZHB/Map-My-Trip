#include "dbhelper.h"
#include <QDebug>
#include <QDateTime>
#include <iostream>

DBHelper::DBHelper(QObject *parent)
    : QObject{parent}
{
    fileName = "data.db";
}

bool DBHelper::open()
{
    bool needInitData = !QFileInfo::exists(fileName);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(fileName);
    if(!db.isOpen()) {
        if(!db.open()) {
            qDebug()<<"open database failed"<<db.lastError();
            return false;
        }
    }
    if(needInitData) {
        initData();
    }
    return true;
}

void DBHelper::close()
{
    db.close();
}

int DBHelper::addUser(QString username, QString password)
{
    QSqlQuery query;
    query.prepare("insert into t_user(username,password,create_time) values(:username,:password,:createTime)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.bindValue(":createTime", QDateTime::currentDateTime());
    query.exec();
    return query.lastInsertId().toInt();
}

int DBHelper::checkUser(QString username, QString password)
{
    QSqlQuery query;
    query.prepare("select id, username,password,create_time,deleted from t_user where deleted=0 and username=:username and password=:password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.exec();
    if(query.next()) {
        return query.value(0).toInt();
    } else {
        return -1;
    }
}

int DBHelper::addPoint(int userId, double latitude, double longitude, QString name)
{
    QSqlQuery query;
    query.prepare("insert into t_point(user_id, latitude, longitude, create_time,name) values(:userId, :latitude, :longitude, :createTime, :name)");
    query.bindValue(":userId", userId);
    query.bindValue(":latitude", latitude);
    query.bindValue(":longitude", longitude);
    query.bindValue(":createTime", QDateTime::currentDateTime());
    query.bindValue(":name", name);
    query.exec();
    return query.lastInsertId().toInt();
}

QString DBHelper::getName(int userId)
{
    QSqlQuery query;
    query.prepare("select id, user_id, latitude, longitude, create_time, deleted from t_point where deleted=0 and user_id=:userId");
    query.bindValue(":userId", userId);
    query.exec();

    return query.value(6).toString();
}

QList<PointEntity> DBHelper::getPointList(int userId)
{
    QSqlQuery query;
    query.prepare("select id, user_id, latitude, longitude, create_time, deleted from t_point where deleted=0 and user_id=:userId");
    query.bindValue(":userId", userId);
    query.exec();

    QList<PointEntity> list;
    while(query.next()) {
        PointEntity entity(query.value(0).toInt(),
                           query.value(1).toInt(),
                           query.value(2).toDouble(),
                           query.value(3).toDouble(),
                           query.value(4).toInt(),
                           query.value(5).toInt(),
                           query.value(6).toString());
        list.append(entity);
    }
    return list;
}

int DBHelper::addPicture(int pointId, QString fileName, QByteArray fileData)
{
    QSqlQuery query;
    query.prepare("insert into t_picture(point_id, file_name, file_data, create_time) values(:pointId, :fileName, :fileData, :createTime)");
    query.bindValue(":pointId", pointId);
    query.bindValue(":fileName", fileName);
    query.bindValue(":fileData", fileData);
    query.bindValue(":createTime", QDateTime::currentDateTime());
    query.exec();

    return query.lastInsertId().toInt();
}

QList<PictureEntity> DBHelper::getPictureList(int pointId)
{
    QSqlQuery query;
    query.prepare("select id, point_id, file_name, file_data, create_time, deleted from t_picture where deleted=0 and point_id=:pointId order by create_time desc");
    query.bindValue(":pointId", pointId);
    query.exec();

    QList<PictureEntity> list;
    while(query.next()) {
        PictureEntity entity(query.value(0).toInt(),
                             query.value(1).toInt(),
                             query.value(2).toString(),
                             query.value(3).toByteArray(),
                             query.value(4).toInt(),
                             query.value(5).toInt());
        list.append(entity);
    }
    return list;
}

bool DBHelper::deletePicture(int id)
{
    QSqlQuery query;
    query.prepare("update t_picture set deleted=1 where id=:id");
    query.bindValue(":id", id);
    query.exec();
    return query.numRowsAffected()>0;
}

void DBHelper::initData()
{
    // init t_user
    QSqlQuery result = db.exec("CREATE TABLE t_user ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT,"
            "username TEXT(128),"
            "password INTEGER,"
            "create_time INTEGER,"
            "deleted INTEGER DEFAULT (0)"
            ");");
    qDebug()<<"create t_user"<<result.numRowsAffected();

    // init t_point
    result = db.exec("CREATE TABLE t_point ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "user_id INTEGER ,"
               "longitude NUMERIC,"
               "latitude NUMERIC,"
               "create_time INTEGER,"
               "deleted INTEGER DEFAULT (0),"
               "name TEXT (128)"
               ");");
    qDebug()<<"create t_point"<<result.numRowsAffected();

    // init t_picture
    result = db.exec("CREATE TABLE t_picture ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "point_id INTEGER ,"
               "file_name TEXT(1024),"
               "file_data BLOB,"
               "create_time INTEGER,"
               "deleted INTEGER DEFAULT (0)"
               ");");
    qDebug()<<"create t_picture"<<result.numRowsAffected();

}
