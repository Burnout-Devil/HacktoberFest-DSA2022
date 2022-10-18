import java.util.Scanner;

public class Calculator{
  public class void main(String[] args)
  {
    double num1,num2;
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter First Number");
    num1 = sc.nextDouble();
    System.out.print("Enter Second Number");
    num2 = sc.nextDouble();
    System.out.print("Pick An Operation ( + , - , / , * ) :");
    char op = sc.next.charAt(0);
    
    double output;
    sc.close();
    
    switch(operator)
    {
      case '+':
        output = num1 + num2;
        break;
      
      case '-':
        output = num1 - num2;
        break;
        
      case '/':
        output = num1 / num2;
        break;
        
      case '*':
        output = num1 * num2;
        break;
        
      default:
        System.out.print("Wrong Inputs");
        return;
    }
    System.out.println(num1+" "+operator+" "+num2+":"+output);
  }
}


    
