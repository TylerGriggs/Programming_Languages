// Tyler Griggs
// VCU CMSC 403 Assignment 8 Spring 2020

public class FoodBank {
	int food;
	
	FoodBank(){
		this.food = 0;
	}
	
	void giveFood(int donate){
		this.food += donate;
	}
	
	void takeFood(int donate){
		this.food -= donate;
	}
}


