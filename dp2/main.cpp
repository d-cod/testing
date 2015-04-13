//
//  main.cpp
//  dp2
//
//  Created by Shiva Mahajan on 02/10/14.
//  Copyright (c) 2014 Shiva Mahajan. All rights reserved.
//http://www.spoj.com/problems/TRIKA/

#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<algorithm>
#include<map>
#include<string>
#include<sstream>
#include<numeric>
#include<stack>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
    long long int mat[50][50] = {{0}} , dp[50][50] = {{0}};
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    x--;y--;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin>>mat[i][j];
        }
    }
    long long int ans = mat[x][y];
    mat[x][y] =  0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0 ; j < m; j++)
            dp[i][j] = 10000000000;
    }
    for(int i = x; i < n; i++)
    {
        for(int j = y ; j < m; j++)
            dp[i][j] = 0000000000;
    }
    
    for(int i = x; i < n; i++)
    {
        for(int j = y; j < m; j++)
        {
            long long mn1 , mn2;
            if(i -1 < x)
                mn1 = 100000000;
            else
                mn1 = dp[i-1][j];
            if(j-1 < y)
                mn2 = 100000000;
            else
                mn2 = dp[i][j-1];
            if(i==x && j== y)
            {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = min(mn1,mn2) + mat[i][j];
        }
    }
    //cout<<ans<<" , "<<dp[n-1][m-1]<<endl;
    ans -= dp[n-1][m-1];
    if(ans >= 0)
    {
        cout<<"Y "<<ans<<endl;
    }
    else
        cout<<"N\n";
    return 0;
}
