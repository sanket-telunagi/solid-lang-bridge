for _ in range(int(input())) :
    nums = list(map(int, input().split()))
    max_votes = max(nums) + 1
    result = [
        max(0, max(nums[1], nums[2]) - nums[0] + 1),
        max(0, max(nums[0], nums[2]) - nums[1] + 1),
        max(0, max(nums[0], nums[1]) - nums[2] + 1)
    ]
    print(*result)
    