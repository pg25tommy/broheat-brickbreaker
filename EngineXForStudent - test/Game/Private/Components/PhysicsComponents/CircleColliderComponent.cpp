#include "Game/Public/Components/PhysicsComponents/CircleColliderComponent.h"
#include "Game/Public/GameObject.h"
#include <cmath>



CircleColliderComponent::CircleColliderComponent(std::shared_ptr<GameObject> owner) : PhysicsComponent(owner)
{
	mRadius = 15.0f;
}


CircleColliderComponent::CircleColliderComponent(std::shared_ptr<GameObject> owner, bool isStatic) : PhysicsComponent(owner,isStatic)
{
	mRadius = 15.0f;
}

CircleColliderComponent::CircleColliderComponent(std::shared_ptr<GameObject> owner, float radius, bool isStatic) : PhysicsComponent(owner, isStatic)
{
	mRadius = radius;
}

CircleColliderComponent::CircleColliderComponent(std::shared_ptr<GameObject> owner, float radius, bool isStatic, bool isGravityEnabled, exVector2 velocity) : PhysicsComponent(owner, isStatic, isGravityEnabled, velocity)
{
	mRadius = radius;
}

void CircleColliderComponent::InitializeComponent()
{
	PhysicsComponent::InitializeComponent();
}

bool CircleColliderComponent::IsColliding(std::shared_ptr<PhysicsComponent> otherComponent)
{
	// check if other component is a circle Component
	if (std::shared_ptr<CircleColliderComponent> otherCircleCollider = std::dynamic_pointer_cast<CircleColliderComponent>(otherComponent))
	{
		if (mOwner.expired() || otherCircleCollider->mOwner.expired())
		{
			return false;
		}

		std::shared_ptr<TransformComponent> owningTransformComp = mOwner.lock()->FindComponentOfType<TransformComponent>();
		std::shared_ptr<TransformComponent> otherTransformComp = otherCircleCollider->mOwner.lock()->FindComponentOfType<TransformComponent>();

		if (owningTransformComp && otherTransformComp)
		{
			auto a = owningTransformComp->GetPosition(); 
			auto b = otherTransformComp->GetPosition();
			exVector2 vectorBetweenCenterPoints = a - b;
			// Sqrt((x^2) + (y^2))
			float distanceBetweenCircle = std::sqrt((vectorBetweenCenterPoints.x * vectorBetweenCenterPoints.x) + (vectorBetweenCenterPoints.y * vectorBetweenCenterPoints.y));
			if (distanceBetweenCircle <= (mRadius + otherCircleCollider->mRadius))
			{
				return true;
			}
		}
	}
	return false;
}
