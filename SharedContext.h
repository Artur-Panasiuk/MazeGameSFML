#pragma once
#include "Window.h"

struct SharedContext
{
	SharedContext()
		: mWindow(nullptr), mEventManager(nullptr) {}

	Window* mWindow;
	EventManager* mEventManager;
};