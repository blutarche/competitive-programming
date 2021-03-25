import _ from 'lodash'

import { readInput, writeAnswer, addAnswerLine, getAnswer } from './utils'

const solve = (n) => {
  const nums = _.toString(n).split('')
  // console.log('solve -> nums', nums)
  let last = -1
  let duplicated = false
  let countDup = 1
  for (let i = 0; i < nums.length; i++) {
    const num = _.toNumber(nums[i])
    if (num < last) return false
    if (num === last) {
      countDup++
    } else {
      if (countDup === 2) {
        duplicated = true
      }
      countDup = 1
    }
    last = num
  }
  if (countDup === 2) {
    duplicated = true
  }
  return duplicated
}

const main = async () => {
  const input = await readInput('4')

  const splitted = input[0].split('-')
  const start = _.toNumber(splitted[0])
  const end = _.toNumber(splitted[1])
  let sum = 0
  for (let n = start; n <= end; n++) {
    if (solve(n)) {
      sum++
    }
  }

  addAnswerLine(sum)
  await writeAnswer(getAnswer(), '4a')
}

main()
