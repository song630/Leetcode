'''
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
'''
class ListNode:
    def __init__(self, x):
        self.val = x  # could be 0
        self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        cur1, cur2 = l1, l2
        l3 = ListNode(0)
        cur3 = l3
        carry = 0
        if cur1 == None and cur2 == None:
            return None
        while cur1 != None and cur2 != None:
            new_val = cur1.val + cur2.val + carry  # add two digits
            if new_val >= 10:  # carry
                carry = 1
                new_val = new_val % 10  # convert a int to digit
            else:  # no carry
                carry = 0
            cur1, cur2 = cur1.next, cur2.next  # move on
            cur3.next = ListNode(new_val)
            cur3 = cur3.next
        l3 = l3.next  # discard the first node
        # discuss in cases:
        # 1. cur1 != None, cur2 == None:
        while cur1 != None:  # continue to traverse l1
            new_val = cur1.val + carry
            if new_val >= 10:  # carry
                carry = 1
                new_val = new_val % 10  # convert a int to digit
            else:  # no carry
                carry = 0
            cur3.next = ListNode(new_val)
            cur3 = cur3.next
            cur1 = cur1.next
            print('111')
        # 2. cur1 == None, cur2 != None:
        while cur2 != None:  # continue to traverse l1
            new_val = cur2.val + carry
            if new_val >= 10:  # carry
                carry = 1
                new_val = new_val % 10  # convert a int to digit
            else:  # no carry
                carry = 0
            cur3.next = ListNode(new_val)
            cur3 = cur3.next
            cur2 = cur2.next
        # now both cur1 and cur2 have reached the ends:
        if carry == 1:
            cur3.next = ListNode(1)
            cur3 = cur3.next
        return l3

''' SUMMARY:
1. difficuties: cases.
2. trick 1: it's hard to create a linked list from a list using a loop, so discard the first node, save data from the second one.
3. trick 2: two difficult cases: (1) carry = 1; (2) carry = 1 and val = 9. solution: put the case carry == 1 in the end.
'''

def createList(l: list) -> ListNode:
    if l is []:
        return None
    res = ListNode(0)
    cur = res
    for i in l:
        cur.next = ListNode(i)
        cur = cur.next
    res = res.next  # discard the first node
    return res

if __name__ == '__main__':
    L1 = [1, 8]
    L2 = [0]
    input1 = createList(L1)
    input2 = createList(L2)
    s = Solution()
    result = s.addTwoNumbers(input1, input2)
    while result != None:
        print(result.val, end='')
        result = result.next
