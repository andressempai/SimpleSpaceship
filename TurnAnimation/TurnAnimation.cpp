#include "TurnAnimation.h"

#include <UnigineGame.h>

#include "../Utils/input_flags.hpp"

REGISTER_COMPONENT(TurnAnimation)

void TurnAnimation::initialize() noexcept
{
    if (node.isNull())
        return;

    if (space_ship_property_ptr_ = node->getProperty(1))
        space_ship_property_param_ptr_ = space_ship_property_ptr_->getParameterPtr("input_flags");
}

void TurnAnimation::update() noexcept
{
    const auto delta_time = Unigine::Game::getIFps();

    input_flags_ = space_ship_property_param_ptr_->getValueInt();

    auto turn_direction = 0.0f;

    if (input_flags_ & right)
        turn_direction -= turn_angle_;
    
    if (input_flags_ & left)
        turn_direction += turn_angle_;
    
    const auto turn = Unigine::Math::rotateY(turn_direction).getRotate();
    
    node->setWorldRotation(Unigine::Math::slerp(node->getWorldRotation(), turn, turn_speed_ * delta_time));
}