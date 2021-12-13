#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <tf/transform_broadcaster.h>
#include <string>

tf::Transform transform;
tf::Quaternion q;
std::string prefix;


void pose_callback(const geometry_msgs::PoseStampedPtr &pose)
{
    static tf::TransformBroadcaster br;

    q.setX(pose->pose.orientation.x);
    q.setY(pose->pose.orientation.y);
    q.setZ(pose->pose.orientation.z);
    q.setW(pose->pose.orientation.w);

    transform.setOrigin(tf::Vector3(pose->pose.position.x, pose->pose.position.y, 0.04));
    transform.setRotation(q);

    br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), prefix+"odom", prefix+"base_link"));
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "drive_controller");
    ros::NodeHandle n("~");
    
    n.param<std::string>("tf_prefix", prefix, "");
    prefix += "/";

    ros::Subscriber pose_sub = n.subscribe("/pose", 1, pose_callback);
    ros::Rate loop_rate(100);
    while (ros::ok())
    {
        ros::spinOnce();
        loop_rate.sleep();
    }
}
