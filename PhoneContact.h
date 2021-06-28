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

class PhoneContact {  // �����ڸ� ������ ��� �Լ��� ���� ���� �Լ�, ����Ŭ���������� �޼ҵ� �������̵��� �Ͼ
public:
	PhoneContact(){}
	virtual bool insert(String name, int number, String email)=0;
	virtual bool update(String name, int number, String email)=0;
	virtual bool update(String name, int number)=0;
	virtual bool update(String name, String email)=0;  // update() - �޼ҵ� �����ε�
	virtual bool remove(String name)=0;

	virtual ValueInfo find(String name) const=0;
	virtual String findName(int number) const=0;
	virtual String findName(String email) const=0;  // findName() - �޼ҵ� �����ε�

	virtual void listAll()const=0;
};

#endif /* PHONECONTACT_H_ */
