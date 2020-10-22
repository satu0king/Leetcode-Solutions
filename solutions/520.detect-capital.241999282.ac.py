class Solution(object):
    def detectCapitalUse(self, word):
        """
        :type word: str
        :rtype: bool
        """
        return word.upper() == word or word.lower() == word or word[1:].lower() == word[1:]
