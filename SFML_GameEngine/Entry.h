#pragma once

//엔트리 클래스
//엔트리 클래스는 우선순위 큐에 들어갈 자료형을 정의한다
/* 키 캆과 데이터 값을 저장한다
생성할 때, 데이터 값의 타입을 정의해 주어야 한다.
*/
template <typename T>
class Entry {
public : 
	T data;//데이터 값
	int key;//키 값
	Entry(T data, int key) {
		this->data = data;
		this->key = key;
	}
};