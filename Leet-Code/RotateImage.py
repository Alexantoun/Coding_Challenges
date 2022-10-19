class Solution:   
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """        
        n = len(matrix[0])             
        # Transpose the matrix 
        for row in range(0, n):
            for col in range(row,n):
                temp = matrix[col][row]
                matrix[col][row] = matrix[row][col]
                matrix[row][col] = temp

        # This is the index to reach before stopping
        halfN = int(n/2) - 1 
        for row in range(0, n): #Swap right most point and left most point, then move limits in by one
            righty = n - 1 
            lefty = 0
            while righty > halfN: 
                temp = matrix[row][lefty]
                matrix[row][lefty] = matrix[row][righty]
                matrix[row][righty] = temp
                lefty = lefty + 1
                righty = righty - 1
           