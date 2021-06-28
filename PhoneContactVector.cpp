/*
 * PhoneContactVector.cpp
 *
 *  Created on: 2017. 3. 27.
 *      Author: cskim
 */
#include <iostream>
#include "String.h"
#include <vector>
using namespace std;

#include "Entry.h"
#include "PhoneContactVector.h"

ValueInfo viNull2;

PhoneContactVector::PhoneContactVector() { }

ValueInfo PhoneContactVector::find(String name) const {
	int loc = findLoc(name);
	if (loc == -1)
		return viNull2; // not found
	return vectorPhoneBook[loc].valueInfo;
}
bool PhoneContactVector::insert(String name, int number, String email){
	int loc = findLoc(name);

	if (loc == -1){ // insert
		vectorPhoneBook.push_back(Entry(name, number, email));
		return false;
	}
	else {
		cout << "***Error -- Duplicated Name" << endl;
	}

	return true;
}

bool PhoneContactVector::remove(String name){
	int loc = findLoc(name);

	if (loc != -1){ // there exist name
		// remove array entry at loc
		for (int i=loc+1; i<vectorPhoneBook.size(); ++i){
			vectorPhoneBook[i-1] = vectorPhoneBook[i];
		}
		vectorPhoneBook.pop_back();
	}
	else {
		cout << "***Error -- Name not found" << endl;
		return false;
	}

	return true;
}

void PhoneContactVector::listAll() const {
	cout.setf(ios::left);

	cout << "Name      " << "Number      " << "Email" << endl;
	for (int i=0; i<vectorPhoneBook.size(); ++i){
		cout << "  " << vectorPhoneBook[i].phoneName
			 << "  " << vectorPhoneBook[i].valueInfo.phoneNumber
			 << "  " << vectorPhoneBook[i].valueInfo.emailAddress << endl;
	}
}
int PhoneContactVector::findLoc(String name) const {
	for (int i=0; i<vectorPhoneBook.size(); ++i){
		if (vectorPhoneBook[i].phoneName == name)
			return i;
	}
	return -1; // not found
}

bool PhoneContactVector::update(String name, int number, String email){
	if(!update(name, number))
		return false;
	else
		update(name, email);

	return true;
}
bool PhoneContactVector::update(String name, int number){
	int loc = findLoc(name);

	if(loc == -1){
		cout << "***Error -- Name not found" << endl;
		return false;
	}
	else {
		vectorPhoneBook[loc].valueInfo.phoneNumber = number;
	}

	return true;
}

bool PhoneContactVector::update(String name, String email){
	int loc = findLoc(name);

	if(loc == -1){
		cout << "***Error -- Name not found" << endl;
		return false;
	}
	else {
		vectorPhoneBook[loc].valueInfo.emailAddress = email;
	}

	return true;
}

String PhoneContactVector::findName(int number) const {
	int loc = findLocFromNumber(number);

	if(loc == -1)
		return "";

	return vectorPhoneBook[loc].phoneName;
}
String PhoneContactVector::findName(String email) const {
	int loc = findLocFromEmail(email);

	if(loc == -1)
		return "";

	return vectorPhoneBook[loc].phoneName;
}

int PhoneContactVector::findLocFromNumber(int number) const {
	for (int i=0; i<vectorPhoneBook.size(); ++i){
		if (vectorPhoneBook[i].valueInfo.phoneNumber == number)
			return i;
	}
	return -1; // not found
}

int PhoneContactVector::findLocFromEmail(String email) const {
	for (int i=0; i<vectorPhoneBook.size(); ++i){
		if (vectorPhoneBook[i].valueInfo.emailAddress == email)
			return i;
	}
	return -1; // not found
}
