//
// Created by yuhailin on 2018/12/7.
//

#ifndef HLSLAM_VIEWER_H
#define HLSLAM_VIEWER_H

#include <pangolin/pangolin.h>
#include "Map.h"
#include "MapPoint.h"
#include "KeyFrame.h"

class Viewer
{
public:
    Viewer(Map* pMap);

    void Run();

protected:
    void DrawMapPoints();

private:
    Map* mpMap;

    int mWinHeight, mWinWidth;
    float mViewpointX, mViewpointY, mViewpointZ, mViewpointF;
};


#endif //HLSLAM_VIEWER_H
