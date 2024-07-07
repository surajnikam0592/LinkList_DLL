#include "CSinglyCircularLL.h"
#include<iostream>

using namespace std;
CSinglyCircularLL::CSinglyCircularLL()
{
	m_ptrStart = nullptr;
}

inline CNode* CSinglyCircularLL::getLast()
{
	CNode* ptrIterator = m_ptrStart;
	while (ptrIterator->m_ptrNext != m_ptrStart)
	{
		ptrIterator = ptrIterator->m_ptrNext;
	}
	return ptrIterator;
}

inline CNode* CSinglyCircularLL::getFirst()
{
	return m_ptrStart;
}

inline CNode* CSinglyCircularLL::getAtPosition(int iPos)
{
	if (iPos > getCount())
	{
		return nullptr;
	}
	int iTempPos = 1;
	CNode* ptrIterator = m_ptrStart;
	while ((ptrIterator->m_ptrNext != m_ptrStart) && (iPos != iTempPos))
	{
		ptrIterator = ptrIterator->m_ptrNext;
		iTempPos++;
	}
	return ptrIterator;
}


//!Done
void CSinglyCircularLL::insertAtBeginning(int iData)
{
	CNode* Temp = new CNode();
	Temp->m_iData = iData;
	if (getFirst() == nullptr)
	{
		Temp->m_ptrNext = Temp;
		m_ptrStart = Temp;
	}
	else
	{
		CNode* ptrIterator = getLast();
		if (ptrIterator == nullptr)
		{
			cout << "Sorry, Something Error in insertAtBeginning()";
			return;
		}
		ptrIterator->m_ptrNext = Temp;
		Temp->m_ptrNext = m_ptrStart;
		m_ptrStart = Temp;
	}
}
//Done
void CSinglyCircularLL::insertAtPosition(int iData, int iPos)
{
	if (iPos == 1)
		insertAtBeginning(iData);
	else if (iPos - 1 == getCount())
		insertAtEnd(iData);
	else if (iPos > getCount())
	{
		cout << "\nInvalid Position....";
		cout << "\nAdding Element in Last";
		insertAtEnd(iData);
	}
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
//!Done
void CSinglyCircularLL::insertAtEnd(int iData)
{
	if (m_ptrStart == NULL)
	{
		insertAtBeginning(iData);
		return;
	}
	else
	{
		CNode* ptrIterator = getLast();
		if (ptrIterator == nullptr)
		{
			cout << "Sorry, Something Error in insertAtEnd()";
			return;
		}
		CNode* Temp = new CNode();
		Temp->m_iData = iData;
		ptrIterator->m_ptrNext = Temp;
		Temp->m_ptrNext = m_ptrStart;
	}
}

void CSinglyCircularLL::deleteAtBeginning()
{
	if (getFirst() == nullptr)
	{
		cout << "\nSorry, List is Empty";
	}
	else
	{
		CNode* ptrLast =  getLast();
		if (ptrLast == getFirst())
		{
			CNode* temp = m_ptrStart;
			m_ptrStart = m_ptrStart->m_ptrNext;
			delete temp;
			temp = nullptr;
			m_ptrStart = nullptr;
		}
		else if (ptrLast != nullptr)
		{
			ptrLast->m_ptrNext = m_ptrStart->m_ptrNext;

			CNode * temp = m_ptrStart;
			m_ptrStart = m_ptrStart->m_ptrNext;
			delete temp;
			temp = nullptr;
		}
	}
}

void CSinglyCircularLL::deleteAtPosition(int iPos)
{
	if (getFirst() == nullptr)
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
		CNode* ptrPreviousNode = getAtPosition(iPos - 1);
		if (ptrPreviousNode == nullptr)
		{
			cout << "Sorry, Something Error in deleteAtPosition()";
			return;
		}
		CNode* deleteNode = ptrPreviousNode->m_ptrNext;
		ptrPreviousNode->m_ptrNext = deleteNode->m_ptrNext;
		delete deleteNode;
		deleteNode = nullptr;
	}
}

void CSinglyCircularLL::deleteAtEnd()
{
	if (getFirst() == NULL)
	{
		cout << "\nSorry, List is Empty";
	}
	else if (getCount() == 1)
	{
		deleteAtBeginning();
	}
	else
	{
		CNode* secondLastNode = getAtPosition(getCount() - 1);
		if (secondLastNode == nullptr)
		{
			cout << "Sorry, Something Error in deleteAtEnd()";
			return;
		}
		CNode* DeleteNode = secondLastNode->m_ptrNext;
		secondLastNode->m_ptrNext = DeleteNode->m_ptrNext;
		delete DeleteNode;
		DeleteNode = nullptr;
	}
}

void CSinglyCircularLL::updateAtBeginning(int iData)
{
	if (getFirst() == nullptr)
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

void CSinglyCircularLL::updateAtPosition(int iData, int iPos)
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
		CNode* Temp = getAtPosition(iPos);
		if (Temp == nullptr)
		{
			cout << "Sorry, Something Error in updateAtPosition()";
			return;
		}
		if (iPos == 2)
			cout << "\nOld Data at " << iPos << "nd Position : " << Temp->m_iData;
		else if (iPos == 3)
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

void CSinglyCircularLL::updateAtEnd(int iData)
{
	if (m_ptrStart == NULL)
	{
		cout << "\nSorry, List is Empty";
	}
	else
	{
		CNode* Temp = getLast();
		if (Temp == nullptr)
		{
			cout << "Sorry, Something Error in updateAtEnd()";
			return;
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

void CSinglyCircularLL::searchFirstOccurance(int iData)
{
	bool bFound = false;
	if (getFirst() == NULL)
	{
		cout << "\nSorry, List is Empty";
	}
	else
	{
		if (m_ptrStart->m_iData == iData)
		{
			cout << "First occurence Position = " << 1;
			bFound = true;
			return;
		}
		else
		{
			int iTempPos = 2;
			CNode* Temp = m_ptrStart->m_ptrNext;
			while (Temp != getFirst())
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
}

void CSinglyCircularLL::searchLastOccurance(int iData)
{
	
	if (getFirst() == NULL)
	{
		cout << "\nSorry, List is Empty";
	}
	else
	{
		bool bFound = false;
		int iTempPos = 1;
		int iLastOccurence = 0;

		if (m_ptrStart->m_iData == iData)
		{
			iLastOccurence = iTempPos;
			bFound = true;
		}
		iTempPos++;
		CNode* Temp = m_ptrStart->m_ptrNext;
		while (Temp != getFirst())
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

void CSinglyCircularLL::searchAllOccurance(int iData)
{
	
	if (getFirst() == NULL)
	{
		cout << "\nSorry, List is Empty";
	}
	else
	{
		bool bFound = false;
		int iTempPos = 1;
		if (m_ptrStart->m_iData == iData)
		{
			if (bFound == false)
			{
				cout << "All Occurence's Positions = ";
				bFound = true;
			}
			cout << iTempPos << "\t";
		}
		iTempPos++;
		CNode* Temp = m_ptrStart->m_ptrNext;
		while (Temp != getFirst())
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

//Done
int CSinglyCircularLL::getCount()
{
	if (m_ptrStart == nullptr)
	{
		return 0;
	}
	else
	{
		int count = 1;
		CNode* Temp;
		Temp = m_ptrStart;
		
		while (Temp->m_ptrNext != m_ptrStart)
		{
			count++;
			Temp = Temp->m_ptrNext;
		}
		return count;
	}
}
//Done
void CSinglyCircularLL::display()	
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
		while (Temp->m_ptrNext != m_ptrStart)
		{
			if (iCount % 10 == 0)
			{
				cout << "\n";
			}
			cout << Temp->m_iData << "\t";
			Temp = Temp->m_ptrNext;
			iCount++;
		}
		cout << Temp->m_iData << "\t";
	}
}
