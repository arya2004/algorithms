#!/usr/bin/env node
function fisherYates(a, rng = Math.random) {
  for (let i = a.length - 1; i > 0; i--) {
    const j = Math.floor(rng() * (i + 1)); // 0..i
    [a[i], a[j]] = [a[j], a[i]];
  }
  return a;
}

// Optional deterministic seed (LCG for portability)
function seeded(seed) {
  let s = BigInt(seed) & ((1n<<48n)-1n);
  return () => {
    s = (25214903917n * s + 11n) & ((1n<<48n)-1n);
    return Number(s) / Number(1n<<48n);
  };
}

const args = process.argv.slice(2);
let items = args.length ? args : require("fs").readFileSync(0,"utf8").trim().split(/\s+/);
const seed = process.env.SEED;
const rng = seed ? seeded(seed) : Math.random;
console.log(fisherYates(items, rng).join(" "));
