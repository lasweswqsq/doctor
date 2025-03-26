def main():
    import sys
    input = sys.stdin.read().split()
    ptr = 0
    n = int(input[ptr])
    ptr += 1
    Q = int(input[ptr])
    ptr += 1
    s = list(map(int, input[ptr:ptr+n]))
    ptr += n
    s = [0] + s  # 1-based indexing
    p = list(range(n + 1))  # p[i] = i initially
    
    for _ in range(Q):
        x_j = int(input[ptr])
        ptr += 1
        y_j = int(input[ptr])
        ptr += 1
        p[x_j] = y_j
        s_current = s[x_j]
        visited = [False] * (n + 1)
        current_node = x_j
        i = 1
        while True:
            next_node = p[current_node]
            if next_node == current_node or visited[next_node]:
                break
            visited[next_node] = True
            k = i % 32
            # Calculate cyclic shift left by k positions
            shifted_s = ((s_current << k) | (s_current >> (32 - k))) & 0xFFFFFFFF
            # Update the singularity value
            s[next_node] = (s[next_node] ^ shifted_s) & 0xFFFFFFFF
            current_node = next_node
            i += 1
    
    # Find the minimum s_x and the smallest index
    min_s = s[1]
    min_x = 1
    for x in range(2, n + 1):
        if s[x] < min_s or (s[x] == min_s and x < min_x):
            min_s = s[x]
            min_x = x
    print(min_x)
    print(min_s)

if __name__ == "__main__":
    main()