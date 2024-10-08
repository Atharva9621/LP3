#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;

float fractionalKnapsack(int capacity, vector<int>weights, vector<int>value){
    vector<tuple<float, int, int>>weighted_values;
    for(int i=0; i<weights.size(); i++)weighted_values.push_back(make_tuple((float)value[i]/weights[i], weights[i], value[i]));
    sort(weighted_values.begin(), weighted_values.end(), [](const auto& a, const auto& b){
        return get<0>(a) > get<0>(b);
    });
    float res = 0;

    for (auto &&i : weighted_values){
        int weight, value; float ratio;
        std::tie(ratio, weight, value) = i;
        if(capacity==0)break;
        if(capacity >= weight){
            res += value;
            capacity -= weight;
        }
        else{
            res += value*((float)capacity/weight);
            capacity = 0;
        }
    }
    return res;
}

int main(){
    vector<int> weights = {10, 20, 30};
    vector<int> values = {60, 100, 120};
    int capacity = 50;
    cout<<fractionalKnapsack(capacity, weights, values);
    return 0;
}