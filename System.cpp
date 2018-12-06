//
// Created by yuhailin on 2018/12/1.
//

#include "System.h"

System::System()
{
    std::cout<<"SLAM CopyRigth @ HailinYu Version 1.0! \nSystem runing ..."<<std::endl;

    mpMap = new Map();
    mpLocalMap = new LocalMap();
    mpTracker = new Tracking(mpLocalMap);
    mpInitializer = new Initializer(mpMap, mpLocalMap);
}

int System::Run(const cv::Mat im, const double timestamp)
{
    Frame frame(im, timestamp);

    if(mpLocalMap->IsInitilized())
    {
        mpInitializer->Initialize(frame);
        return 1;
    }

    mpTracker->Run(frame);

    return 1;
}