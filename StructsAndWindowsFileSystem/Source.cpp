#include <Windows.h>
#include <string>
#include <iostream>
using namespace std;

const int MAX_CHAR_LENGTH = 64;

struct ItemInfo {
	int itemID;
	int quantity;
	double price;
	char description[MAX_CHAR_LENGTH];

	ItemInfo() : itemID(1), quantity(1), price(1), description("description") {};

	void setItem(int id, int q, double p)
	{
		itemID = id;
		quantity = q;
		price = p;
	}
};

void main()
{
	const int ITEM_LIMIT = 4;

	ItemInfo itemList[ITEM_LIMIT];

	//set some values for each item in the array
	for (int i = 1; i < ITEM_LIMIT+1; i++)
	{
		itemList[i-1].setItem(i, i + 1, 2.99);
	}

	DWORD count;
	HANDLE file;
	TCHAR fileName[] = TEXT("C:\\Users\\ebbmf\\Desktop\\OrderData.out");

	//create file for read and write
	file = CreateFile(fileName, GENERIC_WRITE | GENERIC_READ, 0, NULL, CREATE_ALWAYS, FILE_FLAG_RANDOM_ACCESS, NULL);

	// write each item in the array to the disk
	for (int i = 0; i < ITEM_LIMIT; ++i) {
		WriteFile(file, &itemList[i], sizeof(itemList[i]), &count, NULL);
	}

	ItemInfo itemListRead[ITEM_LIMIT];

	//read each item from the disk and display on the monitor
	for (int i = ITEM_LIMIT-1; i >= 0; i--)
	{
		SetFilePointer(file, i*sizeof(ItemInfo), 0, FILE_BEGIN);
		ReadFile(file, &itemListRead[i], sizeof(itemListRead[i]), &count, NULL);
		cout << "Item ID # " << itemListRead[i].itemID << endl
			<< "Quantity: " << itemListRead[i].quantity << endl
			<< "Price: " << itemListRead[i].price << endl
			<< "Description: " << itemListRead[i].description << endl << endl;
	}
	
	CloseHandle(file);
	Sleep(5000);
}