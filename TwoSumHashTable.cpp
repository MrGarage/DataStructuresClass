// hash map solution
#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& arr, int target) {

    //create a new map
      map<int, int> map;
      vector<int> pairOfNum;

      //run it through a for loop
      for(int i = 0; i < arr.size(); i++) {
          int otherNum = target - arr[i];

          //if it is not sent to the end
          if(map.find(otherNum) != map.end()) {
              pairOfNum.push_back(map.find(otherNum)->second); //put the value at the end
              pairOfNum.push_back(i); //put the index after
              break;
          }//end if
        map.insert(pair<int, int>(arr[i], i));
      }//end for
      return pairOfNum;
};//end vector

int main() { 

  vector<int>arr = {2,11,4,7,15,10,6};
  vector<int>pairOfNums = twoSum(arr,9);

  cout << "The indices of the pairs are " << pairOfNums[0] << " and " << pairOfNums[1] << endl;
  return 0;
}//end main