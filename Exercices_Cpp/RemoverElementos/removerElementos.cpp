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

ListNode* removeElements(ListNode *head, int val){
    ListNode *aux, *remover = nullptr;
    for(ListNode * ptr = head; ptr != nullptr; ptr = ptr->next){
        if(head->val == val){
            remover = head;
            head = remover->next;
        }
        else{
            aux = head;
            while(aux->next && aux->next->val != val){
                aux = aux->next;
            }
            if(aux->next){
                remover = aux->next;
                aux->next = remover->next;
            }
        }
    }
    return head;
}

int main(){
    int n, val;
    ListNode * head= nullptr;
    cin >> n >> val;
    for(int i = 0; i < n; i++){
        ListNode * ptr;
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
    head = removeElements(head, val);

    for(ListNode * ptr = head; ptr != nullptr; ptr = ptr->next)
        cout << ptr->val << endl;
    
    return 0;    
}

