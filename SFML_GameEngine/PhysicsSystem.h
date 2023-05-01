#pragma once
#include "PriorityQueue.h"
#include <iostream>

class RigidBody;


class PhysicsSystem {
private:
	PriorityQueue<RigidBody*> pq;
	PhysicsSystem() {}
	static PhysicsSystem* instance;

public:
	//������ ������� �����Ѵ�.
	float gravityConstant = 9.8f;//�߷»��, 0�� ��� ���߷�
	float airResistance = 0.3f;//�������� ���, �������� ���� ������ �پ���, 0�� ��� ���������� ��������.
	bool collisionWithWall = true; //���� �浹 ������ �ϴ°�?
	static PhysicsSystem* getInstance() {
		if (PhysicsSystem::instance == NULL) {
			PhysicsSystem::instance = new PhysicsSystem();
		}
		return PhysicsSystem::instance;
	}
	void XENGINE_Begine_PhySics_Thread();
	void enqueue(RigidBody* target);
	void removeTarget(RigidBody* target);
	void attachCollision(RigidBody* r1,RigidBody * r2,int xOrY);
	void justBounce(RigidBody* r1, int xOrY);
	void attatchAirResistance(RigidBody* r1);
	float getCollsionSpeed(float vS,float vT,float mS,float mT,float tE);
};