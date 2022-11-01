#include "PlayerMovement.hpp"

#include <UnigineGame.h>

#include "../Utils/input_flags.hpp"

REGISTER_COMPONENT(PlayerMovement)

void PlayerMovement::initialize() noexcept
{
    if (node.isNull())
        return;

    if (space_ship_property_ptr_ = node->getProperty(1))
        space_ship_property_param_ptr_ = space_ship_property_ptr_->getParameterPtr("input_flags");
}

void PlayerMovement::update() noexcept
{
    const auto delta_time = Unigine::Game::getIFps();

    input_flags_ = space_ship_property_param_ptr_->getValueInt();

    auto movement_direction = Unigine::Math::vec2_zero;

    if (input_flags_ & right)
        movement_direction.x -= movement_speed_;
    
    if (input_flags_ & left)
        movement_direction.x += movement_speed_;
    
    auto new_position = node->getWorldPosition() + Unigine::Math::vec3{ movement_direction, 0.0f } * delta_time;
    new_position.x = Unigine::Math::clamp(new_position.x, -3.0f, 3.0f);

    node->setWorldPosition(new_position);
}