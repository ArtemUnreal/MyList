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
    newNode->next = NULL;

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

List* reverseList(List* list)
{
    List* prev = NULL;
    List* next = NULL;

    while (list != NULL)
    {
        next = list->next;
        list->next = prev;
        prev = list;
        list = next;
    }

    return prev;
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
            list1 = add_front(list->data, list1);
        }
        else
        {
            list2 = add_front(list->data, list2);
        }

        list = list->next;
    }

    List* delList1 = list1;
    List* delList2 = list2;

    list1 = quickSort(list1);
    list2 = quickSort(list2);

    removeList(delList1);
    removeList(delList2);

    list2 = add_front(first_elem, list2);

    list2 = reverseList(list2);
    list1 = reverseList(list1);

    list2 = append(list2, list1);

    //list1 = reverseList(list1);
    return reverseList(list2);
}

List* merge(List* list1, List* list2)
{
    List* res = NULL;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data < list2->data)
        {
            res = add_front(list1->data, res);
            list1 = list1->next;
        }
        else
        {
            res = add_front(list2->data, res);
            list2 = list2->next;
        }
    }

    if (list1 != NULL)
    {
        while (list1 != NULL)
        {
            res = add_front(list1->data, res);
            list1 = list1->next;
        }
    }
    else if (list2 != NULL)
    {
        while (list2 != NULL)
        {
            res = add_front(list2->data, res);
            list2 = list2->next;
        }
    }

    res = reverseList(res);

    return res;
}

int len(List* list)
{
    int res = 0;

    while (list != NULL)
    {
        list = list->next;
        ++res;
    }

    return res;
}

List* mergeSort(List* list)
{
    if (list == NULL) 
    {
        return list;
    }

    if (list->next == NULL)
    {
        list = add_front(list->data, NULL);
        return list;
    }

    int sz = len(list);
    int half = sz / 2;
    int count = 0;

    List* list1 = NULL;
    List* list2 = NULL;

    while (count < half)
    {
        list1 = add_front(list->data, list1);
        list = list->next;
        ++count;
    }

    while (count < sz)
    {
        list2 = add_front(list->data, list2);
        list = list->next;
        ++count;
    }
    List* del1 = list1;
    List* del2 = list2;
    list1 = mergeSort(list1);
    list2 = mergeSort(list2);

    removeList(del1);
    removeList(del2);

    del1 = list1;
    del2 = list2;

    List* res = merge(list1, list2);

    removeList(del1);
    removeList(del2);

    return res;
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
    int size = 8;
    int arr[] = {3, 1, 2, 5, 4, 8, 7, 6};
    List* list = convertFromArrayToList(arr, size);

    int size_ = 3;
    int arr_[] = {8, 7, 6};
    List* list2 = convertFromArrayToList(arr_, size_);

    //Print(list);

    //list = reverseList(list);

    Print(list);
    //Print(list2);

    //List* fun = NULL;

    //fun = append(fun, list);

    List* del = list;
    list = quickSort(list);
    //list = quickSort(list);
    removeList(del);
    //list = push(list, 0);

    removeList(list2);

    //list = removeFirstElement(list);

    //std::cout << sizeof(*list) << std::endl;
    
    Print(reverseList(list));

    removeList(list);

    //removeList(list);

    return 0;
}