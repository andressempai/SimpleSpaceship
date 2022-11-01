#ifndef TURN_ANIMATION
#define TURN_ANIMATION

#include <UnigineComponentSystem.h>

class TurnAnimation final : public Unigine::ComponentBase
{
	COMPONENT_DEFINE(TurnAnimation, Unigine::ComponentBase);
    COMPONENT_INIT(initialize);
    COMPONENT_UPDATE(update);

private:
    void initialize() noexcept;
    void update() noexcept;

    PROP_PARAM(
            Float
        ,   turn_angle_
        ,   30.0f
        ,   "Turn Angle"
        ,   "Max angle in the Turn");

    PROP_PARAM(
            Float
        ,   turn_speed_
        ,   3.5f
        ,   "Turn Speed"
        ,   "How fast is ther turn");

    Unigine::PropertyPtr space_ship_property_ptr_{};
    Unigine::PropertyParameterPtr space_ship_property_param_ptr_{};

    int input_flags_{};
};

#endif // !TURN_ANIMATION