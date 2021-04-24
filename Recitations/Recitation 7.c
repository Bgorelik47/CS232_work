int ll_has_cycle(node *head) {
    /* your code here */
  
    struct node * t = head;
    struct node * h = head;
    
    while(h != NULL && h->next != NULL)
  { 
        h = h->next->next;
        t = t->next;

        if(h == t)
    {
            while(t != head)
      {
                t = t->next;
                head = head->next;
            }
            return head;
        }
    }
    return NULL; 
}