/*
** client_node.cpp for ros2_learning_ws [WSL: Ubuntu-22.04] in /home/edwin/ros2_learning_ws/my_package/src
**
** Made by dirennoukpo
** Login   <diren.noukpo@epitech.eu>
**
** Started on  Mon Feb 23 9:50:48 AM 2026 dirennoukpo
** Last update Tue Feb 23 4:47:56 PM 2026 dirennoukpo
*/

#include "../include/my_package/client_node.hpp"

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    if (argc != 3) {
        RCLCPP_INFO(rclcpp::get_logger("client_node"), "usage: add_two_ints_client X Y");
        return 1;
    }
    std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("client_node");
    rclcpp::Client<example_interfaces::srv::AddTwoInts>::SharedPtr client = node->create_client<example_interfaces::srv::AddTwoInts>("service_node");

    auto request = std::make_shared<example_interfaces::srv::AddTwoInts::Request>();
    request->a = atoll(argv[1]);
    request->b = atoll(argv[2]);

    while (!client->wait_for_service(1s)) {
        if (!rclcpp::ok()) {
            RCLCPP_ERROR(rclcpp::get_logger("client_node"), "Interrupted while waiting for the service. Exiting.");
            return 0;
        }
        RCLCPP_INFO(rclcpp::get_logger("client_node"), "service not available, waiting again...");
    }

    auto result = client->async_send_request(request);
    //wait for the result.
    if (rclcpp::spin_until_future_complete(node, result) == rclcpp::FutureReturnCode::SUCCESS)
    {
        RCLCPP_INFO(rclcpp::get_logger("client_node"), "Sum: %ld", result.get()->sum);
    } else {
        RCLCPP_ERROR(rclcpp::get_logger("client_node"), "Failed to call service add_two_ints");
    }
    rclcpp::shutdown();
    return 0;
}