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

	// 수정하기 전의  조회

	cout << "삽입된 정보 전체 조회" << endl;
	pb->listAll();
	cout << endl;

	// insert, remove, update

	cout << "이미 존재하는 이름을 insert (error)" << endl;
	pb->insert("K Honoka", 3958, "kHonoka@lovelive.com");
	cout << endl;

	cout << "없는 이름을 insert" << endl;
	pb->insert("S Riko", 6937, "sRiko@loveliveSunshine.com");
	cout << endl;

	cout << "존재하는 이름을 remove" << endl;
	pb->remove("JH Shim");
	cout << endl;

	cout << "존재하지도 않는 이름을 remove (error)" << endl;
	pb->remove("K Ruby");
	cout << endl;

	cout << "존재하는 이름을 update" << endl;
	pb->update("M Kotori", 3672, "kotoriDaisuki@lovelive.com");
	cout << endl;

	cout << "존재하지도 않는 이름을 update (error)" << endl;
	pb->update("T Chika", 2759, "tChika@loveliveSunshine.com");
	cout << endl;

	// 이름으로부터 번호 또는 이메일 주소 찾아내기

	cout << "T Nozomi의 번호는 무엇인가? : " << pb->find("T Nozomi").phoneNumber << endl;
	cout << endl;

	cout << "A Eri의 이메일 주소는 무엇인가? : " << pb->find("A Eri").emailAddress << endl;
	cout << endl;

	// 번호 또는 이메일 주소로부터 이름 찾아내기

	cout << "존재하는 번호로부터 이름 찾아내기" << endl;
	cout << "번호 2785은 누구의 번호인가? : " << pb->findName(2785) << endl;
	cout << endl;

	cout << "존재하지도 않는 번호로부터 이름 찾아내기" << endl;
	cout << "4478은 누구의 번호인가? : " << pb->findName(4478) << endl;
	cout << endl;

	cout << "존재하는 이메일 주소로부터 이름 찾아내기" << endl;
	cout << "nMaki@lovelive.com 은 누구의 이메일 주소인가? : " << pb->findName("nMaki@lovelive.com") << endl;
	cout << endl;

	cout << "존재하지도 않는 이메일 주소로부터 이름 찾아내기" << endl;
	cout << "kHanamaru@loveliveSunshine.com 은 누구의 이메일 주소인가? : " << pb->findName("kHanamaru@loveliveSunshine.com") << endl;
	cout << endl;

	cout << "번호로부터 이름을 찾아낸 다음 다른 문자열과 비교하기" << endl;
	cout << "2573은 누구의 번호이고, 문자열 'W You'하고 비교했을 때 결과는? : " << endl;

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

	// 수정한 후의  조회

	cout << "수정된 정보 전체 조회" << endl;
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
