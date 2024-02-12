#include "Game/Public/Component.h"
#include "Game/Public/GameObject.h"

Component::Component(std::shared_ptr<GameObject> inOwner)
{
	mOwner = inOwner;
}

Component::~Component()
{
};
