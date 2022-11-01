#ifndef PROJECTILE_MOVEMENT
#define PROJECTILE_MOVEMENT

#include <UnigineComponentSystem.h>

class ProjectileMovement final : public Unigine::ComponentBase
{
    COMPONENT_DEFINE(ProjectileMovement, Unigine::ComponentBase);
    COMPONENT_UPDATE(update);

    PROP_PARAM(
            Vec3
        ,   movement_direction_
        ,   Unigine::Math::vec3_forward
        ,   "Movement Direction"
        ,   "Movemement Direction for this Projectile");

    void set_projectile_speed(float projectile_speed) { projectile_speed_ = projectile_speed; }

private:
    void update() noexcept;
    
    PROP_PARAM(Float, projectile_speed_, 20.5f, "Projectile Speed");
};

#endif  // !PROJECTILE_MOVEMENT