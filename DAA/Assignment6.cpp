#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <chrono>
using namespace std;

void swap(vector<int>&v, int a, int b){
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}

int partition(vector<int>&v, int l, int r, bool random = false){
    if(random){
        int random = l + rand() % (r - l);
        swap(v, random, r);
    }
    int pivot = v[r];
    int i = l-1;
    for(int j=l; j<r; j++){
        if(v[j] < pivot){
            i++;
            swap(v, i, j);
        }
    }
    swap(v, i+1, r);
    return i+1;
}

void quickSort(vector<int>&v, int l, int r, bool random = false){
    if(l<r){
        int pi = partition(v, l, r, random);

        quickSort(v, l, pi-1, random);
        quickSort(v, pi+1, r, random);
    }
}

int main(){
    vector<int>v = {7,1,4,2, 3, 2, 2, 5, 1};
    cout<<"Original  :"; for(auto &&i : v)cout<<i<<", "; cout<<endl;
    quickSort(v, 0, v.size()-1);
    cout<<"Partition :"; for(auto &&i : v)cout<<i<<", "; cout<<endl;
    v = {7,1,4,2, 3, 2, 2, 5, 1};
    quickSort(v, 0, v.size()-1, true);
    cout<<"Random    :"; for(auto &&i : v)cout<<i<<", "; cout<<endl;

    //TIME ANALYSIS

    vector<int>vv; for (int i = 0; i < 1000000; ++i)vv.push_back(rand()%100);
    v = vv;
    auto start = chrono::high_resolution_clock::now();
    quickSort(v, 0, v.size()-1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout<<"Last Elem : "<<"Ran in "<<diff.count()<<" seconds"<<endl;

    v = vv;
    start = chrono::high_resolution_clock::now();
    quickSort(v, 0, v.size()-1, true);
    end = chrono::high_resolution_clock::now();
    diff = end - start;
    cout<<"Random    : "<<"Ran in "<<diff.count()<<" seconds"<<endl;
}