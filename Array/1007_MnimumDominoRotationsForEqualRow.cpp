//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-11-07.
//

#include <vector>

using std::vector;

int minDominoRotations(vector<int>& A, vector<int>& B)
{
    vector<int> targets{A[0], B[0]};
    int res = INT_MAX;
    for(const auto & target : targets){
        int aToB = 0, bToA = 0;
        bool success = true;
        for(int i = 0; i < A.size(); i++){
            if(target != A[i] && target != B[i]){
                success = false;
                break;
            }
            if(target != A[i] && target == B[i]) bToA++;
            if(target == A[i] && target != B[i]) aToB++;
        }
        if(success) res = std::min(res, std::min(bToA, aToB));
    }
    return res==INT_MAX ? -1 : res;

}

