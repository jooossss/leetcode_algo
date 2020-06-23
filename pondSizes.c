/**
应地点的海拔高度。若值为0则表示水域。由垂直、水平或对角连接的水域为池塘。
池塘的大小是指相连接的水域的个数。编写一个方法来计算矩阵中所有池塘的大小，
返回值需要从小到大排序。

示例：

输入：
[
  [0,2,1,0],
  [0,1,0,1],
  [1,1,0,1],
  [0,1,0,1]
]
输出： [1,2,4]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pond-sizes-lcci
 */

 int cmp(const void *a,const void *b){     //比较函数，用于qsort
        return (*(int *)a - *(int *)b);
}

 int DFS(int** land,int curi,int curj,int landSize,int landColSize){
    if(curi < 0 || curj < 0 || curi >= landSize || curj >= landColSize || land[curi][curj]!=0)
        return 0;
    int di[8] = {0,0,-1,-1,-1,1,1,1};
    int dj[8] = {1,-1,0,1,-1,-1,0,1};
    int i,L = 1;
    land[curi][curj] = 1;
    for(i = 0;i < 8;i++){
        int nexti = curi + di[i];
        int nextj = curj + dj[i];
        L += DFS(land,nexti,nextj,landSize,landColSize);
    }
    return L;
}

int* pondSizes(int** land, int landSize, int* landColSize, int* returnSize){
    int i,j,L,retS = 0;
    int* ret = malloc(sizeof(int) * 100000);
    for(i = 0 ;i < landSize;i++){
        for(j = 0;j < landColSize[0]; j++){
            L = DFS(land,i,j,landSize,landColSize[0]);
            if(L > 0)
                ret[retS++] = L;
        }
    }
    *returnSize = retS;
    qsort(ret,retS, sizeof(int), cmp);
    return ret;
}