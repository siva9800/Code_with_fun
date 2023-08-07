//given an intervals we have to tell min overlapping intervals to remove 
//intution to do this simple if we have 1-2, 1-8,3-4, 5-6, if we remove 1-8 we will not have  any overalpping intervals so the idea is to sort based on end time beacuse
//1-2, 1-8,3-4, 5-6,7-11,8-20,12-13,14-15 in this case we can remove 1-8 and 8-20 this can be simple achieve if our arr is like this 1-2,3-4, 5-6,1-8,7-11,12-13,14-15,8-20 so simple 6<1 and 15<8 we can remove it
class Solution {
public:

    static bool customSort(vector<int> &a ,vector<int> &b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int prev=-1e6,delete_cnt=0;
        sort(intervals.begin(),intervals.end(),customSort);
        for(vector<int> it:intervals){
            if(it[0]>=prev){
                prev=it[1];
            }
            else{
                delete_cnt++;
            }
        }
        return delete_cnt;
    }
};
