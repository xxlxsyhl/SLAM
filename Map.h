//
// Created by yuhailin on 2018/12/1.
//

#ifndef SLAM_MAP_H
#define SLAM_MAP_H

#include <vector>
#include <string>
#include "MapPoint.h"
#include "KeyFrame.h"

class KeyFrame;
class MapPoint;

class Map
{
public:
    typedef unsigned int MapPointIndex;
    typedef unsigned int KeyFrameIndex;

public:
    Map();
    Map(const std::string& filename);

    //save
    void Save(const std::string& filename) const;
    void Load(const std::string& filename);

    MapPointIndex GetMapPointIndex(const MapPoint* const pMP) const;
    KeyFrameIndex GetKeyFrameIndex(const KeyFrame* const pKF) const;

    MapPoint* GetMapPoint(const MapPointIndex mpidx) const;
    KeyFrame* GetKeyFrame(const KeyFrameIndex kfidx) const;

    bool IsInitialized();

public:
    std::vector<MapPoint*> mvpMapPoints;
    std::vector<KeyFrame*> mvpKeyFrames;
    bool mbInited;
};

#endif //SLAM_MAP_H
