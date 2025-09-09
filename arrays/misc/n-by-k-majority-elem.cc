class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int slot1 = -1, slot2 = -1;
        int count1 = 0, count2 = 0;
        for(auto &num : nums){
            // printf("%d %d %d %d\n", slot1, slot2, count1, count2);
            if(count1 == 0 && slot2 != num) slot1 = num;
            else if (count2 == 0) slot2 = num;
            if(num == slot1){
                count1++;
            }
            else if (num == slot2){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1 = 0; count2 = 0;
        for(auto &num: nums){
            if(num == slot1) count1++;
            if(num == slot2) count2++;
        }
        vector<int> res;
        int majority = nums.size() / 3;
        if(count1 > majority) res.push_back(slot1);
        if(count2 > majority && slot1 != slot2) res.push_back(slot2);
        return res;
    }
};