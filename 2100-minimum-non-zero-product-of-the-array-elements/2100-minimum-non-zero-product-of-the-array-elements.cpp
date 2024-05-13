class Solution {
public:

    long long int mod=1000000007;

    long long int power(long long int a,long long int b){

        if(b==0){
            return 1;
        }
        if(b==1){
            return a%mod;
        }
        long long int ans=power(a,b/2);
        ans%=mod;
        
        if(b&1){
            ans=ans*ans%mod;
            a%=mod;
            return (a*ans)%mod;
        }
        else{
            return (ans*ans)%mod;
        }
    }

    int minNonZeroProduct(int p) {

        long long int range=(1LL<<p)-1;

        long long int temp=power(range-1,range/2)%mod;
        return (temp*(range%mod))%mod;
    }
};