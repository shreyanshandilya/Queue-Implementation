#include <bits/stdc++.h>
using namespace std;

class PriorityQueue{
    vector<int> pq;

    public:

        bool isEmpty() {
            return pq.size()==0;
        }

        int getMin() {
            if(isEmpty()) return 0;
            else return pq[0];
        }

        void insert(int value) {
            pq.push_back(value);
            int cI = pq.size()-1;
            while(cI>0) {
                int pI = (cI-1)/2;
                if(pq[pI] > pq[cI]) {
                    swap(pq[pI], pq[cI]);
                    cI = pI;
                }
                else break;
            }
        }

        int removeMin() {
            if(isEmpty()) return 0;
            int ans = pq[0];
            swap(pq[0], pq[pq.size()-1]);
            pq.pop_back();
            int pi = 0;
            int mini = pi; 
            while(true) {
                int lci = 2*pi+1;
                int rci = 2*pi+2;
                if(lci<pq.size() && pq[mini] > pq[lci]) {
                    mini = lci;
                }
                if(rci<pq.size() && pq[mini] > pq[rci]) {
                    mini = rci;
                }
                if(mini==pi) break;
                swap(pq[pi], pq[mini]);
                pi = mini;
            }
            return ans;
        }

};

int main() {
    PriorityQueue pq;
    pq.insert(1);
    pq.insert(2);
    pq.insert(4);
    pq.insert(3);
    while(!pq.isEmpty()) {
        cout << pq.removeMin() << endl;
    }
    return 0;
}




