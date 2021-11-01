#include "BoxCollider2D.h"


void BoxCollider2D::Create(const Vector2<int>& center, const Vector2<int>& dimension)
{
	m_CenterPos = center;
	m_Dimension = dimension;
}

ContactPoint BoxCollider2D::HasEntered(Ball& ball)
{
	Vector2<int> ballPos = ball.BallPos();

	////if corner of the collider is hit
	//if ((ballPos.x == m_CenterPos.x + m_Dimension.x / 2 || ballPos.x == m_CenterPos.x - m_Dimension.x / 2)
	//	&& (ballPos.y == m_CenterPos.y + m_Dimension.y / 2 || ballPos.y - m_Dimension.y / 2)
	//	)
	//	return ContactPoint::Corner;

	//if the lateral side (X) part of the collider is hit
	if (ballPos.x == m_CenterPos.x + m_Dimension.x / 2 || ballPos.x == m_CenterPos.x - m_Dimension.x / 2)
		return ContactPoint::X;

	//if the top or the bottom of the collider is hit
	if ((ballPos.y >= m_CenterPos.y + m_Dimension.y / 2 || ballPos.y <= m_CenterPos.y - m_Dimension.y / 2)
		&& (ballPos.x <= m_CenterPos.x - m_Dimension.x / 2 && ballPos.x >= m_CenterPos.x + ballPos.x / 2)
		)
		return ContactPoint::Y;

	//if all the above conditions are false, this means it hasn't collided yet
	return ContactPoint::No_Contact;
}

void BoxCollider2D::Update(const Vector2<int>& center, const Vector2<int> dimension)
{
	m_CenterPos = center;
	m_Dimension = dimension;
}