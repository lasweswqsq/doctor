def oracle(path:list):
    return ord(path[-1][0]) - ord('A') + 1


def check(search_social_tree):
    social_tree = {
   "Alice": {
       "Daniel": {
           "Henry": {},
           "Ives": {}
       },
       "Emily": {}
   },
   "Bob": {
       "Frank": {
           "Jack": {},
       },
       "Grace": {}
   },
   "Charlotte": {}
    }

    input_data = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    output_data = ["!", "Alice", "Bob", "Charlotte", "Daniel", "Emily", "Frank", "Grace", "Henry", "Ives", "Jack"]

    for j in range(11):
        res = search_social_tree(social_tree, input_data[j], oracle)
        ans = output_data[j]
        if res != ans:
            print("Wrong Anser. r = %d, ans = %s, but your answer is %s" % (input_data[j], output_data[j], res))
            return
    print("Accepted.")

