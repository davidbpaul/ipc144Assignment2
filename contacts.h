#ifndef CONTACTS_H_
#define CONTACTS_H_
// Header file contents... 
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

//------------------------------------------------------
// Structure Types
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-1 Milestone-4 |
// |        structures here...                       |
// +-------------------------------------------------+

// Structure type Name declaration
struct Name {	//declare struct. typedef allows for simplified calling
	char firstName[31];	//define firstName member as array with 30 characters
	char middleInitial[7];	//define middleInitial member as array with 6 characters
	char lastName[36];	//define lastName member as array with 35 characters
};
// Structure type Address declaration
// Place your code here...
struct Address {	//declare struct. typedef allows for simplified calling
	unsigned streetNumber;	//define streetNumber member as unsigned integer
	char street[41];	//define street member as array with 40 characters
	unsigned apartmentNumber;	//define apartmentNumber member as unsigned integer
	char postalCode[8];	//define postalCode member as array with 7 characters
	char city[41];	//define city member as array with 40 characters

};

// Structure type Numbers declaration
// Place your code here...
// NOTE: Modify the C String arrays sizes according to the
//       Assignment-2 Milestone-1 specifications
struct Numbers {	//declare struct. typedef allows for simplified calling
	char cell[11];	//define cell member as array with 20 characters
	char home[11];	//define home member as array with 20 characters
	char business[11];	//define business member as array with 20 characters
};

// Structure type Contact declaration
// NOTE:  Make sure the structure name does not have an 's' on the end!
// Place your code here...

struct Contact {	//declare struct. typedef allows for simplified calling
	struct Name name;
	struct Address address;
	struct Numbers numbers;

};

//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-1 Milestone-4 |
// |        function prototypes here...              |
// +-------------------------------------------------+


// Get and store from standard input the values for Name
// Place your code here...

void getName(struct Name *contactName);	//get Name information

										// Get and store from standard input the values for Address
										// Place your code here...
void getAddress(struct Address *contactAddress);	//get address information

													// Get and store from standard input the values for Numbers
													// Place your code here...
void getNumbers(struct Numbers *contactNumbers);	//get phone information

													// Get and store from standard input the values for a Contact (NOT: Contacts)
													// NOTE:  Make sure the structure Contact does not have an 's' on the end!
													// Put function prototype below:

void getContact(struct Contact *);


// ----------------------------------------------------------------------------
// DO NOT remove the below line (closing of the "safeguard" condition)
#endif // !CONTACTS_H_