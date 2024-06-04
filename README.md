# UAV-Path-Planning（无人机路径规划软件）

##  项目简介

​	无人机路径规划软件的设计与实现

​	这个题目针对无人机的路径规划问题，展开路径规划时考虑诸多物理约束条件下的设计方法研究，并在计算机上完成路径规划设计的仿真验证。

## 算法

​	本项目采用的A star算法，A star算法最早可追溯到1968年，在IEEE Transactions on Systems Science and Cybernetics中的论文A Formal Basis for the Heuristic Determination of Minimum Cost Paths中首次提出。A*算法是把启发式方法（heuristic approaches）如BFS（完全使用贪心策略），和常规方法如Dijsktra算法结合在一起的算法。有点不同的是，类似BFS的启发式方法经常给出一个近似解而不是保证最佳解。然而，尽管A star基于无法保证最佳解的启发式方法，A star却能保证找到一条最短路径。

##  目录结构说明

UVA-Path-Planning

`README.md` -- 自述文件

DAO

SERVICE

VIEW

## 开发工具

| 工具 | 说明         | 版本   | 备注                                        |
| :--- | ------------ | ------ | ------------------------------------------- |
| VS   | 开发工具     | 2022   | https://visualstudio.microsoft.com/zh-hans/ |
| Git  | 版本控制工具 | latest | https://git-scm.com/                        |
| Qt   | C++开发      | 6.7.3  | https://www.qt.io/zh-cn/                    |

