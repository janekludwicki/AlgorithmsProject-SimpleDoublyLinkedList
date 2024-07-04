#include <iostream>
#include <stdio.h>
using namespace std;

struct ListElement {
    unsigned long long int Value;
    ListElement* next = nullptr;
    ListElement* prev = nullptr;
};

void AddToListBefore(ListElement*& head, ListElement*& tail, ListElement*& element, unsigned long long int value) {
    ListElement* newElement = new ListElement;
    newElement->Value = value;

    if (head == nullptr)
    {
        head = newElement;
        tail = newElement;
        return;
    }
    if (element->prev == nullptr)
    {
        newElement->next = head;
        head->prev = newElement;
        head = newElement;
        return;
    }
    ListElement* prevElement = element->prev;

    prevElement->next = newElement;
    newElement->prev = prevElement;

    newElement->next = element;
    element->prev = newElement;
}

void AddToListAfter(ListElement*& head, ListElement*& tail, ListElement*& element, unsigned long long int value) {
    ListElement* newElement = new ListElement;
    newElement->Value = value;
    if (tail == nullptr)
    {
        head = newElement;
        tail = newElement;
        return;
    }
    if (element->next == nullptr)
    {
        newElement->prev = tail;
        tail->next = newElement;
        tail = newElement;
        return;
    }
    ListElement* nextElement = element->next;

    nextElement->prev = newElement;
    newElement->next = nextElement;

    newElement->prev = element;
    element->next = newElement;
}

void Remove(ListElement*& head, ListElement*& tail, ListElement* element, ListElement* tab[10]) {
    if (head == nullptr)
        return;

    if (element->next == nullptr)
    {
        ListElement* prevElement = element->prev;
        if (prevElement != nullptr)
        {
            prevElement->next = nullptr;
            tail = prevElement;
        }
        else
        {
            head = nullptr;
            tail = nullptr;
        }
        ListElement* temp = element;

        for (int i = 0; i < 10; i++)
        {
            if (element == tab[i])
            {
                tab[i] = tab[i]->prev;
            }
        }
        delete temp;
        return;
    }
    if (element->prev == nullptr)
    {
        ListElement* nextElement = element->next;

        if (nextElement != nullptr)
        {
            nextElement->prev = nullptr;
            head = nextElement;
        }
        else
        {
            head = nullptr;
            tail = nullptr;
        }
        ListElement* temp = element;

        for (int i = 0; i < 10; i++)
        {
            if (element == tab[i])
            {
                tab[i] = tab[i]->next;
            }
        }
        delete temp;
        return;
    }
    ListElement* prevElement = element->prev;
    ListElement* nextElement = element->next;

    prevElement->next = nextElement;
    nextElement->prev = prevElement;
    ListElement* temp = element;

    for (int i = 0; i < 10; i++)
    {
        if (element == tab[i])
        {
            tab[i] = tab[i]->next;
        }
    }
    delete temp;
}

void Print(ListElement* element, bool printAll) {
    if (element == nullptr)
        return;

    cout << element->Value;

    if (printAll)
    {
        while (element->next != nullptr)
        {
            cout << " " << element->next->Value;
            element = element->next;
        }
    }
    cout << endl;
}

int main() {
    char command[100];
    ListElement* tab[10];
    ListElement* head = nullptr;
    ListElement* tail = nullptr;
    while (true)
    {
        scanf_s("%s", command, 100);

        if (feof(stdin) != 0)
        {
            break;
        }
        if (command[0] == 'i')
        {
            int y = 0;
            scanf_s("%d", &y);

            scanf_s("%s", command, 100);

            if (command[0] == 'B')
            {
                tab[y] = head;
            }
            else if (command[0] == 'E')
            {
                tab[y] = tail;
            }
            else
            {
                tab[y] = tab[command[0] - '0'];
            }
        }
        else if (command[0] == '+')
        {
            scanf_s("%s", command, 100);
            if ((tab[command[0] - '0'] != nullptr) && (tab[command[0] - '0']->next != nullptr))
                tab[command[0] - '0'] = tab[command[0] - '0']->next;
        }
        else if (command[0] == '-')
        {
            scanf_s("%s", command, 100);
            if ((tab[command[0] - '0'] != nullptr) && (tab[command[0] - '0']->prev != nullptr))
                tab[command[0] - '0'] = tab[command[0] - '0']->prev;
        }
        else if (command[0] == '.')
        {
            scanf_s("%s", command, 100);

            unsigned long long int y = 0;
            cin >> y;

            if (command[0] == 'B')
            {
                AddToListBefore(head, tail, head, y);
            }
            else if (command[0] == 'E')
            {
                AddToListBefore(head, tail, tail, y);
            }
            else
            {
                AddToListBefore(head, tail, tab[command[0] - '0'], y);
            }
        }
        else if (command[0] == 'A')
        {
            scanf_s("%s", command, 100);

            unsigned long long int y = 0;
            cin >> y;

            if (command[0] == 'B')
            {
                AddToListAfter(head, tail, head, y);
            }
            else if (command[0] == 'E')
            {
                AddToListAfter(head, tail, tail, y);
            }
            else
            {
                AddToListAfter(head, tail, tab[command[0] - '0'], y);
            }
        }
        else if (command[0] == 'R')
        {
            scanf_s("%s", command, 100);

            if (command[0] == 'B')
            {
                Remove(head, tail, head, tab);
            }
            else if (command[0] == 'E')
            {
                Remove(head, tail, tail, tab);
            }
            else
            {
                Remove(head, tail, tab[command[0] - '0'], tab);
            }
        }
        else if (command[0] == 'P')
        {
            scanf_s("%s", command, 100);
            if (command[0] == 'A')
            {
                Print(head, true);
            }
            else
            {
                Print(tab[command[0] - '0'], false);
            }
        }
    }
}