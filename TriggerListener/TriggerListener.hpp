#ifndef TRIGGER_LISTENER
#define TRIGGER_LISTENER

#include <UnigineComponentSystem.h>

class TriggerListener final : public Unigine::ComponentBase
{
    COMPONENT_DEFINE(TriggerListener, Unigine::ComponentBase);
    COMPONENT_INIT(initialize);
    COMPONENT_UPDATE(update);

    PROP_PARAM(File, explosion_file_node_, nullptr, "Explosion File Node", "Explosion File Node Path");

private:
    void initialize() noexcept;
    void update() noexcept;
};

#endif  // !TRIGGER_LISTENER