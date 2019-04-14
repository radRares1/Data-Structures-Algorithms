#include "DLL.h"
#include "Node.h"


DoublyLinkedList::DoublyLinkedList()
{
	head = tail = NULL;
	size = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{
}

void DoublyLinkedList::insert_front(int rowPos, int colPos,int value)
{
	Node* temp = new Node(rowPos, colPos,value);

	if (head == NULL)
		head = tail = temp;
	else
	{
		head->prev = temp;
		temp->next = head;
		head = temp;
	}
	size++;
}

void DoublyLinkedList::insert_back(int rowPos, int colPos,int value)
{
	Node* temp = new Node(rowPos,colPos,value);

	if (tail == NULL)
		head = tail = temp;
	else
	{
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
	size++;
}

void DoublyLinkedList::delete_front()
{
	if (!is_empty())
	{
		Node* temp = head;
		if (head == tail)
		{
			tail = NULL;
			head = NULL;
		}
		else {
			head = head->next; //setting head to NULL
			head->prev = NULL; //also set head->prev to NULL otherwise this node points to a freed memory space
		} //see how an else block is added
		delete temp;

		size--;

	}
}

void DoublyLinkedList::delete_back()
{
	if (!is_empty())
	{
		Node* temp = tail;
		if (head == tail)
		{
			head = NULL;
			tail = NULL;
		}
		else { //see how an else block is added
			tail = tail->prev;
			tail->next = NULL; // set tail->next to null otherwise it point to freed memory
		}
		delete temp;

		size--;

	}
}

bool DoublyLinkedList::is_empty()
{
	if (size <= 0)
	{
		return true;
	}

	return false;
}


int DoublyLinkedList::length()
{
	return size;
}

bool DoublyLinkedList::search(int rowPos, int colPos)
{
	if (!is_empty())
	{
		Node* temp = head;
		while (temp)
		{
			if (temp->rowPos == rowPos && temp->colPos == colPos)
			{
				cout << "YES! got it." << endl;
				return true;
			}
			temp = temp->next;
		}
	}
	
		return false;
}

void DoublyLinkedList::modify(int rowPos, int colPos,int value)
{
	int ok = 0;
	if (!is_empty())
	{
		Node* temp = head;
		while (temp)
		{
			if (temp->rowPos == rowPos && temp->colPos == colPos)
			{
				ok = 1;
				temp->value = value;
			}
			temp = temp->next;
		}
		if (ok == 0)
		{
			Node* temp = head->next;
			temp->rowPos = rowPos;
			temp->colPos = colPos;
			temp->value = value;
		}
	}
	else
	{
		head->rowPos = rowPos;
		head->colPos = colPos;
		head->value = value;
		this->size++;
	}

	
}

int DoublyLinkedList::getElement(int rowPos, int colPos)
{
	if (!is_empty())
	{
		Node* temp = head;
		while (temp)
		{
			if (temp->rowPos == rowPos && temp->colPos == colPos)
			{
				return temp->value;
			}
			temp = temp->next;
		}
	}

		return false;
}

void DoublyLinkedList::deleteNode(int rowPos, int colPos)
{
	if (!is_empty())
	{
		Node* temp = head;
		while (temp)
		{
			if (temp->rowPos == rowPos && temp->colPos == colPos)
				temp->prev->next = temp->next;
		}
	}
}
