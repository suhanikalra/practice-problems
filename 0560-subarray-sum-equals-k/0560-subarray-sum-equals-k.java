class Solution {
    public int subarraySum(int[] nums, int k) {
        int currsum = 0, count = 0;
        Map<Integer, Integer> map = new HashMap<>();

        map.put(0, 1);

        for (int num : nums) {
            currsum += num;
            if (map.containsKey(currsum - k)) {
                count += map.get(currsum - k);
            }
            map.put(currsum, map.getOrDefault(currsum, 0) + 1);
        }

        return count;
    }
}