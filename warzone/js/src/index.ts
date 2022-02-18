import { readInput } from './utils'
import _ from 'lodash'
import { promises as fs } from 'fs'

type Like = {
  [id: number]: {
    [ing: string]: boolean
  }
}

type Hate = {
  [id: number]: {
    [ing: string]: boolean
  }
}

type HateIndex = {
  [ing: string]: number
}

type IngredientIndex = {
  [ing: string]: boolean
}

let total: number = 0
let like: Like = {}
let hate: Hate = {}
let hateIndex: HateIndex = {}
let ingIndex: IngredientIndex = {}
let isFirstLine: boolean = true
let currentId: number = 0
let isLike: boolean = true

const processLine = (line: string, last?: boolean) => {
  if (isFirstLine) {
    total = parseInt(line)
    isFirstLine = false
    return
  }
  const splitted = line.split(' ')
  if (isLike) {
    like[currentId] = {}
    for (let i = 1; i < splitted.length; i++) {
      const ing = splitted[i]
      like[currentId][ing] = true
      ingIndex[ing] = true
    }
    isLike = false
  } else {
    hate[currentId] = {}
    for (let i = 1; i < splitted.length; i++) {
      const ing = splitted[i]
      hate[currentId][ing] = true
      if (!hateIndex[ing]) hateIndex[ing] = 0
      hateIndex[ing]++
      ingIndex[ing] = true
    }
    isLike = true
    currentId++
  }
}

const reset = () => {
  like = {}
  hate = {}
  hateIndex = {}
  ingIndex = {}
  total = 0
  isFirstLine = true
  currentId = 0
  isLike = true
}

const processCase = async (inputDir: string, fileName: string) => {
  reset()
  await readInput(`${inputDir}/${fileName}`, processLine)
  if (fileName === 'a_an_example.in.txt') {
    console.log(like)
    console.log(hate)
    // console.log(hateIndex)
    // console.log(ingIndex)
  }
  let ans = []
  _.forEach(ingIndex, (val, ing) => {
    if (!hateIndex[ing]) {
      ans.push(ing)
    }
  })
  const outFileName = fileName.replace('.in.', '.out.')
  let ansString = `${ans.length} ${ans.join(' ')}`
  console.log(`${inputDir}/${fileName}`)
  console.log(ansString)
  console.log('================================')
  console.log('')
  await fs.writeFile(`output/${outFileName}`, ansString)
}

const main = async () => {
  if (process.argv[2]) {
    processCase('input', process.argv[2])
  } else {
    const files = await fs.readdir('input/input_data')
    for (const f of files) {
      await processCase('input/input_data', f)
    }
  }
}

main()
