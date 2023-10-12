#pragma once
#include <iostream>
#include "Classes.h"
using namespace std;

class Node {
public:
	Doctor data;
	Node* next;
};

class List {
private:
	Node* head;

public:

	List(void);

	~List(void);

	bool IsEmpty();

	void InsertDoc(Doctor);

	int FindDoc(Doctor);

	//int DeleteDoc(Doctor);

	void DisplayList(void);

};

List::List(void)
{
	head = NULL;
}

List::~List(void)
{
	Node* currNode = head;
	Node* nextNode = NULL;
	while (currNode != NULL) {
		nextNode = currNode->next;
		delete currNode; // destroy the current node
		currNode = nextNode;
	}
}

bool List::IsEmpty()
{
	return head == NULL;
}

void List::InsertDoc(Doctor a)
{
	Node* newNode = new Node;
	Node* currNode = head;
	newNode->data.set_DrID(a.get_DrID());
	newNode->data.set_DrName(a.get_DrN());
	newNode->data.set_DrS(a.get_DrS());
	if (currNode == NULL)
	{
		newNode->next = head;
		head = newNode;
	}
	else {
		newNode->next = currNode->next;
		currNode->next = newNode;
	}
}

void List::DisplayList(void)
{
	int num = 0;
	Node* currNode = head;
	while (currNode != NULL) {
		currNode->data.display_info();
		currNode = currNode->next;
		num++;
	}
	cout << "Number of nodes in the list: " << num << endl;
}

int List::FindDoc(Doctor a)
{
	Node* currNode = head;
	int currIndex = 1;
	while (currNode && currNode->data.get_DrID() != a.get_DrID()) {
		currNode = currNode->next;
		currIndex++;
	}
	if (currNode)
		return currIndex;
	return 0;
}

