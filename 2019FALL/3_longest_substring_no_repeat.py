class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if s == '':
            return 0
        table0 = 0b0  # ascii: 20-126
        table1 = 0b0
        max_len = 1  # max length of substring
        for cur1 in range(len(s)):  # two loops, the complexity would be O(N^2)
            cur_len = 1  # current length
            # ord: get ascii of a character
            table1 = table0 | (1 << (ord(s[cur1]) - 20))  # record the first letter in the table
            for cur2 in range(cur1 + 1, len(s)):
                #print('substring: {}'.format(s[cur1:cur2 + 1]))
                new_letter = (1 << (ord(s[cur2]) - 20))  # use a binary string to represent a letter: one digit is 1, the rest are 0.
                #print('new_letter: {}'.format(bin(new_letter)))
                if table1 & new_letter == 0:  # no '1's on the same place of the two binary strings: no conflict, no repeated letters
                    cur_len += 1
                    table1 = table1 | new_letter  # update
                    if cur_len > max_len:
                        max_len = cur_len  # update
                else:
                    break
        return max_len

# hint: hash table, two pointers, sliding window

if __name__ == '__main__':
    s = Solution()
    print(s.lengthOfLongestSubstring('pwwkew'))
