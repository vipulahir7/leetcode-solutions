class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fib;
        long long int a = 0, b = 1;
        while(1){
            int num = a + b;
            if(num > k) break;
            fib.push_back(num);
            a=b;
            b=num;
        }
        int ans = 0;
        for(int idx = fib.size() - 1; idx>=0; idx--){
            int num = fib[idx];
            if(k >= num){
                k-=num;
                ans++;
            }
        }
        ans += k;
        return ans;
    }
};