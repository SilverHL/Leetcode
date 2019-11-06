//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-11-06.
//

using std::vector;

class RLEIterator {
public:
    RLEIterator(vector<int>& A) : A_(A) {
    }

    int next(int n) {
        while (pos < A_.size() && n > 0) {
            if (A_[pos] >= n) {
                A_[pos] -= n;
                n = 0;
            } else {
                n -= A_[pos];
                A_[pos] = 0;
                pos += 2;
            }
        }
        if (pos >= A_.size() - 1)
            return -1;
        return A_[pos + 1];
    }

    int nxt(int n) {
        while (pos < A_.size() && n > 0) {
            if (A_[pos] > n) {
                A_[pos] -= n;
                n = 0;
            } else {
                n -= A_[pos];
                A_[pos] = 0;
                pos += 2;
            }
        }

        if (pos > A_.size())
            return -1;
        return A_[pos+1];
    }
private:
    vector<int> A_;
    int pos;

};

