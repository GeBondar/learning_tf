#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "my_tf_broadcaster");
  ros::NodeHandle node;
  float radius = 1, velocity = 1;

  tf::TransformBroadcaster br;
  tf::Transform transform;

  ros::Rate rate(10.0);
  while (node.ok()){
    node.getParam("/velocity",velocity);
    node.getParam("/radius",radius);
    transform.setOrigin( tf::Vector3(radius*sin(ros::Time::now().toSec()*velocity), radius*cos(ros::Time::now().toSec()*velocity), 0.0) );
    transform.setRotation( tf::Quaternion(0, 0, 0, 1) );
    br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "turtle1", "carrot1"));
    rate.sleep();
  }
  return 0;
};

