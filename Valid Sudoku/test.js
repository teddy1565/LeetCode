
for (let i = 0; i < 9; i++) {
    for (let j = 0; j < 9; j++) {
        let block_row = Math.trunc(i / 3) * 3;
        let block_col = (i % 3) * 3;
        let s_row = Math.trunc(j / 3);
        let s_col = Math.trunc(j % 3);
        console.log(block_row + s_row, block_col + s_col, s_row, s_col);
    }
}