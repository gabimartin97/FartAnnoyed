#include "Ball.h"

Ball::Ball(const Vec2& position_in, const Vec2& velocity_in)
	:
	position(position_in),
	velocity(velocity_in)
	//hitbox(RectF(position_in, float(radius), hitboxColor))
	{}

void Ball::Draw(Graphics& gfx)const
{
	SpriteCodex::DrawBall(position, gfx);
}

void Ball::DrawHitbox(Graphics & gfx) const
{
	hitbox.DrawBorders(gfx);
}

void Ball::Update(const float dt)
{
	position += velocity * dt;
	hitbox.Update((velocity.x * dt), (velocity.y * dt));
}

void Ball::DoWallCollision()
{
	if (hitbox.x <= 0.0f) {
		position.x = 0.0f + radius + 1.0f;
		hitbox.x = 1.0f;
		SwitchVelocityX();
	}
	else if (hitbox.x + 2*radius >= Graphics::ScreenWidth) {
		position.x = Graphics::ScreenWidth - radius - 1.0f;
		hitbox.x = Graphics::ScreenWidth - 1.0f - (2*radius);
		SwitchVelocityX();
	}

	if (hitbox.y <= 0.0f) {
		position.y = 0.0f + radius + 1.0f;
		hitbox.y = 1.0f;
		SwitchVelocityY();
	}
	else if (hitbox.y + 2*radius >= Graphics::ScreenHeight) {
		position.y = Graphics::ScreenHeight - radius - 1.0f;
		hitbox.y = Graphics::ScreenHeight - 1.0f - (2 * radius);
		SwitchVelocityY();
	}
}

void Ball::SwitchVelocityX()
{
	velocity.x = -velocity.x;
}

void Ball::SwitchVelocityY()
{
	velocity.y = -velocity.y;
}

RectF Ball::GetHitbox() const
{
	return hitbox;
}
