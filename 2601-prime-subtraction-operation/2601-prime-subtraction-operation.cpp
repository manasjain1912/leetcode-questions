class Solution {
public:
    vector<int> SOE(int n) 
    {
    vector<bool> prime(n + 1, true);
    int p = 2;
    while (p * p <= n) 
    {
        if (prime[p]) 
        {
            for (int i = p * p; i <= n; i += p) 
            {
                prime[i] = false;
            }
        }
        p++;
    }

    vector<int> primes;
    for (int p = 2; p <= n; p++) 
    {
        if (prime[p]) {
            primes.push_back(p);
        }
    }

    return primes;
}

    bool primeSubOperation(vector<int>& nums)
    {
        if(nums.size()==1)
        {
            return true;
        }
        int temp=1;
        for (int i = 1; i < nums.size(); i++) 
    {
        if (nums[i - 1]>=nums[i]) 
        {
            temp=0;
        }
    }
        if(temp==1)
        {
            return true;
        }
    vector<int> prime=SOE(*max_element(nums.begin(), nums.end()));
    for (int i=0;i<nums.size();i++) 
    {
        if (i==0) 
        {
            int pr = lower_bound(prime.begin(),prime.end(), nums[i]) - prime.begin();
            pr-=1;
            if (pr == -1) 
            {
                continue;
            }
            nums[i]-= prime[pr];
        } else 
        {
            int pr =lower_bound(prime.begin(),prime.end(),nums[i] - nums[i - 1]) - prime.begin();
            pr--;
            if (pr == -1 || pr==prime.size()) {
                continue;
            }
            nums[i] -= prime[pr];
        }
    }

    for (int i = 1; i < nums.size(); i++) 
    {
        if (nums[i - 1]>=nums[i]) 
        {
            return false;
        }
    }

    return true;

    }
};
