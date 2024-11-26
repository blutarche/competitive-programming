export function removeDuplicates(nums: number[]): number {
  let maxFound = -10000;
  let max2ndFound = -10000;
  let ansIdx = 0;
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] > maxFound) {
      max2ndFound = maxFound;
      maxFound = nums[i];
      nums[ansIdx++] = nums[i];
    } else if (nums[i] == maxFound && nums[i] != max2ndFound) {
      max2ndFound = nums[i];
      nums[ansIdx++] = nums[i];
    }
  }
  return ansIdx;
}
