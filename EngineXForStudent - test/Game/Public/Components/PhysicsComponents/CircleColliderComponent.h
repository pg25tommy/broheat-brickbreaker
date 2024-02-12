#pragma once
#include "Game/Public/Components/PhysicsComponent.h"


class CircleColliderComponent : public PhysicsComponent
{

public:

	CircleColliderComponent() = delete;
	CircleColliderComponent(std::shared_ptr<GameObject> owner);
	CircleColliderComponent(std::shared_ptr<GameObject> owner,bool isStatic);
	CircleColliderComponent(std::shared_ptr<GameObject> owner, float radius, bool isStatic);
	CircleColliderComponent(std::shared_ptr<GameObject> owner, float radius, bool isStatic, bool isGravityEnabled, exVector2 velocity);

protected:
	virtual void InitializeComponent() override;
	virtual bool IsColliding(std::shared_ptr<PhysicsComponent> otherComponent) override;

private:

	float mRadius;
};

