#include "Game/Public/Singletons/PhysicsEngine.h"
#include "Game/Public/GameObject.h"

std::unique_ptr<PhysicsEngine> PhysicsEngine::sInstance = nullptr;

PhysicsEngine::PhysicsEngine()
{
}

PhysicsEngine::~PhysicsEngine()
{
}


void PhysicsEngine::AddPhysicsComponent(std::shared_ptr<PhysicsComponent> physicsComponentToAdd)
{
	mPhysicsComponentList.push_back(physicsComponentToAdd);
}

PhysicsEngine& PhysicsEngine::GetInstance()
{
	if (!sInstance)
	{
		std::unique_ptr<PhysicsEngine> newInstance(new PhysicsEngine());
		sInstance = std::move(newInstance);
	}
	return *sInstance;
}

void PhysicsEngine::Physics()
{
	Collide();
	Move();
}

void PhysicsEngine::Move()
{
	for (std::weak_ptr<PhysicsComponent> physicsComponentIter : mPhysicsComponentList)
	{
		if (physicsComponentIter.expired())
		{
			continue;
		}

		std::shared_ptr<PhysicsComponent> currentComponent = physicsComponentIter.lock();
		if (!currentComponent)
		{
			continue;
		}
		currentComponent->Physics();
	}
}

void PhysicsEngine::Collide()
{
	for (std::weak_ptr<PhysicsComponent> physicsComponentIter : mPhysicsComponentList)
	{
		for (std::weak_ptr<PhysicsComponent> otherPhysicsComponentIter : mPhysicsComponentList)
		{
		
			if (physicsComponentIter.expired())
			{
				continue;
			}

			if (otherPhysicsComponentIter.expired())
			{
				continue;
			}

			std::shared_ptr<PhysicsComponent> currentComponent = physicsComponentIter.lock();
			std::shared_ptr<PhysicsComponent> otherComponent = otherPhysicsComponentIter.lock();

			if (currentComponent == otherComponent)
			{
				continue;
			}

			if (!currentComponent)
			{
				continue;
			}
			if (!otherComponent)
			{
				continue;
			}

			if (currentComponent->IsColliding(otherComponent))
			{
				float owningX = -1.0f * currentComponent->mVelocity.x;
				float owningY = -1.0f * currentComponent->mVelocity.y;
				exVector2 newPos1 = exVector2{ owningX,owningY };

				float otherX = otherComponent->mVelocity.x;
				float otherY = otherComponent->mVelocity.y;
				exVector2 newPos2 = exVector2{ otherX, otherY };

				currentComponent->SetVelocity(newPos1);
				otherComponent->SetVelocity(newPos2);
			}
		}
	}
}
