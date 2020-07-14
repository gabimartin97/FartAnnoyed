#pragma once
#include "RectF.h"
#include "Vec2.h"


class Brick {
public:
	Brick() = default;
	Brick(const Vec2& loc_in, const float width_in, const float height_in, const Color& c_in  );
	void Draw(Graphics& gfx)const;
	
private:

	Vec2 location;
	RectF rectangle;
	Color c;
	bool destroyed = false;

};