#ifndef PLAYER_MOVEMENT
#define PLAYER_MOVEMENT

#include <UnigineComponentSystem.h>

class PlayerMovement final : public Unigine::ComponentBase
{
    COMPONENT_DEFINE(PlayerMovement, Unigine::ComponentBase);
    COMPONENT_INIT(initialize);
    COMPONENT_UPDATE(update);

private:
    void initialize() noexcept;
    void update() noexcept;

    PROP_PARAM(Float, movement_speed_, 2.5f, "Movement Speed");

    Unigine::PropertyPtr space_ship_property_ptr_{};
    Unigine::PropertyParameterPtr space_ship_property_param_ptr_{};

    int input_flags_{};
};

#endif  // !PLAYER_MOVEMENT