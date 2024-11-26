/**
 Do not return anything, modify nums1 in-place instead.
 */
export function merge(
  nums1: number[],
  m: number,
  nums2: number[],
  n: number
): void {
  let idx1 = 0;
  let idx2 = 0;
  let ans: number[] = [];

  while (ans.length < m + n) {
    if ((idx1 < m && nums1[idx1] < nums2[idx2]) || idx2 >= n) {
      ans.push(nums1[idx1]);
      ++idx1;
    } else {
      ans.push(nums2[idx2]);
      ++idx2;
    }
  }

  for (let i = 0; i < m + n; i++) {
    nums1[i] = ans[i];
  }
}
