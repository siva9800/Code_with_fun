class Solution {
public:

    static bool customSort(Job &a, Job&b){
            
            return a.dead<b.dead;
            
    }
    
    vector<int> JobScheduling(Job arr[], int n) { 
        
        sort(arr,arr+n,customSort);
        
        priority_queue<int, vector<int>, greater<int>> pq;

        
        int size=0,max_profit=0;
        
        for(int i=0; i<n; i++){
            
            int profit = arr[i].profit;
            int deadline = arr[i].dead;
            
            if(deadline>size){
                size++;
                pq.push(profit);
                max_profit+=profit;
                
            }
            else{
                if(profit>pq.top()){
                    max_profit-=pq.top();
                    max_profit+=profit;
                    pq.pop();
                    pq.push(profit);
                }
                
            }
        }
        
        return {size,max_profit};
    } 
};
