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

 

ListNode* readList(){
    int n;
    cin >> n;
    ListNode * head;
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

    return head;

}

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

ListNode *intersectionList(ListNode *head1, ListNode *head2){
    ListNode *newList = nullptr;
    ListNode *ptr2 = head2;
    for(ListNode *ptr = head1; ptr != nullptr; ptr = ptr->next){
        
        while(ptr2 != nullptr){
            if(ptr->val < ptr2->val) break;
            else if(ptr->val == ptr2->val){
                ListNode *aux;
                if(newList == nullptr){
                    newList = new ListNode(ptr->val);
                    aux = newList;
                    break;
                }else{
                    aux->next = new ListNode(ptr->val, nullptr);
                    aux = aux->next;
                    break;
                }
            }
            ptr2 = ptr2->next;
        }
    }
    newList = deleteDuplicates(newList);
    return newList;
}


void printList(ListNode * head){
    for(ListNode * ptr = head; ptr != nullptr; ptr = ptr->next){
        cout << ptr->val << endl;
    }
}



int main(){
    
    ListNode * head1 = readList();
    ListNode * head2 = readList();

    ListNode * res = intersectionList(head1, head2);

    printList(res);

    return 0;    
}