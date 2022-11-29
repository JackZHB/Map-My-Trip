#include "userentity.h"

/**
 * @brief Initialize User Entity
 * @param
 * @return
 */
UserEntity::UserEntity()
{

}

/**
 * @brief Initialize User Entity
 * @param
 * @return
 */

UserEntity::UserEntity(int id, const QString &username, const QString &password, long createTime, bool deleted) : id(id),
    username(username),
    password(password),
    createTime(createTime),
    deleted(deleted)
{}

/**
 * @brief getId of the user
 * @param
 * @return Id
 */

int UserEntity::getId() const
{
    return id;
}

/**
 * @brief get Username
 * @param
 * @return username
 */
const QString &UserEntity::getUsername() const
{
    return username;
}

/**
 * @brief get Password
 * @param
 * @return Password
 */
const QString &UserEntity::getPassword() const
{
    return password;
}


/**
 * @brief get created time
 * @param
 * @return time greated
 */
int UserEntity::getCreateTime() const
{
    return createTime;
}

/**
 * @brief delete the user
 * @param
 * @return True if user got deleted, false otherwise
 */
bool UserEntity::getDeleted() const
{
    return deleted;
}
