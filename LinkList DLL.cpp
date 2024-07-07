// LinkList DLL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//#include "SinglyLinkList.h"
#include "CSinglyCircularLL.h"
#include<iostream>
using namespace std;

void DisplayMenu()
{
	cout << "\n**********************************************************************************\n";
	cout << "\n1. Insert at Beginning";
	cout << "\t\t2. Insert at Position";
	cout << "\t\t3. Insert at End";

	cout << "\n4. Delete at Beginning";
	cout << "\t\t5. Delete at Position";
	cout << "\t\t6. Delete at End";

	cout << "\n7. Update at Beginning";
	cout << "\t\t8. Update at Position";
	cout << "\t\t9. Update at End";

	cout << "\n10. First Occurance";
	cout << "\t\t11. Last Occurance";
	cout << "\t\t12. All Occurance";

	cout << "\n13. Display";
	cout << "\n14. Get Count";
	cout << "\n15. Insert 10 elements";
	cout << "\n\n**********************************************************************************\n";
}
int getChoice()
{
	int iChoice = 0;
	cout << "---------------------------";
	cout << "\nEnter your choice : ";
	cin >> iChoice;
	cout << "---------------------------";

	return iChoice;
}
int main()
{
	int iData;
	//SinglyLinkList objLinkList;
	CSinglyCircularLL objLinkList;

	while (1)
	{
		DisplayMenu();
		switch (getChoice())
		{
			case 1:
			{
				cout << "\nInsert at Beginning";
				cout << "\n\nEnter your data : ";
				cin >> iData;
				objLinkList.insertAtBeginning(iData);
			
			}
			break;
			case 2:
			{
				int iPos = 0;
				cout << "\nInsert at Position";
				cout << "\n\nEnter your data : ";
				cin >> iData;
				cout << "\nEnter your Position : ";
				cin >> iPos;
				objLinkList.insertAtPosition(iData,iPos);

			}
			break;
			case 3:
			{
				cout << "\nInsert at End";
				cout << "\n\nEnter your data : ";
				cin >> iData;
				objLinkList.insertAtEnd(iData);
			}
			break;
			case 4:
			{
				cout << "\nDelete at Beginning\n";
				objLinkList.deleteAtBeginning();

			}
			break;
			case 5:
			{
				int iPos = 0;
				cout << "\nDelete at Position";
				cout << "\nEnter your Position : ";
				cin >> iPos;
				objLinkList.deleteAtPosition(iPos);

			}
			break;
			case 6:
			{
				cout << "\nDelete at End";
				objLinkList.deleteAtEnd();
			}
			break;
			case 7:
			{
				cout << "\nUpdate at Beginning";
				cout << "\n\nEnter your data : ";
				cin >> iData;
				objLinkList.updateAtBeginning(iData);

			}
			break;
			case 8:
			{
				int iPos = 0;
				cout << "\nUpdate at Position";
				cout << "\n\nEnter your data : ";
				cin >> iData;
				cout << "\nEnter your Position : ";
				cin >> iPos;
				objLinkList.updateAtPosition(iData, iPos);

			}
			break;
			case 9:
			{
				cout << "\nUpdate at End";
				cout << "\n\nEnter your data : ";
				cin >> iData;
				objLinkList.updateAtEnd(iData);
			}
			break;
			case 10:
			{
				cout << "\nFirst Occurance";
				cout << "\n\nEnter data to Search: ";
				cin >> iData;
				objLinkList.searchFirstOccurance(iData);

			}
			break;
			case 11:
			{
				int iPos = 0;
				cout << "\nLast Occurance";
				cout << "\n\nEnter data to Search: ";
				cin >> iData;
				objLinkList.searchLastOccurance(iData);

			}
			break;
			case 12:
			{
				cout << "\nAll Occurances";
				cout << "\n\nEnter data to Search: ";
				cin >> iData;
				objLinkList.searchAllOccurance(iData);
			}
			break;
			case 13:
			{
				objLinkList.display();
			}
			break;
			case 14:
			{
				cout << "\n\nTotal Count is : " << objLinkList.getCount() << "\n";
			}break;
			case 15:
			{
				for (int i = 1; i <= 10; i++)
				{
					objLinkList.insertAtEnd(10*i);
				}
			}
			break;
		}
	}
}
