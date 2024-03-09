#include <iostream>

//using namespace std;

struct List
{
    int data;
    List* next;
};

void Print(List* list)
{
    List* current = list;
    while (current != NULL)
    {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << std::endl;
}

List* add_front(int element, List* list)
{
    List* res = new List;
    (*res).data = element;

    res->next = list;    
    return res;    
}

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

List* append(List* list1, List* list2)
{
    if (list1 == NULL)
    {
        return list2;
    }

    List* res = list1;

    while (list1->next != NULL)
    {
        list1 = list1->next;
    }

    list1->next = list2;

    return res;
}

List* push(List* list, int num)
{
    List* newNode = new List;
    newNode->data = num;

    if (list == NULL || list->data >= num)
    {
        newNode->next = list;
        return newNode;
    }

    List* current = list;

    while (current->next != NULL && current->next->data < num)
    {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    return list;
}

List* insertionSort(List* list)
{
    List* sorted = NULL;

    while (list != NULL)
    {
        sorted = push(sorted, list->data);
        list = list->next;
    }

    return sorted;
}

List* quickSort(List* list)
{
    if (list == NULL) 
    {
        return list;
    }

    List* list1;
    list1 = NULL;
    List* list2;
    list2 = NULL;
    int first_elem = list->data;

    list = list->next;

    while (list != NULL)
    {
        if (first_elem <= list->data)
        {
            list1 = push(list1, list->data);
        }
        else
        {
            list2 = push(list2, list->data);
        }

        list = list->next;
    }
    List* delList1 = list1;
    List* delList2 = list2;

    list1 = quickSort(list1);
    list2 = quickSort(list2);

    removeList(delList1);
    removeList(delList2);

    list2 = push(list2, first_elem);

    list1 = append(list2, list1);

    return list1;
}

void merge(List* list1, List* list2)
{
    while (list1->next != NULL && list2->next != NULL)
    {
        List* res;
        if (list1->data < list2->data)
        {
            res;
        }
    }
}

void bubbleSort(List* list)
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

List* convertFromArrayToList(int* arr, int size)
{
    List* res = NULL;
    
    for (int i = size - 1; i >= 0 ; --i)
    {  
	res = add_front(arr[i], res);
    }

    return res;
}


int main() 
{
    int size = 5;
    int arr[] = {3, 1, 2, 5, 4};
    List* list = convertFromArrayToList(arr, size);

    Print(list);

    List* fun = NULL;

    //fun = append(fun, list);

    List* del = list;

    list = quickSort(list);
    removeList(del);
    //list = push(list, 0);

    std::cout << sizeof(*list) << std::endl;
    
    Print(list);

    removeList(list);

    return 0;
}