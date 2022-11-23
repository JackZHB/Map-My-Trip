#include "pointentity.h"

PointEntity::PointEntity()
{

}

int PointEntity::getId() const
{
    return id;
}

int PointEntity::getUserId() const
{
    return userId;
}

double PointEntity::getLatitude() const
{
    return latitude;
}


double PointEntity::getLongitude() const
{
    return longitude;
}

int PointEntity::getCreateTime() const
{
    return createTime;
}

bool PointEntity::getDeleted() const
{
    return deleted;
}

PointEntity::PointEntity(int id, int userId, double latitude, double longitude,  long createTime, bool deleted) : id(id),
    userId(userId),
    latitude(latitude),
    longitude(longitude),
    createTime(createTime),
    deleted(deleted)
{}
