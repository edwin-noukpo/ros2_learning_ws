/*
** s_node.hpp for ros2_humble_ws [WSL: Ubuntu-22.04] in /home/edwin/ros2_humble_ws/my_package/include/my_package
**
** Made by dirennoukpo
** Login   <diren.noukpo@epitech.eu>
**
** Started on  undefined Feb 22 3:09:14 PM 2026 dirennoukpo
** Last update Mon Feb 22 10:38:02 PM 2026 dirennoukpo
*/

#pragma once
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <memory>

class sNode : public rclcpp::Node {
    public:
        sNode();
        ~sNode() = default;
    private:
        void topicCallBack(const std_msgs::msg::String &msg) const;
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr _subscriber_node;
};
