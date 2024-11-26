export function maximumSubarraySum(nums: number[], k: number): number {
  let max = 0;
  let foundNum = {};
  let currentSum = 0;
  let lastDuplicateIdx = -1;

  for (let i = 0; i < nums.length; i++) {
    currentSum += nums[i];
    // console.log('values', {
    //   i,
    //   currentSum,
    //   lastDuplicateIdx,
    //   foundNum,
    // })
    if (i >= k) {
      currentSum -= nums[i - k];
    }

    const lastFoundNum = foundNum[nums[i]];
    foundNum[nums[i]] = i;

    if (lastFoundNum !== undefined && i - lastFoundNum < k) {
      lastDuplicateIdx = Math.max(lastFoundNum, lastDuplicateIdx);
      continue;
    }

    if (lastDuplicateIdx !== -1 && lastDuplicateIdx > i - k) {
      continue;
    }

    if (i >= k - 1) {
      max = Math.max(max, currentSum);
    }
  }

  return max;
}
