/**
 * @param {number} n
 * @param {string[]} logs
 * @return {number[]}
 */
function exclusiveTime(n, logs) {
    const ans = new Array(n);
    ans.fill(0);
    const action_stack = [];
    let prev_tick = 0;
    for (const log of logs) {
        const ln = log.split(":");
        const id = parseInt(ln[0]);
        const action = ln[1];
        const tick = parseInt(ln[2]);

        if (action == "start") {
            if (action_stack.length > 0) {
                let prev_id = action_stack[action_stack.length - 1];
                ans[prev_id] += (tick - prev_tick);
            }
            action_stack.push(id);
            prev_tick = tick;
        } else if (action == "end") {
            ans[id] += ((tick - prev_tick) + 1);
            action_stack.pop();
            prev_tick = tick + 1;
        }
    }

    return ans;
};

const test_case = [
    [8, ["0:start:0","1:start:5","2:start:6","3:start:9","4:start:11","5:start:12","6:start:14","7:start:15","1:start:24","1:end:29","7:end:34","6:end:37","5:end:39","4:end:40","3:end:45","0:start:49","0:end:54","5:start:55","5:end:59","4:start:63","4:end:66","2:start:69","2:end:70","2:start:74","6:start:78","0:start:79","0:end:80","6:end:85","1:start:89","1:end:93","2:end:96","2:end:100","1:end:102","2:start:105","2:end:109","0:end:114"]],
    [2, ["0:start:0","0:start:2","0:end:5","1:start:7","1:end:7","0:end:8"]],
    [2, ["0:start:0","0:start:2","0:end:5","1:start:6","1:end:6","0:end:7"]],
    [1, ["0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7"]],
    [2, ["0:start:0","1:start:2","1:end:5","0:end:6"]]
];

for (const [n, logs] of test_case) {
    console.log(exclusiveTime(n, logs));
}
