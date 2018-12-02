//
// Created by yuhailin on 2018/12/2.
//

#ifndef SLAM_LOCALIZER_H
#define SLAM_LOCALIZER_H

#include "Map.h"

class Localizer
{
public:
    Localizer(Map* pMap);

private:
    Map* mpMap;
};


#endif //SLAM_LOCALIZER_H
