/*
 * CPhoneContact.h
 *
 *  Created on: 2016. 3. 28.
 *      Author: cskim
 */

#ifndef PHONECONTACTLIST_H_
#define PHONECONTACTLIST_H_

#include "List.h"
#include "Entry.h"
#include "PhoneContact.h"
/*
 *
 */
typedef Iterator LIter;

class PhoneContactList: public PhoneContact {
public:
	PhoneContactList();
	bool insert(String name, int number, String email);
	bool update(String name, int number, String email);
	bool update(String name, int number);
	bool update(String name, String email);
	bool remove(String name);

	ValueInfo find(String name) const;
	String findName(int number) const;
	String findName(String email) const;

	void listAll()const;

private:
	List contactTable;
	LIter findLoc(String name);
	LIter findLocConst (String name) const;
	LIter findLocFromNumber(int number) const;
	LIter findLocFromEmail(String email) const;
};

#endif /* PHONECONTACTLIST_H_ */
