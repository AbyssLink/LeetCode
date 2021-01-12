import java.util.ArrayList;
import java.util.List;

class Solution {
  public List<String> summaryRanges(int[] nums) {
    List<String> ans = new ArrayList<>();
    if (nums.length == 0) {
      return ans;
    }
    if (nums.length == 1) {
      ans.add(String.valueOf(nums[0]));
      return ans;
    }
    StringBuilder sb = new StringBuilder();
    int left = nums[0], right = nums[0];

    for (int i = 1; i < nums.length; i++) {
      if (left == nums[i]) {
        continue;
      } else if (right + 1 == nums[i]) {
        right = right + 1;
      } else {
        if (left == right) {
          sb.append(left);
          ans.add(sb.toString());
          left = right = nums[i];
          sb.setLength(0);
        } else {
          sb.append(left);
          sb.append("->");
          sb.append(right);
          ans.add(sb.toString());
          left = right = nums[i];
          sb.setLength(0);
        }
      }
    }
    if (left == right) {
      sb.append(left);
      ans.add(sb.toString());
    } else {
      sb.append(left);
      sb.append("->");
      sb.append(right);
      ans.add(sb.toString());
    }

    return ans;
  }

  public static void main(String[] args) {
    int arr[] = { 0, 2, 3, 4, 6, 8, 9 };
    int arr2[] = { 0, 1, 2, 4, 5, 7 };
    int arr3[] = { 0, 3, 4, 5, 5, 5, 5 };
    int arr4[] = { 1 };
    int arr5[] = { 1, 1, 1, 1, 3, 3, 3, 3, 3, 4 };
    int arr6[] = {};
    int arr7[] = { -3, -2, -1, 0, 1 };
    int arr8[] = { 1, 2, 3, 4, 5 };
    int arr9[] = { -2147483648, -2147483647, 2147483647 };
    Solution solution = new Solution();
    List<String> ranges = solution.summaryRanges(arr7);
    for (String range : ranges) {
      System.out.println(range);
    }
  }
}
