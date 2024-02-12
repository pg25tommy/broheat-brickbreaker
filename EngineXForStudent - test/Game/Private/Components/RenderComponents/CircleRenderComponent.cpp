#include "Game/Public/Components/RenderComponents/CircleRenderComponent.h"
#include "Engine/Public/EngineInterface.h"
#include "Game/Public/GameObject.h"

CircleRenderComponent::~CircleRenderComponent()
{
}

CircleRenderComponent::CircleRenderComponent(std::shared_ptr<GameObject> owner) : RenderComponent(owner)
{
    mRadius = 20.0f; // This could be repurposed as half the width or height of the paddle
}

CircleRenderComponent::CircleRenderComponent(std::shared_ptr<GameObject> owner, float radius) : RenderComponent(owner)
{
    mRadius = radius; // Repurpose as width or height
}

CircleRenderComponent::CircleRenderComponent(std::shared_ptr<GameObject> owner, float radius, exColor color) : RenderComponent(owner, color)
{
    mRadius = radius; // Width or height
}

CircleRenderComponent::CircleRenderComponent(std::shared_ptr<GameObject> owner, float radius, exColor color, int layer) : RenderComponent(owner, color, layer)
{
    mRadius = radius; // Width or height
}

void CircleRenderComponent::Render(exEngineInterface* inEngineInterface)
{
    if (mOwner.expired())
    {
        return;
    }

    std::shared_ptr<GameObject> owningGameObject = mOwner.lock();
    if (std::shared_ptr<TransformComponent> renderTransformComponent = owningGameObject->FindComponentOfType<TransformComponent>())
    {
        const exVector2 position = renderTransformComponent->GetPosition();

        
        // Adjust these values to create a paddle shape. 
        float paddleHeight = 20.0f; // Fixed height for the paddle
        float paddleWidth = mRadius * 2; // Full width of the paddle
        exVector2 topLeft = { position.x - mRadius, position.y - paddleHeight / 2 };
        exVector2 bottomRight = { position.x + mRadius, position.y + paddleHeight / 2 };

        inEngineInterface->DrawBox(topLeft, bottomRight, mColor, 0); // Using layer 0 for rendering
    }
}
