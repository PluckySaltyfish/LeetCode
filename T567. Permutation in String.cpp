//等长窗口+字典
class Solution {
public:
    int s1_dic[26] = {0};
    int s2_dic[26] = {0};
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length()) return false;
        for (int i = 0; i < s1.length(); i++) {
            s1_dic[s1[i] - 'a'] += 1;
            s2_dic[s2[i] - 'a'] += 1;
        }
        if (isEqual())
            return true;
        for (int i = 1; i + s1.length() - 1 < s2.length() ; i++) {
            int j = i + s1.length() - 1;
            s2_dic[s2[i - 1] - 'a'] -= 1;
            s2_dic[s2[j] - 'a'] += 1;
            if (isEqual())
                return true;
        }
        return false;
    }
    
    bool isEqual(){
        for (int i = 0; i < 26; i++) {
            if(s1_dic[i] != s2_dic[i])
                return false;
        }
        return true;
    }
};

//双指针
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        vector<int>a1(26,0);
        for(auto c : s1)
            a1[c -'a']++;
        int left = 0,right = 0;
        vector<int>a2(a1);
        while(right < s2.size()){
            a2[s2[right] - 'a']--;
            while(a2[s2[right] - 'a']< 0){
                a2[s2[left] - 'a']++;
                left++;
            }
            if(n == right - left + 1)return true;
            right++;
        }
        return false;
    }
};