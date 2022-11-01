#include "Lifespan.hpp"

#include <UnigineGame.h>

REGISTER_COMPONENT(Lifespan);

void Lifespan::update() noexcept
{
	const auto delta_time = Unigine::Game::getIFps();

	if (timer_ -= delta_time; timer_ <= 0.0f)
		node->deleteLater();
}