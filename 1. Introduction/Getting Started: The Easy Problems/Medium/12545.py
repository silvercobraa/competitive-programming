C = int(input())
for c in range(C):
    S = list(input().strip())
    T = list(input().strip())
    S_zeros = S.count("0")
    S_ones = S.count("1")
    S_question = S.count("?")
    T_zeros = T.count("0")
    T_ones = T.count("1")
    T_question = T.count("?")
    # missing_ones = T_ones - S_ones
    missing_zeros = T_zeros - (S_zeros + S_question)
    ans = S_question # al menos tantas operaciones como unos haya que colocar
    # a menos que sea imposible
    if missing_zeros > 0:
        ans = -1
    else:
        # colocar unos donde se espere 1
        for i in range(len(S)):
            if S_ones == T_ones:
                break
            if S[i] == "?" and T[i] == "1":
                S[i] = "1"
                S_ones += 1
        # colocar los 1s restantes donde se pueda
        for i in range(len(S)):
            if S_ones == T_ones:
                break
            if S[i] == "?":
                S[i] = "1"
                S_ones += 1
        # Llenar con ceros los signos de pregunta faltantes
        for i in range(len(S)):
            if S[i] == "?":
                S[i] = "0"
                S_zeros += 1
        # reemplazar 0s por 1s
        for i in range(len(S)):
            if S_ones == T_ones:
                break
            if S[i] == "0" and T[i] == "1":
                S[i] = "1"
                S_ones += 1
                ans += 1

        different = sum(s != t for s, t in zip(S, T)) // 2
        ans += different

    print("Case %d: %d" % (c+1, ans))