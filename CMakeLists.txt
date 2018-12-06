cmake_minimum_required(VERSION 3.12)
project(hlslam)

SET(CMAKE_BUILD_TYPE Release)

set(CMAKE_CXX_STANDARD 14)
set(LIBRARY_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/lib)

find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)

include_directories(
    ${PROJECT_SOURCE_DIR}
    ${EIGEN3_INCLUDE_DIR}
    ${OPENCV_INCLUDE_DIR}
)

set(SRC
    System.cpp
    Map.cpp
    Frame.cpp
    KeyFrame.cpp
    Tracking.cpp
    LocalMap.cpp
    Initializer.cpp
    Localizer.cpp
    MapPoint.cpp
)

add_library(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME}
    ${OpenCV_LIBS}
    ${EIGEN3_LIBS}
)

add_executable(test sample/main.cpp)
target_link_libraries(test ${PROJECT_NAME})