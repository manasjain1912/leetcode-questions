class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        map<string, int> serial;
        int nm = 0, n = people.size();
        for(string skill: req_skills)
            serial[skill] = nm++;
        int target = (1<<nm)-1;
        vector<int> ppl;
        for(vector<string> skills: people)
        {
            int skillToMask = 0;
            for(string skill: skills)
                skillToMask += (1<<serial[skill]);
            ppl.push_back(skillToMask);
        }

        vector<int> minForTarget(target+1, INT_MAX);
        vector<int> idxForTarget(target+1, -1);
        minForTarget[0] = 0;
        for(int idx = 0; idx < n; ++idx)
        {
            for(int curOr = target; curOr >= 0; --curOr)
            {
                if(minForTarget[curOr] != INT_MAX or curOr == 0)
                {
                    if(minForTarget[curOr|ppl[idx]] > minForTarget[curOr]+1)
                    {
                        minForTarget[curOr|ppl[idx]] = minForTarget[curOr]+1;
                        idxForTarget[curOr|ppl[idx]] = idx;
                    }
                }
            }
        }
        vector<int> answer;
        int curOr = target, idx = 0, prev = target, count = minForTarget[target];
        while(count and curOr >= 0)
        {
            if(count == minForTarget[curOr] and (curOr|ppl[idx]) == prev)
            {
                answer.push_back(idxForTarget[curOr]);
                --count;
                prev = curOr;
                idx = idxForTarget[curOr];
            }
            --curOr;
        }
        return answer;
    }
};