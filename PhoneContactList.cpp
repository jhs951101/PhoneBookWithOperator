/*
 * CPhoneContact.cpp
 *
 *  Created on: 2016. 3. 28.
 *      Author: cskim
 */
#include <iostream>
#include "String.h"
#include "List.h"
using namespace std;

#include "Entry.h"
#include "PhoneContactList.h"

ValueInfo viNull1;

PhoneContactList::PhoneContactList() { }

ValueInfo PhoneContactList::find(String name) const {
	LIter citer = findLocConst(name);
	if (citer==contactTable.end())
		return viNull1;
	return citer->valueInfo;
}
bool PhoneContactList::insert(String name, int number, String email){
	LIter iter = findLoc(name);

	if (iter != contactTable.end()){
		cout << "***Error -- Duplicated Name" << endl;
		return false;
	}
	else{
		contactTable.push_back(Entry(name, number, email));
	}

	return true;
}

bool PhoneContactList::remove(String name){
	LIter iter = findLoc(name);

	if (iter == contactTable.end()){
		cout << "***Error -- Name not found" << endl;
		return false;
	}
	else{
		contactTable.erase(iter);
	}

	return true;
}

void PhoneContactList::listAll() const{
	LIter citer;

	cout << "Name      " << "Number      " << "Email" << endl;
	for (citer=contactTable.begin(); citer!=contactTable.end(); citer++){
		cout << citer->phoneName
			 << "  " << citer->valueInfo.phoneNumber
			 << "  " << citer->valueInfo.emailAddress << endl;
	}
}
LIter PhoneContactList::findLoc(String name){
	LIter iter;
	for (iter=contactTable.begin(); iter!=contactTable.end(); iter++){
		if (iter->phoneName == name)
			return iter;
	}
	return iter; // not found, iter==end()
}
LIter PhoneContactList::findLocConst (String name) const {
	LIter citer;
	for (citer=contactTable.begin(); citer!=contactTable.end(); citer++){
		if (citer->phoneName == name)
			return citer;
	}
	return citer; // not found, iter==end()
}

bool PhoneContactList::update(String name, int number, String email){
	if(!update(name, number))
		return false;
	else
		update(name, email);

	return true;
}

bool PhoneContactList::update(String name, int number){
	LIter iter = findLoc(name);

	if (iter == contactTable.end()){
		cout << "***Error -- Name not found" << endl;
		return false;
	}
	else {
		iter->valueInfo.phoneNumber = number;
	}

	return true;
}

bool PhoneContactList::update(String name, String email){
	LIter iter = findLoc(name);

	if (iter == contactTable.end()){
		cout << "***Error -- Name not found" << endl;
		return false;
	}
	else {
		iter->valueInfo.emailAddress = email;
	}

	return true;
}

String PhoneContactList::findName(int number) const {
	LIter citer = findLocFromNumber(number);

	if(citer == contactTable.end())
		return "";

	return citer->phoneName;
}

String PhoneContactList::findName(String email) const {
	LIter citer = findLocFromEmail(email);

	if(citer == contactTable.end())
		return "";

	return citer->phoneName;
}

LIter PhoneContactList::findLocFromNumber(int number) const {
	LIter citer;

	for (citer=contactTable.begin(); citer!=contactTable.end(); citer++){
		if (citer->valueInfo.phoneNumber == number)
			return citer;
	}

	return citer; // not found, iter==end()
}

LIter PhoneContactList::findLocFromEmail(String email) const {
	LIter citer;

	for (citer=contactTable.begin(); citer!=contactTable.end(); citer++){
		if (citer->valueInfo.emailAddress == email)
			return citer;
	}

	return citer; // not found, iter==end()
}
