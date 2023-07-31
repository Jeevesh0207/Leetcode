//https://www.codingninjas.com/studio/problems/merge-sort_920442

void Merge(vector<int> &arr, int L, int M, int R, int ans[]) {
  int i = L;
  int j = M+1 ;
  int k = L;
  while (i <= M && j <= R) {
    if (arr[i] <= arr[j]) {
      ans[k++] = arr[i];
      i++;
    } else {
      ans[k++] = arr[j];
      j++;
    }
  }
  for(;i<=M;i++) ans[k++]=arr[i];
  for(;j<=R;j++) ans[k++]=arr[j];
  for (int i = L; i <=R; i++) {
    arr[i] = ans[i];
  }
}

void Split(vector<int> &arr, int L, int R, int ans[]) {
    if(L>=R) return;
    int M = (L+R) / 2;
    Split(arr, L, M, ans);
    Split(arr, M+1, R, ans);
    Merge(arr, L, M, R, ans);
}

void mergeSort(vector<int> &arr, int n) {
  int ans[n]={0};
  Split(arr, 0, n - 1, ans);
  
}
