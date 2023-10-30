
class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split()
        if len(pattern) != len(words):
            return False

        pattern_to_word = {}
        word_to_pattern = {}

        for i in range(len(pattern)):
            if pattern[i] in pattern_to_word:
                if pattern_to_word[pattern[i]] != words[i]:
                    return False
            else:
                pattern_to_word[pattern[i]] = words[i]

            if words[i] in word_to_pattern:
                if word_to_pattern[words[i]] != pattern[i]:
                    return False
            else:
                word_to_pattern[words[i]] = pattern[i]
        return True

# class Solution:
#     def wordPattern(self, pattern: str, s: str) -> bool:
#         z = list(zip(s.split(), list(pattern)))
#         if  len(pattern) == len(s.split()) and len(set(z)) == len(set(s.split())) and len(set(z)) == len(set(pattern)):
#             return True
#         else:
#             return False


# class Solution:
    # def wordPattern(self, pattern: str, s: str) -> bool:
    #         s = s.split()
    #         return (len(set(pattern)) ==
    #                 len(set(s)) ==
    #                 len(set(zip_longest(pattern,s))))              