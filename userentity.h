#ifndef USERENTITY_H
#define USERENTITY_H

#include <QString>

/**
 * @brief Class User Entity
 * @param
 * @return
 */

class UserEntity
{
public:

    /**
     * @brief Initialize User Entity
     * @param
     * @return
     */
    UserEntity();

    /**
     * @brief Intitalize User Enity
     * @param id, username, password, createTime, deleted
     * @return
     */
    UserEntity(int id, const QString &username, const QString &password, long createTime, bool deleted);

    /**
     * @brief getId of the user
     * @param
     * @return Id
     */
    int getId() const;

    /**
     * @brief get Username
     * @param
     * @return username
     */
    const QString &getUsername() const;

    /**
     * @brief get Password
     * @param
     * @return Password
     */
    const QString &getPassword() const;

    /**
     * @brief get created time
     * @param
     * @return time greated
     */
    int getCreateTime() const;

    /**
     * @brief delete the user
     * @param
     * @return True if user got deleted, false otherwise
     */
    bool getDeleted() const;

private:

    /**
     * @brief ID of the username
     */
    int id;

    /**
     * @brief username of the account
     */
    QString username;

    /**
     * @brief password of the account
     */
    QString password;

    /**
     * @brief time account is created
     */
    int createTime;

    /**
     * @brief indicated account is deleted or not
     */
    bool deleted;
};

#endif // USERENTITY_H
