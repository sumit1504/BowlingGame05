#include <iostream>
#include <vector>
using namespace std;
class BowlingGame {
public:
    void roll(int pins) {
        rolls.push_back(pins);
    }

    int score() {
        int totalScore = 0;
        int rollIndex = 0;

        for (int frame = 0; frame < 10; ++frame) {
            if (isStrike(rollIndex)) {  // Strike case
                totalScore += 10 + strikeBonus(rollIndex);
                rollIndex += 1;
            }
            else if (isSpare(rollIndex)) {  // Spare case
                totalScore += 10 + spareBonus(rollIndex);
                rollIndex += 2;
            }
            else {  // Open frame
                totalScore += frameScore(rollIndex);
                rollIndex += 2;
            }
        }
        return totalScore;
    }

private:
    std::vector<int> rolls;

    bool isStrike(int rollIndex) {
        return rolls[rollIndex] == 10;
    }

    bool isSpare(int rollIndex) {
        return rolls[rollIndex] + rolls[rollIndex + 1] == 10;
    }

    int strikeBonus(int rollIndex) {
        return rolls[rollIndex + 1] + rolls[rollIndex + 2];
    }

    int spareBonus(int rollIndex) {
        return rolls[rollIndex + 2];
    }

    int frameScore(int rollIndex) {
        return rolls[rollIndex] + rolls[rollIndex + 1];
    }
};

int main() {
    BowlingGame game;
    vector<int> l_Rolls = {1, 4, 4, 5, 6, 4, 5, 5, 10, 0, 1, 7, 3, 6, 4, 10, 2, 8, 6};

    for (int l_pins : l_Rolls) {
        game.roll(l_pins);
    }

    cout << "Total Score: " << game.score() << endl;

    return 0;
}