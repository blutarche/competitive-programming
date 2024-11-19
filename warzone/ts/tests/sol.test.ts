import { maximumSubarraySum } from '../src/sol'

describe('Maximum Subarray Sum', () => {
  test('Case 1', () => {
    expect(maximumSubarraySum([1, 5, 4, 2, 9, 9, 9], 3)).toBe(15)
  })
  test('Case 2', () => {
    expect(maximumSubarraySum([4, 4, 4], 3)).toBe(0)
  })

  test('Case 3', () => {
    expect(maximumSubarraySum([1, 9, 9, 2], 3)).toBe(0)
  })

  test('Case 4', () => {
    expect(maximumSubarraySum([1, 9, 9, 2, 3], 3)).toBe(14)
  })

  test('Case 5', () => {
    expect(maximumSubarraySum([9, 9, 9, 1, 2, 3], 3)).toBe(12)
  })
})
