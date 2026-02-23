#include "../include/my_package/s_node.hpp"

sNode::sNode() : rclcpp::Node("s_node")
{
    _subscriber_node = this->create_subscription<std_msgs::msg::String>(
        "my_topic",
        10,
        std::bind(
            &sNode::topicCallBack,
            this,
            std::placeholders::_1
        )
    );
}

void sNode::topicCallBack(const std_msgs::msg::String &msg) const
{
    RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg.data.c_str());
}

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<sNode>());
    rclcpp::shutdown();
    return 0;
}
