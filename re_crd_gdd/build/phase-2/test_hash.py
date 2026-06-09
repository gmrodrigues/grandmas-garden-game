"""Test TIM2 hash function against all RESOURCE.MAP entries."""

import struct
import csv
from tim2_hash import tim2_hash

# Read MAP
with open('RESOURCE.MAP', 'rb') as f:
    data = f.read()

hash_idx = list(data[0:4])
nul = data.index(b'\x00', 6)
entry_start = nul + 1

entries = []
for i in range((len(data) - entry_start) // 8):
    p = entry_start + i * 8
    _, hv, _ = struct.unpack_from("<HIH", data, p)
    entries.append(hv)

# Read manifest
with open('build/phase-1/manifest.csv') as f:
    reader = csv.reader(f)
    next(reader)
    names = [r[1] for r in reader]

# Verify
n = min(len(entries), len(names))
correct = 0
for i in range(n):
    if tim2_hash(names[i], hash_idx) == entries[i]:
        correct += 1

print(f"Hash verification: {correct}/{n} correct ({100*correct/n:.1f}%)")
assert correct == n, f"Expected {n} matches, got {correct}"
print("PASSED")
