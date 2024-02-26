#include <iostream>

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
    list1.data = 1;
    list2.data = 2;
    list3.data = 3;

    list1.next = &list2;
    list2.next = &list3;
    list3.next = NULL;

    std::cout << list1.data << std::endl;
    std::cout << list1.next->data << std::endl;
    std::cout << list1.next->next->data << std::endl;

    List* list4 = add_front(10, &list1);
    
    int size = 5;
    int arr[size];

    for (int i = 0; i < size; ++i)
    {
        arr[i] = i;
    } 
    
    List* list5 = convertFromArrayToList(arr, size);
    int sum = sumCount(list5);

    //cout << sum << endl;

    int elem = nth(list5, 1);

    //std::cout << elem << std::endl;
    //removeLastElement(&list1);
    append(&list1, list5);
    Print(&list1);

    return 0;
}