#include "SinglyLinkList.h"
#include<iostream>

using namespace std;
SinglyLinkList::SinglyLinkList()
{
	m_ptrStart = nullptr;
}

void SinglyLinkList::insertAtBeginning(int iData)
{
	CNode* Temp  = new CNode();
	Temp->m_iData = iData;
	Temp->m_ptrNext = m_ptrStart;
	m_ptrStart = Temp;
}

void SinglyLinkList::insertAtPosition(int iData, int iPos)
{
	if (iPos == 1)
	{
		insertAtBeginning(iData);
	}
	else if (iPos > getCount())
	{
		cout << "\nInvalid Position....";
		cout << "\nAdding Element in Last";
		insertAtEnd(iData);
	}
	else if (iPos == getCount())
		insertAtEnd(iData);
	else
	{
		CNode* newNode = new CNode();
		newNode->m_iData = iData;
		newNode->m_ptrNext = nullptr;

		int iTempPos = 1;
		CNode* Temp = m_ptrStart;
		while (/*Temp != nullptr &&*/ iTempPos != iPos - 1)
		{
			Temp = Temp->m_ptrNext;
			iTempPos++;
		}
		newNode->m_ptrNext = Temp->m_ptrNext;
		Temp->m_ptrNext = newNode;
	}
}

void SinglyLinkList::insertAtEnd(int iData)
{
	if (m_ptrStart == NULL)
	{
		insertAtBeginning(iData);
		return;
	}
	CNode* newNode = new CNode();
	newNode->m_iData = iData;
	newNode->m_ptrNext = nullptr;

	CNode* Temp;
	Temp = m_ptrStart;
	while (Temp->m_ptrNext != nullptr)
	{
		Temp = Temp->m_ptrNext;
	}
	Temp->m_ptrNext = newNode;
}

void SinglyLinkList::deleteAtBeginning()
{
	if (m_ptrStart == nullptr)
	{
		cout << "\nSorry, List is Empty";
	}
	else
	{
		CNode* temp = m_ptrStart;
		m_ptrStart = m_ptrStart->m_ptrNext;
		delete temp;
	}
	
}

void SinglyLinkList::deleteAtPosition(int iPos)
{
	if (m_ptrStart == nullptr)
	{
		cout << "\nSorry, List is Empty";
	}
	else if (iPos > getCount())
	{
		cout << "\nInvalid Position....";
	}
	else if (iPos == 1)
	{
		deleteAtBeginning();
	}
	else if (iPos == getCount())
	{
		deleteAtEnd();
	}
	else
	{
		int iTempPos = 1;
		CNode* Temp = m_ptrStart;
		while (iTempPos != iPos - 1)
		{
			Temp = Temp->m_ptrNext;
			iTempPos++;
		}
		CNode* deleteNode = Temp->m_ptrNext;

		Temp->m_ptrNext = (Temp->m_ptrNext)->m_ptrNext;
		if(deleteNode != nullptr)
			delete deleteNode;
	}
}

void SinglyLinkList::deleteAtEnd()
{
	if (m_ptrStart == NULL)
	{
		cout << "\nSorry, List is Empty";
	}
	else if (getCount() == 1)
	{
		deleteAtBeginning();
	}
	else
	{
		CNode* Temp;
		Temp = m_ptrStart;
		while ((Temp->m_ptrNext)->m_ptrNext != nullptr)
		{
			Temp = Temp->m_ptrNext;
		}
		CNode* DeleteNode = Temp->m_ptrNext;
		delete DeleteNode;
		Temp->m_ptrNext = nullptr;
	}
}

void SinglyLinkList::updateAtBeginning(int iData)
{
	if (m_ptrStart == nullptr)
	{
		cout << "\nSorry, List is Empty";
	}
	else
	{
		cout << "\nOld Data at 1st Position: " << m_ptrStart->m_iData;
		int iChoice = 0;
		cout << "\nDo you want to replace it? \n1. Yes\t\t 2. No";
		cout << "\nEnter your choice: ";
		cin >> iChoice;
		if (iChoice == 1)
		{
			m_ptrStart->m_iData = iData;
		}
		else if (iChoice == 2)
		{
			return;
		}
	}
}

void SinglyLinkList::updateAtPosition(int iData, int iPos)
{
	if (iPos == 1)
	{
		updateAtBeginning(iData);
	}
	else if (iPos > getCount())
	{
		cout << "\nInvalid Position....";
	}
	else
	{
		int iTempPos = 1;
		CNode* Temp  = m_ptrStart;
		while (iTempPos != iPos)
		{
			Temp = Temp->m_ptrNext;
			iTempPos++;
		}
		if (iPos == 2)
			cout << "\nOld Data at "<< iPos << "nd Position : " << Temp->m_iData;
		else if(iPos == 3)
			cout << "\nOld Data at " << iPos << "rd Position : " << Temp->m_iData;
		else
			cout << "\nOld Data at " << iPos << "st Position : " << Temp->m_iData;

		int iChoice = 0;
		cout << "\nDo you want to replace it? \n1. Yes\t\t 2. No";
		cout << "\nEnter your choice: ";
		cin >> iChoice;
		if (iChoice == 1)
		{
			Temp->m_iData = iData;
		}
		else if (iChoice == 2)
		{
			return;
		}
	}
}

void SinglyLinkList::updateAtEnd(int iData)
{
	if (m_ptrStart == NULL)
	{
		cout << "\nSorry, List is Empty";
	}
	else
	{
		CNode* Temp;
		Temp = m_ptrStart;
		while (Temp->m_ptrNext != nullptr)
		{
			Temp = Temp->m_ptrNext;
		}
		cout << "\nOld Data at Last Position: " << Temp->m_iData;
		int iChoice = 0;
		cout << "\nDo you want to replace it? \n1. Yes\t\t 2. No";
		cout << "\nEnter your choice: ";
		cin >> iChoice;
		if (iChoice == 1)
		{
			Temp->m_iData = iData;
		}
		else if (iChoice == 2)
		{
			return;
		}
	}
}

void SinglyLinkList::searchFirstOccurance(int iData)
{
	bool bFound = false;
	if (m_ptrStart == NULL)
	{
		cout << "\nSorry, List is Empty";
	}
	else
	{
		int iTempPos = 1;
		CNode* Temp = m_ptrStart;
		while (Temp != nullptr)
		{
			if (Temp->m_iData == iData)
			{
				cout << "First occurence Position = " << iTempPos;
				bFound = true;
				break;
			}
			Temp = Temp->m_ptrNext;
			iTempPos++;
		}
		if (bFound == false)
		{
			cout << "\nSorry, No Data found";
		}
	}
}

void SinglyLinkList::searchLastOccurance(int iData)
{
	bool bFound = false;
	if (m_ptrStart == NULL)
	{
		cout << "\nSorry, List is Empty";
	}
	else
	{
		int iTempPos = 1;
		int iLastOccurence = 0;
		CNode* Temp = m_ptrStart;
		while (Temp != nullptr)
		{
			if (Temp->m_iData == iData)
			{
				iLastOccurence = iTempPos;
				bFound = true;
			}
			Temp = Temp->m_ptrNext;
			iTempPos++;
		}
		if (bFound == false)
		{
			cout << "\nSorry, No Data found";
		}
		else
		{
			cout << "Last occurence Position = " << iLastOccurence;
		}
	}
}

void SinglyLinkList::searchAllOccurance(int iData)
{
	bool bFound = false;
	if (m_ptrStart == NULL)
	{
		cout << "\nSorry, List is Empty";
	}
	else
	{
		int iTempPos = 1;
		CNode* Temp = m_ptrStart;
		while (Temp != nullptr)
		{
			if (Temp->m_iData == iData)
			{
				if (bFound == false)
				{
					cout << "All Occurence's Positions = ";
					bFound = true;
				}
				cout << iTempPos << "\t";
			}
			Temp = Temp->m_ptrNext;
			iTempPos++;
		}
		if (bFound == false)
		{
			cout << "\nSorry, No Data found";
		}
	}
}

int SinglyLinkList::getCount()
{
	CNode* Temp;
	Temp = m_ptrStart;
	int count = 0;
	while (Temp != nullptr)
	{
		count++;
		Temp = Temp->m_ptrNext;
	}
	return count;
}

void SinglyLinkList::display()
{
	if (m_ptrStart == NULL)
	{
		cout << "\nSorry, List is Empty";
	}
	else
	{
		int iCount = 0;
		CNode* Temp;
		Temp = m_ptrStart;
		cout << "\nLinkList Data:\n";
		//cout << "\n***************************************\n";
		while (Temp != nullptr)
		{
			if (iCount % 10 == 0)
			{
				cout << "\n";
			}
			cout << Temp->m_iData << "\t";
			Temp = Temp->m_ptrNext;
			iCount++;
		}
	}
}
