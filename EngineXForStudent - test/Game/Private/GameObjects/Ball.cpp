#include "Game/Public/GameObjects/Ball.h"


Ball::Ball() : GameObject()
{
	mRadius = 100.0f;
	mDirection = exVector2{ 1.0f,1.0f };
	mBallColor = exColor{ 255,255,0,255 };
	mBallSpawnLocation = exVector2{ 400.0f,400.0f };
}

Ball::Ball(exVector2 directionOfMovement, exVector2 spawnLocation, float radius, exColor color)
{
	mRadius = radius;
	mDirection = directionOfMovement;
	mBallColor = color;
	mBallSpawnLocation = spawnLocation;
}

Ball::~Ball()
{
}

void Ball::Tick(float deltaTime)
{
	GameObject::Tick(deltaTime);
}

void Ball::BeginPlay()
{
	GameObject::BeginPlay();
	mTransform = AddComponentOfType<TransformComponent>(mBallSpawnLocation);
	mCircleRenderComponent = AddComponentOfType<CircleRenderComponent>(mRadius, mBallColor, 2);
	mPhysicsComponent = AddComponentOfType<CircleColliderComponent>(mRadius+5.0f,false, false, mDirection);
}
