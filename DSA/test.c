while(temp->link != NULL){
        ptr = temp;
        ptr->link = NULL
        free(temp);
    } 

        int key;
    printf("enter the key ");
    scanf("%d",&key);
    struct node *ptr = head;
    while(ptr != NULL && ptr->data != key){
        ptr = ptr->link;
    }
    if (ptr == NULL){
        printf("Search failed, Node not foud");
        return;
    }
    struct node* temp = ptr;
    ptr->link = temp->link;
    free(ptr);
    printf("NULL\n");