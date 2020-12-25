#ifndef BALLTRACKER_H
#define BALLTRACKER_H

#include <ros/ros.h>

#include <mainwindow.h>

using namespace std;

class TrackingGUI
{
public:
    TrackingGUI(int argc, char *argv[]);
private:
    void process_cb(std::shared_ptr<five_axis_tracking::tracking> msg);

    std::shared_ptr<ros::NodeHandle> nh_;
    ros::Publisher param_pub_;
    std::shared_ptr<MainWindow> w_;

    const int hu_ = 66;
    const int hl_ = 33;
    const int su_ = 264;
    const int sl_ = 86;
    const int vu_ = 295;
    const int vl_ = 23;

    const int hough_min_dist_ = 15; //Detect the minimum distance between the centers of the circles
    const int hough_param_1_ = 253; //High threshold of the Canny edge function
    const int hough_param_2_ = 17; // center detection threshold.
};

#endif // BALLTRACKER_H
