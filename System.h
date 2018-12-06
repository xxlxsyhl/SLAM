//
// Created by yuhailin on 2018/12/1.
//

#ifndef SLAM_SYSTEM_H
#define SLAM_SYSTEM_H

#include <opencv2/opencv.hpp>

#include "Map.h"
#include "Frame.h"
#include "Tracking.h"
#include "LocalMap.h"
#include "Initializer.h"

class System
{
public:
    System();

    int Run(const cv::Mat im, const double timestamp);

private:
    Map* mpMap;
    LocalMap* mpLocalMap;
    Tracking* mpTracker;
    Initializer* mpInitializer;
};


#endif //SLAM_SYSTEM_H
