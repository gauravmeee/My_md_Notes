#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n; cin>>n;
        int l; cin>>l;
        int r; cin>>r;
        int i=0;

        vector<int> arr(n,0);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        int cnt=0;
       for(int i=0; i<n; i++){
            if(arr[i]<l){
                int sum = arr[i];
                while(arr[i]<l){
                    if(sum>=l and sum<=r){
                        cnt++;
                        i++;
                        sum = sum+ arr[i];
                    }    
                i++; 
            }
            else if(arr[i]<=r){
                i++;
                cnt++;
            }
            else{
                i++;
                continue;
            }
        }
    }
}