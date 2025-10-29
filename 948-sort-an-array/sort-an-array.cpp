class Solution {
public:
    void merge(vector<int>&arr,int left,int mid,int right){
        vector<int>L(arr.begin() + left,arr.begin()+ mid + 1);
        vector<int>R(arr.begin() + mid + 1,arr.begin() + right + 1);
        int i=0,j=0,k=left;
        while(i <L.size() && j < R.size()){
            if(L[i] <= R[j]){
                arr[k++] = L[i++];
            }
            else{
                arr[k++] = R[j++];
            }
        }
        while(i < L.size()) arr[k++] = L[i++];
        while(j < R.size()) arr[k++] = R[j++];
    }
    void mergeSort(vector<int>&arr,int left,int right){
        if(left >= right) return;
        int mid = left + (right-left) / 2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
    vector<int> sortArray(vector<int>& arr) {
        int n = arr.size();
        mergeSort(arr,0,n-1);
        return arr;
    }
};