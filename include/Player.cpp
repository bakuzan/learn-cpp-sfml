#include <SFML/Graphics.hpp>
#include <cmath>

#include "Player.h"

Player::Player(sf::Texture *texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) : animation(texture, imageCount, switchTime)
{
    this->speed = speed;
    this->jumpHeight = jumpHeight;
    row = 0;
    faceRight = true;

    body.setSize(sf::Vector2f(100.0f, 150.0f));
    body.setOrigin(body.getSize() / 2.0f);
    body.setPosition(206.0f, 206.0f);
    body.setTexture(texture);
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
    velocity.x = 0.0f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        velocity.x -= speed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        velocity.x += speed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
    {
        canJump = false;
        velocity.y = -std::sqrtf(2.0f * 981.0f * jumpHeight);
    }

    // Gravity mechanic!
    velocity.y += 981.0f * deltaTime;

    if (velocity.x == 0.0f)
    {
        row = 0;
    }
    else
    {
        row = 1;
        faceRight = velocity.x > 0.0f;
    }

    animation.Update(row, deltaTime, faceRight);
    body.setTextureRect(animation.textureRect);
    body.move(velocity * deltaTime);
}

void Player::Draw(sf::RenderWindow &window)
{
    window.draw(body);
}

void Player::OnCollision(sf::Vector2f direction)
{
    if (direction.x < 0.0f)
    {
        velocity.x = 0.0f; // Collide left
    }
    else if (direction.x > 0.0f)
    {
        velocity.x = 0.0f; // Collide right
    }

    if (direction.y < 0.0f)
    {
        velocity.y = 0.0f; // Collide bottom, you landed
        canJump = true;
    }
    else if (direction.y > 0.0f)
    {
        velocity.y = 0.0f; // Collide top
    }
}
