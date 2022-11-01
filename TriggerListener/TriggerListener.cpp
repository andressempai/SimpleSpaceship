#include "TriggerListener.hpp"

#include <UnigineWorlds.h>

REGISTER_COMPONENT(TriggerListener)

void TriggerListener::initialize() noexcept
{
	if (node.isNull())
		return;

	const auto world_trigger = Unigine::static_ptr_cast<Unigine::WorldTrigger>(node);
	if (world_trigger.isNull())
		return;

	world_trigger->addEnterCallback(Unigine::MakeCallback(
		[this](Unigine::NodePtr invader_node)
		{
			const auto node_type_property = invader_node->getProperty(0);
			if (node_type_property.isNull())
				return;

			const auto type_parameter = node_type_property->getParameterPtr("type");
			if (type_parameter.isNull())
				return;

			const auto type_bitfield = type_parameter->getValueMask();

			if (type_bitfield & 0x02)
			{
				if (explosion_file_node_)
				{
					const auto explosion_node = Unigine::NodeReference::create(explosion_file_node_);
					if (explosion_node.isNull())
						return;

					explosion_node->setWorldPosition(node->getWorldPosition());
				}
			}

			invader_node->deleteLater();
			node->getParent()->deleteLater();
		}));
}

void TriggerListener::update() noexcept
{
	//node->renderVisualizer();
}