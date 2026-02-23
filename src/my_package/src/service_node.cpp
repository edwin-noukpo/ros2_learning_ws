/*
** service_node.cpp for ros2_learning_ws [WSL: Ubuntu-22.04] in /home/edwin/ros2_learning_ws/my_package/src
**
** Made by dirennoukpo
** Login   <diren.noukpo@epitech.eu>
**
** Started on  Mon Feb 23 9:50:45 AM 2026 dirennoukpo
** Last update Tue Feb 23 4:22:22 PM 2026 dirennoukpo
*/

#include "../include/my_package/service_node.hpp"

void add(
    const std::shared_ptr<example_interfaces::srv::AddTwoInts::Request> request,
    std::shared_ptr<example_interfaces::srv::AddTwoInts::Response> response
) {
    response->sum = request->a + request->b;
    RCLCPP_INFO(rclcpp::get_logger("server_node"), "Incoming request\na: %ld " "b: %ld",
        request->a,
        request->b
    );
    RCLCPP_INFO(rclcpp::get_logger("server_node"),
        "sending back response: [%ld]",
        (long int)response->sum
    );
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("server_node");
    rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr service = node->create_service<example_interfaces::srv::AddTwoInts>("service_node", &add);
    RCLCPP_INFO(rclcpp::get_logger("service_node"), "Ready to add two ints.");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
