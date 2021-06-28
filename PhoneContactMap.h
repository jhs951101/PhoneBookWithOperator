/*
 * PhoneContactMap.h
 *
 *  Created on: 2016. 4. 4.
 *      Author: cskim
 */

#ifndef PHONECONTACTMAP_H_
#define PHONECONTACTMAP_H_

#include <map>
#include "Entry.h"

typedef map<String, ValueInfo>::const_iterator MCIter;
typedef map<String, ValueInfo>::iterator MIter;
#include "PhoneContact.h"

class PhoneContactMap: public PhoneContact {
public:
	PhoneContactMap();
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
	map<String, ValueInfo> contactTable;
	MIter findLoc(String name);
	MCIter findLocConst (String name) const;
	MCIter findLocFromNumber(int number) const;
	MCIter findLocFromEmail(String email) const;
};

#endif /* PHONECONTACTMAP_H_ */
