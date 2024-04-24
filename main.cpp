#include "A_Star.h"

int main(int argv, char **argc)
{
    // 定义地图 ROW和COL定义在A_Star.h中,要保持和矩阵维度一致
    int grid[ROW][COL] = {
        {0, 0, 0, 0, 0},
        {1, 1, 1, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 1, 1, 1, 1},
        {0, 0, 0, 0, 0}};

    // 定义起点和目标点
    pair<int, int> start = {0, 0};
    pair<int, int> end = {4, 4};

    // 创建 AStar 对象并运行算法
    A_Star astar(grid, start, end);
    astar.Excute();

    // // 创建图形
    // plt::figure();

    // // 绘制网格线
    // for (int i = 0; i <= ROW; ++i)
    // {
    //     for (int j = 0; j <= COL; ++j)
    //     {
    //         plt::plot({0, COL}, {i, i}, "k-"); // 水平线
    //         plt::plot({j, j}, {0, ROW}, "k-"); // 垂直线
    //     }
    // }

    // vector<int> x, y;
    // for (const auto &point : path)
    // {
    //     x.push_back((point.first + 0.5));
    //     y.push_back((point.second + 0.5));
    // }
    // plt::plot(x, y);

    // // 设置网格线
    // plt::grid(true);

    // // 显示图形
    // plt::show();

    return 0;
}