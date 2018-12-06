//
// Created by yuhailin on 2018/12/5.
//

#include "KeyFrame.h"

KeyFrame::KeyFrame(Map* pMap):mpMap(pMap)
{}

void KeyFrame::Save(std::ofstream &out) const
{
    double K[9];
    double Pose[12];
    for(int row = 0; row != 3; row++)
    {
        for(int col = 0; col != 3; col++)
        {
            K[row*3+col] = mK.at<double>(row,col);
            Pose[row*3+col] = mR.at<double>(row,col);
        }
    }
    Pose[9]  = mt.at<double>(0,0);
    Pose[10] = mt.at<double>(1,0);
    Pose[11] = mt.at<double>(2,0);
    out.write((char*)K, sizeof(double)*9);
    out.write((char*)Pose, sizeof(double)*12);

    Map::MapPointIndex size = mvPoint2ds.size();
    out.write((char*)&size, sizeof(Map::MapPointIndex));

    unsigned char* data = mDescriptors.data;
    for(auto ipt = 0; ipt != size; ++ipt)
    {
        //2dpoint
        double pt[2];
        pt[0] = mvPoint2ds[ipt].x, pt[1] = mvPoint2ds[ipt].y;
        out.write((char*)pt, sizeof(double)*2);
        //descriptor
        out.write((char*)data, sizeof(unsigned char)*32);
        data += mDescriptors.step;
        //map point
        Map::MapPointIndex mpidx = mpMap->GetMapPointIndex(mvpMapPoints[ipt]);
        out.write((char*)&mpidx, sizeof(mpidx));
    }
}

void KeyFrame::Load(std::ifstream &in)
{
    double K[9];
    double Pose[12];
    in.read((char*)K, sizeof(double)*9);
    in.read((char*)Pose, sizeof(double)*12);
    mK.create(3, 3, CV_64FC1);
    mR.create(3, 3, CV_64FC1);
    mt.create(3, 1, CV_64FC1);
    for(int row = 0; row != 3; row++)
    {
        for(int col = 0; col != 3; col++)
        {
            mK.at<double>(row,col) = K[row*3+col];
            mR.at<double>(row,col) = Pose[row*3+col];
        }
    }
    mt.at<double>(0,0) = Pose[9];
    mt.at<double>(1,0) = Pose[10];
    mt.at<double>(2,0) = Pose[11];

    Map::KeyFrameIndex kfSize = 0;
    in.read((char*)&kfSize, sizeof(kfSize));
    mvpMapPoints.resize(kfSize);
    mvPoint2ds.resize(kfSize);
    mDescriptors.create(kfSize, 32, CV_8UC1);
    unsigned char* data = mDescriptors.data;
    for(int ipt = 0; ipt != kfSize; ipt++)
    {
        //point
        double pt[2];
        in.read((char*)pt, sizeof(double)*2);
        mvPoint2ds[ipt] = cv::Point2d(pt[0], pt[1]);
        //descriptor
        in.read((char*)data, sizeof(unsigned char)*32);
        data += mDescriptors.step;
        //map point
        Map::MapPointIndex mpidx = 0;
        in.read((char*)&mpidx, sizeof(mpidx));
        mvpMapPoints[ipt] = mpMap->GetMapPoint(mpidx);
    }
}