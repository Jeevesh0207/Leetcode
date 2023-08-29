class Solution {
public:
    int bestClosingTime(string customers) {
      int maxScore = 0;  
        int currentScore = 0;
        int bestHour = -1;

        for (int hour = 0; hour < customers.size(); ++hour) {
            if (customers[hour] == 'Y') {
                currentScore++;
            } else {
                currentScore--;
            }

            if (currentScore > maxScore) {
                maxScore = currentScore;
                bestHour = hour;
            }
        }

        return bestHour + 1;  
    }
};
