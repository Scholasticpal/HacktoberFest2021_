#pragma once
#include "Core_Components.h"
#include "Ball.h"

enum class ContactPoint
{
	X, Y, Corner, No_Contact
};

class BoxCollider2D
{
public:
	//Default Ctor
	BoxCollider2D() = default;

	//Initializer Method
	void Create(const Vector2<int>&, const Vector2<int>&);

public:
	//Return the point or direction where the ball collides
	ContactPoint HasEntered(Ball&);

	//Update the box collider's position and dimensions based on the object on which HAS it
	void Update(const Vector2<int>& center, const Vector2<int> dimension);
	
private:
	Vector2<int> m_CenterPos;		//position of the center of the collider
	Vector2<int> m_Dimension;		//the width & the height of the collider 
};

