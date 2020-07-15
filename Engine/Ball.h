#pragma once
#include "SpriteCodex.h"
#include "Vec2.h"
#include "RectF.h"



class Ball {
public:
	Ball() = default;
	Ball(const Vec2& position_in, const Vec2& velocity_in);
	void Draw(Graphics& gfx)const;
	void DrawHitbox(Graphics& gfx)const;
	void Update(const float dt);
	void DoWallCollision();
	void SwitchVelocityX();
	void SwitchVelocityY();
	RectF GetHitbox() const;
private:
	Vec2 position; //centro
	Vec2 velocity;
	static const int radius = 7;
	static constexpr Color hitboxColor = Colors::Red;
	RectF hitbox = RectF(position, float(radius), hitboxColor);
	
	



};