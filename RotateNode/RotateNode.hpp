#ifndef ROTATE_NODE
#define ROTATE_NODE

#include <UnigineComponentSystem.h>

class RotateNode final : public Unigine::ComponentBase
{
    COMPONENT_DEFINE(RotateNode, Unigine::ComponentBase);
    COMPONENT_UPDATE(update);

    void set_yaw_rotation_speed(float speed) { yaw_rotation_speed_ = speed; }
    void set_roll_rotation_speed(float speed) { roll_rotation_speed_ = speed; }

private:
    void update() noexcept;

    PROP_PARAM(
            Float
        ,   yaw_rotation_speed_
        ,   45.0f
        ,   "Yaw Rotation Speed"
        ,   "Control the max rotation on Yaw Coordinate");

    PROP_PARAM(
            Float
        ,   roll_rotation_speed_
        ,   0.0f
        ,   "Roll Rotation Speed"
        ,   "Control the max rotation on Roll Coordinate");
};

#endif // !ROTATE_NODE