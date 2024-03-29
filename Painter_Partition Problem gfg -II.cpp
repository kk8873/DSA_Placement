
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;
class Solution{
public:

    bool isPossibleSolution(int arr[],int n, int k,long long mid){
     long long Sum = 0;
     int c = 1;
     for(int i = 0; i<n;i++){

    if(arr[i]>mid){
        return false;
        }

    if(arr[i]+ Sum > mid){
        c++;
        Sum = 0;
        Sum += arr[i];
        if(c>k){
            return false;
        }
    }
    else{
        Sum += arr[i];
    }
     }
      return true;
    }



    long long minTime(int arr[], int n,int k){
    long long start = 0;
    long long end   = 0;
    for(int i = 0;i<n; i++){
        end = end + arr[i];
    }

    long long ans  = -1;

    while(start<=end){
            long long mid = start + (end - start)/2;
            if(isPossibleSolution(arr,n,k,mid)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }


    }
    return ans;
 }


};

int main(){
int t;
cin>>t;
while(t--){
    int k,n;
    cin>>k>>n;
    int arr[n];

    for(int i = 0; i<n;i++){
        cin>>arr[i];
    }
     Solution obj;
    cout<<obj.minTime(arr,n,k)<<endl;

 }

return 0;
}
