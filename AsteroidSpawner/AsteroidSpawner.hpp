#ifndef ASTEROID_SPAWNER
#define ASTEROID_SPAWNER

#include <UnigineComponentSystem.h>

class AsteroidSpawner final : public Unigine::ComponentBase
{
    COMPONENT_DEFINE(AsteroidSpawner, Unigine::ComponentBase);
    COMPONENT_INIT(initialize);
    COMPONENT_UPDATE(update);

private:
    void initialize() noexcept;
    void update() noexcept;

    [[nodiscard]] Unigine::NodeReferencePtr spawn() noexcept;

    PROP_ARRAY(
            File
        ,   node_files_container_
        ,   "Node Files Container"
        ,   "Node Files Container");

    PROP_PARAM(
            Float
        ,   min_time_to_spawn_
        ,   0.0f
        ,   "Min Time to Spawn"
        ,   "Min Time to Spawn");

    PROP_PARAM(
            Float
        ,   max_time_to_spawn_
        ,   5.0f
        ,   "Max Time to Spawn"
        ,   "Max Time to Spawn");

    float time_interval_{ max_time_to_spawn_ };
    float timer_{};
};

#endif  // !ASTEROID_SPAWNER