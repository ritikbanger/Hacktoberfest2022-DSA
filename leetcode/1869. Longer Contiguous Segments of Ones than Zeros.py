class Solution:
    def checkZeroOnes(self, s: str) -> bool:
        def check(num):
            return num=='1'
        def big(x,y):
            return x>y
        oc=0
        zc=0
        o=0
        z=0
        for x in s:
            if check(x):
                oc+=1
                if big(zc,z):z=zc
                zc=0
            else:
                zc+=1
                if big(oc,o):o=oc
                oc=0
        if big(zc,z):z=zc
        if big(oc,o):o=oc
        return big(o,z)
