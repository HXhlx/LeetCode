#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int dxy[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}}, curColor = image[sr][sc], r = image.size(), c = image[0].size();
        if (curColor == newColor)
            return image;
        queue<pair<int, int>> points;
        points.emplace(sr, sc);
        image[sr][sc] = newColor;
        while (!points.empty())
        {
            for (auto point : dxy)
            {
                int x = points.front().first + point[0], y = points.front().second + point[1];
                if (x >= 0 && x < r && y >= 0 && y < c && image[x][y] == curColor)
                {
                    points.emplace(x, y);
                    image[x][y] = newColor;
                }
            }
            points.pop();
        }
        return image;
    }
};