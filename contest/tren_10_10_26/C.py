from datetime import datetime, timedelta
from math import ceil

n = int(input())
tr = {}
for i in range(n):
    x = input().rsplit(maxsplit=2)
    t1 = datetime.strptime(x[1], "%H:%M")
    t2 = datetime.strptime(x[2], "%H:%M")
    delta = t2 - t1

    if delta.total_seconds() <= 0:
        delta += timedelta(days=1)
        
    tr[x[0]] = delta

min_key = min(tr, key=tr.get)
print(f'The fastest train is {min_key}.')
print(f'Its speed is {round(650 / tr[min_key].total_seconds() * 3600)} km/h, approximately.')