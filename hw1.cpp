/*
 * main.cpp
 *
 *  Created on: Mar 30, 2012
 *      Author: cskim
 */

#include <iostream>
#include "String.h"

using namespace std;

#include "PhoneContactList.h"
#include "PhoneContactMap.h"
#include "PhoneContactVector.h"

String nameData[] = {"K Honoka", "S Umi", "M Kotori", "N Maki", "H Rin",
				  "K Hanayo", "T Nozomi", "A Eri", "Y Nico", "JH Shim"};
int numberData[] = {3958, 2573, 2850, 1649, 9274, 1627, 9742, 4839, 2785, 1049};
String emailData[] = {
		"kHonoka@lovelive.com", "sUmi@lovelive.com", "mKotori@lovelive.com", "nMaki@lovelive.com", "hRin@lovelive.com",
		"kHanayo@lovelive.com", "tNozomi@lovelive.com", "aEri@lovelive.com", "yNico@lovelive.com", "tails1101@naver.com"
		};

PhoneContactList pbList;
PhoneContactMap pbMap;
PhoneContactVector pbVector;

int incount = 10;
void testPhoneBook(PhoneContact* pb, String pbType){

	cout << "***Test "+pbType+"PhoneBook***" << endl;

	for (int i=0; i < incount; ++i){
		pb->insert(nameData[i], numberData[i], emailData[i]);
	}

	// �����ϱ� ����  ��ȸ

	cout << "���Ե� ���� ��ü ��ȸ" << endl;
	pb->listAll();
	cout << endl;

	// insert, remove, update

	cout << "�̹� �����ϴ� �̸��� insert (error)" << endl;
	pb->insert("K Honoka", 3958, "kHonoka@lovelive.com");
	cout << endl;

	cout << "���� �̸��� insert" << endl;
	pb->insert("S Riko", 6937, "sRiko@loveliveSunshine.com");
	cout << endl;

	cout << "�����ϴ� �̸��� remove" << endl;
	pb->remove("JH Shim");
	cout << endl;

	cout << "���������� �ʴ� �̸��� remove (error)" << endl;
	pb->remove("K Ruby");
	cout << endl;

	cout << "�����ϴ� �̸��� update" << endl;
	pb->update("M Kotori", 3672, "kotoriDaisuki@lovelive.com");
	cout << endl;

	cout << "���������� �ʴ� �̸��� update (error)" << endl;
	pb->update("T Chika", 2759, "tChika@loveliveSunshine.com");
	cout << endl;

	// �̸����κ��� ��ȣ �Ǵ� �̸��� �ּ� ã�Ƴ���

	cout << "T Nozomi�� ��ȣ�� �����ΰ�? : " << pb->find("T Nozomi").phoneNumber << endl;
	cout << endl;

	cout << "A Eri�� �̸��� �ּҴ� �����ΰ�? : " << pb->find("A Eri").emailAddress << endl;
	cout << endl;

	// ��ȣ �Ǵ� �̸��� �ּҷκ��� �̸� ã�Ƴ���

	cout << "�����ϴ� ��ȣ�κ��� �̸� ã�Ƴ���" << endl;
	cout << "��ȣ 2785�� ������ ��ȣ�ΰ�? : " << pb->findName(2785) << endl;
	cout << endl;

	cout << "���������� �ʴ� ��ȣ�κ��� �̸� ã�Ƴ���" << endl;
	cout << "4478�� ������ ��ȣ�ΰ�? : " << pb->findName(4478) << endl;
	cout << endl;

	cout << "�����ϴ� �̸��� �ּҷκ��� �̸� ã�Ƴ���" << endl;
	cout << "nMaki@lovelive.com �� ������ �̸��� �ּ��ΰ�? : " << pb->findName("nMaki@lovelive.com") << endl;
	cout << endl;

	cout << "���������� �ʴ� �̸��� �ּҷκ��� �̸� ã�Ƴ���" << endl;
	cout << "kHanamaru@loveliveSunshine.com �� ������ �̸��� �ּ��ΰ�? : " << pb->findName("kHanamaru@loveliveSunshine.com") << endl;
	cout << endl;

	cout << "��ȣ�κ��� �̸��� ã�Ƴ� ���� �ٸ� ���ڿ��� ���ϱ�" << endl;
	cout << "2573�� ������ ��ȣ�̰�, ���ڿ� 'W You'�ϰ� ������ �� �����? : " << endl;

	String stringToCompare = pb->findName(2573);

	if(stringToCompare == "W You")
		cout << "findName(2573) == W You : True " << endl;
	if(stringToCompare != "W You")
		cout << "findName(2573) != W You : True " << endl;
	if(stringToCompare >= "W You")
		cout << "findName(2573) >= W You : True " << endl;
	if(stringToCompare > "W You")
		cout << "findName(2573) > W You : True " << endl;
	if(stringToCompare <= "W You")
		cout << "findName(2573) <= W You : True " << endl;
	if(stringToCompare < "W You")
		cout << "findName(2573) < W You : True " << endl;

	cout << endl;

	// ������ ����  ��ȸ

	cout << "������ ���� ��ü ��ȸ" << endl;
	pb->listAll();
	cout << endl;
}

int main ()
{

	PhoneContact* pBooks[] = { &pbList , &pbMap, &pbVector };
	String pbTypes[] = { "List", "Map", "Vector" };

	for (int i=0; i<3; ++i){ // i<3
		testPhoneBook(pBooks[i], pbTypes[i]);
	}

	return 0;
}
