#ifndef DBHELPER_H
#define DBHELPER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QFileInfo>
#include <QList>
#include "pointentity.h"
#include "pictureentity.h"
#include <string>
#include <QString>
#include "profileentity.h"

class DBHelper : public QObject
{
    Q_OBJECT
public:
    explicit DBHelper(QObject *parent = nullptr);

    /**
     * @brief open database connection
     * @brief open
     * @return
     */
    bool open();


    /**
     * @brief close database connection
     * @brief close
     */
    void close();


    /**
     * @brief register new user
     * @brief addUser
     * @param username
     * @param password
     * @return
     */
    int addUser(QString username, QString password);


    /**
     * @brief find user and return id
     *
     * @brief checkUser
     * @param username
     * @param password
     * @return userId
     */
    int checkUser(QString username, QString password);


    /**
     * @brief add new mark point
     * @brief addPoint
     * @param userId
     * @param latitude
     * @param longitude
     * @return
     */
    int addPoint(int userId, double latitude, double longitude, QString name);


    /**
     * @brief get name of point by pointId
     * @brief getName
     * @param pointId
     * @return name
     */

    QString getName(int pointId);

    /**
     * @brief get point list by userId
     * @brief getPointList
     * @param userId
     * @return
     */

    QList<PointEntity> getPointList(int userId);


    /**
     * @brief add picture data by pointId
     * @brief addPicture
     * @param pointId
     * @param fileName
     * @param fileData
     * @return
     */
    int addPicture(int pointId, QString fileName, QByteArray fileData);


    /**
     * @brief get picture list by pointId
     * @brief getPictureList
     * @param pointId
     * @return
     */
    QList<PictureEntity> getPictureList(int pointId);


    /**
     * @brief Add user post by pointId
     * @brief addPost
     * @param pointId
     * @param postText
     * @return
     */
    int addPost(int pointId, QString postText);


    /**
     * @brief logical delete picture by id
     * @brief deletePicture
     * @param id
     * @return
     */
    bool deletePicture(int id);


    /**
     * @brief add Profile
     * @brief addProfile
     * @param userId, name, Gender, Tagline, fileName, Location
     * @return
     */
    int addProfile(int userID, QString name, int Gender, QString Tagline, QString fileName, QString Location);


    /**
     * @brief check if Profile existed
     * @brief checkProfile
     * @param userID
     * @return
     */
    int checkProfile(int userID);


    /**
     * @brief Update Profile
     * @brief updateProfile
     * @param userID, name, Gender, Tagline, fileName, Location
     * @return
     */
    int updateProfile(int userID, QString name, int Gender, QString Tagline, QString fileName, QString Location);

    /**
     * @brief Get Profile
     * @brief getProfile
     * @param userID
     * @return ProfileEntity
     */
    ProfileEntity getProfile(int userID);
signals:

private:
    /**
     * @brief if database not exist, create new database and init tables.
     * @brief initData
     */
    void initData();

    QSqlDatabase db;
    /**
     * @brief database filename, default is 'data.db'
     * @brief fileName
     */
    QString fileName;

};

#endif // DBHELPER_H
