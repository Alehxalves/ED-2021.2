#include <iostream>
#include <vector>
#include <set>

using namespace std;

void showNewQueue(vector<int> & queue, set<int> & leftQueue, int sizeQueue){
    for(int i = 0; i < sizeQueue; i++){
        if(leftQueue.find(queue[i]) == leftQueue.end()){
            cout << queue[i]<<" ";
        }
        if(i == sizeQueue - 1){
            cout << endl;
        }    
    }
}

int main(){
    int sizeQueue, sizeLeft, value;
    vector<int> queue;
    set<int> leftQueue;

    cin>>sizeQueue;
    for (int i = 0; i < sizeQueue; i++){
        cin >> value;
        queue.push_back(value);
    }

    cin>>sizeLeft;
    for (int i = 0; i < sizeLeft; i++){
        cin >> value;
        leftQueue.insert(value);
    }
    
    showNewQueue(queue, leftQueue, sizeQueue);
    
    return 0;
}