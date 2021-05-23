#include <iostream>



struct node {
    int data;
    node* next;
};

node* head = nullptr;

void insert(node* &L, int x) {
    node* q = new node;
    q->data = x;
    q->next = L;
    L = q;
}

void PrintList(node *L) {
    node* p = L;
    while (p != nullptr) {
        std::cout << p->data << ' ';
        p = p->next;
    }
    std::cout << '\n';
}

void tie(node* &lhs, node* rhs) {
    node* ptr = lhs;
    if (lhs == nullptr) {
        lhs = rhs;
        return;
    }
    while (ptr->next != nullptr) {
        ptr = ptr->next;
    }
    ptr->next = rhs;
}

void QuickSort(node *&lhs) {
    if (lhs != nullptr) {
        if (lhs->next == nullptr) return;
        int pivot = lhs->data;

        node* lhs_beg = nullptr;
        node* mid_beg = nullptr;
        node* rhs_beg = nullptr;

        node* p = lhs;
           
        while (p != nullptr) {
            node* tmp = p->next;
            if (p->data < pivot) {
                p->next = nullptr;
                tie(lhs_beg, p);
                p = tmp;
            } else if (p->data == pivot) {
                p->next = nullptr;
                tie(mid_beg, p);
                p = tmp;
            } else {
                p->next = nullptr;
                tie(rhs_beg, p);
                p = tmp;
            }
        }

        QuickSort(lhs_beg);
        QuickSort(rhs_beg);

        tie(lhs_beg, mid_beg);
        tie(lhs_beg, rhs_beg);

        lhs = lhs_beg;
        if (lhs == head) {
            head = lhs_beg;
            return;
        }
    }
}

int main()
{
    int size_of_array;
    std::cin >> size_of_array;

    for (int i = 0; i < size_of_array; ++i) {
        int A = rand();
        insert(head, A);
    }

    PrintList(head);
    std::cout << '\n';

    QuickSort(head);
    PrintList(head);
}

