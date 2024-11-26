export function canJump(nums: number[]): boolean {
  let maxReachablePosition = 0;
  for (let i = 0; i < nums.length; i++) {
    if (i <= maxReachablePosition) {
      maxReachablePosition = Math.max(maxReachablePosition, i + nums[i]);
    } else {
      return false;
    }
  }
  return true;
}
