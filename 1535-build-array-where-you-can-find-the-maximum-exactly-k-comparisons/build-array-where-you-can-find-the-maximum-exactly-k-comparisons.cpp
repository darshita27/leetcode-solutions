class Solution {
public:
int N,M,K;
int mod= 1e9 +7;
int t[51][51][101];
int solve(int idx, int searchCost, int maxsoFar){
    if(idx==N){
        if(searchCost==K){
            return 1;
        }
        return 0;
    }
    if(t[idx][searchCost][maxsoFar] !=-1){
        return t[idx][searchCost][maxsoFar];
    }
    int result=0;
    for(int i=1;i<=M;i++){
        if(i>maxsoFar){
            result= (result+ solve(idx+1, searchCost +1, i)) % mod;
        }else{
            result= (result+ solve(idx+1, searchCost, maxsoFar))% mod;
        }
    }
    return t[idx][searchCost][maxsoFar]=result % mod;
}
    int numOfArrays(int n, int m, int k) {
        N=n;
        M=m;
        K=k;
        memset(t, -1, sizeof(t));
        return solve(0,0,0);
    }
};