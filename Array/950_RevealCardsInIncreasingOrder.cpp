//
// Created by neojxwang(Íõ¾¸ìÓ) on 2019-09-02.
//
#include <vector>
#include <deque>

using namespace std;

vector<int> deckRevealedIncreasing(vector<int>& deck)
{
    if (deck.empty())
        return {};
    sort(deck.begin(), deck.end());
    deque<int> deq;

    for (int i = deck.size()-1; i >= 0; --i)
    {
        if (deq.empty())
            deq.push_back(deck[i]);
        else
        {
            deq.push_front(deq.back());
            deq.pop_back();
            deq.push_front(deck[i]);
        }
    }

    return vector<int>(deq.begin(), deq.end());
}

