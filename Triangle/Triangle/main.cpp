//
//  main.cpp
//  Triangle
//
//  Created by 李佳 on 15/11/4.
//  Copyright © 2015年 LiJia. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        if (triangle.empty())
            return 0;
        vector<int> rowSumResult(triangle.size(), 0);
        rowSumResult[0] = triangle[0][0];
        
        for (int i = 1; i < triangle.size(); ++i)
        {
            rowSumResult[i] = rowSumResult[i - 1] + triangle[i][i];
            for (int j = i - 1; j >= 1; --j)
            {
                rowSumResult[j] = std::min(rowSumResult[j - 1], rowSumResult[j]) + triangle[i][j];
            }
            rowSumResult[0] += triangle[i][0];
            
        }
        
        return *std::min_element(rowSumResult.begin(), rowSumResult.end());
    }
    
    
    //bottom to top  省去了最后获取最小值的步骤。
    /*
    
    int size=triangle.size();
    vector<int> result(triangle[size-1]);
    for(int i=size-2;i>=0;--i)
        for(int j=0;j<=i;++j)
            result[j]=triangle[i][j]+min(result[j],result[j+1]);
            return result[0];
    */
};


int main(int argc, const char * argv[])
{
    Solution sol;
    vector<vector<int>>triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    int result = sol.minimumTotal(triangle);
    printf("result = %d", result);
    return 0;
}
