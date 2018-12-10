//
// Created by yuhailin on 2018/12/1.
//
#include <fstream>
#include "Map.h"

Map::Map():mbInited(false)
{}

Map::Map(const std::string &filename)
{
    Load(filename);
}

std::vector<MapPoint*> Map::GetAllMapPoints()
{
    return std::vector<MapPoint*>(mvpMapPoints.begin(), mvpMapPoints.end());
}

std::vector<KeyFrame*> Map::GetAllKeyFrames()
{
    return std::vector<KeyFrame*>(mvpKeyFrames.begin(), mvpKeyFrames.end());
}

void Map::Save(const std::string &filename) const
{
    std::ofstream out(filename, std::ios::binary);
    if(!out.is_open())
    {
        std::cout<<"Map::Save:  file path error!"<<std::endl;
        exit(1);
    }
    MapPointIndex mpsize = mvpMapPoints.size();
    KeyFrameIndex kfsize = mvpKeyFrames.size();

    out.write((char*)&mpsize, sizeof(MapPointIndex));
    out.write((char*)&kfsize, sizeof(KeyFrameIndex));

    //MapPoints
    std::for_each(mvpMapPoints.begin(), mvpMapPoints.end(), [&out](const MapPoint* pMP){
        pMP->Save(out);
    });

    //KeyFrames
    std::for_each(mvpKeyFrames.begin(), mvpKeyFrames.end(), [&out](const KeyFrame* pKF){
        pKF->Save(out);
    });
}


void Map::Load(const std::string &filename)
{
    std::ifstream in(filename, std::ios::binary);
    if(!in.is_open())
    {
        std::cout<<"Map::Load:  file path error!"<<std::endl;
        exit(1);
    }

    MapPointIndex mpsize = 0;
    KeyFrameIndex kfsize = 0;
    in.read((char*)&mpsize, sizeof(MapPointIndex));
    in.read((char*)&kfsize, sizeof(KeyFrameIndex));
    mvpMapPoints.resize(mpsize, nullptr);
    mvpKeyFrames.resize(kfsize, nullptr);

    for(auto it = mvpMapPoints.begin(); it != mvpMapPoints.end(); it++)
    {
        *it = new MapPoint(this);
    }

    for(auto it = mvpKeyFrames.begin(); it != mvpKeyFrames.end(); it++)
    {
        *it = new KeyFrame(this);
    }

    //MapPoints
    std::for_each(mvpMapPoints.begin(), mvpMapPoints.end(), [&in](MapPoint* pMP){
        pMP->Load(in);
    });

    //KeyFrames
    std::for_each(mvpKeyFrames.begin(), mvpKeyFrames.end(), [&in](KeyFrame* pKF){
        pKF->Load(in);
    });

    mbInited = true;
}

bool Map::IsInitialized()
{
    return mbInited;
}

Map::MapPointIndex Map::GetMapPointIndex(const MapPoint *const pMP) const
{
    MapPointIndex mpidx = 0;
    for(auto it = mvpMapPoints.begin(); it != mvpMapPoints.end(); it++, mpidx++)
    {
        if(pMP == *it) return mpidx;
    }
    return mpidx;
}


Map::KeyFrameIndex Map::GetKeyFrameIndex(const KeyFrame *const pKF) const
{
    KeyFrameIndex kfidx = 0;
    for(auto it = mvpKeyFrames.begin(); it != mvpKeyFrames.end(); it++, kfidx++)
    {
        if(pKF == *it)  return kfidx;
    }
    return kfidx;
}

MapPoint* Map::GetMapPoint(const Map::MapPointIndex mpidx) const
{
    return mvpMapPoints[mpidx];
}

KeyFrame* Map::GetKeyFrame(const Map::KeyFrameIndex kfidx) const
{
    return mvpKeyFrames[kfidx];
}