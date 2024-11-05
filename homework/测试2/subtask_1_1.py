def oracle(path:list):
    return 1


def check(search_social_tree):
    social_tree = {}

    input_data = [0, 1]
    output_data = ["!", "!"]

    for j in range(2):
        res = search_social_tree(social_tree, input_data[j], oracle)
        ans = output_data[j]
        if res != ans:
            print("Wrong Anser. r = %d, ans = %s, but your answer is %s" % (input_data[j], output_data[j], res))
            return
    print("Accepted.")