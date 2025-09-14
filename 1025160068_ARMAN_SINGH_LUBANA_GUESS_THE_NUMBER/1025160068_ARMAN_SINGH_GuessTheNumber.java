import java.util.Scanner;
import java.util.Random;
public class GUESS
{
 public static void main(String[] args)
 {
  Random rn = new Random();
  Scanner sc = new Scanner(System.in);
  int guess,attempt=0,number_chosen=0;
  guess = rn.nextInt(100)+1;
  System.out.println("-------------------------------------------------------------------");
  System.out.println("             WELCOME TO GUESS THE NUMBER GAME !!!!!!!");
  System.out.println("-------------------------------------------------------------------");
  System.out.println("A NUMBER HAVE BEEN CHOSEN BETWEEN 1 TO 100 ");
  System.out.println("CAN YOU GUESS THE NUMBER ?");
  while(guess!=number_chosen)
  {
   attempt++;
   System.out.println("GUESS A NUMBER");
   number_chosen=sc.nextInt();
   if(number_chosen<guess)
   {
    System.out.println("TOO FAR AWAY !!! TRY AGAIN!!");
   }
   else if(number_chosen>guess)
   {
    System.out.println("TOO HIGH !!! TRY AGAIN!!");
   }
   else
   {
    System.out.println("YES YOU DID IT !!!");
    System.out.println("NUMBER GUESSED WAS :- "+guess);
    System.out.println("YOU DID IT IN "+attempt+" attempts");
   }
  }
 }
}