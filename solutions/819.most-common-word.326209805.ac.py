class Solution(object):
    def mostCommonWord(self, paragraph, banned):
        banset = set(banned)
        paragraph = paragraph.replace(",", " ")
        count = collections.Counter(
            word.strip("!?',;.") for word in paragraph.lower().split())

        ans, best = '', 0
        for word in count:
            if count[word] > best and word not in banset:
                ans, best = word, count[word]

        return ans
