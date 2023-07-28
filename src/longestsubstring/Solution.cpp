#include<string>
#include<iostream>
#include<map>
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) 
    {
        std::map<char,int> mwin;
        int maxlength = 0;
        int left =0,right =0;
        while(right<s.length()){
            if(mwin.find(s[right])==mwin.end()){  //没有加入的一直有加
                maxlength=right-left;
                mwin[s[right++]]=1;
                continue;
            }
            while(left<right&&s[left]!=s[right]){   //终止为left==right或s[left]==s[right]
                mwin.erase(s[left]);
                left++;
            }
            left++;
            right++;
        }
        return maxlength+1;
    }
};

class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        unordered_set<char> lookup;
        int maxStr = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++){
            while (lookup.find(s[i]) != lookup.end()){   //有的话，左边开整
                lookup.erase(s[left]);
                left ++;
            }
            maxStr = max(maxStr,i-left+1);
            lookup.insert(s[i]);
    }
        return maxStr;
        
    }
};

int main(){
    std::string input = "pwwkew";
    Solution s;
    auto res = s.lengthOfLongestSubstring(input);
    std::cout<<res;
    return 0;
}