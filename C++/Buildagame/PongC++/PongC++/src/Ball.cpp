#include "Ball.h"


Ball::Ball(Renderer* renderer, Vector2<int>& startPos, Vector2<int>& dimensions, Vector2<int>& initialVelocity)
	:m_RendererPtr(renderer), m_Pos(startPos), m_Dimensions(dimensions), m_Velocity(initialVelocity)
{
	//For the first time, it will initialize the ball_rect data
	UpdateRectData();
}

void Ball::UpdateRectData()
{
	//Modify the ball rect
	m_BallRect = {
		m_Pos.x,
		m_Pos.y,
		m_Dimensions.x,
		m_Dimensions.y
	};
}

void Ball::ChangeVelocity(VelocityDir direction)
{

	switch (direction)
	{

		case VelocityDir::X:
			m_Velocity.x *= -1;
			break;

		case VelocityDir::Y:
			m_Velocity.y *= -1;
			break;
	}
}

void Ball::Move()
{
	//Change the position
	//Note: in 1 frame (or 1 second), the distance travelled by the ball wil be the velocity, 
	//so they can be added on a per frame basis 
	m_Pos += m_Velocity;

	//Check if the screen boundary is hit, and change the velocity direction if true
	if (m_Pos.x == 0 || m_Pos.x == WINDOW_WIDTH)
		ChangeVelocity(VelocityDir::X);
	
	if (m_Pos.y == 0 || m_Pos.y == WINDOW_HEIGHT)
		ChangeVelocity(VelocityDir::Y);

	/*
	Note: 
	You need to change the velocity once again (i.e in case if collision is detected)
	But, this method ought to be called once per frame, hence the position, velocity etc.
	will be updated in the next frame.
	*/
}	

void Ball::Render()
{
	SDL_Renderer* rendererPtr = m_RendererPtr->GetRendererPtr();

	//Fill Color
	SDL_SetRenderDrawColor(rendererPtr, 255, 255, 255, 255);

	//Update the ball rect
	UpdateRectData();

	//Draw a rectangle to represent the ball with the updated ball rect
	SDL_RenderDrawRect(rendererPtr, &m_BallRect);
	SDL_RenderFillRect(rendererPtr, &m_BallRect);
}