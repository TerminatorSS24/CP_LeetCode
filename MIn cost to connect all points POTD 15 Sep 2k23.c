/*You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

 

Example 1:

image: https://assets.leetcode.com/uploads/2020/08/26/d.png

Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation: 
image: https://assets.leetcode.com/uploads/2020/08/26/c.png
We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.
Example 2:

Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18
**********LEETCODE POTD(15/09/2023)**********
*/
int mod(int x){
  if(x<0) return -1*x;
  return x;
}

int manhattandistance(int** points, int i, int j, int* pointsColSize){
  int* p1 = *(points + i);
  int* p2 = *(points + j);
  int distance = 0;
  for(int k = 0; k<(*pointsColSize); k++){
    distance = distance + mod(*(p1 + k) - *(p2 + k));
  }
  return distance;
}

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize){
    int distance = 0; 
    int mindist; 
    int dist;
    int S[pointsSize];
    int top = 0;
    int present[pointsSize];
    int v2;
    int edges[pointsSize];
    for(int j = 0; j<pointsSize; j++){
        edges[j] = 2147483646;
        present[j] = 0;
    }
    edges[0] = 1;

    S[top] = 0;
    top++;
    present[0] = 1;
    while(top!=pointsSize){
        for(int j= 1; j<pointsSize; j++){
            if(present[j] == 1) continue;

            dist = manhattandistance(points, S[top-1],j, pointsColSize);

            if(edges[j]>dist){
                edges[j] = dist;
            }
        }

        mindist = 2147483647;
        for(int i = 0; i<pointsSize; i++){
            if(present[i] == 1) continue;
            if(edges[i] < mindist){
                mindist = edges[i];
                v2 = i;
            }
        }
        S[top] = v2;
        top++;
        present[v2] = 1;
        distance = distance+mindist;
    }
    
    return distance;
}