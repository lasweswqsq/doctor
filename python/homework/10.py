def search_social_tree(social_tree, target_r, oracle, path=None):
    flag_nonePath = False
    if path is None:
        path = []
        flag_nonePath = True
    
    class LinkedListNode:
        def __init__(this):
            this.previous = None
            this.name = None
            this.next = None
    
    class LinkedList:
        def __init__(this):
            this.head = LinkedListNode()
            this.end = LinkedListNode()
        
        def push(this, name: str):
            this.end.name = name
            this.end.next = LinkedListNode()
            this.end.next.previous = this.end
            this.end = this.end.next
        
        def pop(this):
            this.end = this.end.previous
            this.end.next = None
        
        def toList(this, target=None):
            node = this.head
            result = [] if target is None else target
            while node.next is not None:
                result.append(node.name)
                node = node.next
            return result
    
    link = LinkedList()
    
    def thisSearch(tree) -> bool:
        for k, v in tree.items():
            link.push(k)
            if oracle(link.toList()) == target_r or thisSearch(v):
                return True
            link.pop()
        return False
    
    thisSearch(social_tree)
    link.toList(path)
    if len(path) != 0:
        return path[-1]
    else:
        return "!"
    # form the current social path (add k to current path)
    # check if it satisfies oracle, if so, return something
    # otherwise , search the elements in v (recursion)
    # if find a solution in v, return something
    
    # return something after iteration

