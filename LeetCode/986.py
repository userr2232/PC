class Solution(object):
    def intervalIntersection(self, firstList, secondList):
        """
        :type firstList: List[List[int]]
        :type secondList: List[List[int]]
        :rtype: List[List[int]]
        """
        def intersect(i1, i2):
            start_1, end_1 = i1
            start_2, end_2 = i2
            if end_1 < start_2 or end_2 < start_1:
                return -1, -1
            return max(start_1, start_2), min(end_1, end_2)
        answer = []
        i, j = 0, 0
        while i < len(firstList) and j < len(secondList):
            first_interval = firstList[i]
            second_interval = secondList[j]
            intersection = intersect(first_interval, second_interval)
            if first_interval[1] < second_interval[1]:
                i += 1
            elif second_interval[1] < first_interval[1]:
                j += 1
            else:
                i += 1
                j += 1
            if intersection != (-1, -1):
                answer.append(intersection)
        return answer