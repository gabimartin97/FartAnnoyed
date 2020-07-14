#include "Brick.h"

Brick::Brick(const Vec2 & loc_in, const float width_in, const float height_in, const Color & c_in)
	:
	location(loc_in),
	rectangle(location, width_in, height_in, c_in)
{}

void Brick::Draw(Graphics & gfx) const
{
	rectangle.Draw(gfx);
}
