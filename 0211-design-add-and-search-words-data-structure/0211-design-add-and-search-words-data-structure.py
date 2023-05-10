class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_word = False

class WordDictionary:

    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        curr = self.root
        for char in word:
            if char not in curr.children:
                curr.children[char] = TrieNode()
            curr = curr.children[char]
        curr.is_word = True

    def search(self, word: str) -> bool:
        return self._search(self.root, word)
    
    def _search(self, node, word):
        if not word:
            return node.is_word
        
        if word[0] == '.':
            for child in node.children.values():
                if self._search(child, word[1:]):
                    return True
            return False
        else:
            if word[0] in node.children:
                return self._search(node.children[word[0]], word[1:])
            return False
