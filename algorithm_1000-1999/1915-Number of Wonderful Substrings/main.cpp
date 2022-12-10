class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n = word.size();

        unordered_map<int, int> cnts;
        cnts[0] = 1;

        long long ret = 0;
        for (int state = 0, i = 0; i < n; ++i) {
            state ^= (1 << (word[i] - 'a'));

            // all letter appear an even number of times.
            ret += cnts[state];

            // one letter appear an odd number of times.
            for (int j = 0; j < 10; ++j) {
                ret += cnts[state ^ (1<<j)];
            }

            ++cnts[state];
        }

        return ret;
    }
};

/*
assume we have only 4 letters: a b c d

state of a string: the parity of the number of each letter. represented in binary form. Odd: 1, even: 0
"abbaca"
a: 3, odd = > 1
b: 2, even => 0
c: 1, odd = > 1
d: 0, odd = > 0
=> 1010
   abcd

assume we are looking for the number of substring containing s[i] where each letter appears an even number of times.
s: X X X X X X X X
         j       i
=> j exists such that state[i] == state[j]

assume we are looking for the number of substring containing s[i] where only letter 'c' appears an odd number of times and the rest letters appears an even number of times.
s: X X X X X X X X
         j       i
=> index 2 of state is the parity of number of 'c'
=>j exists such that (state[i] ^ 1 << 2) == state[j]

[a b c d e f g h i j], size: 10
*/
