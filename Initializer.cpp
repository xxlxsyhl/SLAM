//
// Created by yuhailin on 2018/12/2.
//

#include "Initializer.h"

Initializer::Initializer(Map *pMap, LocalMap *pLocalMap)
{
    mpMap = pMap;
    mpLocalMap = pLocalMap;
    mpLocalizer = new Localizer(mpMap);
}

int Initializer::Initialize(const Frame &frame)
{
    int ret = mpLocalizer->Localize(frame);
    if(ret == 1)
    {
        //initialize local map

    }
}