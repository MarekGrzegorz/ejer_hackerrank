/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as:
	struct Node {
		int data;
		struct Node* next;
	}
*/

bool has_cycle(Node* head) {
	int it = 0;
	Node* tmp = head;

	while (tmp != nullptr) {
		tmp = tmp->next;
		it++;
		if (it > 101) { return true; }
	}

	return false;
}