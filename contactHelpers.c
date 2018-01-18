/* ------------------------------------------ -
Name:David Paul
Student number : 115192171
Email : dpaul9@myseneca.ca
Section : Assignment 1
Date : 2017 - 12 - 15
----------------------------------------------
Assignment : 2
Milestone : 1
----------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "contactHelpers.h"

// This source file needs to "know about" the functions you prototyped
//       in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:


	

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:


// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:



// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5
//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+

// clearKeyboard:  Empty function definition 
void clearKeyboard(void) {
	while (getchar() != '\n');	//empty buffer
}

// pause: Empty function definition goes here:
void pause(void) {
	printf("(Press Enter to Continue)\n");
	clearKeyboard();	//wait for enter

}



// getInt: Empty function definition goes here:

int getInt(void) {
	int value;	//get int value
	int flag = 0;	//flag
	char null;	//check if value not int
	do {
		scanf(" %d%c", &value, &null);	//get user input
		if (null != '\n') {	//if yes
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}
		else {
			flag = 1; //end loop
		}
	} while (flag == 0);	//ask until program is satisfied with answer

	return value;
}


// getIntInRange: Empty function definition goes here:

int getIntInRange(int min, int max) {
	int value;	// user input
	int flag = 0;	//loop
	do {
		value = getInt();	//get int value

		if (value >= min && value <= max) {	//if value meets conditions from parametres
			flag = 1;	//end loop
		}
		else {
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);	//error msg
		}
	} while (flag == 0);	//ask until program is satisfied with answer

	return value;
}


// yes: Empty function definition goes here:

int yes(void) {
	char input[4];	//get char value
	char value;
	int flag = 0;	//flag
	int num;
	int i;
	int check = 0;
	do {	//run code before checking conditions
		scanf(" %4s", input);	//get input
		value = input[0];	//get val
		for (i = 0; input[i] != '\0'; i++) {	// check how many characters input
			check++;
		}
		if (check < 2) {
			if (value == 'y' || value == 'Y') {	//if yes
				num = 1;	//return 1 to indicate true
				flag = 1;	//end loop
			}
			else if (value == 'n' || value == 'N') {	//if no
				num = 0;	//return 0 to indicate false
				flag = 1; //end loop
			}
		}
		else {
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");	//error msg
			for (i = 0; i < 3; i++) {	//clear arr
				input[i] = 0;
			}
			clearKeyboard();	//clear buffer
			check = 0;	//reset check
		}
	} while (flag == 0);	//ask until program is satisfied with answer
	return num;
}


// menu: Empty function definition goes here:

int menu(void) {
	//print selection menu
	int num;
	//options
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n\n");
	printf("Select an option:> ");
	num = getIntInRange(0, 6);	//get user input 
	printf("\n");
	return num;

}


// ContactManagerSystem: Empty function definition goes here:
void ContactManagerSystem(void) {

	struct Contact contacts[MAXCONTACTS] = { 
		{
			{"Rick",{ '\0' }, "Grimes" },
			{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
			{ "4161112222", "4162223333", "4163334444" } 
		},
		{ 
			{ "Maggie", "R.", "Greene" },
			{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
			{ "9051112222", "9052223333", "9053334444" } },
		{ 
			{ "Morgan", "A.", "Jones" },
			{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
			{ "7051112222", "7052223333", "7053334444" } },
		{
			{ "Sasha",{ '\0' }, "Williams" },
			{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
			{ "9052223333", "9052223333", "9054445555" } 
		}, 
	};



	int flag = 0;	//falg to stop loop
	do {
		int selection = menu();	// get menu and return user selection

		switch (selection) {	//match user selection with task
		case 0:
			printf("Exit the program? (Y)es/(N)o: ");	//confirm exit
			if (yes() == 1) {
				flag = 1;	//exit
				printf("\nContact Management System: terminated\n");
			}
			else {
				printf("\n");
			}
			break;
		case 1:
			displayContacts(contacts, MAXCONTACTS);
			pause();
			break;
		case 2:
			addContact(contacts, MAXCONTACTS);
			pause();
			break;
		case 3:
			updateContact(contacts, MAXCONTACTS);
			pause();
			break;
		case 4:
			deleteContact(contacts, MAXCONTACTS);
			clearKeyboard();
			pause();
			break;
		case 5:
			searchContacts(contacts, MAXCONTACTS);
			pause();
			break;
		case 6:
			sortContacts(contacts, MAXCONTACTS);
			pause();
			break;

		}
	} while (flag == 0);

}

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10 chars entered)
void getTenDigitPhone(char telNum[])
{
	int needInput = 1;

	while (needInput == 1) {
		scanf("%10s", telNum);
		clearKeyboard();

		// (String Length Function: validate entry of 10 characters)
		if (strlen(telNum) == 10)
			needInput = 0;
		else
			printf("Enter a 10-digit phone number: ");
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]){
	int i;
	int key = -1;
	for (i = 0; i < size; i++) {	
		if (strcmp(contacts[i].numbers.cell, cellNum) == 0) {
			key = i;
			break;
		}
	}


	return key;
}


// displayContactHeader
// Put empty function definition below:


void displayContactHeader(void) {
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}
// displayContactFooter
// Put empty function definition below:

void displayContactFooter(int numOfContacts) {
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", numOfContacts);
}

// displayContact:
// Put empty function definition below:

void displayContact(const struct Contact* n) {
	printf(" %s ", n->name.firstName);
	if (strlen(n->name.middleInitial) > 0) {
		printf("%s ", n->name.middleInitial);
	}
	printf("%s\n", n->name.lastName);
	printf("    C: %s   ", n->numbers.cell);
	if (strlen(n->numbers.home) > 0) {
		printf("H: %s   ", n->numbers.home);
	}
	else {
		printf("H:              ");
	}
	if (strlen(n->numbers.business) > 0) {
		printf("B: %s\n", n->numbers.business);
	}
	else {
		printf("B:           ");
		printf("\n");

	}
	printf("       %d ", n->address.streetNumber);
	printf("%s, ", n->address.street);
	if (n->address.apartmentNumber > 0) {
		printf("Apt# %d, ", n->address.apartmentNumber);
	}
	printf("%s, ", n->address.city);
	printf("%s\n", n->address.postalCode);
};


// displayContacts:
// Put empty function definition below:

void displayContacts(const struct Contact a[], int b) {
	int i;
	int valid = 0;
	displayContactHeader();
	for (i = 0; i < b; i++) {
		if (strlen(a[i].numbers.cell) > 0) {
			displayContact(&a[i]);
			valid++;
		}
	}
	displayContactFooter(valid);

}

// searchContacts:
// Put empty function definition below:

void searchContacts(const struct Contact a[], int b) {
	char num[11];
	int d;
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(num);
	d = findContactIndex(a, b, num);
	if (d == -1) {
		printf("*** Contact NOT FOUND ***\n");
	}
	else {
		printf("\n");
		displayContact(&a[d]);
		printf("\n");
	}

}

// addContact:
// Put empty function definition below:
void addContact(struct Contact contacts[], int size) {
	int i;
	int found = 0;
	static int count = 0;
	struct Contact contact;
	for (i = 0; i < size; i++) {
		contact = contacts[i];
		if (strlen(contact.numbers.cell) == 0 ) {
			found++;
			break;
		}
	}
	if (found > 0) {
		getContact(&contact);
		contacts[i] = contact;
		printf("--- New contact added! ---\n");
		if (count == 0) {
			clearKeyboard();
		}
		count++;
	}
	else {
		printf("*** ERROR: The contact list is full! ***\n");
	}

}


// updateContact:
// Put empty function definition below:

void updateContact(struct Contact contacts[], int size) {
	char num[11];
	int loc;
	struct Contact empty = { {{0}} };
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(num);
	loc = findContactIndex(contacts, size, num);
	if (loc == -1) {
		printf("*** Contact NOT FOUND ***\n");
	}
	else {
		printf("\nContact found:\n");
		displayContact(&contacts[loc]);
		printf("\n");

		printf("Do you want to update the name? (y or n): ");
		if (yes() == 1) {
			contacts[loc].name = empty.name;
			getName(&contacts[loc].name);
		}
		printf("Do you want to update the address? (y or n): ");
		if (yes() == 1) {
			contacts[loc].address = empty.address;
			getAddress(&contacts[loc].address);
		}
		printf("Do you want to update the numbers? (y or n): ");
		if (yes() == 1) {
			contacts[loc].numbers = empty.numbers;
			getNumbers(&contacts[loc].numbers);
		}
		printf("--- Contact Updated! ---\n");
		clearKeyboard();
	}
		
}

// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact contacts[], int size) {
	char num[11];
	int loc;
	struct Contact empty = { { { 0 } } };
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(num);
	loc = findContactIndex(contacts, size, num);
	if (loc == -1) {
		printf("*** Contact NOT FOUND ***\n");
	}
	else {
		printf("\nContact found:\n");
		displayContact(&contacts[loc]);
		printf("\n");
		printf("CONFIRM: Delete this contact? (y or n): ");
		if (yes() == 1) {
			contacts[loc].numbers.cell[0] = '\0';
			contacts[loc] = empty;
			printf("--- Contact deleted! ---\n");
		}
	}
}


// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact contacts[], int size) {
	int i, j;
	struct Contact temp = { {{0}} };

	for (i = size - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (strcmp(contacts[j].numbers.cell, contacts[j + 1].numbers.cell) > 0) {
				temp = contacts[j];
				contacts[j] = contacts[j + 1];
				contacts[j + 1] = temp;

			}
		}
	}

	printf("--- Contacts sorted! ---\n");
}