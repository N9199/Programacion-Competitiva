from datetime import date, timedelta
import sys

D = date(day=1, month=1, year=1901)
c = 0
while D.year <= 2000:
    print(D, file=sys.stderr)
    if D.day == 1 and D.isoweekday() == 7:
        c = c+1
    D = D + timedelta(days=1)

print(c)
