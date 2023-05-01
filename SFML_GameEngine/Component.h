#pragma once
//������Ʈ Ŭ������ �⺻������ ���� ������Ʈ�� ������ ���� �� �ִ�.
//�� ������Ʈ�� ��ӹ޾� �پ��� ������Ʈ�� ������ �� �ִ�.

class Component
{
protected:
	bool active;	//�� ������Ʈ�� Ȱ�� ����
public :
	Component() {
		this->active = true;
	}
	//�� ������Ʈ�� �̸��� ��ȯ�Ѵ�.
	virtual const char * getType() {
		return "Component";
	}

	//�� ������Ʈ�� Ȱ�� ���¸� �����Ѵ�.
	//�� Ŭ������ ��ӹ��� ��� �� �޼ҵ带 �������̵� �Ͽ�, ���� ���ҽ��� ���� ó���� ���־�� �Ѵ�.
	virtual void setActive(bool isActive) {
		this->active = isActive;
	}

	bool isActive() {
		return active;
	}
	
};