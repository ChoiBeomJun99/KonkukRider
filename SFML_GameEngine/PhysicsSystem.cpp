#include "RigidBody.h"
#include "PhysicsSystem.h"
#include "Options.h"

PhysicsSystem* PhysicsSystem::instance;

// �����带 �����Ѵ�.
void PhysicsSystem::XENGINE_Begine_PhySics_Thread() {
	PriorityQueue<RigidBody *> temp;
	PriorityQueue<RigidBody *> used;
	while (!pq.isEmpty()) {//ť�� �����ִ� ��ü�� �ϳ��� ����.
		RigidBody * subject = pq.pop();//ť���� ��������Ʈ�� �̰� ��ü�� �����Ѵ�,
		if (!(subject->isStatic)) {
			subject->move();
		}
		else {
			subject->vX = 0;
			subject->vY = 0;
		}
		attatchAirResistance(subject);
		int collideWithWall = subject->collisionWithWall(SCREEN_X, SCREEN_Y);
		if ( collideWithWall!= 0&&this->collisionWithWall) {
			justBounce(subject, collideWithWall);
			if (!(subject->isStatic)) {
				subject->move();
			}
		}
		int i = 0;
		while (!pq.isEmpty()) {//������ ��ü�� �ϳ��� ť��
			RigidBody * target = pq.pop();//ť���� ��ü�� �̰� ��ü�� �����Ѵ�,
			int collideType = subject->isCollide(target);
			if (collideType) {
				attachCollision(subject,target,collideType);
				if (!(subject->isStatic)) {
					subject->move();
				}
				else {
					target->move();
				}
			}
			temp.push(target, i);
			i++;
		}
		i = 0;
		while (!temp.isEmpty()) {//������ ��ü�� �ϳ��� ť��
			RigidBody * target = temp.pop();//ť���� ��ü�� �̰� ��ü�� �����Ѵ�,
			pq.push(target, i);
			i++;
		}
		used.push(subject, 0);
	}
	int i = 0;
	while (!used.isEmpty()) {//ť�� ���� ���ͽ�Ų��.
		RigidBody * target = used.pop();//ť���� �̰�
		pq.push(target, i);//�������´�.
		i++;
	}
}

//�������� ť�� ��ü�� ����Ѵ�.
void PhysicsSystem::enqueue(RigidBody* target) {
	if (target != nullptr) {
		pq.push(target, 0);
	}
}

//�������� ť���� ������Ʈ�� �����Ѵ�.
void PhysicsSystem::removeTarget(RigidBody* target) {
	pq.removeAt(target);
}

//�� ��ü���� �浹ó���� �Ѵ�.
void PhysicsSystem::attachCollision(RigidBody * r1, RigidBody * r2,int xOrY) {
	float te = (r1->eles + r2->eles) / 2;
	float vX1, vY1, vX2, vY2;
	float vXC1, vYC1, vXC2, vYC2;
	float m1, m2;
	vX1 = r1->vX;
	vX2 = r2->vX;
	vY1 = r1->vY;
	vY2 = r2->vY;
	m1 = r1->mass;
	m2 = r2->mass;
	vXC1 = getCollsionSpeed(vX1, vX2, m1, m2, te);
	vXC2 = getCollsionSpeed(vX2, vX1, m2, m1, te);
	vYC1 = getCollsionSpeed(vY1, vY2, m1, m2, te);
	vYC2 = getCollsionSpeed(vY2, vY1, m2, m1, te);
	if (!(r1->isStatic)) {
		r1->vX = vXC1;
		r1->vY = vYC1;
	}
	else {
		this->justBounce(r2, xOrY);
		return;
	}
	if (!(r2->isStatic)) {
		r2->vX = vXC2;
		r2->vY = vYC2;
	}
	else {
		this->justBounce(r1, xOrY);
		return;
	}
}

//�浹 ������ �ӵ��� ����Ѵ�.
float PhysicsSystem::getCollsionSpeed(float vs,float vt,float ms,float mt,float te) {
	double massSum = ms + mt;
	double upperSeg = ((1 + te) * (mt * vt)) + (vs * (ms - (te * mt)));
	return (float)(upperSeg / massSum);
}


//�ܼ��� ������Ʈ�� ƨ���, ���� ��� ���� �浹�ϴ� ��쿡 �� �޼ҵ带 ȣ���Ѵ�.
void PhysicsSystem::justBounce(RigidBody* r1,int xOrY) {
	float te = r1->eles;
	float vX1, vY1;
	vX1 = r1->vX;
	vY1 = r1->vY;
	if (!r1->isStatic) {
		if (xOrY == 1) {
			r1->vX = -vX1 * te;
			r1->vY *= te;
		}
		else {
			r1->vY = -vY1 * te;
			r1->vX *= te;
		}
	}
}

//���� ������ �����Ѵ�.
void PhysicsSystem::attatchAirResistance(RigidBody* r1) {
	r1->vX -= (abs(r1->vX) * (r1->vX) * (0.01)) / r1->mass;
	r1->vY -= (abs(r1->vY) * (r1->vY) * (0.01)) / r1->mass;
}