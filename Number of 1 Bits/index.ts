function hammingWeight_v2(n: number): number {
    return n.toString(2).match(/1/g)!.length;
}
