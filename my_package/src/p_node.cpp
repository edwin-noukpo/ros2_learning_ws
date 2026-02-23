#include "../include/my_package/p_node.hpp"

pNode::pNode() : rclcpp::Node("p_node"), _count(0)
{
    _publisher_node = this->create_publisher<std_msgs::msg::String>("my_topic", 10);
    _p_timer = this->create_wall_timer(
        std::chrono::microseconds(100000),
        std::bind(&pNode::timerCallBack, this)
    );
}

void pNode::timerCallBack()
{
    auto message = std_msgs::msg::String();
    message.data = "Hello, world! " + std::to_string(_count++);
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
    _publisher_node->publish(message);
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<pNode>());
    rclcpp::shutdown();
    return 0;
}
