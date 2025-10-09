import java.util.*;

public class Solution {
    int N;
    boolean[] visit;
    int[] aDiceIndices;
    int[] bDiceIndices;
    int[] sol;
    int win = 0;
    int aWin = 0;

    public void combination(int depth, int start, int[][] dice) {
        if (depth == N / 2) {
            aWin = 0;
            calculateWinCount(dice);

            if (aWin > win) {
                for (int i = 0; i < N / 2; i++) {
                    sol[i] = aDiceIndices[i] + 1;
                }
                win = aWin;
            }
            return;
        }

        for (int i = start; i < N; i++) {
            visit[i] = true;
            combination(depth + 1, i + 1, dice);
            visit[i] = false;
        }
    }

    public void calculateWinCount(int[][] dice) {
        aDiceIndices = new int[N / 2];
        bDiceIndices = new int[N / 2];
        int aCount = 0, bCount = 0;

        for (int i = 0; i < N; i++) {
            if (visit[i]) aDiceIndices[aCount++] = i;
            else bDiceIndices[bCount++] = i;
        }

        List<Integer> aTotalSums = new ArrayList<>(10000);
        List<Integer> bTotalSums = new ArrayList<>(10000);

        generateDiceSums(0, 0, aDiceIndices, dice, aTotalSums);
        generateDiceSums(0, 0, bDiceIndices, dice, bTotalSums);

        countAWins(aTotalSums, bTotalSums);
    }

    public void generateDiceSums(int depth, int currentSum, int[] selectedDice, int[][] dice, List<Integer> sumList) {
        if (depth == N / 2) {
            sumList.add(currentSum);
            return;
        }
        int diceIndex = selectedDice[depth];
        for (int face = 0; face < 6; face++) {
            generateDiceSums(depth + 1, currentSum + dice[diceIndex][face], selectedDice, dice, sumList);
        }
    }

    public void countAWins(List<Integer> aSums, List<Integer> bSums) {
        Collections.sort(bSums);
        for (int aSum : aSums) {
            aWin += countLessThan(bSums, aSum);
        }
    }

    public int countLessThan(List<Integer> sortedList, int target) {
        int left = 0;
        int right = sortedList.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (sortedList.get(mid) < target) left = mid + 1;
            else right = mid;
        }
        return right;
    }

    public int[] solution(int[][] dice) {
        N = dice.length;
        visit = new boolean[N];
        sol = new int[N / 2];
        combination(0, 0, dice);
        return sol;
    }
}
