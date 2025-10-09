import java.util.ArrayList;
import java.util.List;

class Solution {

    private boolean[] used;
    private int coin;
    private boolean canNext = true;

    public int solution(int coin, int[] cards) {
        List<Integer> list = new ArrayList<>();
        used = new boolean[cards.length];
        this.coin = coin;

        // 초기 카드: 전체의 1/3만큼 가져오기
        for (int i = 0; i < cards.length / 3; i++) {
            list.add(cards[i]);
        }

        int round = 1;

        // 라운드별로 2장씩 새 카드 추가
        for (int i = cards.length / 3; i < cards.length; i += 2) {
            list.add(cards[i]);
            list.add(cards[i + 1]);

            // 현재 카드 리스트로 조합 시도
            submit(list, cards.length + 1, cards);

            // 더 이상 진행 불가 조건
            if (this.coin < 0 || !canNext) {
                return round;
            }

            round++;
        }

        return round;
    }

    private void submit(List<Integer> list, int n, int[] cards) {
        int initialCount = cards.length / 3;
        boolean found = false;

        // 1️⃣ 초기 카드 영역에서 n 합을 만드는 조합 탐색 (코인 사용 X)
        for (int i = 0; i < initialCount && !found; i++) {
            for (int j = i + 1; j < initialCount; j++) {
                if (!used[i] && !used[j] && list.get(i) + list.get(j) == n) {
                    used[i] = true;
                    used[j] = true;
                    found = true;
                    break;
                }
            }
        }

        // 2️⃣ 초기 카드 내에서 못 찾은 경우: 전체 리스트 탐색 (필요 시 코인 사용)
        if (!found) {
            for (int i = 0; i < list.size() - 1 && !found; i++) {
                for (int j = i + 1; j < list.size(); j++) {
                    if (!used[i] && !used[j] && list.get(i) + list.get(j) == n) {
                        used[i] = true;
                        used[j] = true;

                        // 새로 추가된 카드 쓴 경우 코인 차감
                        if (i >= initialCount) coin--;
                        if (j >= initialCount) coin--;

                        found = true;
                        break;
                    }
                }
            }
        }

        // 3️⃣ 둘 다 실패한 경우
        if (!found) {
            canNext = false;
        }
    }
}
