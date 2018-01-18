/* -------------------------------------------
Name:David Paul
Student number:115192171
Email:dpaul9@myseneca.ca
Section:Assignment 1
Date:2017-12-15
----------------------------------------------
Assignment: 2
Milestone:  1
----------------------------------------------
---------------------------------------------------------------------
Description: This header file modularizes general helper functions to
help reduce redundant coding for common repetative tasks.
---------------------------------------------------------------------*/

// HINT: 
// You will most likely want to include this header file
// in other files of the project since it provides general 
// helper functions that can be used throughout.

#include "contacts.h"
//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// Clear the standard input buffer
void clearKeyboard(void);	//define function

							// pause:
							// Put function prototype below:
void pause(void);	//define function
					// getInt:
					// Put function prototype below:
int getInt(void);	//define function
					// getIntInRange:
					// Put function prototype below:
int getIntInRange(int one, int two);	//define function
										// yes:
										// Put function prototype below:
int yes(void);	//define function
				// menu:
				// Put function prototype below:
int menu(void);	//define function
				// ContactManagerSystem:
				// Put function prototype below:
void ContactManagerSystem(void);	//define function
									// +-------------------------------------------------+
									// | ====== Assignment 2 | Milestone 3 =======       |
									// +-------------------------------------------------+
									// | Put new function prototypes below...            |
									// +-------------------------------------------------+

									// Generic function to get a ten-digit phone number (provided for you)
void getTenDigitPhone(char number[]);

// findContactIndex (provided for you)
int findContactIndex(const struct Contact contacts[], int size, const char num[]);


// displayContactHeade
// put function prototype here:

void displayContactHeader(void);

// displayContactFooter:
// put function prototype here:
void displayContactFooter(int a);

// displayContact:
// put function prototype here:
void displayContact(const struct Contact* contacts);

// displayContacts:
// put function prototype here:

void displayContacts(const struct Contact contacts[], int size);
// searchContacts:
// put function prototype here:
void searchContacts(const struct Contact contacts[], int size);

// addContact:
// put function prototype here:

void addContact(struct Contact contacts[], int size);
// updateContact:
// put function prototype here:

void updateContact(struct Contact contacts[], int size);
// deleteContact:
// put function prototype here:
void deleteContact(struct Contact contacts[], int size);
// sortContacts:
// put function prototype here:
void sortContacts(struct Contact contacts[], int size);