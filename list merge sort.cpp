#include <iostream>


struct node {
    int data;
    node* next;
    node* prev;
};

node* head = nullptr;

void insert(int x) {
    node* q = new node;
    q->data = x;
    q->prev = nullptr;
    q->next = head;

    if (head != nullptr)
        head->prev = q;
    head = q;    
}

void PrintList(node* L) {
    node* p = L;
    while (p != nullptr) {
        std::cout << p->data << ' ';
        p = p->next;
    }
    std::cout << '\n';
}

void MakeLists(node* ptr_lhs, node* &ptr_rhs) {
    ptr_lhs->prev = nullptr;
    node* tmp_lhs = ptr_lhs;
    node* tmp_rhs = ptr_rhs;

    while (tmp_lhs != nullptr) {
        tmp_lhs = tmp_lhs->next;
        if (tmp_lhs != nullptr) {
            tmp_rhs = tmp_rhs->next;
            tmp_lhs = tmp_lhs->next;
        }
    }

    if (tmp_rhs->prev != nullptr) {
        tmp_rhs->prev->next = nullptr;
        tmp_rhs->prev = nullptr;
    }

    ptr_rhs = tmp_rhs;
}

void tie(node* &lhs, node* rhs, node* end) {
    if (lhs == nullptr) {
        lhs = rhs;
        return;
    }
    end->next = rhs;
    rhs->prev = lhs;
}

void Merge(node* &lhs, node* &rhs) {
    node* res = nullptr;
    node* end = nullptr;

    while (lhs != nullptr && rhs != nullptr) {
        if (lhs->data < rhs->data) {
            node* tmp = lhs->next;
            lhs->next = nullptr;
            tie(res, lhs, end);
            end = lhs;
            lhs = tmp;
        } else {
            node* tmp = rhs->next;
            rhs->next = nullptr;
            tie(res, rhs, end);
            end = rhs;
            rhs = tmp;
        }
    }

    if (lhs != nullptr) {
        tie(res, lhs, end);
    }
    if (rhs != nullptr) {
        tie(res, rhs, end);
    }

    lhs = res;
}

void MergeSort(node*& ptr) {
    if (ptr == nullptr || ptr->next == nullptr) {
        return;
    }
    node* ptr_lhs = ptr;
    node* ptr_rhs = ptr;
    MakeLists(ptr_lhs, ptr_rhs);

    MergeSort(ptr_lhs);
    MergeSort(ptr_rhs);

    Merge(ptr_lhs, ptr_rhs);
    ptr = ptr_lhs;
}

int main()
{

    int size_of_array;
    std::cin >> size_of_array;

    for (int i = 0; i < size_of_array; ++i) {
        int A = rand();
        insert(A);
    }

    PrintList(head);
    MergeSort(head);
    PrintList(head);
    std::cout << '\n';
}
