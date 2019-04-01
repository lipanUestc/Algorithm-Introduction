/*
ListNode* insertionSortList(ListNode* head) {
	ListNode dummy(INT_MAX);
	while (head) {//traverse every element of origin list
		//find the insertable place,record the pre and tmp pointer
		ListNode* tmp = dummy.next;
		ListNode* pre = &dummy;

		while (tmp && tmp->val < head->val) {
			tmp = tmp->next;
			pre = pre->next;
		}
		ListNode* hold = head;//record the current insert element

		head = head->next;//head point to next
		pre->next = hold;//insert current element to dummy list
		hold->next = tmp;
	}
	return dummy.next;
}
*/