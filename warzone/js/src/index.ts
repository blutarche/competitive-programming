import { readInput } from './utils'
import _, { split } from 'lodash'
import { promises as fs } from 'fs'

type Person = {
  name: string
  freeAt: number
  skills: {
    [skill: string]: number
  }
}

type People = {
  [name: string]: Person
}

type Project = {
  name: string
  days: number
  score: number
  bestBefore: number
  wannaWorkOnScore?: number
  roles: Array<{
    name: string
    level: number
  }>
}

type Projects = {
  [name: string]: Project
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
const DEBUG = false

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
      people[currentPerson] = {
        name: currentPerson,
        skills: {},
        freeAt: 0,
      }
      return
    }
    --skillsLeft
    const skillName = splitted[0]
    const skillLevel = parseInt(splitted[1])
    people[currentPerson].skills[skillName] = skillLevel
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
      name: currentProject,
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

const calcMagicWannaWorkOnScore = (p: Project) => {
  // return (p.days * p.score) / p.bestBefore
  return p.score / Math.abs(p.days)
}

const calcProjectDoneScore = (p: Project, startAt: number): number => {
  const doneAt = startAt + p.days
  if (doneAt <= p.bestBefore) return p.score
  const realScore = p.score - (doneAt - p.bestBefore)
  return realScore >= 1 ? realScore : 1
}

const doProject = (
  p: Project
): {
  doable: boolean
  startAt: number
  contributors: Array<Person>
} => {
  const highestSkills: { [skill: string]: number } = {}

  type DoProjectRoleData = {
    bestPerson: Person
  }
  let maxFreeAt = 0
  let isDoable = true
  let busyPeople: { [name: string]: boolean } = {}

  const isPersonSuitable = (
    person: Person,
    skillName: string,
    skillLevel: number
  ): boolean => {
    if (busyPeople[person.name]) return false
    return (
      person.skills[skillName] >= skillLevel || // no need for mentor
      ((skillLevel === 1 || person.skills[skillName] === skillLevel - 1) &&
        highestSkills[skillName] >= skillLevel)
    ) // mentor
  }
  if (DEBUG) {
    console.log('PROJECT', p.name)
  }
  const contributors = _.map(p.roles, (r) => {
    const roleData: DoProjectRoleData = _.reduce(
      people,
      (current: DoProjectRoleData, person: Person, personName: string) => {
        if (
          isPersonSuitable(person, r.name, r.level) &&
          (!current.bestPerson || current.bestPerson.freeAt > person.freeAt)
          //  ||
          // (person.freeAt <= current.bestPerson.freeAt &&
          //   current.bestPerson.skills[r.name] > r.level &&
          //   person.skills[r.name] <= r.level))
        ) {
          return {
            bestPerson: person,
          }
        }
        return current
      },
      {
        bestPerson: null,
      }
    )
    if (DEBUG) {
      console.log(
        '🚀 ~ file: index.ts ~ line 149 ~ contributors ~ roleData',
        roleData
      )
    }
    if (roleData.bestPerson) {
      _.forEach(roleData.bestPerson.skills, (level, name) => {
        if (!highestSkills[name] || level > highestSkills[name])
          highestSkills[name] = level
      })
      if (roleData.bestPerson.freeAt > maxFreeAt) {
        maxFreeAt = roleData.bestPerson.freeAt
      }
      busyPeople[roleData.bestPerson.name] = true
    } else {
      isDoable = false
    }
    return roleData.bestPerson
  })
  if (!isDoable) {
    return {
      doable: false,
      startAt: 0,
      contributors: [],
    }
  }
  _.forEach(contributors, (person, idx) => {
    people[person.name].freeAt = maxFreeAt + p.days
    if (person.skills[p.roles[idx].name] <= p.roles[idx].level) {
      if (!people[person.name].skills[p.roles[idx].name]) {
        people[person.name].skills[p.roles[idx].name] = 1
      } else {
        people[person.name].skills[p.roles[idx].name]++
      }
    }
  })
  return {
    doable: true,
    startAt: maxFreeAt,
    contributors,
  }
}

const processCase = async (inputDir: string, fileName: string) => {
  reset()
  await readInput(`${inputDir}/${fileName}`, processLine)

  if (DEBUG) {
    console.log('people', people)
    console.log('projects', JSON.stringify(projects, null, 2))
    console.log('projectNames', projectNames)
  }

  await fs.writeFile(
    `output/${fileName
      .replace('.in.', '.out.people.')
      .replace('.txt', '.json')}`,
    JSON.stringify(people, null, 2)
  )

  await fs.writeFile(
    `output/${fileName
      .replace('.in.', '.out.projects.')
      .replace('.txt', '.json')}`,
    JSON.stringify(projects, null, 2)
  )

  const sortedProjects = _.chain(projects)
    .map((p) => {
      p.wannaWorkOnScore = calcMagicWannaWorkOnScore(p)
      return p
    })
    .sortBy((p) => -p.wannaWorkOnScore)
    .value()
  if (DEBUG) {
    console.log(
      '🚀 ~ file: index.ts ~ line 137 ~ processCase ~ sortedProjects',
      sortedProjects
    )
  }

  let totalScore = 0

  let impossibleProjectsCount = 0

  let answers: Array<{
    projectName: string
    startAt: number
    contributors: Array<string>
  }> = []

  while (
    !_.isEmpty(sortedProjects) &&
    impossibleProjectsCount < sortedProjects.length
  ) {
    const proj = sortedProjects.shift()
    const result = doProject(proj)
    if (DEBUG) {
      console.log(
        '🚀 ~ file: index.ts ~ line 236 ~ processCase ~ result',
        result
      )
    }
    if (!result.doable) {
      // const nextProj = sortedProjects.shift()
      sortedProjects.push(proj) // try to do it after everything else
      impossibleProjectsCount++
      continue
    } else {
      impossibleProjectsCount = 0
      totalScore += calcProjectDoneScore(proj, result.startAt)
      if (DEBUG) {
        console.log(
          '🚀 ~ file: index.ts ~ line 254 ~ processCase ~ totalScore',
          totalScore
        )
      }
      answers.push({
        projectName: proj.name,
        startAt: result.startAt,
        contributors: _.map(result.contributors, (c) => c.name),
      })
    }
  }

  console.log('TOTAL SCORE', totalScore)

  answers = _.sortBy(answers, (a) => a.startAt)
  if (DEBUG) {
    console.log(
      '🚀 ~ file: index.ts ~ line 290 ~ processCase ~ answers',
      answers
    )
  }

  let answerLines: Array<string> = []
  answerLines.push(answers.length.toString())
  _.forEach(answers, (a) => {
    answerLines.push(a.projectName)
    answerLines.push(a.contributors.join(' '))
  })

  const ansString = answerLines.join('\r\n')
  const outFileName = fileName.replace('.in.', '.out.')
  console.log(`in: ${inputDir}/${fileName}`)
  console.log(`out: output/${outFileName}`)
  // console.log(ansString)
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
