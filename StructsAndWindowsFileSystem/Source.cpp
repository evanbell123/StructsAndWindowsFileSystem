#include <Windows.h>
#include <iostream>
using namespace std;

const int MaxLength = 64;

struct itemInfo {
	int itemID;
	int quantity;
	double price;
	char description[MaxLength];
};

void main()
{
	itemInfo testItem;

	cout << "Enter item id: ";
	cin >> testItem.itemID;
	cout << "Enter quantity: ";
	cin >> testItem.quantity;
	cout << "Enter price: ";
	cin >> testItem.price;
	cout << "Enter description: ";
	cin >> testItem.description;

	cout << testItem.itemID << endl;
	cout << testItem.quantity << endl;
	cout << testItem.price << endl;
	cout << testItem.description << endl;

	//double value;

	DWORD count;
	//char data[250] = { 0 };
	HANDLE file;

	TCHAR fileName[] = TEXT("C:\\Users\\ebbmf\\Documents\\Operating Systems\\OrderData.out");

	file = CreateFile(fileName, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, &testItem, sizeof(testItem), &count, NULL);


	//SetFilePointer(file, 0, 0, FILE_BEGIN);
	//ReadFile(file, &value, sizeof(itemInfo., &count, NULL);
	//cout <<  value << endl;

	CloseHandle(file);
	Sleep(5000);
}