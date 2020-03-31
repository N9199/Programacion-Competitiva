from sys import stderr


def isPalindrome(s: str):
    print("Palindrome? ", s, file=stderr)
    for i in range(len(s)//2):
        if s[i] != s[len(s) - 1 - i]:
            return False
    return True


t = int(input())
for _ in range(t):
    s = input().strip()
    i, j = 1, len(s)-1
    while isPalindrome(s[:i] + s[j:]) and i < j:
        i += 1
        j -= 1
    i -= 1
    j += 1

    if i == j:
        print(s)
    else:
        k = 0
        ans = ""
        for k in range(j-i):
            if isPalindrome(s[:i+k]+s[j:]) and len(ans) < len(s[:i+k]+s[j:]):
                ans = s[:i+k]+s[j:]

        for k in range(j-i):
            if isPalindrome(s[:i]+s[j-k:]) and len(ans) < len(s[:i]+s[j-k:]):
                ans = s[:i] + s[j - k:]

        for k in range(len(s)):
            if isPalindrome(s[:k]) and len(ans) < len(s[:k]):
                ans = s[:k]

        for k in range(len(s)):
            if isPalindrome(s[k:]) and len(ans) < len(s[k:]):
                ans = s[k:]

        print(ans)
