#pragma once
#include "Game/Public/Components/RenderComponent.h"

class CircleRenderComponent : public RenderComponent
{

public:

	CircleRenderComponent() = delete;
	~CircleRenderComponent();

	CircleRenderComponent(std::shared_ptr<GameObject> owner);
	CircleRenderComponent(std::shared_ptr<GameObject> owner, float radius);
	CircleRenderComponent(std::shared_ptr<GameObject> owner, float radius, exColor color);
	CircleRenderComponent(std::shared_ptr<GameObject> owner, float radius, exColor color, int layer);

protected:

	virtual void Render(exEngineInterface* inEngineInterface);

private:

	float mRadius;
};

