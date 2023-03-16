/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k){
  if(head==NULL || head->next==NULL)
         return head;
    if(k==0)
      return head;
    struct ListNode* temp = head;
    int count=0;
    while(temp!=NULL){
      temp=temp->next;
      count++;
    }
    if(count==k){
        return head;
    }
    printf("%d",count);
    if(count>k){
    int key = count-k;
    struct ListNode* a = head;
    for(int i=key-1;i>0;i--){
      a = a->next;
    }
    // printf("a val data %d\n",a->val);
    struct ListNode* flag = a->next;
    a->next = NULL;
    struct ListNode* prime = flag;
    while(prime->next!=NULL){
        prime = prime->next;
    }
    prime->next = head;
    head = flag;
    }
    else{
      int key = k%count;
      if(key==0)
        return head;
    //   printf("key is %d\n",key);
        struct ListNode* a = head;
    for(int i=(count-key)-1;i>0;i--){
      a = a->next;
    }
    printf("a val is %d\n",a->val);
    struct ListNode* flag = a->next;
    a->next=NULL;
    struct ListNode* prime = flag;
    while(prime->next!=NULL){
        prime=prime->next;
    }
    prime->next = head;
    head = flag;
    }
   return head;
}