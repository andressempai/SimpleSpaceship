#include "MissileSpawner.hpp"

#include <UnigineGame.h>
#include <UnigineNode.h>

#include "../Utils/input_flags.hpp"

REGISTER_COMPONENT(MissileSpawner)

void MissileSpawner::initialize() noexcept
{
    if (node.isNull())
        return;

    if (property_ptr_ = node->getProperty(1))
        property_param_ptr_ = property_ptr_->getParameterPtr("input_flags");
}

void MissileSpawner::update() noexcept
{
    if (cooldown_ < cooldown_time_)
        cooldown_ += Unigine::Game::getIFps();

    input_flags_ = property_param_ptr_->getValueInt();

    if (cooldown_ >= cooldown_time_ && input_flags_ & launch)
    {
        const auto missile = spawn();
        missile->setWorldPosition(node->getWorldPosition() + spawn_position_offset_);

        cooldown_ = 0.0f;
    }
}

Unigine::NodeReferencePtr MissileSpawner::spawn() const noexcept
{
    if (missile_node_reference_)
        return Unigine::NodeReference::create(missile_node_reference_);

    return{};
}