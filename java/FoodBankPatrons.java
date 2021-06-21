// Tyler Griggs
// VCU CMSC 403 Assignment 8 Spring 2020

public class FoodBankPatrons {
	public static void main(String args[]) 
    { 
		FoodBank theBank = new FoodBank();
		FoodProducer produce = new FoodProducer(theBank);
		FoodConsumer consume = new FoodConsumer(theBank);
		
		produce.start();
		consume.start();
		
    }
}
