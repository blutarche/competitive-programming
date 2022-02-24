import { readInput } from './utils'
import _, { split } from 'lodash'
import { promises as fs } from 'fs'

type People = {
  [name: string]: {
    [skill: string]: number
  }
}

type Projects = {
  [name: string]: {
    days: number
    score: number
    bestBefore: number
    roles: Array<{
      name: string
      level: number
    }>
  }
}

let projectNames: Array<string> = []
let people: People = {}
let projects: Projects = {}
let totalPeople: number = 0
let totalProject: number = 0
let isFirstLine: boolean = true
let peopleLeft: number = 0
let skillsLeft: number = 0
let rolesLeft: number = 0
let projectsLeft: number = 0
let currentPerson: string = ''
let currentProject: string = ''

const processLine = (line: string, last?: boolean) => {
  const splitted = line.split(' ')
  if (isFirstLine) {
    totalPeople = parseInt(splitted[0])
    totalProject = parseInt(splitted[1])
    peopleLeft = totalPeople
    projectsLeft = totalProject
    isFirstLine = false
    return
  }
  if (peopleLeft > 0 || skillsLeft > 0) {
    if (skillsLeft === 0) {
      --peopleLeft
      currentPerson = splitted[0]
      skillsLeft = parseInt(splitted[1])
      people[currentPerson] = {}
      return
    }
    --skillsLeft
    const skillName = splitted[0]
    const skillLevel = parseInt(splitted[1])
    people[currentPerson][skillName] = skillLevel
    return
  }
  if (rolesLeft === 0) {
    --projectsLeft
    currentProject = splitted[0]
    projectNames.push(currentProject)
    const days = parseInt(splitted[1])
    const score = parseInt(splitted[2])
    const bestBefore = parseInt(splitted[3])
    rolesLeft = parseInt(splitted[4])
    projects[currentProject] = {
      days,
      score,
      bestBefore,
      roles: [],
    }
    return
  }
  --rolesLeft
  const skillName = splitted[0]
  const skillLevel = parseInt(splitted[1])
  projects[currentProject].roles.push({
    name: skillName,
    level: skillLevel,
  })
  return
}

const reset = () => {
  projectNames = []
  people = {}
  projects = {}
  totalPeople = 0
  totalProject = 0
  isFirstLine = true
  peopleLeft = 0
  currentPerson = ''
  currentProject = ''
  skillsLeft = 0
  rolesLeft = 0
  projectsLeft = 0
}

const processCase = async (inputDir: string, fileName: string) => {
  reset()
  await readInput(`${inputDir}/${fileName}`, processLine)

  console.log('people', people)
  console.log('projects', JSON.stringify(projects, null, 2))
  console.log('projectNames', projectNames)

  let ans = []

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
