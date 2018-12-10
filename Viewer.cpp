//
// Created by yuhailin on 2018/12/7.
//

#include "Viewer.h"

Viewer::Viewer(Map *pMap):mpMap(pMap)
{
    mWinHeight = 768;
    mWinWidth = 1024;

    mViewpointF = 420;
    mViewpointX = 1;
    mViewpointY = 1;
    mViewpointZ = 1;
}

void Viewer::Run()
{
    pangolin::CreateWindowAndBind("HLSLAM: Map Viewer",1024,768);
    // 3D Mouse handler requires depth testing to be enabled
    glEnable(GL_DEPTH_TEST);

    pangolin::OpenGlRenderState s_cam(
            pangolin::ProjectionMatrix(mWinWidth, mWinHeight, mViewpointF, mViewpointF, 512, 389, 0.1, 1000),
            pangolin::ModelViewLookAt(mViewpointX, mViewpointY, mViewpointZ, 0, 0, 0, 0.0, -1.0, 0.0)
    );

    pangolin::View& d_cam = pangolin::CreateDisplay()
            .SetBounds(0.0, 1.0, 0.0, 1.0, mWinWidth*1.0/mWinHeight)
            .SetHandler(new pangolin::Handler3D(s_cam));

    while( !pangolin::ShouldQuit() )
    {
        // Clear screen and activate view to render into
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //Activate
        d_cam.Activate(s_cam);

        DrawMapPoints();

        // Swap frames and Process Events
        pangolin::FinishFrame();
    }
}

void Viewer::DrawMapPoints()
{
    const std::vector<MapPoint*> &vpMPs = mpMap->GetAllMapPoints();

    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(1.0,1.0,1.0);

    for(size_t i=0, iend=vpMPs.size(); i<iend;i+= 1)
    {
        cv::Vec3d p3d = vpMPs[i]->GetWorldCoord();
        glVertex3d(p3d(0), p3d(1), p3d(2));
    }
    glEnd();

}