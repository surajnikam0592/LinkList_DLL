#pragma once
struct CNode
{
	CNode* m_ptrPrev;
	int m_iData;
	CNode* m_ptrNext;
};
class CDoublyLL
{
	CNode* m_ptrStart;
public:
	CDoublyLL();
	inline CNode* getLast();
	inline CNode* getFirst();
	inline CNode* getAtPosition(int iPos);

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

