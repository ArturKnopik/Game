#pragma once
#include <string>
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Texture.hpp>
#include "Enums.h"

class AnimationComponent
{

	Direction siteofTexture;
	sf::Texture texture;
	sf::Sprite currentSprite;
	float timeToNextFrame;
	float currentTime;
	int currentFrame;
	AnimationType animationType;
	Direction currentDirection;
	bool moving;
	sf::Vector2f currentStartPosition;
	sf::Vector2f walkingTarget;
public:
	void setPosition(sf::Vector2i position);
	
	AnimationComponent()=delete;

	AnimationComponent(std::string url, AnimationType typeOfAnimation, float timeToNextFrame);
	
	virtual ~AnimationComponent();

	void setTextureSubRect(Direction currentDirection, int frame);

	void setDirection(Direction direction);
	
	Direction getDirecyion();

	void draw(std::shared_ptr<sf::RenderWindow> window);

	void update(const float dt);

	void setMoving(bool moving);

	void setSiteOfTexture(Direction dir);


};

