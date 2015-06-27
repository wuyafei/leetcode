class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n= gas.size();
        int* g=new int[n];
        for(int i=0;i<n;i++)
            g[i]=gas[i]-cost[i];
        int start=0;
        int sum=0;
        while(start<n){
            bool fail=false;
            for(int i=0;i<n;i++){
                int idx = (i+start)%n;
                sum += g[idx];
                if(sum<0){
                    fail=true;
                    start=i+start+1;
                    sum=0;
                    break;
                }
            }
            if(!fail) return start;
        }
        return -1;
    }
};