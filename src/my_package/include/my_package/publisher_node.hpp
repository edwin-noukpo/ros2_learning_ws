/*
** publisher_node.hpp for ros2_humble_ws [WSL: Ubuntu-22.04] in /home/edwin/ros2_humble_ws/my_package/include/my_package
**
** Made by dirennoukpo
** Login   <diren.noukpo@epitech.eu>
**
** Started on  undefined Feb 22 3:09:04 PM 2026 dirennoukpo
** Last update Tue Feb 23 9:47:14 AM 2026 dirennoukpo
*/

#pragma once

#include "rclcpp/rclcpp.hpp"
#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include "std_msgs/msg/string.hpp"

class pNode : public rclcpp::Node {
    public:
        pNode();
        ~pNode() = default;
    private:
        void timerCallBack();
        size_t _count;
        rclcpp::TimerBase::SharedPtr _p_timer;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr _publisher_node;
};

