#pragma once

//��Ʈ�� Ŭ����
//��Ʈ�� Ŭ������ �켱���� ť�� �� �ڷ����� �����Ѵ�
/* Ű ���� ������ ���� �����Ѵ�
������ ��, ������ ���� Ÿ���� ������ �־�� �Ѵ�.
*/
template <typename T>
class Entry {
public : 
	T data;//������ ��
	int key;//Ű ��
	Entry(T data, int key) {
		this->data = data;
		this->key = key;
	}
};