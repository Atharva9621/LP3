#include<iostream>
#include<vector>
using namespace std;

vector<int> fibonacci_nos(int n){
    vector<int>res;
    int fib1 = 0, fib2 = 1;
    while(n>0){
        res.push_back(fib1);
        int temp = fib1 + fib2;
        fib1 = fib2;
        fib2 = temp;
        n--;
    }
    return res;
}

int fibonacci_nos_recursive(vector<int>& dp, int n){
    if(n==1)return 0;
    if(n==2)return 1;
    if(dp[n])return dp[n];
    return dp[n] = (fibonacci_nos_recursive(dp, n-1)+fibonacci_nos_recursive(dp, n-2));
}

int main(){
    vector<int>v = fibonacci_nos(8);
    cout<<"Tabulation Approach"<<endl;
    for (auto &&i : v)cout<<i<<' '; cout<<endl;

    vector<int>dp(9, 0);
    cout<<"Recursive Approach"<<endl;
    fibonacci_nos_recursive(dp, 8);
    for (auto &&i : dp)cout<<i<<' '; cout<<endl;
}