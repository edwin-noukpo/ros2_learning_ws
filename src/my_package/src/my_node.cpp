#include "../include/my_package/my_node.hpp"

myNode::myNode() : rclcpp::Node("myNode")
{
    RCLCPP_INFO(this->get_logger(), "Starting...");
}

void myNode::count()
{
    for (int x = 0; x < 10; x++)
        RCLCPP_INFO(this->get_logger(), "x = %d", x);
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto my_node {std::make_shared<myNode>()};
    my_node->count();
    // auto my_node {rclcpp::Node::make_shared("my_node")};
    rclcpp::spin(my_node);
    rclcpp::shutdown();
    return 0;
}
