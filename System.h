//
// Created by yuhailin on 2018/12/1.
//

#ifndef SLAM_SYSTEM_H
#define SLAM_SYSTEM_H

#include <opencv2/opencv.hpp>

class System
{
public:
    System();
    int Track(cv::Mat im, double timestamp);
};


#endif //SLAM_SYSTEM_H
