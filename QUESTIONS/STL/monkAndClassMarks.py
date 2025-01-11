t = int(input())
result = {}
while (t > 0) :
    string,marks = input().split(" ")
    result[string] = int(marks)
    t -= 1
result = sorted(result,reverse=True)
print(result.items())