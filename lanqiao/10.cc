// #include <map>
// std::map<char,int> mp = {{'F',0},{'L',1},{'R',2}};

struct status
{
    int x,y;
    int ward;
};

int ans = -1;
int steps;
void dfs(int step,int x,int y)
{
    if(step == steps)
    {
        ans++;
        return;
    }

}