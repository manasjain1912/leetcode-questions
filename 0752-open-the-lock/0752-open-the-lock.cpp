class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        queue<string>q;
        unordered_set<string>visited;
        int levels=0;
        
        
        for(int i=0;i<deadends.size();i++)
            visited.insert(deadends[i]);
        
        
        q.push("0000");
        
        while(!q.empty())
        {
            int t= q.size();
           
            
            while(t--)
            {
                string st = q.front();
                q.pop();
                
                if(visited.find(st)!=visited.end())
                    continue;
                
                visited.insert(st);
                
                if(st==target)
                    return levels;
                
                
                for(int i=0;i<4;i++)
                {
                    string s1=st,s2=st;
                    
                    if(st[i]=='9') s1[i] = '0';
                    else s1[i] = st[i]+1;

                    if(st[i]=='0')s2[i]='9';
                    else s2[i]= st[i]-1;
                
                    if(visited.find(s1)==visited.end())
                        q.push(s1);

                    if(visited.find(s2)==visited.end())
                        q.push(s2);
                }
            }
           levels++;
        }
        return -1;
    }
};