#pragma once
#include "RectF.h"
#include "Vec2.h"
#include "MainWindow.h"
#include "Ball.h"


class Paddle {
public:
	Paddle(const Vec2& loc_in, float width_in, float height_in);
	void Update(Keyboard& kbd, const float dt);
	void Draw(Graphics& gfx) const;
	void DoBallCollision(Ball& ball);
	void DoWallCollision();

private:
	Vec2 location;
	RectF rectangle;
	static constexpr float speed = 200;
	static constexpr Color mainColor = Colors::Red;


};