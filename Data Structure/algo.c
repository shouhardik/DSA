#include <stdio.h>
#include<stdlib.h>

struct node
{
    int number;
    struct node *next;
};

 struct linked_list node;
node *head=NULL, *last=NULL;

void create();
void print();
void insert_at_last(int value);
void insert_at_first(int value);
void insert_after(int key, int value);
void delete_item(int value);
void search_item(int value);


int main()
{
    int key, value;

    //Create a linked list
    printf("Create Linked List\n");
    create();
    print_linked_list();

    //Insert value at first position to existing Linked List
    printf("\nInsert new item at first\n");
    scanf("%d", &value);
    insert_at_first(value);
    print_linked_list();

      //Insert value after a defined value to existing Linked List
    printf("\nEnter a KEY (existing item of List), after that you want to insert a value\n");
    scanf("%d", &key);
    printf("\nInsert new item after %d KEY\n", key);
    scanf("%d", &value);
    insert_after(key, value);
    print();


    //Insert value at last position to existing Linked List
    printf("\nInsert new item at last\n");
    scanf("%d", &value);
    insert_at_last(value);
    print();


    


  


    //Search an item from Linked List
    printf("\nEnter an item to search it from List\n");
    scanf("%d", &value);
    search_item(value);


    //Delete value from List
    printf("\nEnter a value, which you want to delete from list\n");
    scanf("%d", &value);
    delete_item(value);
    print();
    


    return 0;
}


/*
    User Defined Functions
*/
void create()
{
    int val;

    while(1)
    {
        printf("Input a number. (Enter -1 to exit)\n");

        scanf("%d", &val);

        if(val==-1){
		
            break;

        insert_at_last(val);
    }    
       

    }

}


void insert_at_last(int value)
{
    node *temp_node;
    temp_node = (node *) malloc(sizeof(node));

    temp_node->number=value;
    temp_node->next=NULL;

    //For the 1st element
    if(head==NULL)
    {
        head=temp_node;
        last=temp_node;
    }
    else
    {
        last->next=temp_node;
        last=temp_node;
    }

}


void insert_at_first(int value)
{
    node *temp_node = (node *) malloc(sizeof(node));

    temp_node->number=value;
    temp_node->next = head;

    head = temp_node;
}




void delete_item(int value)
{
    node *myNode = head, *previous=NULL;
    int flag = 0;

    while(myNode!=NULL)
    {
        if(myNode->number==value)
        {
            if(previous==NULL)
                head = myNode->next;
            else
                previous->next = myNode->next;

            printf("%d is deleted from list\n", value);

            flag = 1;
            free(myNode); //need to free up the memory to prevent memory leak
            break;
        }

        previous = myNode;
        myNode = myNode->next;
    }

    if(flag==0)
        printf("Key not found!\n");
}
void insert_after(int key, int value)
{
    node *myNode = head;
    int flag = 0;

    while(myNode!=NULL)
    {
        if(myNode->number==key)
        {
            node *newNode = (node *) malloc(sizeof(node));
            newNode->number = value;
            newNode->next = myNode->next;
            myNode->next = newNode;

            printf("%d is inserted after %d\n", value, key);

            flag = 1;


            break;
        }
        else
            myNode = myNode->next;
    }

    if(flag==0)
        printf("Key not found!\n");

}




void print()
{
    printf("\nYour full linked list is\n");

    node *myList;
    myList = head;

    while(myList!=NULL)
    {
        printf("%d ", myList->number);

        myList = myList->next;
    }
    puts("");
}

void search_item(int value)
{
    node *searchNode = head;
    int flag = 0;

    while(searchNode!=NULL)
    {
        if(searchNode->number==value)
        {
            printf("%d is present in this list. Memory address is %d\n", value, searchNode);
            flag = 1;
            break;
        }
        else
            searchNode = searchNode->next;
    }

    if(flag==0)
        printf("Item not found\n");

}


void mergesort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l + (r - l) / 2; 
        mergesort(arr, l, m); 
        mergesort(arr, m + 1, r); 
        merge(arr, l, m, r); 
    } 
}
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
    int L[n1], R[n2]; 
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 