#include <iostream> 
#include <vector>
using namespace std;

int* TwoSum(int nums[], int target, int length) {

    int* ans = new int[2];
    int* broken;
    *broken = -1;
    for(int i = 0; i < length; i++) {

        for(int j = i + 1; j < length; j++) {

            if(nums[j] == target - nums[i]){
                //return { i, j };
                ans[0] = i;
                ans[1] = j;

                return ans;             
            }

        }//end for j
    }//end for i

    return broken;
};//end int TwoSum

int main()
{
    int target;
    int nums[] = {2,7,11,15};
    cout << "Target: " ;
    cin >> target;
    
    int* result = TwoSum(nums, target, sizeof(nums));
    cout <<"[" << result[0] << " , " << result[1] << "]" << endl;
}