#pragma once
#include "Game/Public/Component.h"
#include "Engine/Public/EngineTypes.h"


class exEngineInterface;

class RenderComponent : public Component , public std::enable_shared_from_this<RenderComponent>
{

	friend class RenderEngine;
public:

	RenderComponent() = delete;
	~RenderComponent();

	RenderComponent(std::shared_ptr<GameObject> owner);
	RenderComponent(std::shared_ptr<GameObject> owner, exColor color);
	RenderComponent(std::shared_ptr<GameObject> owner, exColor color, int layer);

	// Getters and Setters

	exColor GetColor() const;
	void SetColor(const exColor& newColor);


protected:

	// making the render function abstaract by putting = 0
	virtual void Render(exEngineInterface* inEngineInterface) = 0;
	virtual void InitializeComponent() override;

	exColor mColor;
	int mLayer;

private:

	void RegisterSelfToRenderEngine();
};

