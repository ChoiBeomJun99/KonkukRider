#pragma once
#include "Component.h"
#include "GameObject.h"
#include "PriorityQueue.h"
#include <math.h>


class PhysicsSystem;



//������ �ٵ� ������Ʈ
/*
* �� ������Ʈ�� ������ ���õ� ��� �� ���������� ������ �ְ�, �ڵ����� ���� ������ �����迡 ��ϵǾ�, ���������� ���� �޴´�.
* ���� ��Ҵ� ������ ����.
* ����(���� �޴� ����, Ŭ ���� ���� �� �޴´�.), ���׸���(���� ������ �󸶳� �޴���?), ź����(�� ��ü�� �浹���� �� ��ŭ �������� ������ ��)
* x,y�� �ӵ�(�����迡�� �� ��ü�� �� �� �������� ������ �ӵ�), x,y�� �浹���� ����(�浹 ������ �� ��Ʈ�ڽ��� ũ��)
* ����ü�ΰ�?(����ü�� ���, ���� ���� ������, �ٸ� ��ü���� ������ �� ���� �ִ�.)
*/


class RigidBody : Component{
private:
	GameObject * gameObject;//�� ������Ʈ�� ������ ���� ������Ʈ.
	PhysicsSystem * pCore;//�������� �ھ�
public :
	float mass = 1;//�� ��ü�� ����
	float area = 0.5f;//���������� �޴� ����
	float eles = 0;//ź���� 0~1���̿��� ���� 1�̸� ���� ź�� �浹,0�̸� ���� ��ź�� �浹
	float vX = 0;//x,y������ �ӵ�.
	float vY = 0;
	float boxX;//�浹���� ������ x,y�� ũ��
	float boxY;
	bool isStatic = false;//������ ��ü�ΰ�? �� ��� �� ��ü�� �浹�ϸ�, ���ۿ��� �״�� �ް� �ȴ�.
	const char * getType();//�� ������Ʈ�� Ÿ���� ��ȯ�Ѵ�(RigidBody)
	RigidBody(GameObject * obj);
	~RigidBody();
	//�������� ũ�⸸ŭ ���� ���Ѵ�.
	void addForce(float angle, float power);//�� ��ü�� ���� ���Ѵ�.
	void setForce(float angle, float power);//�� ��ü�� ���� �����Ѵ�(�ʱ�ȭ �Ѵ�.)
	float getForece();//�� ��ü�� ���� ũ��
	float getDir();//�� ��ü�� ���� ����
	int isCollide(RigidBody * target);//�� ��ü�� �ٸ� ��ü�� �浹�ߴ°�??
	int collisionWithWall(int lX, int lY);//������ �浹����.
	void move();// �� ��ü�� �ӵ���ŭ �̵� ��Ų��.
	Transform getTransform();//�� ��ü�� ���� ������Ʈ�� Ʈ������ ��ȯ.
	void setPos(float x,float y);//�� ��ü�� ���� ������Ʈ�� ��ǥ�� set�Ѵ�.
};