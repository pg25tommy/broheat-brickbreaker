#pragma once

#include "Game/Public/GameObject.h"
#include "Game/Public/Components/PhysicsComponent.h" // Make sure to include the correct path

class TransformComponent;
class CircleRenderComponent;

class Ball : public GameObject
{
public:
    Ball();
    Ball(exVector2 directionOfMovement, exVector2 spawnLocation, float radius, exColor color);
    ~Ball();

    virtual void Tick(float deltaTime) override;
    virtual void BeginPlay() override;

    // Accessor for the PhysicsComponent
    std::shared_ptr<PhysicsComponent> GetPhysicsComponent() const { return mPhysicsComponent; }

private:
    std::shared_ptr<TransformComponent> mTransform;
    std::shared_ptr<CircleRenderComponent> mCircleRenderComponent;
    std::shared_ptr<PhysicsComponent> mPhysicsComponent;

    float mRadius;
    exVector2 mDirection;
    exVector2 mBallSpawnLocation;
    exColor mBallColor;
};

