class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int chef = customers[0][1]+customers[0][0];
        double sum=customers[0][1];
        for(int i=1; i<customers.size(); i++){
            chef = max(chef, customers[i][0]);
            chef+=customers[i][1];
            sum+= chef-customers[i][0];
            cout<<chef-customers[i][0]<<' ';
        }

        return sum/customers.size();
    }
};