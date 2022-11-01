#ifndef NODE_KILLER
#define NODE_KILLER

#include <UnigineComponentSystem.h>

class NodeKiller final : public Unigine::ComponentBase
{
	COMPONENT_DEFINE(NodeKiller, Unigine::ComponentBase);
    COMPONENT_INIT(initialize);

private:
    void initialize() noexcept;
};

#endif // !NODE_KILLER