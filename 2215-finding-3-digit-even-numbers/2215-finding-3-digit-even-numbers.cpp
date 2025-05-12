class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int freq[10] = {0};
        set<int>A;
        for(int i:digits)
        {
            freq[i]++;
        }
        for(int i=100;i<=999;i++)
        {
            if(i%2!=0)
            continue;
            int a = i/100;
            int b = (i/10)%10;
            int c = i%10;

            int tempo[10] = {0};
            tempo[a]++;
            tempo[b]++;
            tempo[c]++;

        
        bool flag = true;
        for(int i=0;i<10;i++)
        {
            if(freq[i]<tempo[i])
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            A.insert(i);
        }
        }

        return vector<int>(A.begin(),A.end());


    }
};