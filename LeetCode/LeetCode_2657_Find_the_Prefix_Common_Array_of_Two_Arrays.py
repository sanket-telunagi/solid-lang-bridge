from typing import List
def findThePrefixCommonArray(A: List[int], B: List[int]) -> List[int]:
        track = [0]*(len(A) + 1)
        result = [0]*len(A)


        
        for index, num in enumerate(A) :
            track[num] += 1
            track[B[index]] += 1

            count2 = 0 
            for val in track :
                if val == 2 : count2 += 1
            result[index] = count2
        
        return result

A = list(map(int, input().split()))
B = list(map(int, input().split()))
print(*findThePrefixCommonArray(A, B))