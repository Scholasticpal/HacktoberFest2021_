package throwDice;

/**
 * @author S.Dergunov sdergynov@gmail.com
 * <br>"Keep it simply stupid!"
 */
public class Dice {
 public int throwDice(){
   return (int)((Math.random() *6 ) + 1);
 }
}
