import java.lang.Math;
public class Problem9
{
    public static void main(String[] args){
        for(int i = 1; i < 1000; i++){
            for(int j = i; j < 1000; j++){
                if(i + j + Math.sqrt(i*i + j*j) == 1000)
                    System.out.println(i + "," + j + "," + Math.sqrt(i*i + j*j));
            }
        }
    }
}
