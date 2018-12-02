//
// Created by yuhailin on 2018/12/1.
//

#ifndef SLAM_TRACKING_H
#define SLAM_TRACKING_H

#include "Frame.h"
#include "LocalMap.h"

class Tracking
{
public:
    Tracking(LocalMap* pLocalMap);
    int Run(const Frame& frame);

private:
    LocalMap* mpLocalMap;
};


#endif //SLAM_TRACKING_H
