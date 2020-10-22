public class Solution {
    public boolean isSubsequence(String x, String y) {
        int j = 0;
        for (int i = 0; i < y.length() && j < x.length(); i++)
            if (x.charAt(j) == y.charAt(i))
                j++;
        return j == x.length();
    }
    public int findLUSlength(String[] strs) {
        int res = -1;
        for (int i = 0, j; i < strs.length; i++) {
            for (j = 0; j < strs.length; j++) {
                if (j == i)
                    continue;
                if (isSubsequence(strs[i], strs[j]))
                    break;
            }
            if (j == strs.length)
                res = Math.max(res, strs[i].length());
        }
        return res;
    }
}

