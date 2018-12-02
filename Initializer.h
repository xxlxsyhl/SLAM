//
// Created by yuhailin on 2018/12/2.
//

#ifndef SLAM_INITIALIZER_H
#define SLAM_INITIALIZER_H

#include "Frame.h"
#include "Map.h"
#include "LocalMap.h"
#include "Localizer.h"

class Initializer
{
public:

    Initializer(Map* pMap, LocalMap* pLocalMap);

    int Initialize(const Frame& frame);

private:
    Map* mpMap;
    LocalMap* mpLocalMap;
    Localizer* mpLocalizer;
};


#endif //SLAM_INITIALIZER_H
