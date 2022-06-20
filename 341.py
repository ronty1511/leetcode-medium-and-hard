# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger:
#    def isInteger(self) -> bool:
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        """
#
#    def getInteger(self) -> int:
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        """
#
#    def getList(self) -> [NestedInteger]:
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        """

class NestedIterator:
    def __init__(self, nestedList: [NestedInteger]):
        self.flattenedList = []
        self.recurse(nestedList, self.flattenedList)
        self.cur_index = 0
        
    def recurse(self, nestedList, flattenedList):
        for elem in nestedList:
            if elem.isInteger():
                self.flattenedList.append(elem.getInteger())
            else:
                self.recurse(elem.getList(), flattenedList)
    
    def next(self) -> int:
        val = self.flattenedList[self.cur_index]
        self.cur_index += 1
        return val
    
    def hasNext(self) -> bool:
         return self.cur_index < len(self.flattenedList)

# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())