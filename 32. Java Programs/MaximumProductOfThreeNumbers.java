import java.util.Arrays;

public class MaximumProductOfThreeNumbers {

    public static void main(String[] args) {
        int[] numsA = new int[]{1, 2, 3, 4, 5, 6};
        int[] numsB = new int[]{1, 2, 3, 4, 5, 6};
        int productA = maximumProductSorting(numsA);
        int productB = maximumProductSingleScan(numsB);
        System.out.println("Result A: " + productA);
        System.out.println("Result B: " + productB);
    }

    private static int maximumProductSorting(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        return Math.max(nums[n - 1] * nums[n - 2] * nums[n - 3],
                nums[0] * nums[1] * nums[n - 1]);
    }

    private static int maximumProductSingleScan(int[] nums) {
        int max1 = Integer.MIN_VALUE;
        int max2 = Integer.MIN_VALUE;
        int max3 = Integer.MIN_VALUE;
        int min1 = Integer.MAX_VALUE;
        int min2 = Integer.MAX_VALUE;

        for (int elem : nums) {
            if (elem > max1) {
                //Now, max1 will get update with these new greater element, so
                //element which max1 was holding earlier is smaller than the
                //new element which max1 is holding now.

                //So, element which max1 was holding earlier is now 2nd
                //largest element, so update max2 with these element

                //So, element which max2 was holding earlier is now 3rd
                //largest element, so update max3 with these element

                max3 = max2;
                max2 = max1;
                max1 = elem;
            } else if (elem > max2) {
                max3 = max2;
                max2 = elem;
            } else if (elem > max3) {
                max3 = elem;
            }

            if (elem < min1) {
                min2 = min1;
                min1 = elem;
            } else if (elem < min2) {
                min2 = elem;
            }
        }
        return Math.max(max1 * max2 * max3, min1 * min2 * max1);
    }
}