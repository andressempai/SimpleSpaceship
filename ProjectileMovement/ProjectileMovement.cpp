#include "ProjectileMovement.hpp"

#include <UnigineGame.h>

REGISTER_COMPONENT(ProjectileMovement)

void ProjectileMovement::update() noexcept
{
    if (node.isNull())
        return;

    const auto delta_time = Unigine::Game::getIFps();

    node->setWorldPosition(node->getWorldPosition() + movement_direction_.get() * projectile_speed_ * delta_time);
}