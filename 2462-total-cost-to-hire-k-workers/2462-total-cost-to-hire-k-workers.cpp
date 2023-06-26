class Solution {

public:

    long long totalCost(vector<int>& costs, int k, int candidates) {

priority_queue<int, vector<int>,greater<int>> pq1,pq2;

    long long sum=0,ip=0,jp=0,n=costs.size(),it1,it2;;

    for(int i=0;i<candidates;i++){

        pq1.push(costs[i]);

        ip=i;

    }

    for(int i=n-1;i>=candidates and i>=n-candidates;i--){

        pq2.push(costs[i]);

        jp=i;

    }

    ip++,jp--;

    while(k--){

        it1=1e9,it2=1e9;

        if(pq1.size()) it1=pq1.top();

        if(pq2.size()) it2=pq2.top();

        if(it1<=it2){

         sum+=it1;  

         pq1.pop(); 

         if(ip<=jp) pq1.push(costs[ip++]); 

        } else {

        sum+=it2;

        pq2.pop();

         if(ip<=jp)  pq2.push(costs[jp--]); 

        }

    }

    return sum;

    }

};