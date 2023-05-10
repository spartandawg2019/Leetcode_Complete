from typing import List
from collections import deque

class Solution:
    def minMutation(self, startGene: str, endGene: str, bank: List[str]) -> int:
        genes = set(bank)
        if endGene not in genes:
            return -1
        q = deque([startGene])
        res = 0
        dna = ['A', 'C', 'G', 'T']
        while q:
            for _ in range(len(q)):
                gene = q.popleft()
                if gene == endGene:
                    return res
                for i in range(len(gene)):
                    for c in dna:
                        tmp = gene[:i] + c + gene[i+1:]
                        if tmp in genes:
                            q.append(tmp)
                            genes.remove(tmp)
            res += 1
        return -1
