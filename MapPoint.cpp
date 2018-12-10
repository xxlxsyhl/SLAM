//
// Created by yuhailin on 2018/12/5.
//
#include <vector>
#include "MapPoint.h"

MapPoint::MapPoint(Map* pMap):mpMap(pMap)
{}

MapPoint::MapPoint(const cv::Vec3d &p3d): mWorldCoord(p3d)
{}

cv::Vec3d MapPoint::GetWorldCoord()
{
    return mWorldCoord;
}

void MapPoint::Save(std::ofstream &out)const
{
    double data[3];
    data[0] = mWorldCoord(0);
    data[1] = mWorldCoord(1);
    data[2] = mWorldCoord(2);
    out.write((char*)data, sizeof(double)*3);

    int flag = mDescriptor.empty() ? 0 : 1;
    out.write((char*)&flag, sizeof(int));
    //std::cout<<flag<<std::endl;

    if(flag)  out.write((char*)mDescriptor.data, sizeof(unsigned char)*32);

    Map::KeyFrameIndex size  = mvpKeyFrames.size();
    out.write((char*)&size, sizeof(Map::KeyFrameIndex));

    for(auto pkf = mvpKeyFrames.begin(); pkf != mvpKeyFrames.end(); pkf++)
    {
        Map::MapPointIndex mpidx = mpMap->GetKeyFrameIndex(*pkf);
        out.write((char*)&mpidx, sizeof(Map::MapPointIndex));
    }
}

void MapPoint::Load(std::ifstream &in)
{
    double data[3];
    in.read((char*)data, sizeof(double)*3);
    mWorldCoord = cv::Vec3d(data[0], data[1], data[2]);

    int flag = 1;
    in.read((char*)&flag, sizeof(int));

    if(flag)
    {
        mDescriptor.create(1, 32, CV_8UC1);
        in.read((char*)mDescriptor.data, sizeof(unsigned char)*32);
    }

    Map::MapPointIndex mpSize = 0;
    in.read((char*)&mpSize, sizeof(Map::MapPointIndex));
    mvpKeyFrames.resize(mpSize);
    for(auto pkf = mvpKeyFrames.begin(); pkf != mvpKeyFrames.end(); pkf++)
    {
        Map::KeyFrameIndex kfidx = 0;
        in.read((char*)&kfidx, sizeof(Map::KeyFrameIndex));
        (*pkf) = mpMap->GetKeyFrame(kfidx);
    }
}