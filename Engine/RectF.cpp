#include "RectF.h"

RectF::RectF(const float x_in, const float y_in, const float width_in, const float height_in)
	:
	x(x_in),
	y(y_in),
	width(width_in),
	height(height_in)
	
{
}

RectF::RectF(const Vec2 & origin, const Vec2 & bottom_right)
	:
	RectF::RectF(origin.x, origin.y, bottom_right.x - origin.x , bottom_right.y - origin.y)
{
}

RectF::RectF(const Vec2 & origin, const float width_in, const float height_in)
	:
	RectF::RectF(origin, Vec2(origin.x + width_in, origin.y + height_in))
{
}

bool RectF::IsOverlappingWith(const RectF & rect_in) const
{
	if ((rect_in.right >= x && rect_in.right <= right && rect_in.bottom >= y && rect_in.bottom <= bottom) ||
		(rect_in.x >= x && rect_in.x <= right && rect_in.bottom >= y && rect_in.bottom <= bottom) ||
		(rect_in.x >= x && rect_in.x <= right && rect_in.y >= y && rect_in.y <= bottom) ||
		(rect_in.right >= x && rect_in.right <= right && rect_in.y >= y && rect_in.y <= bottom))
	{
		return true;
	}
	else {
		return false;
	}
}

void RectF::Draw(Graphics& gfx, Color c) const
{
	gfx.DrawRect(int(x), int (y), int(x + width), int(y + height), c);
}