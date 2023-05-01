
#include "RigidBody.h"
#include "PhysicsSystem.h"


RigidBody::RigidBody(GameObject * obj) {
	this->gameObject = obj;
	this->pCore = PhysicsSystem::getInstance();
	(this->pCore)->enqueue(this);
}

RigidBody::~RigidBody() {
	(this->pCore)->removeTarget(this);
}


//�� ��ü�� ���� ���Ѵ�.
//�Ķ���� ���� (angle : ���� ���� ����(360�� ��), power : ���� ���� ũ��)
void RigidBody::addForce(float angle, float power) {
	float calculatedPower = power / (this->mass);
	vX += sin(angle*0.017453)* calculatedPower;
	vY += cos(angle*0.017453)* calculatedPower;
}


//�� ��ü�� �ӵ��� �����Ѵ�, ������ ��� ���� �ش� �ӵ��� ���õȴ�.
//�Ķ���� ���� (angle : ����, power : �ӵ�)
void RigidBody::setForce(float angle, float power) {
	vX = sin(angle*0.017453)* power;
	vY = cos(angle*0.017453)* power;
}


//�� ��ü�� ���� ũ�⸦ ��ȯ�Ѵ�.
//�Ķ���� ���� ()
float RigidBody::getForece() {
	double sqare = (vX * vX) + (vY *vY);
	return sqrt(sqare);
}

//�� ��������Ʈ �������� ������ �߿䵵�� �����Ѵ�. �������� �տ� ������ �ȴ�.
//�Ķ���� ���� (i : �� ������ �켱����)
float RigidBody::getDir() {
	return atan2(vY,vX);
}


//�� ������Ʈ�� Ÿ���� ��ȯ�Ѵ� : RigidBody.
//�Ķ���� ���� ()
const char * RigidBody::getType() {
	return "RigidBody";
}

//�� ������Ʈ�� ���� ������Ʈ�� Ʈ���� ���� ��ȯ�Ѵ�.
Transform RigidBody::getTransform() {
	return this->gameObject->transform;
}


//�� ��ü�� �ٸ� ��ü�� �浹 ���θ� ��ȯ�Ѵ�.
int RigidBody::isCollide(RigidBody * target) {
	if (target == nullptr) {
		return false;
	}
	Transform tPos = target->getTransform();
	Transform sPos = this->getTransform();
	float xGap, yGap;
	float xCol, yCol;
	xGap = abs(tPos.x - sPos.x);
	yGap = abs(tPos.y - sPos.y);
	xCol = target->boxX + this->boxX;
	yCol = target->boxY + this->boxY;
	if (xGap < xCol && yGap < yCol){
		float difX, difY;
		difX = xCol - xGap;//�Ĺ��� ����
		difY = yCol - yGap;
		if (isStatic) {//�浹 ��ü�� ��ǥ ����
			difX /= target->vX;
			difY /= target->vY;
			difX = abs(difX);
			difY = abs(difY);
			if (difX < difY) {
				int dX;
				if (tPos.x > sPos.x) {
					dX = sPos.x + xCol + 1;
				}
				else {
					dX = sPos.x - xCol - 1;
				}
				target->setPos(dX, tPos.y);
				return 1;
			}
			else {
				int dY;
				if (tPos.y > sPos.y) {
					dY = sPos.y + yCol + 1;
				}
				else {
					dY = sPos.y - yCol - 1;
				}
				target->setPos(tPos.x, dY);
				return -1;
			}
		}
		else {
			difX /= this->vX;
			difY /= this->vY;
			difX = abs(difX);
			difY = abs(difY);
			if (difX < difY) {
				int dX;
				if (tPos.x < sPos.x) {
					dX = tPos.x + xCol + 1;
				}
				else {
					dX = tPos.x - xCol - 1;
				}
				this->setPos(dX, sPos.y);
				return -1;
			}
			else {
				int dY;
				if (tPos.y < sPos.y) {
					dY = tPos.y + yCol + 1;
				}
				else {
					dY = tPos.y - yCol - 1;
				}
				this->setPos(sPos.x, dY);
				return 1;
			}
		}
	}else {
		return 0;
	}
}

//�� ��ü�� ���� �浹���θ� ��ȯ�Ѵ�.
//�Ķ���� ���� (lX : x�� â�� ����, lY : y�� â�� ����)
int RigidBody::collisionWithWall(int lX, int lY) {
	Transform sPos = this->getTransform();
	int x, y;
	x = sPos.x;
	y = sPos.y;
	if (x < this->boxX) {
		this->gameObject->transform.x = this->boxX;
		return 1;
	}
	if (x > lX - this->boxX) {
		this->gameObject->transform.x = lX - this->boxX;
		return 1;
	}
	if (y < this->boxY) {
		this->gameObject->transform.y = this->boxY;
		return -1;
	}
	if (y > lY - this->boxY) {
		this->gameObject->transform.y = lY - this->boxY;
		return -1;
	}
	return 0;
}


void RigidBody::move() {
	this->gameObject->transform.x += this->vX;
	this->gameObject->transform.y += this->vY;
}


void RigidBody::setPos(float x,float y) {
	printf("��ǥ�� X : %f, Y : %f�� ������\n", x, y);
	this->gameObject->transform.x = x;
	this->gameObject->transform.y = y;
}