class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;
        int m = s.length(), n = s.length();

        int[] v = new int[26];
        for (int i = 0; i < m; ++i) {
            char c = s.charAt(i);
            ++v[c - 'a'];
        }

        for (int j = 0; j < n; ++j) {
            char c = t.charAt(j);
            if (v[c - 'a'] == 0) return false;
            --v[c - 'a'];
        }
        return true;
    }
}
