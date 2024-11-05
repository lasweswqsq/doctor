def oracle(path: list):
    return int(''.join(path))

def check(search_social_tree):
    social_tree = {
        "1": {
            "2": {
            "3": {
                    "6": {}
            },
            "4": {}
            },
        },
        "5": {}
    }


    input_data = [0, 1, 12, 123, 124, 1236, 5]
    output_data = ["!", "1", "2", "3", "4", "6", "5"]

    for j in range(7):
        res = search_social_tree(social_tree, input_data[j], oracle)
        ans = output_data[j]
        if res != ans:
            print("Wrong Anser. r = %d, ans = %s, but your answer is %s" % (input_data[j], output_data[j], res))
            return
    print("Accepted.")