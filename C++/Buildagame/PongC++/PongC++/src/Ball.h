#pragma once
#include "Core_Components.h"

class Ball
{
public:
	//Ctor
	Ball(Renderer* renderer, Vector2<int>& startPos, Vector2<int>& dimensions, Vector2<int>& initialVelocity);
	
	//To change velocity on collision (call each time to change velocity on collision for each direction)
	void ChangeVelocity(VelocityDir direction);

	//Called every frame to move the ball, based on its velocity, also check if the ball hits the walls of the screen, and then to bounce off (by calling the ChangeVelocity method)
	void Move();

	void Render();

	//Provide methods to the Player so that collision with the player can be detected
	inline Vector2<int>& BallPos()
	{
		return m_Pos;
	}

private:
	Renderer* m_RendererPtr;
	Vector2<int> m_Pos;
	Vector2<int> m_Dimensions;
	Vector2<int> m_Velocity;

	//Rectangle to represent the ball
	SDL_Rect m_BallRect;

private:
	
	//To update the ball rectangle data
	void UpdateRectData();
};

