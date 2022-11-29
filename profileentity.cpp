#include "profileentity.h"

/**
 * @brief Class Profile Entity
 * @brief Initializing profile entity
 */
ProfileEntity::ProfileEntity()
{

}

/**
 * @brief Initializing profile entity
 * @param userID, Name, Gender, Tagline, fileName, Location, createTime
 * @return
 */
ProfileEntity::ProfileEntity(int userID, QString Name, int Gender, QString Tagline, QString fileName, QString Location, int createTime) :userID(userID),
    Name(Name),
    Gender(Gender),
    Tagline(Tagline),
    fileName(fileName),
    Location(Location),
    createTime(createTime)
{}

/**
 * @brief get userID
 * @param
 * @return userID
 */
int ProfileEntity::getuserID() const
{
    return userID;
}

/**
 * @brief get Name
 * @param
 * @return Name
 */
QString ProfileEntity::getName() const
{
    return Name;
}

/**
 * @brief get Location
 * @param
 * @return Location
 */
QString ProfileEntity::getLocation() const
{
    return Location;
}

/**
 * @brief get Tagline
 * @param
 * @return Tagline
 */
QString ProfileEntity::getTagline() const
{
    return Tagline;
}

/**
 * @brief get Gender
 * @param
 * @return Gender
 */
int ProfileEntity::getGender() const
{
    return Gender;
}

/**
 * @brief get File name
 * @param
 * @return File name
 */
const QString &ProfileEntity::getFileName() const
{
    return fileName;
}

/**
 * @brief set new name
 * @param name
 * @return
 */
void ProfileEntity::newName (QString name)
{
    Name = name;
}

/**
 * @brief get created time
 * @param
 * @return Created time
 */
int ProfileEntity::getCreateTime() const
{
    return createTime;
}

/**
 * @brief set new Gender
 * @param Gender
 * @return
 */
void ProfileEntity::newGender(int gender)
{
    Gender = gender;
}

/**
 * @brief set new Location
 * @param Location
 * @return
 */
void ProfileEntity::newLocation (QString location)
{
    Location = location;
}

/**
 * @brief set new Tagline
 * @param Tagline
 * @return
 */
void ProfileEntity::newTagline(QString tagline)
{
    Tagline = tagline;
}

/**
 * @brief set new File name
 * @param File name
 * @return
 */
void ProfileEntity::newfileName(QString filename)
{
    fileName = filename;
}
