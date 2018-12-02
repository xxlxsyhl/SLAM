//
// Created by yuhailin on 2018/12/1.
//

#include "Tracking.h"

Tracking::Tracking(LocalMap* pLocalMap)
{
    mpLocalMap = pLocalMap;
}

int Tracking::Run(const Frame &frame)
{
    return 1;
}