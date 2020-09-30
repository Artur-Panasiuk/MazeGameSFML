#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include <algorithm>
#include "TextureManager.h"
#include "Maze.h"


enum class Dir
{
	Up, Down, Left, Right
};

struct CollisionElement
{
	float mArea;
	TileInfo* mTile;
	sf::FloatRect mTileBounds;
};


struct CollisionsComparator
{
	bool operator() (const CollisionElement& l1, const CollisionElement& l2) { return l1.mArea > l2.mArea; }
};

class StateManager;
class Player
{
public:
	Player();
	~Player();

	void SetTextureManager(TextureManager* lTextureManager);
	void SetMap(Maze* lMaze);
	void SetTexture(const std::string& lName);
	void SetStateManager(StateManager* lState);
	void ReleaseTexture();

	void SetPosition(const sf::Vector2f& lPos);
	sf::Vector2f GetPosition();
	void Accelerate(const Dir& lDir);
	void Move(const float&x, const float&y);

	void Draw(sf::RenderWindow* lWind);
	void Update(const sf::Time& lTime);
private:
	void UpdateAABB();
	void ApplyFriction();
	void CheckForCollisions();
	void ResolveCollisions();

	sf::Sprite mSpriteSheet;//placeholderowy typ
	std::string mTexture;
	sf::Vector2f mAcceleration;
	sf::Vector2f mVelocity;
	float mSpeed;
	float mMaxVelocity;
	float mBaseFriction;

	sf::FloatRect mAABB;
	std::vector<CollisionElement> mCollisions;

	Maze* mMaze;
	TextureManager* mTextureManager;
	StateManager* mStateManager;
	CollisionsComparator mComp;
};