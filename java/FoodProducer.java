// Tyler Griggs
// VCU CMSC 403 Assignment 8 Spring 2020

import java.util.Random;

public class FoodProducer extends Thread{
	FoodBank bank;
	
	FoodProducer(FoodBank b){
		this.bank = b;
	}
	
	@Override
	public void run() {
		Random r = new Random();
		while(true) {
			// The object 'bank's monitor is invoked to ensure singular access
			synchronized(this.bank) {
				int randomNum = r.nextInt(100) + 1;
				synchronized(this) {
					bank.giveFood(randomNum);
					System.out.println("Giving " + randomNum + " units of food, the balance is now " + this.bank.food + " units.");
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
