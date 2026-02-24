#include<vector>
#include<iostream>

using namespace std;
void segregate0and1(vector<int>& arr) {
    int count0 = 0;
    int count1 = 0;
for(int x:arr){
if(x==0){
    count0++;
}
else{
    count1++;
}

}
for(int i=0;i<count0;i++){
    arr[i]=0;
}
for(int i=count0;i<arr.size();i++){
    arr[i]=1;
}
return ;
}
int main() {
    vector<int> arr = {0, 1, 0, 1, 1, 0};
    segregate0and1(arr);
    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}