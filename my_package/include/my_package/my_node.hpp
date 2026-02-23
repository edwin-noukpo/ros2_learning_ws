/*
** my_node.hpp for ros2_humble_ws [WSL: Ubuntu-22.04] in /home/edwin/ros2_humble_ws/my_package/include/my_package
**
** Made by dirennoukpo
** Login   <diren.noukpo@epitech.eu>
**
** Started on  Sat Feb 21 11:10:20 PM 2026 dirennoukpo
** Last update Sun Feb 21 11:24:18 PM 2026 dirennoukpo
*/

#pragma once

#include "rclcpp/rclcpp.hpp"

class myNode : public rclcpp::Node
{
    public:
        myNode();
        ~myNode() = default;
        void count();
    private:
};
