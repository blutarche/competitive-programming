export function jump(nums: number[]): number {
  let maxReachablePosition = 0;
  let farthestJumpedPosition = 0;
  let jumpsCount = 0;
  for (let i = 0; i < nums.length - 1; i++) {
    maxReachablePosition = Math.max(maxReachablePosition, i + nums[i]);
    if (i == farthestJumpedPosition) {
      farthestJumpedPosition = maxReachablePosition;
      ++jumpsCount;
    }
  }
  return jumpsCount;
}
