def search_social_tree(social_tree, target_r, oracle, path = []):
    final_path = []
    for k, v in social_tree.items():
        path1 = path + [k]
        while type(v) == dict: