#pragma once
#include "Game/Public/Utils.h"
#define PHYSICS_ENGINE PhysicsEngine::GetInstance()

class PhysicsComponent;

class PhysicsEngine
{
public:

	~PhysicsEngine();

	void Physics();
	void AddPhysicsComponent(std::shared_ptr<PhysicsComponent> physicsComponentToAdd);

	static PhysicsEngine& GetInstance();

private:
	PhysicsEngine();

	void Move();
	void Collide();

	std::vector<std::weak_ptr<PhysicsComponent>> mPhysicsComponentList;
	static std::unique_ptr<PhysicsEngine> sInstance;
};