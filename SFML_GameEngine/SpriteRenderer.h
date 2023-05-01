#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "PriorityQueue.h"
#include "Component.h"


class RenderingCore;


//��������Ʈ ������ ������Ʈ Ŭ����
/*
* �� Ŭ������ ��������Ʈ�� ������ �ְ�, �� ��������Ʈ�� ������ �ھ ���� ȭ�鿡 ������ �ȴ�.
* ��������Ʈ�� ������ ���� �����ȴ�.
* ȭ�鿡 ����� �ؽ���(�̹���) -> ex ): png,jpg,bmp,jpeg ����� �̹��� ���� 
* �ؽ����� ȸ�� ���� -> ex ) : ���� �ٶ󺸴� ��ž
* �ؽ����� ���� -> ex ) : �ҷ��� �̹����� �󸶳� �����ϰ� �� ��(�ɸ��Ͱ� �����ϸ� ����������.)
* �ؽ����� ���� ����ġ -> ex) : ��� ���� �̹����� �־��µ�, ������(255,0,0)�� ����ġ�� �ؽ��Ŀ� �����Ͽ�, ���� ������ �Ǿ���.
* �ؽ����� ũ�� -> ex) : �ؽ��ĸ� x,y������ ���Ͽ� �󸶳� Ȯ�� �Ǵ� ��� ��ų��(�̹����� ũ��)
* ��������Ʈ�� �� 5���� ��Ҹ� �����Ͽ� ���ο� �ý��ĸ� �����ϰ�, �̸� �츮�� ��������Ʈ��� �θ� �� �ִ�.
*/
class SpriteRenderer : Component {
private:
	int sortOrder;//������ �߿䵵, ��������, ȭ���� �տ� ������ �ȴ�.
	sf::Sprite sprite;//�� ��������Ʈ �������� ������ �� ��������Ʈ
	sf::Texture texture;//�⺻���� �� �̹���
	GameObject* gameObject;//�� �������� �����ϴ� ���� ������Ʈ
	RenderingCore* rCore;//������ �ھ� ����
public :
	float imageXPoint = 12.5;//�̹����� X,Y�߽���
	float imageYPoint = 20;
	void setOrder(int i);//�� �������� �߿䵵�� �����Ѵ�.
	int getOrder();//�� �������� �߿䵵�� ��ȯ�Ѵ�.
	~SpriteRenderer();//�Ҹ���, �Ҵ�� ���ҽ����� ��� �����Ѵ�.
	SpriteRenderer(GameObject * gameObejct);//������, �� ������Ʈ�� ������ ���� ������Ʈ�� ������ ��
	GameObject * getGameObject();//�� �������� �����ϴ� ���� ������Ʈ�� ��ȯ�Ѵ�.
	void setTexture(const char * ptr);//�� �������� ������ �� �̹����� �ε��Ͽ� �����Ѵ�.
	sf::Sprite getSprite();//�� �������� ������ �� ��������Ʈ�� ��ȯ�Ѵ�.
	const char * getType();//�� ������Ʈ�� Ÿ���� ��ȯ�Ѵ�(SpriteRenderer)

};


