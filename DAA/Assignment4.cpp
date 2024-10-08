#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;

int recursiveKnapsack(int n, int capacity, vector<int>& weights, vector<int>& values){
    if(n==0)return 0;
    int take = 0, leave;
    if(capacity>=weights[n-1])take = values[n-1] + recursiveKnapsack(n-1, capacity-weights[n-1], weights, values);
    leave = recursiveKnapsack(n-1, capacity, weights, values);
    return max(take, leave);
}

int tabulationKnapsack(int n, int capacity, vector<int>& weights, vector<int>& values, vector<vector<int>>&dp){
    if(n==0)return 0;
    if(dp[n][capacity] != -1)return dp[n][capacity];
    int take = 0, leave;
    if(capacity>=weights[n-1])take = values[n-1] + tabulationKnapsack(n-1, capacity-weights[n-1], weights, values, dp);
    leave = tabulationKnapsack(n-1, capacity, weights, values, dp);
    return dp[n][capacity] = max(take, leave);
}

int memoisedKnapsack(int n, int capacity, vector<int>& weights, vector<int>& values){
    vector<int>prev(capacity+1, 0);
    vector<int>current(capacity+1);
    for(int i=1; i<=n; i++){
        for(int j=0; j<capacity+1; j++){
            int take = 0, leave;
            if(j>=weights[i-1])take = values[i-1] + prev[j-weights[i-1]];
            leave = prev[j];
            current[j] = max(take, leave);
        }
        prev = current;
    }
    return *max_element(current.begin(), current.end());
}

int main(){
    vector<int>values = {1, 2, 3};
    vector<int>weights = {4, 5, 1};
    int n = weights.size();
    int capacity = 4;
    cout<<"Recursive: "<<recursiveKnapsack(n, capacity, weights, values)<<endl;

    vector<vector<int>>dp(n+1, vector<int>(capacity+1, -1));
    cout<<"Tabulation: "<<tabulationKnapsack(n, capacity, weights, values, dp)<<endl;

    cout<<"Memoised: "<<memoisedKnapsack(n, capacity, weights, values)<<endl;
}