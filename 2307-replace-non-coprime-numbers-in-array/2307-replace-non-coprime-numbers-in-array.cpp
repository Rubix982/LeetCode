using ll = long long;
inline ll gcdll(ll a, ll b) { return b ? gcdll(b, a % b) : a; }
inline ll lcmll(ll a, ll b) { return a / gcdll(a, b) * b; }

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<ll> st;  // stack to hold current array state
        for (int x : nums) {
            ll cur = x;
            while (!st.empty() && gcdll(st.back(), cur) > 1) {
                cur = lcmll(st.back(), cur); // merge with stack top
                st.pop_back();               // remove the top
            }
            st.push_back(cur);
        }
        // convert back to int (safe because problem guarantees ≤ 1e8)
        vector<int> res(st.begin(), st.end());
        return res;
    }
};