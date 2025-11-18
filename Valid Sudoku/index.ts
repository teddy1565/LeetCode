function isValidSudoku(board: string[][]): boolean {
    const hash_map: any = [[[],[],[]],[[],[],[]],[[],[],[]]];
    const regexp_n = new RegExp("");
    for (let i = 0; i < 9; i++) {
        const row_str = board[i].join("")!;
        const x = Math.trunc(i / 3);
        for (let j = 0; j < 9; j++) {
            const y = Math.trunc(j / 3);
            const col_str = board.map((x) => x[j]).join("");
            if (board[i][j] === '.') continue;
            regexp_n.compile(board[i][j], "g");
            if (row_str.match(regexp_n)!.length != 1) return false;
            else if (col_str.match(regexp_n)!.length != 1) return false;
            if (hash_map[x][y][board[i][j]] == undefined) hash_map[x][y][board[i][j]] = 1;
            else return false;
        }
    }
    return true;
};