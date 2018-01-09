#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector<int> a[32001]; // number of nodes;

int indegree[32001];

priority_queue<int> pq;


int main (void){
    int n=0, m=0;
    int prev=0, next=0;
    
    scanf("%d %d", &n, &m);
    
    for(int i=0;i<m;i++){
        scanf("%d %d", &prev, &next);
        a[prev].push_back(next);
        indegree[next]++;
    }


    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            pq.push(-i);
        }
    }

    while(!pq.empty()){
        int min = -1* pq.top();
        pq.pop();

        for(auto i:a[min]){
            indegree[i]--;
            if(indegree[i]==0){
                pq.push(-i);
            }
        }

        printf("%d ", min);
    }

    return 0;
}


