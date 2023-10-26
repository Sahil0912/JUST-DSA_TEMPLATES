#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
typedef struct list
{
    int data;
    struct list* next;
}list;

bool is_empty(list *lst){
    return (lst == NULL);
}
list *create_lst(int d){
    list *head = (list *)malloc(sizeof(list));
    head->data = d;
    head->next = NULL;
    return head;
}

list *add_to_front(int d, list*h){
    list *head = create_lst(d);
    head->next = h;
    return head;
}

list* array_to_list(int d[], int size){
    list* head = create_lst(d[0]);
    int i = 1;
    int x = size -1;
    while(x--)
    {
        head = add_to_front(d[i],head);
        i++;
    }
    return head;
}

void print_lst(list *head){
    while (head!=NULL)
    {
        printf("%d, ",head->data);
        head = head->next;
    }
    printf("\n");
}


//count operation-> no. of elements in a list
int count(list *h){
    if (h==NULL)
    {
        return 0;
    }
    return (1+count(h->next));
}


//concatenation to 1 of the lists

void conc(list *h1, list *h2){

    if(h1!= NULL){
        if(h1->next == NULL){
            h1->next = h2;
        }
        else{
            conc(h1->next,h2);
        }
    }
    else{
        h1 = h2;
    }
}

void insert(list* h1,int data_prev, int data){
    list* node = create_lst(data);
    list* data_node = h1;
    while (data_node->data != data_prev && data_node->next!=NULL)
    {
        data_node = data_node->next;
    }
    node-> next = data_node->next;
    data_node->next = node;
}

int main(){

    int arr1[10] = {2,9,10,4,10,29,384,38,190,10};
    list* lst1 = array_to_list(arr1,10);
    print_lst(lst1);

    int arr2[5] = {2,10,29,28,10};
    list *lst2 = array_to_list(arr2,5);
    print_lst(lst2);

    conc(lst1,lst2);
    print_lst(lst1);

    insert(lst1, 38,999);
    print_lst(lst1);
    return 0;
}