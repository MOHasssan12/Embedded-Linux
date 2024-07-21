class Solution {
public:
  int largestAltitude(vector<int> &gain) {
    int leng = gain.size();
    int max = 0;
    int curr = 0;

    for (int i = 0; i < leng; ++i) {
      curr += gain[i];
      if (curr > max) {
        max = curr;
      }
    }
    return max;
  }
};