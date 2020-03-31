try:
    while True:
        ca, ba, pa = list(map(int, input().split()))
        cr, br, pr = list(map(int, input().split()))
        print(max(cr-ca, 0)+max(br-ba, 0)+max(pr-pa, 0))
except:
    asdf = 0
