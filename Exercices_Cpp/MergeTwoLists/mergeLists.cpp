#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class ListNode {
    public:

    int val;
    ListNode *next;
    
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {} 
};

void inserirOrdenado(ListNode *lista, int num){
    ListNode *novo = new ListNode(lista->val); 
    ListNode *aux = nullptr;

    if(novo){
        novo->val = num;
        if(lista == nullptr){
            novo->next = nullptr;
            lista = novo;
        }
        else if(novo->val < (lista)->val){
            novo->next = new ListNode(num, nullptr);
            lista = novo;
        }
        else{
            aux = lista;
            while(aux->next && novo->val > aux->next->val)
                aux = aux->next;
            novo->next = aux->next;
            aux->next = novo;
        }
    }
}

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
    if(l1 != nullptr && l2 == nullptr){
        return l1;
    }
    else if(l1 == nullptr && l2 != nullptr){
        return l2;
    }
    else{
        ListNode *newList = l1;
        for(ListNode *ptr = l2; ptr != nullptr; ptr = ptr->next){
            int value = ptr->val;
            inserirOrdenado(newList, value);
        }
        return newList;
    }
    
}

ListNode* readList(){
    int n;
    cin >> n;
    ListNode *head = nullptr;
    for(int i = 0; i < n; i++){
        ListNode *ptr;
        int x;
        cin >> x;
        if(i == 0){
            head = new ListNode(x);
            ptr = head;
        }else{
            ptr->next = new ListNode(x, nullptr);
            ptr = ptr->next;
        }
    }
    return head;
}


int main(){
    
    ListNode *list1 = readList();
    ListNode *list2 = readList();

    ListNode *head = mergeTwoLists(list1, list2);
    
    for(ListNode *ptr = head; ptr != nullptr; ptr = ptr->next)
        cout << ptr->val << endl;
    
    return 0;    
}

