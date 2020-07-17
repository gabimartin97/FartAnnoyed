#include "RectF.h"

RectF::RectF(const float x_in, const float y_in, const float width_in, const float height_in, const Color& c_in)
	:
	x(x_in),
	y(y_in),
	width(width_in),
	height(height_in),
	c(c_in)
	
{
}

RectF::RectF(const Vec2 & origin, const Vec2 & bottom_right, const Color& c_in)
	:
	RectF::RectF(origin.x, origin.y, bottom_right.x - origin.x , bottom_right.y - origin.y, c_in)
{
}

RectF::RectF(const Vec2 & origin, const float width_in, const float height_in, const Color& c_in)
	:
	RectF::RectF(origin, Vec2(origin.x + width_in, origin.y + height_in), c_in)
{
}

RectF::RectF(const Vec2 & center_in, const float radius_in, const Color& c_in)
	:
	RectF(Vec2(center_in.x - radius_in, center_in.y - radius_in), radius_in *2, radius_in *2, c_in)
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

void RectF::Draw(Graphics& gfx) const
{
	gfx.DrawRect(int(x), int (y), int(x + width), int(y + height), c);
}

void RectF::DrawBorders(Graphics & gfx) const
{
	gfx.DrawFrame(int(x), int(y), int(x + width), int(y + height), c);
}

void RectF::Update(float deltaX, float deltaY)
{
	x += deltaX;
	y += deltaY;
	right = x + width;
	bottom = y + height;
}

void RectF::Update(Vec2 & loc_in)
{
	x = loc_in.x;
	y = loc_in.y;
	right = x + width;
	bottom = y + height;
}

