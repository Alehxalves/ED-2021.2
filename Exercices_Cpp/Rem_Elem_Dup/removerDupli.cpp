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

ListNode* deleteDuplicates(ListNode* head){
    ListNode* a;
    ListNode* ptr;
    ListNode* remove;

    for(ptr = head; ptr != NULL; ptr = ptr -> next){
        a = NULL;

        for(remove = ptr -> next; remove != NULL;){
            if(ptr->val == remove->val){
                if(a == NULL){
                    ptr -> next = remove -> next;
                }
                else{
                    a -> next = remove -> next;
                }

                ListNode* remover = remove;
                remove = remove -> next;
                free(remover);
            }
            else {
                a = remove;
                remove = remove->next;
            }
        }
    }
    return head;
}

int main(){
    int n;
    ListNode * head = nullptr;
    cin >> n;
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

    head = deleteDuplicates(head);

    for(ListNode * ptr = head; ptr != nullptr; ptr = ptr->next)
        cout << ptr->val << endl;
    return 0;    
}

