#pragma once
#include "TextureManager.h"
#include "BaseAnim.h"
#include "Anim_Directional.h"

//bez direction (po co to tam jest?)
class SpriteSheet
{
public:
	SpriteSheet(TextureManager* lTexManager);
	~SpriteSheet();

	void CropSprite(const sf::IntRect& lRect);

	sf::Vector2i GetSpriteSize()const;
	sf::Vector2f GetSpritePosition()const;
	void SetSpriteSize(const sf::Vector2i& lSize);
	void SetSpritePosition(const sf::Vector2f& lPos);

	bool LoadSheet(const std::string& lPath);
	void ReleaseSheet();

	BaseAnim* GetCurrentAnim();
	bool SetAnimation(const std::string& lName, const bool& lPlay = false, const bool& lLoop = false);

	void Update(const sf::Time& lTime);
	void Draw(sf::RenderWindow* lWind);
private:
	std::string mTexture;
	sf::Sprite mSprite;
	sf::Vector2i mSpriteSize;
	sf::Vector2f mSpriteScale;
	std::string mAnimType;
	std::unordered_map<std::string, BaseAnim*> mAnimations;
	BaseAnim* mCurrentAnimation;
	TextureManager* mTextureManager;
};