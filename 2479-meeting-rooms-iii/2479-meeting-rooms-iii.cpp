class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<long long> A(n, 0);
        vector<int> B(n, 0);
        sort(meetings.begin(), meetings.end());

        for (auto& i: meetings) {
            int start = i[0], end = i[1];
            long long minRoomAvailabilityTime = LLONG_MAX;
            int minAvailableTimeRoom = 0;
            bool foundUnusedRoom = false;

            for (int i = 0; i < n; i++) {
                if (A[i] <= start) {
                    foundUnusedRoom = true;
                    B[i]++;
                    A[i] = end;
                    break;
                }

                if (minRoomAvailabilityTime > A[i]) {
                    minRoomAvailabilityTime = A[i];
                    minAvailableTimeRoom = i;
                }
            }

            if (!foundUnusedRoom) {
                A[minAvailableTimeRoom] += end - start;
                B[minAvailableTimeRoom]++;
            }
        }
        int maxMeetingCount = 0, maxi = 0;
        for (int i = 0; i < n; i++) {
            if (B[i] > maxMeetingCount) {
                maxMeetingCount = B[i];
                maxi = i;
            }
        }
        return maxi;
    }
};