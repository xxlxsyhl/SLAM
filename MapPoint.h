//
// Created by yuhailin on 2018/12/5.
//

#ifndef SLAM_MAPPOINT_H
#define SLAM_MAPPOINT_H

#include <opencv2/opencv.hpp>
#include <fstream>

#include "KeyFrame.h"
#include "Map.h"

class KeyFrame;
class Map;

class MapPoint
{
public:
    typedef unsigned int KeyFrameIndex;

public:
    MapPoint();
    MapPoint(const cv::Vec3d& p3d);

    void Save(std::ofstream& out) const;
    void Load(std::ifstream& in);
private:
    //one point one descriptor
    cv::Vec3d mWorldCoord;
    cv::Mat mDescriptor;    //not necessary
    std::vector<KeyFrame*> mvpKeyFrames;

    Map *mpMap;
};


#endif //SLAM_MAPPOINT_H
