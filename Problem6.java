public class Problem6
{
    public static void main(String[] args){
        int sumTo100 = (100*101)/2, squaresSum = 0;
        for(int i = 0; i <= 100; i++)
            squaresSum += i*i;
        System.out.println(sumTo100 * sumTo100 - squaresSum);
    }
}
