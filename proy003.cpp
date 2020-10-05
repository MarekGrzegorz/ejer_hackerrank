#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <locale> //toupper

using namespace std;

class DoublyLinkedListNode{
	public:
		int data;
		DoublyLinkedListNode *next;
		DoublyLinkedListNode *prev;

		DoublyLinkedListNode(int node_data) {
			this->data = node_data;
			this->next = nullptr;
			this->prev = nullptr;
		}
};

class DoublyLinkedList {
public:
	DoublyLinkedListNode *head;
	DoublyLinkedListNode *tail;

	DoublyLinkedList() {
		this->head = nullptr;
		this->tail = nullptr;
	}

	void insert_node(int node_data) {
		DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

		if (!this->head) {
			this->head = node;
		} else {
			this->tail->next = node;
			node->prev = this->tail;
		}

		this->tail = node;
	}
};

void print_doubly_linked_list(DoublyLinkedListNode* node, string sep) {
	while (node) {
		cout << node->data;

		node = node->next;

		if (node) {
			cout << sep;
		}
	}
}

void free_doubly_linked_list(DoublyLinkedListNode* node) {
	while (node) {
		DoublyLinkedListNode* temp = node;
		node = node->next;

		free(temp);
	}
}

// Complete the sortedInsert function below.

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
	
	DoublyLinkedListNode *toInsert = new DoublyLinkedListNode(data);
	DoublyLinkedListNode * tmp = head, *last;

	if (head == nullptr) {
		return toInsert;
		
	} else if (head->data >= data) {
		toInsert->next = head;
		toInsert->prev = nullptr;
		head->prev = toInsert;
		return toInsert;
	} else {
		while (tmp->next->data < data ) {		
			tmp = tmp->next;
			if (tmp->next == nullptr) {break;}
		}
		
		if (tmp->next == nullptr) {
			toInsert->prev = tmp;
			toInsert->next = nullptr;
			tmp->next = toInsert;
			
		}else {
			
			toInsert->prev = tmp;
			toInsert->next = tmp->next;

			tmp->next->prev=toInsert;
			tmp->next = toInsert;
			
		}
		return head;
	}
}

int main() {
	ifstream fout("Text.txt");

	int t;
	fout >> t;
	fout.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int t_itr = 0; t_itr < t; t_itr++) {
		DoublyLinkedList* llist = new DoublyLinkedList();

		int llist_count;
		fout >> llist_count;
		fout.ignore(numeric_limits<streamsize>::max(), '\n');

		for (int i = 0; i < llist_count; i++) {
			int llist_item;
			fout >> llist_item;
			fout.ignore(numeric_limits<streamsize>::max(), '\n');

			llist->insert_node(llist_item);
		}

		int data;
		fout >> data;
		fout.ignore(numeric_limits<streamsize>::max(), '\n');

		DoublyLinkedListNode* llist1 = sortedInsert(llist->head, data);

		print_doubly_linked_list(llist1, " ");
		cout << "\n";

		free_doubly_linked_list(llist1);
	}

	fout.close();

	return 0;
}
