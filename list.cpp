#include <iostream>
#include <string>

//using namespace std;
template <class T>
struct List
{
    T data;
    List* next;
};

template <class T>
void Print(List<T>* list)
{
    List<T>* current = list;
    while (current != NULL)
    {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << std::endl;
}

template <class T>
void removeList(List<T>* list)
{
    List<T>* current = list;
    List<T>* nxt;

    while (current != NULL)
    {
        nxt = current->next;
        delete current;
        current = nxt;
    }
}

template <class T>
List<T>* add_front(T element, List<T>* list)
{
    List<T>* res = new List<T>;
    (*res).data = element;
  
    res->next = list;
    return res;    
}

int nth(List<int>* list, int element)
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

void removeLastElement(List<int>* list)
{
    while (list->next->next != NULL)
    {
        list = list->next;
    }
    
    list->next = NULL;

    delete list->next;
}

template <class T>
List<T>* append(List<T>* list1, List<T>* list2)
{
    if (list1 == NULL)
    {
        return list2;
    }

    List<T>* res = list1;

    while (list1->next != NULL)
    {
        list1 = list1->next;
    }

    list1->next = list2;

    return res;
}

List<int>* push(List<int>* list, int num)
{
    List<int>* newNode = new List<int>;
    newNode->data = num;
    newNode->next = NULL;

    if (list == NULL || list->data >= num)
    {
        newNode->next = list;
        return newNode;
    }

    List<int>* current = list;

    while (current->next != NULL && current->next->data < num)
    {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    return list;
}

List<int>* insertionSort(List<int>* list)
{
    List<int>* sorted = NULL;

    while (list != NULL)
    {
        sorted = push(sorted, list->data);
        list = list->next;
    }

    return sorted;
}

List<int>* reverseList(List<int>* list)
{
    List<int>* prev = NULL;
    List<int>* next = NULL;

    while (list != NULL)
    {
        next = list->next;
        list->next = prev;
        prev = list;
        list = next;
    }    

    return prev;
}

List<int>* quickSort(List<int>* list)
{
    if (list == NULL) 
    {
        return list;
    }

    List<int>* list1 = NULL;
    List<int>* list2 = NULL;

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

    List<int>* delList1 = list1;
    List<int>* delList2 = list2;

    list1 = quickSort(list1);
    list2 = quickSort(list2);

    removeList(delList1);
    removeList(delList2);

    list2 = add_front(first_elem, list2);

    list2 = reverseList(list2);
    list1 = reverseList(list1);

    list2 = append(list2, list1);
    list2 = reverseList(list2);
   
    return list2;
}

List<int>* merge(List<int>* list1, List<int>* list2)
{
    List<int>* res = NULL;

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

template <class T>
int len(List<T>* list)
{
    int res = 0;

    while (list != NULL)
    {
        list = list->next;
        ++res;
    }

    return res;
}

List<int>* mergeSort(List<int>* list)
{
    if (list == NULL) 
    {
        return list;
    }

    if (list->next == NULL)
    {
        list = add_front<int>(list->data, NULL);
        return list;
    }

    int sz = len(list);
    int half = sz / 2;
    int count = 0;

    List<int>* list1 = NULL;
    List<int>* list2 = NULL;

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
    List<int>* del1 = list1;
    List<int>* del2 = list2;
    list1 = mergeSort(list1);
    list2 = mergeSort(list2);

    removeList(del1);
    removeList(del2);

    del1 = list1;
    del2 = list2;

    List<int>* res = merge(list1, list2);

    removeList(del1);
    removeList(del2);

    return res;
}

void bubbleSort(List<int>* list)
{
    int tmp;
    List<int>* current = list;
    List<int>* next;

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

int sumCount(List<int>* list)
{
    int result = 0;
    while (list != NULL)
    {
	list = list->next;
	result++;
    }

    return result;
    
}

List<int>* convertFromArrayToList(int* arr, int size)
{
    List<int>* res = NULL;
    
    for (int i = size - 1; i >= 0 ; --i)
    {  
	res = add_front(arr[i], res);
    }

    return res;
}

List<std::string>* convertFromStringToList(std::string s)
{
    List<std::string>* res = NULL;

    res = add_front(s, res);

    return res;
}

List<std::string>* perStr(std::string str) 
{
    if (str.length() <= 1) 
    {
        List<std::string>* result = new List<std::string>;
        result->next = NULL;
        result->data = str;
        return result;
    }

    List<std::string>* result = NULL;

    for (int i = 0; i < str.length(); i++) 
    {
        std::string sub1 = str.substr(0, i);
        std::string sub2 = str.substr(i + 1);

        List<std::string>* temp = perStr(sub1 + sub2);
        List<std::string>* delTemp = temp;

        while (temp != NULL) 
        {
            result = add_front(str[i] + temp->data, result);
            temp = temp->next;
        }

        removeList(delTemp);
    }

    return result;
}

List<std::string>* perSticks(std::string str)
{
    if (str.length() < 2) 
    {
        List<std::string>* result = new List<std::string>;
        result->next = NULL;
        result->data = str;
        return result;
    }

    List<std::string>* result = new List<std::string>;
    result->data = str;
    result->next = NULL;

    for (int i = 1; i < str.length(); i++) 
    {
        std::string sub_left = str.substr(0, i);
        std::string sub_right = str.substr(i);
        List<std::string>* temp = perSticks(sub_right);
        List<std::string>* delTemp = temp;

        while (temp != NULL)
        {
            result = add_front(sub_left + "|" + temp->data, result);
            temp = temp->next;
        }
        removeList(delTemp);
    }

    return result;
}


int main() 
{
    std::string str = "abc";
    
    List<std::string>* list = convertFromStringToList(str);

    Print(list);

    List<std::string>* delList = list;
    list = perSticks(str);
    removeList(delList);

    Print(list);
    removeList(list);


    return 0;
}