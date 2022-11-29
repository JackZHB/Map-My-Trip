#ifndef PROFILEENTITY_H
#define PROFILEENTITY_H

#include <QString>
#include <QBitArray>

/**
 * @brief Class Profile Entity
 */
class ProfileEntity
{
public:

    /**
     * @brief Inititializing profile entity
     */
    ProfileEntity();

    /**
     * @brief Initializing profile entity
     * @param userID, Name, Gender, Tagline, fileName, Location, createTime
     * @return
     */
    ProfileEntity(int userID, QString Name, int Gender, QString Tagline, QString fileName, QString Location, int createTime);

    /**
     * @brief get userID
     * @param
     * @return userID
     */
    int getuserID() const;

    /**
     * @brief get Name
     * @param
     * @return Name
     */
    QString getName() const;

    /**
     * @brief get Location
     * @param
     * @return Location
     */
    QString getLocation() const;

    /**
     * @brief get Tagline
     * @param
     * @return Tagline
     */
    QString getTagline() const;

    /**
     * @brief get Gender
     * @param
     * @return Gender
     */
    int getGender() const;

    /**
     * @brief get File name
     * @param
     * @return File name
     */
    const QString &getFileName() const;

    /**
     * @brief get created time
     * @param
     * @return Created time
     */
    int getCreateTime() const;

    /**
     * @brief set new name
     * @param name
     * @return
     */
    void newName(QString);

    /**
     * @brief set new Location
     * @param Location
     * @return
     */
    void newLocation(QString);

    /**
     * @brief set new Tagline
     * @param Tagline
     * @return
     */
    void newTagline(QString);

    /**
     * @brief set new Gender
     * @param Gender
     * @return
     */
    void newGender(int);

    /**
     * @brief set new File name
     * @param File name
     * @return
     */
    void newfileName(QString);

private:
    /**
     * @brief userID
     */
    int userID;

    /**
     * @brief Name
     */
    QString Name;

    /**
     * @brief Gender
     */
    int Gender;

    /**
     * @brief Tagline
     */
    QString Tagline;

    /**
     * @brief fileName
     */
    QString fileName;

    /**
     * @brief Location
     */
    QString Location;

    /**
     * @brief created Time
     */
    int createTime;
};

#endif // PROFILEENTITY_H
