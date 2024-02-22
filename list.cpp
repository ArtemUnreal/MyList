#include <iostream>

using namespace std;


struct List
{
    int data;
    List* next;
};

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
	cout << list->data << " ";
	list = list->next;
    }

    cout << endl;
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

    cout << list1.data << endl;
    cout << list1.next->data << endl;
    cout << list1.next->next->data << endl;

    List* list4 = add_front(10, &list1);
    
    int size = 5;
    int arr[size] = {1, 2, 3, 4, 5}; 
    
    List* list5 = convertFromArrayToList(arr, size);
    //int sum = sumCount(list5);

    //cout << sum << endl;

    Print(list5);

    return 0;
}