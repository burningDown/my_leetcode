class Vector2D:

    def __init__(self, v: List[List[int]]):
        self.memberList = v
        self.point = [0,0]


    def next(self) -> int:
        if len(self.memberList) > 0:
            if self.point[0] < len(self.memberList):
                if self.point[1] < len(self.memberList[self.point[0]]):
                    temp = self.memberList[self.point[0]][self.point[1]]
                    self.point[1] += 1
                    return temp
                else:
                    self.point[1] = 0
                    self.point[0] += 1
                    return self.next()
            else:
                return None
        else:
            return None

    def hasNext(self) -> bool:
        local_point = self.point.copy()
        while(True):
            if len(self.memberList) > 0:
                if local_point[0] < len(self.memberList):
                    if local_point[1] < len(self.memberList[local_point[0]]):
                        return True
                    else:
                        local_point[1] = 0
                        local_point[0] += 1
                else:
                    return False
            else:
                return False



# Your Vector2D object will be instantiated and called as such:
# obj = Vector2D(v)
# param_1 = obj.next()
# param_2 = obj.hasNext()