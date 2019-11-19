//
// Created by neojxwang(王靖煊) on 2019-11-19.
//

#include <iostream>
#include <vector>

using std::vector;

int avg(int i, int j, vector<vector<int>> &M)//这里一定要加上&，不加重新复制了一遍M，慢了很多
{
    int sum = 0, count = 0;
    for (int x = -1; x <= 1; x++) {
        if (i + x >= 0 && i + x < M.size())//前一个条件针对于第一行，后一个条件针对于最后一行
        {
            for (int y = -1; y <= 1; y++) {
                if (j + y >= 0 && j + y < M[0].size())//前一个条件针对于第一列，后一个条件针对于最后一列
                {
                    sum += M[i + x][j + y];
                    count++;
                }
            }
        }
    }
    return (sum / count);
}

vector<vector<int>> imageSmoother(vector<vector<int>> &M) {
    int hang = M.size(), lie = M[0].size(), result;
    vector<int> res1(lie, 0);
    vector<vector<int>> res(hang, res1);//定义一个和M同样行数同样列数的矩阵res
    for (int i = 0; i < hang; i++) {
        for (int j = 0; j < lie; j++)
            res[i][j] = avg(i, j, M);//对res中的每个值进行处理
    }
    return res;
}

int dx8[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy8[] = {-1, 0, 1, -1, 1, -1, 0, 1};
vector<vector<int>> imageSmoother(vector<vector<int>> &v)
{
    int row = v.size(), col = v[0].size();
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j) {
            int sum = v[i][j], cnt = 1;
            for (int k = 0; k < 8; ++k) {
                int nx = i + dx8[k], ny = j + dy8[k];
                if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
                sum += (v[nx][ny] & 0xFF);
                ++cnt;
            }
            v[i][j] |= (sum / cnt) << 8;
        }
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            v[i][j] >>= 8;
    return v;
}

vector<vector<int>> imageSmoother(vector<vector<int>> &v)
{
    int row = v.size(), col = v[0].size();
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; ++j) {
            int sum = v[i][j], cnt = 1;
            for (int k = 0; k < 8; k++) {
                int nx = i + dx8[k], ny = j + dy8[k];
                if (nx < 0 || nx >= row || ny < 0 || ny >= col)
                    continue;
                sum += (v[nx][ny] & 0xFF);
                cnt++;
            }
            v[i][j] |= (sum / cnt) << 8;
        }

    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            v[i][j] >>= 8;

    return v;
}
