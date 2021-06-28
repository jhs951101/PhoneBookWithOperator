/*
 * PhoneContact.h
 *
 *  Created on: 2016. 4. 4.
 *      Author: cskim
 */

#ifndef PHONECONTACT_H_
#define PHONECONTACT_H_

#include "String.h"
using namespace std;

class PhoneContact {  // 생성자를 제외한 모든 함수가 순수 가상 함수, 서브클래스에서는 메소드 오버라이딩이 일어남
public:
	PhoneContact(){}
	virtual bool insert(String name, int number, String email)=0;
	virtual bool update(String name, int number, String email)=0;
	virtual bool update(String name, int number)=0;
	virtual bool update(String name, String email)=0;  // update() - 메소드 오버로딩
	virtual bool remove(String name)=0;

	virtual ValueInfo find(String name) const=0;
	virtual String findName(int number) const=0;
	virtual String findName(String email) const=0;  // findName() - 메소드 오버로딩

	virtual void listAll()const=0;
};

#endif /* PHONECONTACT_H_ */
