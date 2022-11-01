#ifndef LIFESPAN
#define LIFESPAN

#include <UnigineComponentSystem.h>

class Lifespan final : public Unigine::ComponentBase
{
	COMPONENT_DEFINE(Lifespan, Unigine::ComponentBase);
    COMPONENT_UPDATE(update);

private:
    void update() noexcept;

    PROP_PARAM(
            Float
        ,   max_lifespan_
        ,   10.0f
        ,   "Max Lifespan"
        ,   "Max Lifespan");

    float timer_{ max_lifespan_ };
};

#endif // !LIFESPAN