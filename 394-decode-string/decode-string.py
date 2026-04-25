class Solution:
    def decodeString(self, s: str) -> str:
        stack=[]
        num=0
        cur=""

        for i in s:
            if i.isdigit():
                num=num*10+int(i)

            elif i=="[":
                stack.append((cur,num))
                num=0
                cur=""
            
            elif i=="]":
                p_cur,r=stack.pop()
                cur=p_cur + cur*r

            else:
                cur+=i
            
        return cur
            
            
