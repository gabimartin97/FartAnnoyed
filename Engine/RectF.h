#pragma once
#include "Vec2.h"
#include "Graphics.h"




class RectF {

public:
	RectF() = default;
	RectF(const float x_in, const float y_in, const float width_in, const float height_in, const Color& c_in);
	RectF(const Vec2& origin, const Vec2& bottom_right, const Color& c_in);
	RectF(const Vec2& origin, const float width_in, const float height_in, const Color& c_in);
	RectF(const Vec2& center_in, const float radius_in, const Color& c_in);
	bool IsOverlappingWith(const RectF& rect_in) const;
	void Draw(Graphics& gfx) const;
	void DrawBorders(Graphics& gfx) const;
	void Update(float deltaX, float deltaY);
public:
	float width;
	float height;
	float x;
	float y;
	float right = x + width; //Ojo cuando hay que actualizar estos valores
	float bottom = y + height; //Ojo cuando hay que actualizar estos valores
	Color c;
};