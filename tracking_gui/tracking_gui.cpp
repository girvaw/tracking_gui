#include <QApplication>

#include <tracking_gui.h>

#include <iostream>
#include <string>

TrackingGUI::TrackingGUI(int argc, char *argv[])
{
    ros::init(argc, argv, "publisher");
    nh_ = std::make_shared<ros::NodeHandle>();
    param_pub_ = nh_->advertise<five_axis_tracking::tracking>("tracking_params", 1000);
    ros::Rate loop_rate(10);

    QApplication a(argc, argv);
    std::vector<int> in_range = {hu_, hl_, su_, sl_, vu_, vl_, hough_min_dist_, hough_param_1_, hough_param_2_};
    w_ = std::make_shared<MainWindow>(nullptr, in_range, std::bind(&TrackingGUI::process_cb, this, std::placeholders::_1));
    w_->show();
    a.exec();
}

void TrackingGUI::process_cb(std::shared_ptr<five_axis_tracking::tracking> msg)
{
    if (ros::ok())
    {
      param_pub_.publish(*msg.get());

      ros::spinOnce();
    }
}
