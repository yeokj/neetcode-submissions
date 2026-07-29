class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;

        HashMap<Character, Integer> mp = new HashMap<>();

        for (char c : s.toCharArray()) {
            mp.put(c, mp.getOrDefault(c, 0) + 1);
        }

        for (char c : t.toCharArray()) {
            if (mp.getOrDefault(c, 0) == 0) return false;
            mp.put(c, mp.getOrDefault(c, 0) - 1);
        }
        return true;
    }
}
