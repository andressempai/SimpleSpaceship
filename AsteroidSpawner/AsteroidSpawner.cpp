#include "AsteroidSpawner.hpp"

#include <UnigineNode.h>
#include <UnigineGame.h>

#include "../RotateNode/RotateNode.hpp"
#include "../ProjectileMovement/ProjectileMovement.hpp"

REGISTER_COMPONENT(AsteroidSpawner)

void AsteroidSpawner::initialize() noexcept
{
    time_interval_ = Unigine::Math::randFloat(min_time_to_spawn_, max_time_to_spawn_);
}

Unigine::NodeReferencePtr AsteroidSpawner::spawn() noexcept
{
    if (node_files_container_.size() == 0)
        return{};

    const auto random_iterator = Unigine::Math::randInt(0, node_files_container_.size() - 1);
    const auto new_node = Unigine::NodeReference::create(node_files_container_[random_iterator]);
    
    if (auto* const rotate_node = addComponent<RotateNode>(new_node))
    {
        rotate_node->set_yaw_rotation_speed(Unigine::Math::randFloat(-45.0f, 45.0f));
        rotate_node->set_roll_rotation_speed(Unigine::Math::randFloat(-45.0f, 45.0f));
    }

    if (auto* const projectile_movement = addComponent<ProjectileMovement>(new_node))
    {
        projectile_movement->set_projectile_speed(Unigine::Math::randFloat(1.35f, 1.9535f));
    }

    return new_node;
}

void AsteroidSpawner::update() noexcept
{
    const auto delta_time = Unigine::Game::getIFps();

    if (timer_ += delta_time; timer_ >= time_interval_)
    {
        timer_ = 0.0f;
        time_interval_ = Unigine::Math::randFloat(min_time_to_spawn_, max_time_to_spawn_);

        if (const auto spawned_node = spawn())
            spawned_node->setWorldPosition(node->getWorldPosition());
    }
}