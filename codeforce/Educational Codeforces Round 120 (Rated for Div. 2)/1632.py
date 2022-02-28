t = int(input());

for _ in range(t):
    n = int(input());
    s = input();

    if (n >= 3):
        print("NO");
    elif (n == 1):
        print("YES");
    elif (n== 2):
        if (s == "11" or s =="00"):
            print("NO");
        else:
            print("YES");
    