#include <iostream>
#include <list>

//using namespace std;

struct List
{
    int data;
    List* next;
};

int nth(List* list, int element)
{
    int count = 0;

    while (1)
    {
        if (count == element)
        {
            return list->data;
        }

        list = list->next;
        count++;
    }

    return -1;
}

void removeLastElement(List* list)
{
    while (list->next->next != NULL)
    {
        list = list->next;
    }
    
    list->next = NULL;

    delete list->next;
}

void append(List* list1, List* list2)
{
    while (list1->next != NULL)
    {
        list1 = list1->next;
    }

    list1->next = list2;
}

void removeList(List* list)
{
    List* current = list;
    List* nxt;

    while (current != NULL)
    {
        nxt = current->next;
        delete current;
        current = nxt;
    }
}

void push(List* list, int num)
{
    List* newNode = new List;
    newNode->data = num;

    List* tmp = list;
    while (list->next != NULL)
    {
        if (list->next->data >= num)
        {
            tmp = list->next;
            list->next = newNode;
            newNode->next = tmp;
            break;
        }

        tmp = list->next;
        list = list->next;
    }
}

void sort(List* list)
{
    int tmp;
    List* current = list;
    List* next;

    while (current != NULL) 
    {
        next = current->next;
        
        while (next != NULL) 
        {
            if (current->data > next->data) 
            {
                tmp = current->data;
                current->data = next->data;
                next->data = tmp;
            }
            
            next = next->next;
        }

        current = current->next;
    }
}

int sumCount(List* list)
{
    int result = 0;
    while (list != NULL)
    {
	list = list->next;
	result++;
    }

    return result;
    
}

List* add_front(int element, List* list)
{
    List* res = new List;
    (*res).data = element;

    res->next = list;    
    return res;    
}

List* convertFromArrayToList(int* arr, int size)
{
    List* res = NULL;
    
    for (int i = size - 1; i >= 0 ; --i)
    {  
	res = add_front(arr[i], res);
    }

    return res;
}

void Print(List* list)
{
    while (list != NULL)
    {
	std::cout << list->data << " ";
	list = list->next;
    }

    std::cout << std::endl;
}

int main()
{
    List list1;
    List list2;
    List list3;
    List list4;
    List list6;
    list1.data = 4;
    list2.data = 5;
    list3.data = 6;
    list4.data = 1;
    list6.data = 2;
    list1.next = &list2;
    list2.next = &list3;
    list3.next = &list4;
    list4.next = &list6;

    list6.next = NULL;

    //List* list4 = add_front(10, &list1);
    
    int size = 15;
    int arr[size];

    for (int i = 0; i < size; ++i)
    {
        arr[i] = i;
    } 

    List* list5 = convertFromArrayToList(arr, size);
    int sum = sumCount(list5);

    //cout << sum << endl;

    //int elem = nth(list5, 1);

    //push(&list1, 4);
    //std::cout << elem << std::endl;
    //removeLastElement(&list1);
    //append(&list1, list5);
    sort(&list1);
    Print(&list1);
    //Print(list5);
    //removeList(list5);
    //Print(list5);

    return 0;
}