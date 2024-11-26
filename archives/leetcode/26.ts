export function removeDuplicates(nums: number[]): number {
  let maxFound = -10000;
  let uniqueFound = 0;
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] > maxFound) {
      maxFound = nums[i];
      nums[uniqueFound++] = nums[i];
    }
  }
  return uniqueFound;
}
