// https://www.codingninjas.com/codestudio/problems/rearrange-alternatively_873851?leftPanelTab=1

void rearrange(vector<int> &arr)
{
    int n=arr.size();
	int ptr_pos = 0, ptr_neg=0;
    for(int i=0;i<n;i++){
        if(i&1){
            if(arr[i]>0) continue;
            ptr_pos = max(ptr_pos,i);
            while(ptr_pos<n and arr[ptr_pos]<0) ptr_pos++;
            if(ptr_pos==n) break;
            swap(arr[i], arr[ptr_pos]);
        }
        else{
            if(arr[i]<0) continue;
            ptr_neg = max(ptr_neg,i);
            while(ptr_neg<n and arr[ptr_neg]>0) ptr_neg++;
            if(ptr_neg==n) break;
            swap(arr[i], arr[ptr_neg]);
        }
    }
}
