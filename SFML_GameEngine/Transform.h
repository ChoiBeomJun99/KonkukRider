#pragma once
class Transform {
public:
	float x;//x,y��ǥ
	float y;
	float xSize;//x,y�� ũ��
	float ySize;
	float angle;//�̹����� ����
	Transform() {//����Ʈ ������
		x = 0;
		y = 0;
		xSize = 1;
		ySize = 1;
		angle = 0;
	}
	void setPos(float x, float y) {
		this->x = x;
		this->y = y;
	}
};