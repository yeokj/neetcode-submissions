class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        row, col = len(matrix), len(matrix[0])
        left, right = 0, (row * col) - 1

        while left <= right:
            mid = left + (right - left) // 2
            r, c = mid // col, mid % col
            val = matrix[r][c]

            if val < target:
                left = mid + 1
            elif val > target:
                right = mid - 1
            else:
                return True
        
        return False