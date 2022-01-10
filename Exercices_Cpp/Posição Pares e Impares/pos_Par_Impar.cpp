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
    
    int size(ListNode *list){
        int k = 0;
        for(ListNode *ptr = list; ptr != nullptr; ptr = ptr->next)
            k++;
        return k;
    }
};

ListNode* concatena(ListNode* l1, ListNode* l2){
    ListNode* p;
    ListNode* q;

    if (l1 == NULL) 
        return l2;
    p = l1;   
    do{ 
        q = p; 
        p = p->next;
    }while(p != NULL);
    q->next = l2;

    return l1;   
}

ListNode* oddEvenList(ListNode* head){
    ListNode *ptr = head;
    ListNode *par = new ListNode(head->val), *impar = nullptr;
    int k = head->size(head);

    for(int i = 0; i < k; i++){
        ListNode *parAux, *imparAux;
        if(i == 0)
            parAux = par;
        else if(i % 2 == 0){ 
            parAux->next = new ListNode(ptr->val, nullptr);
            parAux = parAux->next;
        }else{
            if(impar == nullptr){
                impar = new ListNode(ptr->val);
                imparAux = impar;
            }else{
                imparAux->next = new ListNode(ptr->val, nullptr);
                imparAux = imparAux->next;               
            }
        }
        ptr = ptr->next;
    }
    ListNode *newList = concatena(par, impar);
    return par;
}


int main(){
    int n;
    ListNode * head= nullptr;
    cin >> n;
    for(int i = 0; i < n; i++){
        ListNode * ptr;
        int x;
        cin >> x;
        if( i == 0){
            head = new ListNode(x);
            ptr = head;
        }else{
            ptr->next = new ListNode(x, nullptr);
            ptr = ptr->next;
        }
    }

    head = oddEvenList(head);

    for(ListNode * ptr = head; ptr != nullptr; ptr = ptr->next)
        cout << ptr->val << endl;
    
    return 0;    
}