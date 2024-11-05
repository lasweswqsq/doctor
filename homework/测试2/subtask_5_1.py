def oracle(path:list):
    return 0


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

    input_data = [0, 1]
    output_data = [{"Alice", "Bob", "Charlotte", "Daniel", "Emily", "Frank", "Grace", "Henry", "Ives", "Jack"}, {"!"}]

    for j in range(2):
        res = search_social_tree(social_tree, input_data[j], oracle)
        if not res in output_data[j]:
            print("Wrong Anser. r = %d, ans = %s, but your answer is %s" % (input_data[j], output_data[j], res))
            return
    print("Accepted.")

