//
// Created by yuhailin on 2018/12/5.
//

#ifndef HLSLAM_KEYFRAME_H
#define HLSLAM_KEYFRAME_H

#include <vector>
#include <fstream>
#include "Map.h"
#include "MapPoint.h"

class MapPoint;
class Map;

class KeyFrame
{
public:
    typedef unsigned int MapPointIndex;

public:
    KeyFrame();

    void Save(std::ofstream& out) const;
    void Load(std::ifstream& in);

private:
    std::vector<MapPoint*> mvpMapPoints;
    std::vector<cv::Point2d> mvPoint2ds;
    cv::Mat mDescriptors;
    cv::Mat mK, mR, mt;

    Map* mpMap;
};

#endif //HLSLAM_KEYFRAME_H
