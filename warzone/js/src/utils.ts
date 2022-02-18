import lineReader from 'line-reader'
import Promise from 'bluebird'

export const readInput = async (
  fileName: string,
  callback: (line: string, last?: boolean) => void
) => {
  var eachLine = Promise.promisify(lineReader.eachLine)
  await eachLine(fileName, callback)
}
