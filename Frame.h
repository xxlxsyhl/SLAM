//
// Created by yuhailin on 2018/12/1.
//

#ifndef SLAM_FRAME_H
#define SLAM_FRAME_H

#include <opencv2/opencv.hpp>

class Frame
{
public:
    Frame(const cv::Mat im, const double timestamp);
};


#endif //SLAM_FRAME_H
