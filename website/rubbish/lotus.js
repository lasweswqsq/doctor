public class Operator{
    public static void main(String args[]) {
        for(int i = 100;i<1000;i++){
            int ge = i%10;  //一个三位数取余10就是该三位数的个位。
            int shi = i/10%10; //一个三位数除10就是该三位数的百位和十位组成的两位数
                               //然后再%10则是该三位数的十位
            int bai = i/100;   //一个三位数/100则是该三位数的百位
            if(ge*ge*ge+bai*bai*bai+shi*shi*shi==i)
                System.out.println(i+"是水仙花数！！！");
        }
    }
}