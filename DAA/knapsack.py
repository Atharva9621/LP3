def fractional_knapsack(weights:list[float], values:list[float], capacity: int)->float:
    val_ratios = [(i, value/weight) for i, (value, weight) in enumerate(zip(values, weights))]
    res = 0.0
    for i, ratio in sorted(val_ratios, key = lambda a: a[1], reverse=True):
        if capacity > weights[i]:
            res += values[i]
            capacity -= weights[i]
        else:
            res += capacity*values[i]/weights[i]
            capacity = 0
            break
    return res 

def knapsack_dp(weights:list[int], values:list[int], capacity: int, n: int, dp: list[list[int]])->int:
    if n < 1 or capacity <= 0:
        return 0
    if dp[n][capacity] != -1:
        return dp[n][capacity]
    
    take, leave = 0, knapsack_dp(weights, values, capacity, n-1, dp)
    if capacity > weights[n-1]:
        take = knapsack_dp(weights, values, capacity-weights[n-1], n-1, dp) + values[n-1]
    dp[n][capacity] = max(take, leave)
    return dp[n][capacity]

if __name__ == "__main__":
    
    weights = [10,20,30]
    values = [60, 100, 120]
    capacity = 45
    print(f"Fractional knapsack for capacity {capacity} ====>  {fractional_knapsack(weights, values, capacity)}")

    dp = [[-1 for i in range(capacity+1)] for j in range(len(weights)+1)]
    print(f"0/1 knapsack for capacity {capacity} ====>  {knapsack_dp(weights, values, capacity, 3, dp)}")
