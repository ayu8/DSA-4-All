def largestAreaInHistogram(height):
    stack = [-1]
    maxArea = 0
    for i in range(len(height)):
        while stack[-1] != -1 and height[stack[-1]] >= height[i]:
            currentHeight = height[stack.pop()]
            currentWidth = i - stack[-1] - 1
            maxArea = max(maxArea, currentHeight * currentWidth)
        stack.append(i)
 
    while stack[-1] != -1:
        currentHeight = height[stack.pop()]
        currentWidth = len(height) - stack[-1] - 1
        maxArea = max(maxArea, currentHeight * currentWidth)
    return maxArea

height = [5, 6, 4, 3, 7, 5]
print("Maximum area is", largestAreaInHistogram(height))
