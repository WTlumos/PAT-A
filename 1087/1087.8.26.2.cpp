#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
struct node{
    int next,cost;
};
vector<int> happy;
vector<string> indextoname;
map<string,int> indexMap;
vector<node> v[210];
vector<int> disc;
vector<bool> mark;
vector<int> root[210];
vector<int> tempath,path;
int maxvalue = 0,cntpath;
double maxavg;
void dfs(int node)
{
    tempath.push_back(node);
    if( node == 0){
        int value = 0;
        for(int i=0;i<tempath.size();i++)
        {
            value += happy[tempath[i]];
        }
        double tempavg = 1.0 * value / ((int)tempath.size() - 1);
        if(value > maxvalue)
        {
            maxvalue = value;
            maxavg = tempavg;
            path = tempath;
        }else if(value == maxvalue && tempavg > maxavg) {
            maxavg = tempavg;
            path = tempath;
        }
        tempath.pop_back();
        cntpath++;
        return;
    }
        for(int i = 0; i < root[node].size(); i++) {
            dfs(root[node][i]);
        }
        tempath.pop_back();
    
}
int main()
{
    int n,k,a;
    string start,s,t;
    cin >> n >> k;
    disc.resize(n,-1);
    mark.resize(n,false);
    happy.resize(n,0);
    indextoname.resize(n);
    cin >> start;
    indexMap[start] = 0;
    indextoname[0] = start;
    for(int i = 1; i < n;i++)
    {
        cin >> s;
        cin >> a;
        happy[i] = a;
        indexMap[s] = i;
        indextoname[i] = s;
    }
    for(int i=0;i<k;i++)
    {
        cin >> s >> t;
        cin >> a;
        v[indexMap[s]].push_back(node{indexMap[t],a});
        v[indexMap[t]].push_back(node{indexMap[s],a});
    }
    int newP = 0;
    disc[newP] = 0;
    mark[newP] = true;
    for(int i=0;i<n;i++)
    {
        for(int j = 0;j< v[newP].size();j++)
        {
            int t = v[newP][j].next;
            int cost = v[newP][j].cost;
            if(mark[t]==true)
                continue;
            if(disc[t] == -1 || disc[t]>disc[newP] + cost)
            {
                disc[t] = disc[newP] + cost;
                root[t].push_back(newP);
            }else if(disc[t] == disc[newP] + cost){
                root[t].push_back(newP);
            }
        }
        int min = 123123123;
        for(int j=0;j<n;j++)
        {
            if(mark[j] == true)
                continue;
            if(disc[j] == -1)
                continue;
            if(disc[j]<min)
            {
                min = disc[j];
                newP = j;
            }
        }
        mark[newP] = true;
    }
    dfs(indexMap["ROM"]);
    cout << cntpath << " "<< disc[indexMap["ROM"]] << " " << maxvalue << " " << (int)maxavg << endl;
    for(int i=(int)path.size()-1;i>0;i--)
    {
        cout << indextoname[path[i]] << "->";
    }
    cout<<"ROM" <<endl;
    return 0;
}