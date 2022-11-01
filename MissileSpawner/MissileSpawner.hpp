#ifndef MISSILE_SPAWNER
#define MISSILE_SPAWNER

#include <UnigineComponentSystem.h>

class MissileSpawner final : public Unigine::ComponentBase
{
    COMPONENT_DEFINE(MissileSpawner, Unigine::ComponentBase);
    COMPONENT_INIT(initialize);
    COMPONENT_UPDATE(update);

private:
    void initialize() noexcept;
    void update() noexcept;

    [[nodiscard]] Unigine::NodeReferencePtr spawn() const noexcept;

    PROP_PARAM(
            File
        ,   missile_node_reference_
        ,   nullptr
        ,   "Missile Node Reference");

    PROP_PARAM(
            Float
        ,   cooldown_time_
        ,   5.0f
        ,   "Cooldown Time"
        ,   "Cooldown Time before allow next shoot");

    PROP_PARAM(
            Vec3
        ,   spawn_position_offset_
        ,   Unigine::Math::vec3_zero
        ,   "Spawn Position Offset"
        ,   "Position Offset to Spawn Missile");

    Unigine::PropertyPtr property_ptr_{};
    Unigine::PropertyParameterPtr property_param_ptr_{};

    int input_flags_{};

    float cooldown_{ cooldown_time_ };
};

#endif  // !MISSILE_SPAWNER