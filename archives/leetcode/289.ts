// 00, 01, 10, 11

export function gameOfLife(board: number[][]): void {
  const rowCount = board.length;
  const colCount = board[0].length;
  // console.log(rowCount, colCount);
  // console.log(board);

  const getLiveNeighborsCount = (i: number, j: number): number => {
    let count = 0;
    for (let row = i - 1; row <= i + 1; row++) {
      if (row < 0 || row >= rowCount) {
        continue;
      }
      for (let col = j - 1; col <= j + 1; col++) {
        if (row === i && col === j) {
          continue;
        }
        if (col < 0 || col >= colCount) {
          continue;
        }
        count += board[row][col] % 10;
      }
    }
    return count;
  };

  for (let i = 0; i < rowCount; i++) {
    for (let j = 0; j < colCount; j++) {
      const currentState = board[i][j] % 10;
      const liveNeighborsCount = getLiveNeighborsCount(i, j);
      // console.log('state', i, j, liveNeighborsCount);
      if (currentState === 0) {
        if (liveNeighborsCount == 3) {
          board[i][j] = 10;
        }
      } else {
        if (liveNeighborsCount < 2) {
          board[i][j] = 1;
        } else if (liveNeighborsCount === 2 || liveNeighborsCount === 3) {
          board[i][j] = 11;
        } else {
          board[i][j] = 1;
        }
      }
    }
  }

  // console.log(board);

  for (let i = 0; i < rowCount; i++) {
    for (let j = 0; j < colCount; j++) {
      board[i][j] = Math.floor(board[i][j] / 10);
    }
  }
}
