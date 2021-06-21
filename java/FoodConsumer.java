// Tyler Griggs
// VCU CMSC 403 Assignment 8 Spring 2020

import java.util.Random;

public class FoodConsumer extends Thread{
	FoodBank bank;
	
	FoodConsumer(FoodBank b){
		this.bank = b;
	}
	
	@Override
	public void run() {
		Random r = new Random();
		while(true) {
			// The object 'bank's monitor is invoked to ensure singular access
			synchronized(this.bank) {
				int randomNum = r.nextInt(100) + 1;
				int current = bank.food;
				
				if(randomNum > current) {
					bank.takeFood(current);
					System.out.println("Couldn't take " + randomNum + " units, but managed to get " + current + " units of food. The balance is now " + this.bank.food + " units.");
								
				} else {
					bank.takeFood(randomNum);
					System.out.println("Taking " + randomNum + " units of food, the balance is now " + this.bank.food + " units.");
				}
			}
			
			// Wait for 100 milliseconds
			try {
				Thread.sleep(100);
			} catch (InterruptedException e) {
				System.out.println(e);
			}
			
		}
	}
}
