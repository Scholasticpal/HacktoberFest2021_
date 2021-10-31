#pragma once

#include "Core_Components.h"
#include "BoxCollider2D.h"
#include "Ball.h"


class Player
{
public:
	
	//Ctors
	Player() = default;
	Player(Renderer* renderer, Vector2<int>& pos, Vector2<int>& dimensions, Ball* ballPtr);

	void InitializePlayer(Renderer* renderer, Vector2<int>& pos, Vector2<int>& dimensions, Ball* ballPtr);
	/*
	Player shall move only up or down
	1. deltaY will be negative for moving up.
	2. deltaY will be positve for moving down.
	Because origin of screen is in the top left corner of the window.
	*/ 
	void Move(int deltaY);
	
	//Player will shoot only once
	void Shoot();

	//Render functions
	void Render();

	//Dtor
	~Player()
	{
		//Nothing here because player doesnot hold any such data
	}

	//For now..
	//This method will run each frame, checking if the ball enters the region of the 
	void CheckCollisionsWithBall();

private:
	Renderer* m_RendererPtr;
	Vector2<int> m_pos;
	Vector2<int> m_dimension;

	//Rectangle to represent the player
	SDL_Rect m_Player_rect;


	//A reference to the ball
	Ball* m_BallPtr;

	//A box collider for the player, to detect collisions
	BoxCollider2D collider;
private:
	//To update the player's rect data
	void UpdateRectData();
};

