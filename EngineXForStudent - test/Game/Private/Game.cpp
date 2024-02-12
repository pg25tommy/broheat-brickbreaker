//
// * ENGINE-X
// * SAMPLE GAME
//
// + Game.cpp
// implementation of MyGame, an implementation of exGameInterface
//

#include "Game/Private/Game.h"

#include "Engine/Public/EngineInterface.h"
#include "Game/Public/GameObjects/Ball.h"
#include "Engine/Public/SDL.h"
#include "Game/Public/Singletons/RenderEngine.h"
#include "Game/Public/Singletons/PhysicsEngine.h"

//-----------------------------------------------------------------
//-----------------------------------------------------------------

const char* gWindowName = "Rohit's EngineX Game";

//-----------------------------------------------------------------
//-----------------------------------------------------------------

MyGame::MyGame()
	: mEngine( nullptr )
	, mFontID( -1 )
	, mUp( false )
	, mDown( false )
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

MyGame::~MyGame()
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::Initialize(exEngineInterface* pEngine)
{
	mEngine = pEngine;

	// to get screen size
	int screenWidth = 800; //  width
	int screenHeight = 600; // screen height 

	float paddleWidth = 100.0f; // paddle width
	float paddleHeight = 20.0f; // paddle height

	// Position the paddle close to the bottom of the screen
	exVector2 paddleSpawnLocation = { screenWidth / 2.0f, screenHeight - paddleHeight - 10.0f }; // 10 pixels above the bottom edge

	mBall = std::make_shared<Ball>(exVector2{ 0.0f,0.0f }, paddleSpawnLocation, paddleWidth / 2.0f, exColor{ 255,255,0,255 }); // mRadius used as half-width here
	mBall->BeginPlay();
}



//-----------------------------------------------------------------
//-----------------------------------------------------------------

const char* MyGame::GetWindowName() const
{
	return gWindowName;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::GetClearColor( exColor& color ) const
{
	color.mColor[0] = 128;
	color.mColor[1] = 128;
	color.mColor[2] = 128;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::OnEvent( SDL_Event* pEvent )
{
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::OnEventsConsumed()
{
	int nKeys = 0;
	const Uint8* pState = SDL_GetKeyboardState(&nKeys);

	bool left = pState[SDL_SCANCODE_A];
	bool right = pState[SDL_SCANCODE_D];

	if (mBall) { // Ensure mBall is initialized
		auto physicsComp = mBall->GetPhysicsComponent();
		if (left) {
			physicsComp->SetVelocity(exVector2{ -1.0f, 0.0f }); // Adjust to desired speed
		}
		else if (right) {
			physicsComp->SetVelocity(exVector2{ 1.0f, 0.0f }); // Adjust to desired speed
		}
		else {
			physicsComp->SetVelocity(exVector2{ 0.0f, 0.0f }); // Stop moving when neither key is pressed
		}
	}
}


//-----------------------------------------------------------------
//-----------------------------------------------------------------

void MyGame::Run( float fDeltaT )
{
	if ( mUp )
	{
		mTextPosition.y -= 40.0f * fDeltaT;
		if (std::shared_ptr<PhysicsComponent> physicsComp = mBall2->FindComponentOfType<PhysicsComponent>())
		{
			physicsComp->SetVelocity(exVector2{ -0.5f,-0.25f });
		}

	}
	else if ( mDown )
	{
		mTextPosition.y += 40.0f * fDeltaT;
		if (std::shared_ptr<PhysicsComponent> physicsComp = mBall2->FindComponentOfType<PhysicsComponent>())
		{
			physicsComp->SetVelocity(exVector2{ 0.5f,0.25f });
		}
	}


	RENDER_ENGINE.Render(mEngine);
	PHYSICS_ENGINE.Physics();


}
