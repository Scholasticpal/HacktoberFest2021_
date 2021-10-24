package throwDice;

public class Main {

    public static void main(String[] args) {
        boolean theSameDiceVolume = false;
        System.out.println("Let's play dice!");
        Dice firstDice = new Dice();
        Dice secondDice = new Dice();
        int firstDiceVolume;
        int secondDiceVolume;
        while (!theSameDiceVolume) {
            firstDiceVolume = firstDice.throwDice();
            secondDiceVolume = secondDice.throwDice();
            if (firstDiceVolume == secondDiceVolume) {
                theSameDiceVolume = true;
                System.out.println("Ups...! It's amassing!");
            }
            System.out.printf("Dices is %d:%d\n",
                    firstDiceVolume,
                    secondDiceVolume);
        }
    }
}
