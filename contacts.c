/* -------------------------------------------
Name:David Paul
Student number:115192171
Email:dpaul9@myseneca.ca
Section:Assignment 1
Date:2017-12-15
----------------------------------------------
Assignment: 2
Milestone:  1
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-1 Milestone-4 |
// |        function definitions below...            |
// +-------------------------------------------------+

// getName:
void getName(struct Name *contactName) {	//takes 2 parameter addresses, secound is a callback function
	printf("Please enter the contact's first name: ");	//request contacts first name
	scanf(" %[^\n]31s", contactName->firstName);	// get first name
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	if (yes() == 1) {		//if callback returns 1 runs sequance, (callback ask the user if they want to enter info for struct member)
		printf("Please enter the contact's middle initial(s): ");	//request contacts middle initial
		scanf(" %[^\n]7s", contactName->middleInitial);	// get middle initial
	}
	printf("Please enter the contact's last name: ");	//request contacts last name
	scanf(" %[^\n]36s", contactName->lastName);	// get last name
}

// getAddress:
void getAddress(struct Address *contactAddress) {

	printf("Please enter the contact's street number: ");	//request contacts street number
	contactAddress->streetNumber = getIntInRange(0, 1000000);// get contact street number
	printf("Please enter the contact's street name: ");	//request contacts street name
	scanf(" %[^\n]41s", contactAddress->street);	// get contact street name
	printf("Do you want to enter an apartment number? (y or n): ");
	if (yes() == 1) {	//if callback returns 1 runs sequance, (callback ask the user if they want to enter info for struct member)
		printf("Please enter the contact's apartment number: ");	//request contacts apartment number
		contactAddress->apartmentNumber = getIntInRange(0, 1000000);	// get contact apartment number
	}

	printf("Please enter the contact's postal code: ");	//request postal code
	scanf(" %8[^\n]s", contactAddress->postalCode);	//get postal code

	printf("Please enter the contact's city: ");	//request contacts city
	scanf(" %[^\n]41s", contactAddress->city);	// get contact street name
}

// getNumbers:
void getNumbers(struct Numbers *contactNumbers) {	//takes 2 parameters with pointers, secound parameter is a callback function



	printf("Please enter the contact's cell phone number: ");	//request contacts cell phone number
	getTenDigitPhone(contactNumbers->cell);	// get contact cell phone number
	printf("Do you want to enter a home phone number? (y or n): ");
	if (yes() == 1) {	//if callback returns 1 runs sequance, (callback ask the user if they want to enter info for struct member)
		printf("Please enter the contact's home phone number: ");	//request contacts home phone number
		getTenDigitPhone(contactNumbers->home);	// get contact home phone number
	}
	printf("Do you want to enter a business phone number? (y or n): ");
	if (yes() == 1) {	//if callback returns 1 runs sequance, (callback ask the user if they want to enter info for struct member)
		printf("Please enter the contact's business phone number: ");	//request contacts business phone number
		getTenDigitPhone(contactNumbers->business);	// get contact business phone number
	}
}


// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// getContact:
// Define Empty function definition below:

void getContact(struct Contact * contact) {	//get contact pointer
	getName(&contact->name);	//get contact name pointer
	getAddress(&contact->address);	//get contact address pointer
	getNumbers(&contact->numbers);	//get contact numbers pointer
}
