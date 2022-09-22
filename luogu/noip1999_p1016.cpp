//
// Created by 曹钦平 on 2022/7/8.
//

#include<iostream>
using namespace std;

float get_min_price(float d_per_c, float c, float d_all, int n, float* darr, float* parr){
    float dmax = d_per_c * c;
    int curr_station = 0;
    float ans = 0;
    while (curr_station < n + 1) {
        int next_station = curr_station;
        float d_curr = darr[curr_station];
        float p_curr = parr[curr_station];
        float min_p = 502.;
        while (++curr_station < n + 2) {
            if ((darr[curr_station] - d_curr) < dmax) {
                if (parr[curr_station] < min_p) {
                    next_station = curr_station;
                    min_p = parr[curr_station];
                }
            }
        }
        if (min_p == 502.) {
            if(d_all - d_curr < dmax)
                return -1.;
        }
        else {
            ans += (darr[next_station] - d_curr) / d_per_c * p_curr;
        }
        curr_station = next_station;
    }
    return (int)(ans * 100 + 0.5) / 100.;
}


int main(){
    float c = 11.9;
    float d_per_c = 27.4;
    int n = 2;
    float darr[] = {0, 102, 220, 275.6};
    float parr[] = {2.8, 2.9, 2.2, 501.};
    float d_all = 275.6;
    float ans = get_min_price(d_per_c, c, d_all, n, darr, parr);
    if (ans == -1){
        cout << "No solution" << endl;
    }
    else{
        cout << ans << endl;
    }
    return 0;
}