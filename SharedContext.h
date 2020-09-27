#pragma once
#include "Window.h"
#include "TextureManager.h"
#include "FontManager.h"
#include "AudioManager.h"

struct SharedContext
{
	SharedContext()
		: mWindow(nullptr), mEventManager(nullptr), mTextureManager(nullptr), mFontManager(nullptr),
		mAudioManager(nullptr) {}

	Window* mWindow;
	EventManager* mEventManager;
	TextureManager* mTextureManager;
	FontManager* mFontManager;
	AudioManager* mAudioManager;
};