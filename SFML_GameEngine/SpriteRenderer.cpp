//SpriteRenderer�� �Լ��鿡 ���� Implementation
#include "SpriteRenderer.h"
#include "RenderingCore.h"



//�� ��������Ʈ �������� ������ �߿䵵�� �����Ѵ�. �������� �տ� ������ �ȴ�.
//�Ķ���� ���� (i : �� ������ �켱����)
void SpriteRenderer::setOrder(int i) {
	(this->rCore)->removeTarget(this);
	sortOrder = i;
	(this->rCore)->enqueue(this);
}

//�� ��������Ʈ �������� ������ �߿䵵�� ��ȯ�Ѵ�.
//�Ķ���� ���� ()
int SpriteRenderer::getOrder() {
	return sortOrder;
}

SpriteRenderer::~SpriteRenderer() {
	(this->rCore)->removeTarget(this);//�� ������Ʈ�� �Ŵ������� ������ ���� ��û.

}

SpriteRenderer::SpriteRenderer(GameObject * gameObejct) {
	this->gameObject = gameObejct;
	this->sortOrder = 0;
	this->rCore = RenderingCore::getInstance();
	(this->rCore)->enqueue(this);
}

GameObject * SpriteRenderer::getGameObject() {
	return this->gameObject;
}

//�� �������� ������ �� �ؽ��ĸ� �����Ѵ�.
void SpriteRenderer::setTexture(const char * ptr) {
	sf::Texture temp;
	if (!temp.loadFromFile(ptr)) {
		printf("Log::SpriteRenderer::%p - ImageLoadFailError( %s )", this, ptr);
	}
	else {
		this->texture = temp;
	}
}

sf::Sprite SpriteRenderer::getSprite() {
	this->sprite.setTexture(this->texture);
	this->sprite.setOrigin(sf::Vector2f(this->imageXPoint, this->imageYPoint));
	this->sprite.setPosition(sf::Vector2f(this->gameObject->transform.x,SCREEN_Y - (this->gameObject->transform.y)));
	this->sprite.setRotation(this->gameObject->transform.angle);
	this->sprite.setScale(sf::Vector2f(this->gameObject->transform.xSize, this->gameObject->transform.ySize));
	return (this->sprite);
}

const char * SpriteRenderer::getType() {
	return "SpriteRenderer";
}
