public class Problem4
{
    public static void main(String[] args){
        int maxPal = 0;
        for(int i = 100; i < 1000; i++){
                for(int j = 100; j < 1000; j++){
                    if(isPalindrome(i*j)){
                        if(i*j > maxPal)
                            maxPal = i*j;
                    }
                }
        }
        System.out.println(maxPal);
    }
    
    public static boolean isPalindrome(int num){
        int leftSide, rightSide;
        if(num >= 10000 && num < 100000){
            leftSide = (num / 1000);
            rightSide = (num % 100);
            rightSide = rightSide/10 + (rightSide%10)*10;
            return (rightSide == leftSide);
        }
        leftSide = (num / 1000);
        rightSide = (num % 1000);
        rightSide = rightSide/100 + ((rightSide/10)%10)*10 + (rightSide%100)*100;
        return(rightSide == leftSide);
    }
}
