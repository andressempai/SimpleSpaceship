#include "PlayerController.hpp"

#include "../Utils/input_flags.hpp"

#include <UnigineControls.h>

REGISTER_COMPONENT(PlayerController)

void PlayerController::initialize() noexcept
{
    if (node.isNull())
        return;

    if (space_ship_property_ptr_ = node->getProperty(1))
        space_ship_property_param_ptr_ = space_ship_property_ptr_->getParameterPtr("input_flags");
}

void PlayerController::update() noexcept
{
    input_flags_ = space_ship_property_param_ptr_->getValueInt();

    if (Unigine::ControlsApp::getState(Unigine::Controls::STATE_MOVE_RIGHT))
        input_flags_ |= right;
    else
        input_flags_ &= ~right;

    if (Unigine::ControlsApp::getState(Unigine::Controls::STATE_MOVE_LEFT))
        input_flags_ |= left;
    else
        input_flags_ &= ~left;

    if (Unigine::ControlsApp::getState(Unigine::Controls::STATE_FIRE))
        input_flags_ |= launch;
    else
        input_flags_ &= ~launch;

    space_ship_property_param_ptr_->setValueInt(input_flags_);
}