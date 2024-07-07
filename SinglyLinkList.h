#pragma once
struct CNode
{
	CNode* m_ptrNext;
	int m_iData;
};
class SinglyLinkList
{
	CNode* m_ptrStart;
public:
	SinglyLinkList();

	void insertAtBeginning(int iData);
	void insertAtPosition(int iData, int iPos);
	void insertAtEnd(int iData);

	void deleteAtBeginning();
	void deleteAtPosition(int iPos);
	void deleteAtEnd();

	void updateAtBeginning(int iData);
	void updateAtPosition(int iData, int iPos);
	void updateAtEnd(int iData);

	void searchFirstOccurance(int iData);
	void searchLastOccurance(int iData);
	void searchAllOccurance(int iData);

	int getCount();
	void display();
};

