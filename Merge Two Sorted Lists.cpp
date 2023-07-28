class Solution {
  public: ListNode * mergeTwoLists(ListNode * list1, ListNode * list2) {
    ListNode * temp = new ListNode(0);
    ListNode * ans = temp;
    while (list1 && list2) {
      if (list1 -> val < list2 -> val) {
        ListNode * T = new ListNode(list1 -> val);
        temp -> next = T;
        temp = temp -> next;
        list1 = list1 -> next;
      } else {
        ListNode * T = new ListNode(list2 -> val);
        temp -> next = T;
        temp = temp -> next;
        list2 = list2 -> next;
      }

    }
    while (list1) {
      ListNode * T = new ListNode(list1 -> val);
      temp -> next = T;
      temp = temp -> next;
      list1 = list1 -> next;
    }
    while (list2) {
      ListNode * T = new ListNode(list2 -> val);
      temp -> next = T;
      temp = temp -> next;
      list2 = list2 -> next;
    }
    return ans -> next;
  }
};
