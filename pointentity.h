#ifndef POINTENTITY_H
#define POINTENTITY_H

class PointEntity
{
public:
    PointEntity();
    PointEntity(int id, int userId, double latitude, double longitude,  long createTime, bool deleted);

    int getId() const;
    int getUserId() const;
    double getLatitude() const;
    double getLongitude() const;
    int getCreateTime() const;
    bool getDeleted() const;

private:
    int id;
    /**
     * reference to UserEntity id
     * @brief userId
     */
    int userId;
    double latitude;
    double longitude;
    long createTime;
    bool deleted;
};

#endif // POINTENTITY_H
