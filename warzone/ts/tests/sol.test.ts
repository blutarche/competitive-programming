import { gameOfLife } from '../src/sol';

describe('Warzone Test', () => {
  test('Case 1', () => {
    const board = [
      [0, 1, 0],
      [0, 0, 1],
      [1, 1, 1],
      [0, 0, 0],
    ];
    gameOfLife(board);
    expect(board).toStrictEqual([
      [0, 0, 0],
      [1, 0, 1],
      [0, 1, 1],
      [0, 1, 0],
    ]);
  });

  test('Case 2', () => {
    const board = [
      [1, 1],
      [1, 0],
    ];
    gameOfLife(board);
    expect(board).toStrictEqual([
      [1, 1],
      [1, 1],
    ]);
  });
});
