#include "SpriteRenderer.h"
#include "RenderingCore.h"
#include <vector>



using namespace std;

RenderingCore* RenderingCore::instance;

//������ �����带 �����Ѵ�.
void RenderingCore::XENGINE_Begine_Rendering_Thread(sf::RenderWindow * window) {
		this->window = window;
		PriorityQueue<SpriteRenderer *> temp;
		this->window->clear();//â�� ������ �����
		while (!pq.isEmpty()) {//ť�� �����ִ� ��������Ʈ���� ��� â�� �׸���.
			SpriteRenderer * target = pq.pop();//ť���� ��������Ʈ�� �̰�
			temp.push(target, target->getOrder());//���� ��������Ʈ�� ����ϰ�
			this->window->draw(target->getSprite());
		}
		while (!temp.isEmpty()) {//ť�� �����ִ� ��������Ʈ���� ��� â�� �׸���.
			SpriteRenderer * target = temp.pop();//ť���� ��������Ʈ�� �̰�
			pq.push(target, target->getOrder());//���� ��������Ʈ�� ����ϰ�
		}
		window->display();
}

//������ ť�� ��������Ʈ �������� ����Ѵ�.
void RenderingCore::enqueue(SpriteRenderer* target) {
	if (target != nullptr) {
		pq.push(target, target->getOrder());
	}
}

//������ ť���� �ּҿ� �ش��ϴ� ��������Ʈ �������� ���ܽ�Ų��
void RenderingCore::removeTarget(SpriteRenderer* target) {
	pq.removeAt(target);
}