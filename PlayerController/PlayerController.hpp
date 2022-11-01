#ifndef PLAYER_CONTROLLER
#define PLAYER_CONTROLLER

#include <UnigineComponentSystem.h>

class PlayerController final : public Unigine::ComponentBase
{
    COMPONENT_DEFINE(PlayerController, Unigine::ComponentBase);
    COMPONENT_INIT(initialize);
    COMPONENT_UPDATE(update);

private:
    void initialize() noexcept;
    void update() noexcept;

    Unigine::PropertyPtr space_ship_property_ptr_{};
    Unigine::PropertyParameterPtr space_ship_property_param_ptr_{};

    int input_flags_{};
};

#endif  // !PLAYER_CONTROLLER