import _ from 'lodash'

import { readInput, writeAnswer, addAnswerLine, getAnswer } from './utils'

const getDistance = (p1, p2) => {
  // console.log('getDistance -> p', p1, p2)
  return Math.abs(p1.x - p2.x) + Math.abs(p1.y - p2.y)
}

const lineCrossed = (l1, l2) => {
  const l1Hori = l1[0].y === l1[1].y
  // console.log('lineCrossed -> l1Hori', l1Hori)
  const l2Hori = l2[0].y === l2[1].y
  // console.log('lineCrossed -> l2Hori', l2Hori)
  const l1Verti = l1[0].x === l1[1].x
  // console.log('lineCrossed -> l1Verti', l1Verti)
  const l2Verti = l2[0].x === l2[1].x
  // console.log('lineCrossed -> l2Verti', l2Verti)
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
    vertiLine = l1
  }
  // console.log('lineCrossed -> horiLine', horiLine)
  // console.log('lineCrossed -> vertiLine', vertiLine)
  if (horiLine[0].x < vertiLine[0].x && vertiLine[0].x < horiLine[1].x) {
    if (vertiLine[0].y < horiLine[0].y && horiLine[0].y < vertiLine[1].y) {
      const data = {
        x: vertiLine[0].x,
        y: horiLine[0].y,
      }
      if (data.x === 0 && data.y === 0) return null
      return data
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
  console.log('main -> lines1', lines1)
  const lines2 = genLines(input[1])
  console.log('main -> lines2', lines2)
  const points = []
  let dist1 = 0
  let x1 = 0,
    y1 = 0
  let min = -1
  for (let i = 0; i < lines1.length; i++) {
    let dist2 = 0
    let x2 = 0,
      y2 = 0
    for (let j = 0; j < lines2.length; j++) {
      const crossPoint = lineCrossed(lines1[i], lines2[j])
      if (crossPoint) {
        points.push(crossPoint)
        // console.log('main -> crossPoint', crossPoint)
        const crossDist1 = getDistance(
          { x: crossPoint.x, y: crossPoint.y },
          { x: lines1[i][2].startX, y: lines1[i][2].startY }
        )
        // console.log('main -> crossDist1', crossDist1)
        const crossDist2 = getDistance(
          { x: crossPoint.x, y: crossPoint.y },
          { x: lines2[j][2].startX, y: lines2[j][2].startY }
        )
        // console.log('main -> crossDist2', crossDist2)
        const dist = dist1 + dist2 + crossDist1 + crossDist2
        // console.log('main -> dist', dist)
        if (min === -1 || dist < min) {
          min = dist
        }
      }
      const nextX2 = lines2[j][2].endX
      const nextY2 = lines2[j][2].endY
      dist2 += getDistance({ x: x2, y: y2 }, { x: nextX2, y: nextY2 })
      // console.log('main -> dist1, dist2', dist1, dist2)
      x2 = nextX2
      y2 = nextY2
    }
    const nextX1 = lines1[i][2].endX
    const nextY1 = lines1[i][2].endY
    dist1 += getDistance({ x: x1, y: y1 }, { x: nextX1, y: nextY1 })
    x1 = nextX1
    y1 = nextY1
  }

  // let min = -1
  // for (let i = 0; i < points.length; i++) {
  //   const dist = Math.abs(points[i].x) + Math.abs(points[i].y)
  //   if (min === -1 || min > dist) min = dist
  // }
  // console.log(points)
  addAnswerLine(min)
  await writeAnswer(getAnswer(), '1a')
}

main()
