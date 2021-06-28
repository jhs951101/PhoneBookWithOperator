/*
 * PhoneContactVector.h
 *
 *  Created on: 2017. 3. 27.
 *      Author: cskim
 */

#ifndef PHONECONTACTVECTOR_H_
#define PHONECONTACTVECTOR_H_

#include <vector>
#include "Entry.h"
#include "PhoneContact.h"
/*
 *
 */
class PhoneContactVector: public PhoneContact {
public:
	PhoneContactVector();
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
	vector<Entry> vectorPhoneBook;
	int findLoc(String name) const;
	int findLocFromNumber(int number) const;
	int findLocFromEmail(String email) const;
};

#endif /* PHONECONTACTVECTOR_H_ */
