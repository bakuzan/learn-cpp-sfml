#include "Animation.h"

Animation::Animation(sf::Texture *texture, sf::Vector2u imageCount, float switchTime)
{
    this->imageCount = imageCount;
    this->switchTime = switchTime;
    this->totalTime = 0.0f;
    currentImage.x = 0;

    textureRect.width = texture->getSize().x / float(imageCount.x);
    textureRect.height = texture->getSize().y / float(imageCount.y);
}

Animation::~Animation()
{
}

void Animation::Update(int row, float deltaTime, bool faceRight)
{
    currentImage.y = row;
    totalTime += deltaTime;

    if (totalTime >= switchTime)
    {
        totalTime -= switchTime;
        currentImage.x++;

        if (currentImage.x >= imageCount.x)
        {
            currentImage.x = 0;
        }
    }

    textureRect.top = currentImage.y * textureRect.height;
    if (faceRight)
    {
        textureRect.left = currentImage.x * textureRect.width;
        textureRect.width = abs(textureRect.width);
    }
    else
    {
        textureRect.left = (currentImage.x + 1) * abs(textureRect.width);
        textureRect.width = -abs(textureRect.width);
    }
}