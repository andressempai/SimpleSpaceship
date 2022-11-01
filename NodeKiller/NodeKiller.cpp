#include "NodeKiller.h"

#include <UnigineWorlds.h>

REGISTER_COMPONENT(NodeKiller);

void destroy_invader_node(Unigine::NodePtr node)
{
	node->deleteLater();
}

void NodeKiller::initialize() noexcept
{
    if (node.isNull())
		return;

	const auto world_trigger = Unigine::static_ptr_cast<Unigine::WorldTrigger>(node);
	if (world_trigger.isNull())
		return;

	world_trigger->addEnterCallback(Unigine::MakeCallback(destroy_invader_node));
}