#include<vector>
#include<string>
#include<iostream>
#include<map>

class Solution {
public:
    //滑动窗口窗口大小固定；
    //每次右移，加一个右边，去一个左边，看条件是否符合
    std::vector<int> findAnagrams(std::string s, std::string p)
    {
        std::vector<int> res;
        if(s.length()<p.length())return res;

        std::map<char,int> pmap;
        std::map<char,int> smap;
        for(auto c:p)
        {
            pmap[c]++;
        }
        for(int i =0;i<p.size();i++)
        {
            smap[s[i]]++;
        }
        int right =p.size()-1;
        while(right<s.size())
        {
            bool flag =true;
            for(auto it=pmap.begin();it!=pmap.end();it++){
                if(smap.find(it->first)==smap.end()|| it->second-smap[it->first]!=0)
                {
                    flag=false;
                    break;
                }
            }
            if(flag==true)
            {
                res.push_back(right-p.size()+1);
            }
            right++;
            smap[s[right-p.size()]]--;
            smap[s[right]]++;
        }
        return res;
    }
};

std::vector<int> func(std::string s,std::string p)  //官方方法，认为只有字母，所以可以不用map，是快了一点点
{ 
     List<Integer> ans=new ArrayList<Integer>();
int sLen=s.length();
    int pLen=p.length();

    if(sLen<pLen){
        return ans;
    }
    //建立两个数组存放字符串中字母出现的词频，并以此作为标准比较
    int [] scount=new int[26];
    int [] pcount=new int[26];

    //当滑动窗口的首位在s[0]处时 （相当于放置滑动窗口进入数组）
    for(int i=0;i<pLen;i++){
        ++scount[s.charAt(i)-'a']; //记录s中前pLen个字母的词频
        ++pcount[p.charAt(i)-'a']; //记录要寻找的字符串中每个字母的词频(只用进行一次来确定)
    }

    //判断放置处是否有异位词     (在放置时只需判断一次)
    if(Arrays.equals(scount,pcount)){
         ans.add(0);
    }   

    //开始让窗口进行滑动
    for(int i=0;i<sLen-pLen;i++){ //i是滑动前的首位
        --scount[s.charAt(i) -'a'];       //将滑动前首位的词频删去
        ++scount[s.charAt(i+pLen) -'a'];  //增加滑动后最后一位的词频（以此达到滑动的效果）

        //判断滑动后处，是否有异位词
        if(Arrays.equals(scount,pcount)){
            ans.add(i+1);
        } 
    }

    return ans;
}



int main()
{
    std::string s1="baa",p1="aa";
    Solution s;
    auto res = s.findAnagrams(s1,p1);
    for(auto&i:res){
        std::cout<<i<<",";
    }
    return 0;
}