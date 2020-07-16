#include "Paddle.h"

Paddle::Paddle(const Vec2 & loc_in, float width_in, float height_in)
	:
	location(loc_in),
	rectangle(loc_in, width_in, height_in, mainColor)
{
}

void Paddle::Update(Keyboard & kbd, const float dt)
{
	if (!kbd.KeyIsEmpty()) {
		if (kbd.KeyIsPressed(VK_LEFT)) {
			location.x *= -speed * dt;
			rectangle.Update(-speed * dt, 0.0f);
		}
		if (kbd.KeyIsPressed(VK_RIGHT)) {
			location.x *= +speed * dt;
			rectangle.Update(+speed * dt, 0.0f);
		}
		
	}
	
}

void Paddle::Draw(Graphics & gfx) const
{
	rectangle.Draw(gfx);
}

void Paddle::DoBallCollision(Ball & ball)
{
	const RectF ballHitbox = ball.GetHitbox();
	if (rectangle.IsOverlappingWith(ballHitbox)) {

		if (ballHitbox.x < rectangle.x || ballHitbox.right > rectangle.right) {
			ball.SwitchVelocityX();
		}
		if (ballHitbox.y < rectangle.y || ballHitbox.bottom > rectangle.bottom)
		{
			ball.SwitchVelocityY();
		}
	}
}

void Paddle::DoWallCollision()
{
}
