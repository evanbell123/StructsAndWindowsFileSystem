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

	string toString()
	{
		return "item id: " + itemID; // + "\nquantity: " + quantity + "\nprice: " + price + "description: " + description + "\n\n";
	};
};

void main()
{
	const int ITEM_LIMIT = 4;

	ItemInfo itemList[ITEM_LIMIT];

	//set some values for the items
	for (int i = 1; i < ITEM_LIMIT+1; i++)
	{
		itemList[i].setItem(i, i + 1, 2.99);
	}

	DWORD count;
	//char data[250] = { 0 };
	HANDLE writer;

	TCHAR fileName[] = TEXT("C:\\Users\\Evan\\Desktop\\OrderData.out");

	writer = CreateFile(fileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	for (int i = 0; i < ITEM_LIMIT; ++i) {
		WriteFile(writer, &itemList[i].toString(), sizeof(itemList[i].toString()), &count, NULL);
	}


	//SetFilePointer(file, 0, 0, FILE_BEGIN);
	//ReadFile(file, &value, sizeof(itemInfo., &count, NULL);
	//cout <<  value << endl;

	CloseHandle(writer);
	Sleep(5000);
}