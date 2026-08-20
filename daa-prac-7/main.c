#include <stdio.h>
#include <limits.h>

int min_coins_change(int coins[], int coins_count, int target_amount) {
    int dp[target_amount + 1];
    
    dp[0] = 0;
    for (int i = 1; i <= target_amount; i++) {
        dp[i] = INT_MAX;
    }
    
    for (int amount = 1; amount <= target_amount; amount++) {
        for (int i = 0; i < coins_count; i++) {
            int coin = coins[i];
            if (amount - coin >= 0 && dp[amount - coin] != INT_MAX) {
                if (dp[amount - coin] + 1 < dp[amount]) {
                    dp[amount] = dp[amount - coin] + 1;
                }
            }
        }
    }
    
    return dp[target_amount] == INT_MAX ? -1 : dp[target_amount];
}

int main() {
    int coins_count;
    printf("Enter the number of coin denominations: ");
    if (scanf("%d", &coins_count) != 1 || coins_count <= 0) {
        printf("Invalid number of coins.\n");
        return 1;
    }

    int coin_denominations[coins_count];
    printf("Enter the coin values:\n");
    for (int i = 0; i < coins_count; i++) {
        if (scanf("%d", &coin_denominations[i]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    int target;
    printf("Enter the target amount: ");
    if (scanf("%d", &target) != 1 || target < 0) {
        printf("Invalid target amount.\n");
        return 1;
    }
    
    int result = min_coins_change(coin_denominations, coins_count, target);
    
    if (result == -1) {
        printf("It is impossible to make change for %d with the given coins.\n", target);
    } else {
        printf("Minimum coins required for %d: %d\n", target, result);
    }
    
    return 0;
}
