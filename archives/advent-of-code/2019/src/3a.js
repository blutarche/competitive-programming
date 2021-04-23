import _ from 'lodash'

import { readInput, writeAnswer, addAnswerLine, getAnswer } from './utils'

const lineCrossed = (l1, l2) => {
  const l1Hori = l1[0].y === l1[1].y
  const l2Hori = l2[0].y === l2[1].y
  const l1Verti = l1[0].x === l1[1].x
  const l2Verti = l2[0].x === l2[1].x
  // console.log(l1, l2)
  if (l1Hori && l2Hori) {
    return null
  }
  if (l1Verti && l2Verti) {
    return null
  }
  let horiLine
  let vertiLine
  if (l1Hori) {
    horiLine = l1
    vertiLine = l2
  } else {
    horiLine = l2
    vertiLine = l2
  }

  if (horiLine[0].x < vertiLine[0].x && vertiLine[0].x < horiLine[1].x) {
    if (vertiLine[0].y < horiLine[0].y && horiLine[0].y < vertiLine[1].y)
      return {
        x: vertiLine[0].x,
        y: horiLine[0].y,
      }
  }
  return null
}

const genLines = (input) => {
  let x = 0,
    y = 0
  const commands = input.split(',')
  const lines = []
  for (let i = 0; i < commands.length; i++) {
    const cmd = commands[i]
    const op = _.toString(cmd[0])
    // console.log('main -> x, y', x, y)
    // console.log('main -> op', op)
    const num = _.toNumber(cmd.slice(1))
    // console.log('main -> num', num)
    let nextX = x
    let nextY = y
    if (op === 'R') {
      nextX = x + num
    } else if (op === 'U') {
      nextY = y + num
    } else if (op === 'D') {
      nextY = y - num
    } else {
      nextX = x - num
    }
    // console.log('main -> nextX, nextY', nextX, nextY)
    let nextLine
    if (x < nextX) {
      nextLine = [
        { x, y },
        { x: nextX, y: nextY },
        { startX: x, startY: y, endX: nextX, endY: nextY },
      ]
    } else if (nextX < x) {
      nextLine = [
        { x: nextX, y: nextY },
        { x, y },
        { startX: x, startY: y, endX: nextX, endY: nextY },
      ]
    } else {
      if (y < nextY) {
        nextLine = [
          { x, y },
          { x: nextX, y: nextY },
          { startX: x, startY: y, endX: nextX, endY: nextY },
        ]
      } else if (nextY < y) {
        nextLine = [
          { x: nextX, y: nextY },
          { x, y },
          { startX: x, startY: y, endX: nextX, endY: nextY },
        ]
      }
    }
    lines.push(nextLine)
    x = nextX
    y = nextY
  }
  return lines
}

const main = async () => {
  const input = await readInput('3')

  const lines1 = genLines(input[0])
  const lines2 = genLines(input[1])
  const points = []
  for (let i = 0; i < lines1.length; i++) {
    for (let j = 0; j < lines2.length; j++) {
      const crossPoint = lineCrossed(lines1[i], lines2[j])
      if (crossPoint) {
        points.push(crossPoint)
      }
    }
  }

  let min = -1
  for (let i = 0; i < points.length; i++) {
    const dist = Math.abs(points[i].x) + Math.abs(points[i].y)
    if (min === -1 || min > dist) min = dist
  }
  // console.log(points)
  addAnswerLine(min)
  await writeAnswer(getAnswer(), '1a')
}

main()
