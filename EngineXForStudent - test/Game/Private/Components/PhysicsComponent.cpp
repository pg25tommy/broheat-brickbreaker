#include "Game/Public/Components/PhysicsComponent.h"
#include "Game/Public/GameObject.h"
#include "Game/Public/Singletons/PhysicsEngine.h"

PhysicsComponent::~PhysicsComponent()
{
}

PhysicsComponent::PhysicsComponent(std::shared_ptr<GameObject> owner)  : Component(owner)
{
	mIsStatic = true;
	mIsGravityEnabled = false;
	mVelocity = exVector2(0.0f, 0.0f);
}

PhysicsComponent::PhysicsComponent(std::shared_ptr<GameObject> owner, bool isStatic) : Component(owner)
{
	mIsStatic = isStatic;
	mIsGravityEnabled = false;
	mVelocity = exVector2(0.0f, 0.0f);
}

PhysicsComponent::PhysicsComponent(std::shared_ptr<GameObject> owner, bool isStatic, bool isGravityEnabled) : Component(owner)
{
	mIsStatic = isStatic;
	mIsGravityEnabled = isGravityEnabled;
	mVelocity = exVector2(0.0f, 0.0f);
}


PhysicsComponent::PhysicsComponent(std::shared_ptr<GameObject> owner, bool isStatic, bool isGravityEnabled, exVector2 velocity) : Component(owner)
{
	mIsStatic = isStatic;
	mIsGravityEnabled = isGravityEnabled;
	mVelocity = velocity;
}


void PhysicsComponent::ListenToCollision(CollisionEventSignature eventToAdd)
{
	mCollisionEvents.push_back(eventToAdd);
}

bool PhysicsComponent::IsColliding(std::shared_ptr<PhysicsComponent> otherComponent)
{
	return false;
}

void PhysicsComponent::Physics()
{
	if (mIsStatic)
	{
		return;
	}

	if (mOwner.expired())
	{
		return;
	}

	std::shared_ptr<GameObject> owner = mOwner.lock();
	if (std::shared_ptr<TransformComponent> transformComponent = owner->FindComponentOfType<TransformComponent>())
	{
		exVector2 newPosition = transformComponent->GetPosition() + mVelocity;
		transformComponent->SetPosition(newPosition);
	}
}

exVector2 PhysicsComponent::GetVelocity() const
{
	return mVelocity;
}

void PhysicsComponent::SetVelocity(const exVector2& newVelociity)
{
	mVelocity = newVelociity;
}

void PhysicsComponent::InitializeComponent()
{
	PHYSICS_ENGINE.AddPhysicsComponent(shared_from_this());
}
