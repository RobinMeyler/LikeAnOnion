#include "Tree.h"

Tree::Tree(sf::Texture & t_sceneryTexture)
{
	m_sprite.setTexture(t_sceneryTexture);
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 2);
}

Tree::~Tree()
{
}

void Tree::initilaize(MyVector3 t_position, Layers t_layer)
{
	m_position = t_position;
	m_layer = t_layer;

	m_sprite.setPosition(m_position);
	
}

void Tree::render(sf::RenderWindow & t_window)
{
	t_window.draw(m_sprite);
}

sf::Sprite * Tree::getBody()
{
	return &m_sprite;
}

Layers Tree::getLayer()
{
	return m_layer;
}