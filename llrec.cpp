#include "llrec.h"
#include <cstdlib>

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivotHelp(Node *&head, Node *&smaller, Node *&larger, int pivot){
	//if te head node has a smaller valude than the pivot, smaller is set to head.
	if (head->val <= pivot){
		smaller = head;
		llpivot(head->next, smaller->next, larger,pivot);
	}
	// else if larger, larger is set to the head.
	else{
		larger = head; 
		llpivot(head->next, smaller, larger->next,pivot);
	}
}

// helper function
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
	// initial check
	if (head == NULL){
		smaller = nullptr;
		larger = nullptr; 
		return;
	}

	llpivotHelp(head, smaller, larger, pivot);
}
