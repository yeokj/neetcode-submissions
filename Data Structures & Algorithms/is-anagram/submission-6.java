class Solution {
    public boolean isAnagram(String s, String t) {
        HashMap<Character, Integer> mp = new HashMap<>();

        for (char c : s.toCharArray()) {
            mp.put(c, mp.getOrDefault(c, 0) + 1);
        }

        for (char c : t.toCharArray()) {
            if (!mp.containsKey(c)) return false;
            mp.put(c, mp.getOrDefault(c, 0) - 1);
        }

        for (var entry : mp.entrySet()) {
            if (entry.getValue() > 0) return false;
        }
        return true;
    }
}
