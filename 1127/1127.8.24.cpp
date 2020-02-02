#include <cstdio>
#include <vector>
using namespace std;
vector<int> in, post, level[35];
int n;
int maxDeep=-1;
void getLevel(int l,int r,int root,int deep) {
    if (deep>maxDeep)
    {
        maxDeep=deep;
    }
    if (l > r) return;
    int i = l;
    while (i<=r && post[root]!=in[i]) i++;
    level[deep].push_back(post[root]);
    getLevel(l, i - 1, root-1-(r-i),deep+1);
    getLevel(i + 1, r, root-1,deep+1);
}
int main() {
    scanf("%d",&n);
    int a;
    for (int i = 0; i < n; i++){
        scanf("%d",&a);
        in.push_back(a);
    }
    for (int i = 0; i < n; i++){
        scanf("%d",&a);
        post.push_back(a);
    }
    getLevel(0,n-1,n-1,0);

    printf("%d %d", level[0][0],maxDeep); 
    for (int i = 1; i < maxDeep ; i++) {
        if (i % 2 == 1) {
            for (int j = 0; j < level[i].size(); j++)
                printf(" %d", level[i][j]);
        } else {
            for (int j = level[i].size() - 1; j >= 0; j--)
                printf(" %d", level[i][j]);
        }
    }
    return 0;
}