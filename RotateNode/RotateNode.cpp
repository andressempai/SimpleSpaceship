#include "RotateNode.hpp"

#include <UnigineGame.h>

REGISTER_COMPONENT(RotateNode)

void RotateNode::update() noexcept
{
    const auto delta_time = Unigine::Game::getIFps();

    const auto yaw_rotation = Unigine::Math::rotateZ(yaw_rotation_speed_ * delta_time).getRotate();
    const auto roll_rotation = Unigine::Math::rotateX(roll_rotation_speed_ * delta_time).getRotate();
    
    node->setWorldRotation(node->getWorldRotation() * yaw_rotation * roll_rotation);
}