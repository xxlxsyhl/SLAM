cmake_minimum_required(VERSION 3.12)
project(hlslam)

SET(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 14)
set(LIBRARY_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/lib)

find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(Pangolin REQUIRED)

include_directories(
    ${PROJECT_SOURCE_DIR}
    ${EIGEN3_INCLUDE_DIR}
    ${OPENCV_INCLUDE_DIR}
)

set(SRC_BOW
    BowVector.cpp
    Database.cpp
    DescManip.cpp
    FeatureVector.cpp
    QueryResults.cpp
    quicklz.c
    ScoringObject.cpp
    Vocabulary.cpp
)

set(SRC_SLAM
    System.cpp
    Map.cpp
    Frame.cpp
    KeyFrame.cpp
    Tracking.cpp
    LocalMap.cpp
    Initializer.cpp
    Localizer.cpp
    MapPoint.cpp
    Matcher.cpp
    Viewer.cpp
)

add_library(${PROJECT_NAME} ${SRC_SLAM} ${SEC_BOW})

target_link_libraries(${PROJECT_NAME}
    ${OpenCV_LIBS}
    ${EIGEN3_LIBS}
    ${Pangolin_LIBRARIES}
)

add_executable(test sample/main.cpp)
target_link_libraries(test ${PROJECT_NAME})