#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include "matplotlibcpp.h"
using namespace std;
namespace plt = matplotlibcpp;

#define ROW 5
#define COL 5

class A_Star
{
public:
    // 定义节点类
    struct Node
    {
        // 节点的行列坐标
        int x, y;
        // g：从起点到当前节点的代价，h：到终点的估计代价
        double g, h;
        // 父节点指针，用于回溯路径
        Node *parent_node;
        // 节点的构造函数
        Node(int r, int c, int g_val, int h_val, Node *p) : x(r), y(c), g(g_val), h(h_val), parent_node(p) {}

        // 计算节点的总代价 f = g + h
        int getF() const
        {
            return g + h;
        }
    };

    // 根据F定义优先队列
    struct CompareF
    {
        bool operator()(const Node *lhs, const Node *rhs) const
        {
            return lhs->getF() > rhs->getF();
        }
    };

private:
    // 地图
    int grid[ROW][COL];
    // 起点
    Node *start_node;
    // 终点 
    Node *end_node;
    vector<vector<bool>> Closed_List;
    priority_queue<Node *, vector<Node *>, CompareF> Open_List;
    vector<pair<int, int>> Path_list;

public:
    // 构造函数
    A_Star(int map[ROW][COL], pair<int, int> start, pair<int, int> end);

    // 主函数
    void Excute();

    // 初始化
    void LegalStart();
    void LegalEnd();

    // 搜索路径
    vector<pair<int, int>> SearchPath();

    // 回溯路径
    vector<pair<int, int>> Backtrack(Node *current);

    // 寻找当前节点的子结点
    vector<A_Star::Node *> GetNeighbor(Node *current);

    // 更新Open_List
    void UpdateOpenList(vector<A_Star::Node *> neighbor);

    // 输出路径
    void OutputPath();
};