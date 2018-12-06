//
// Created by yuhailin on 2018/12/2.
//

#ifndef SLAM_LOCALIZER_H
#define SLAM_LOCALIZER_H

#include "Map.h"
#include "Frame.h"

class Localizer
{
public:
    Localizer(Map* pMap);

    int Localize(const Frame& frame);

private:
    Map* mpMap;
};


#endif //SLAM_LOCALIZER_H
