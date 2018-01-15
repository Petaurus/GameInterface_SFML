////////////////////////////////////////////////
// Include
#include "camera.h"
#include "tools\vec2.h"

////////////////////////////////////////////////
// Class Camera
Camera::Camera()
{
	m_position = Vec2();
	m_size = Vec2();

	m_renderTexture = 0;

	m_view = sf::View();
}

Camera::Camera(int width, int height)
{
	m_renderTexture = new sf::RenderTexture();
	m_renderTexture->create(width, height);

	m_size = Vec2(width, height);
	m_halfSize = m_size / 2;
	m_view = sf::View(sf::FloatRect(0, 0, width, height));
	m_position = Vec2();
	m_onScreenPosition = Vec2();

	//m_sprite.setOrigin((float)width / 2, (float)height / 2);

	m_backgoundColor = sf::Color(25, 26, 29);
}

Camera::~Camera()
{
	/*if (m_renderTexture)
		delete m_renderTexture;*/
}

sf::Sprite& Camera::getSprite()
{
	m_renderTexture->display();
	m_sprite.setTexture(m_renderTexture->getTexture());

	//m_renderTexture->clear(m_backgoundColor);

	return m_sprite;
}

void Camera::setPosition(Vec2 position)
{
	m_view.move(position.x - m_position.x, position.y - m_position.y);
	m_renderTexture->setView(m_view);
	m_position = position;
}