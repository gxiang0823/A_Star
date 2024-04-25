#include "A_Star.h"

// 构造函数
A_Star::A_Star(int map[ROW][COL], pair<int, int> start, pair<int, int> end)
{
    // 初始化地图
    for (int i = 0; i < ROW; ++i)
    {
        for (int j = 0; j < COL; ++j)
        {
            this->grid[i][j] = map[i][j];
        }
    }
    // 初始化起点和终点
    this->start_node = new Node(start.first, start.second, 0, 0, nullptr);
    this->end_node = new Node(end.first, end.second, 0, 0, nullptr);
    vector<vector<bool>> Temp(ROW, vector<bool>(COL, false));
    this->Closed_List = Temp;
}

// 初始化
void A_Star::LegalStart()
{
    if (start_node->x < 0 || start_node->y < 0 ||
        start_node->x >= ROW || start_node->y >= COL ||
        grid[start_node->x][start_node->y])
    {
        cout << "起点不合法！" << endl;
        exit(0);
    }
}
void A_Star::LegalEnd()
{
    if (end_node->x < 0 || end_node->y < 0 ||
        end_node->x >= ROW || end_node->y >= COL ||
        grid[end_node->x][end_node->y])
    {
        cout << "终点不合法！" << endl;
        exit(0);
    }
}

// 回溯路径
vector<pair<int, int>> A_Star::Backtrack(Node *current)
{
    vector<pair<int, int>> Path;
    while (current != nullptr)
    {
        Path.push_back({current->x, current->y});
        current = current->parent_node;
    }
    // 释放内存
    delete start_node;
    delete end_node;
    return Path;
}

// 寻找当前节点的子结点
vector<A_Star::Node *> A_Star::GetNeighbor(Node *current)
{
    vector<Node *> neighbor;
    // 上下左右四个方向
    int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
    for (int i = 0; i < 8; ++i)
    {
        int neighbor_node_x = current->x + dx[i];
        int neighbor_node_y = current->y + dy[i];

        // 确保新节点在网格内且不是障碍物
        if (neighbor_node_x >= 0 && neighbor_node_x < ROW &&
            neighbor_node_y >= 0 && neighbor_node_y < COL &&
            grid[neighbor_node_x][neighbor_node_y] == 0)
        {
            double neighbor_node_g = current->g + (i < 4 ? 1.0 : 1.414); // 斜向移动的代价为直线移动的 sqrt(2) 倍
            double neighbor_node_h = sqrt(neighbor_node_x - end_node->x) + sqrt(neighbor_node_y - end_node->y);
            Node *neighbor_node = new Node(neighbor_node_x, neighbor_node_y, neighbor_node_g, neighbor_node_h, current);
            // 如果邻居节点已经在Closed_List中，跳过
            if (Closed_List[neighbor_node_x][neighbor_node_y])
            {
                delete neighbor_node;
                continue;
            }
            neighbor.push_back(neighbor_node);
        }
    }
    return neighbor;
}

// 更新Open_List
void A_Star::UpdateOpenList(vector<Node *> neighbor)
{
    for (int i = 0; i < neighbor.size(); ++i)
    {
        Node *neighbor_node = neighbor[i];
        // 如果邻居节点不在开放列表中，将其加入
        bool inOpen_List = false;
        // 检查是否在开放列表中
        priority_queue<Node *, vector<Node *>, CompareF> tempQueue = Open_List;
        while (!tempQueue.empty())
        {
            Node *node = tempQueue.top();
            tempQueue.pop();
            if (node->x == neighbor_node->x &&
                node->y == neighbor_node->y)
            {
                inOpen_List = true;
                if (neighbor_node->g < node->g)
                {
                    node->g = neighbor_node->g;
                    node->parent_node = neighbor_node->parent_node;
                }
                delete neighbor_node;
            }
        }
        if (!inOpen_List)
        {
            Open_List.push(neighbor_node);
        }
    }
}

// 搜索路径
vector<pair<int, int>> A_Star::SearchPath()
{
    while (!Open_List.empty())
    {
        // 从Open_List中取出 f 值最小的节点
        Node *current = Open_List.top();
        Open_List.pop();
        // 判断是否到达目标节点
        if (current->x == end_node->x && current->y == end_node->y)
        {
            // 回溯路径
            vector<pair<int, int>> Path = A_Star::Backtrack(current);
            return Path;
        }
        // 将当前节点标记为已访问
        Closed_List[current->x][current->y] = true;
        // 寻找当前节点的子结点
        vector<Node *> neighbor = A_Star::GetNeighbor(current);
        // 更新Open_List
        A_Star::UpdateOpenList(neighbor);
    }
    // 如果开放列表为空，说明没有找到路径
    delete start_node;
    delete end_node;
    cout << "路径未找到！" << endl;
    exit(0);
}

// 输出路径
void A_Star::OutputPath()
{
    if (Path_list.empty())
    {
        cout << "No path found!" << endl;
    }
    else
    {
        cout << "Path found:" << endl;
        for (auto p : Path_list)
        {
            cout << "[" << p.first << ", " << p.second << "] ";
        }
        cout << endl;
    }
}

// 绘图
void A_Star::PlotPath()
{
    // 创建图形
    plt::figure();

    // 绘制网格线
    for (int i = 0; i <= ROW; ++i)
    {
        for (int j = 0; j <= COL; ++j)
        {
            plt::plot({0, COL}, {i, i}, "k-"); // 水平线
            plt::plot({j, j}, {0, ROW}, "k-"); // 垂直线
        }
    }
    // // 设置网格线
    // plt::grid(true);

    // 显示图形
    plt::show();
}

// 主函数
void A_Star::Excute()
{
    // 初始化
    A_Star::LegalStart();
    A_Star::LegalEnd();

    // 将出发点加入Open_List
    Open_List.push(start_node);

    // 搜索路径
    vector<pair<int, int>> Path = A_Star::SearchPath();

    // 输出路径
    Path_list = Path;
    A_Star::OutputPath();

    // 绘图
}