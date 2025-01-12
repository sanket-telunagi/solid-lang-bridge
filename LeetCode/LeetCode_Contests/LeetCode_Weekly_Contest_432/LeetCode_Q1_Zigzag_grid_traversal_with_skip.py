from typing import List

def zigzagTraversal(grid: List[List[int]]) -> List[int]:
        result = []
        for index, row in enumerate(grid) : 
            temp = []
            if index % 2== 0 :
                for idx, num in enumerate(row) :
                    if idx % 2 == 0 :
                        temp.append(num)
            else :
                for idx, num in enumerate(row) :
                    if idx % 2 != 0 :
                        temp.append(num)
                temp.reverse()
            result.extend(temp)
        return result

grid = []
rows_, cols_ = map(int, input().split())
for rows in range(rows_) :
    row = list(map(int, input().split()))
    # print(*row)
    grid.append(row)

print(*zigzagTraversal(grid))
    