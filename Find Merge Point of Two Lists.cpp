#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

class SinglyLinkedListNode {
public:
	int data;
	SinglyLinkedListNode *next;

	SinglyLinkedListNode(int node_data) {
		this->data = node_data;
		this->next = nullptr;
	}
};

class SinglyLinkedList {
public:
	SinglyLinkedListNode *head;
	SinglyLinkedListNode *tail;

	SinglyLinkedList() {
		this->head = nullptr;
		this->tail = nullptr;
	}

	void insert_node(int node_data) {
		SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

		if (!this->head) {
			this->head = node;
		} else {
			this->tail->next = node;
		}

		this->tail = node;
	}
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep) {
	while (node) {
		cout << node->data;

		node = node->next;

		if (node) {
			cout << sep;
		}
	}
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
	while (node) {
		SinglyLinkedListNode* temp = node;
		node = node->next;

		free(temp);
	}
}

// Complete the findMergeNode function below.
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

	SinglyLinkedListNode  *head_list2 = head2, **x, **y;
	bool f = false;
	
	while (head1 != nullptr) {
		x = &head1->next;
		
		while (head2 != nullptr) {
			y = &head2->next;
			if (x == y) { f = true; break;	}
			head2 = head2->next;
		}
		if (f){break;}
		head1 = head1->next;
		head2 = head_list2;
	}

	if (f) { return head1->data; }

	return 0;
}

int main() {
	ifstream fout("Text.txt");

	int tests;
	fout >> tests;
	fout.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
		int index;
		fout >> index;
		fout.ignore(numeric_limits<streamsize>::max(), '\n');

		SinglyLinkedList* llist1 = new SinglyLinkedList();

		int llist1_count;
		fout >> llist1_count;
		fout.ignore(numeric_limits<streamsize>::max(), '\n');

		for (int i = 0; i < llist1_count; i++) {
			int llist1_item;
			fout >> llist1_item;
			fout.ignore(numeric_limits<streamsize>::max(), '\n');

			llist1->insert_node(llist1_item);
		}

		SinglyLinkedList* llist2 = new SinglyLinkedList();

		int llist2_count;
		fout >> llist2_count;
		fout.ignore(numeric_limits<streamsize>::max(), '\n');

		for (int i = 0; i < llist2_count; i++) {
			int llist2_item;
			fout >> llist2_item;
			fout.ignore(numeric_limits<streamsize>::max(), '\n');

			llist2->insert_node(llist2_item);
		}

		SinglyLinkedListNode* ptr1 = llist1->head;
		SinglyLinkedListNode* ptr2 = llist2->head;

		for (int i = 0; i < llist1_count; i++) {
			if (i < index) {
				ptr1 = ptr1->next;
			}
		}

		for (int i = 0; i < llist2_count; i++) {
			if (i != llist2_count - 1) {
				ptr2 = ptr2->next;
			}
		}

		ptr2->next = ptr1;

		int result = findMergeNode(llist1->head, llist2->head);

		cout << result << "\n";
	}

	fout.close();

	return 0;
}
