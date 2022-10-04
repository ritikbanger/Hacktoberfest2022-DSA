contract Armstrong{
    function checkArm(uint256 n) public pure returns (uint256){
        uint256 c=0;
        uint256 a;
        uint256 s;
        a=n;
        while(a>0){
            c=c+1;
            a/=10;
        }
        a=n;
        while(a>0){
            s=s+((a%10)**c);
            a/=10;
        }
        if(s==n){
            return 1;
        } else {
            return 0;
        }
    }
}