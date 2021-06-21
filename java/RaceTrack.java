// Tyler Griggs
// VCU CMSC 403 Assignment 8 Spring 2020 ('Rona)
//
// Four (4) Images files are required to show the race in vivid detail:
//      car1.png, car2.png, car3.png, finishLine.png
// CHANGE THE GLOBAL VARIABLE race_distance TO SEE THE GUI SCALE TO THE RACE
//      Default for Assignment8; race_distance = 400, for required 500 pixel width

import javafx.application.Application;
import javafx.application.Platform;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.shape.Rectangle;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.stage.Stage;
import javafx.scene.control.Button;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.paint.Color;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Random;

// When this class' main() method is run, a GUI is created displaying three cars, with a track of 'race_distance'
public class RaceTrack extends Application {

    // GUI Objects
    private ImageView carRed;
    private ImageView carBlue;
    private ImageView carGreen;
    private ImageView finish_line;
    private Thread threadRed1;
    private Thread threadBlue2;
    private Thread threadGreen3;

    // Game Status
    private boolean active = false;
    private boolean finished = false;
    private int race_distance = 400; // CHANGE THE RACE DISTANCE TO SEE THE GUI SCALE TO THE RACE

    // Winner of the Race generates an alert box with information
    Alert winner = new Alert(AlertType.INFORMATION);


    @Override
    public void start(Stage view) throws FileNotFoundException {

        // Load in PNG images for scene
        Image car1 = new Image(new FileInputStream("C:\\Users\\Tyler\\Documents\\GitHub\\CMSC_403\\car1.png"));
        Image car2 = new Image(new FileInputStream("C:\\Users\\Tyler\\Documents\\GitHub\\CMSC_403\\car2.png"));
        Image car3 = new Image(new FileInputStream("C:\\Users\\Tyler\\Documents\\GitHub\\CMSC_403\\car3.png"));
        Image finishLinePic = new Image(new FileInputStream("C:\\Users\\Tyler\\Documents\\GitHub\\CMSC_403\\finishLine.png"));


        // Initialize static track objects, draw rectangle (PositionX, PositionY, Width, Height)
        // Assign a color to the rectangle object
        Rectangle track1 = new Rectangle(50, 80, race_distance, 12);
        track1.setFill(Color.LIGHTGRAY);

        Rectangle track2 = new Rectangle(50, 120, race_distance, 12);
        track2.setFill(Color.LIGHTGRAY);

        Rectangle track3 = new Rectangle(50, 160, race_distance, 12);
        track3.setFill(Color.LIGHTGRAY);


        // Assign the global objects the PNG image for it
        // Assign the ImageView a position in the GUI
        carRed = new ImageView(car1);
        carRed.relocate(18, 70);

        carBlue = new ImageView(car2);
        carBlue.relocate(18, 110);

        carGreen = new ImageView(car3);
        carGreen.relocate(18, 150);

        finish_line = new ImageView(finishLinePic);
        finish_line.relocate(race_distance+53, 78);


        // Initialize Start, Pause, Reset Buttons
        // Assign a preferred size for the button
        // Assign the button a position in the GUI
        Button start = new Button("Start");
        start.setPrefSize(80, 30);
        start.relocate(20+(2*(race_distance/9)), 15);

        Button pause = new Button("Pause");
        pause.setPrefSize(80, 30);
        pause.relocate(40+(4*(race_distance/9)), 15);

        Button reset = new Button("Reset");
        reset.setPrefSize(80, 30);
        reset.relocate(60+(6*(race_distance/9)), 15);


        // When the START Button is pressed
        start.setOnAction((event) -> {
            // Race is running, do nothing
            if(active) {
                return;
            }
            // Set start of race to true
            active = true;
            // Begin Race
            start();
        });

        // When the PAUSE Button is pressed
        pause.setOnAction((event) -> {
            // Race is running, stop it from continuing
            if(active) {
                active = false;
            }
            // Do nothing if Race is not running
        });

        // When the RESET Button is pressed
        reset.setOnAction((event) -> {
            // Function call to reset all Race variables
            reset();
        });

        // Attach all the objects into one layer, with background objects first
        Group parent = new Group(finish_line,track1,track2,track3,carRed,carBlue,carGreen,start,pause,reset);

        // Assign GUI size and background color
        Scene root = new Scene(parent,race_distance+100,200 );
        root.setFill(Color.DARKGREY);

        // Set attributes for the GUI's final appearance
        view.setTitle("Richmond Raceway");
        view.setScene(root);
        view.setResizable(false);
        view.show();
    }

    // When REST button is clicked, Assigns all Race variables and objects to starting positions and values
    private void reset() {
        active = false;
        finished = false;
        carRed.setX(0);
        carBlue.setX(0);
        carGreen.setX(0);
    }

    // When START button is clicked, Thread objects are created to concurrently execute the move() loop
    private void start (){

        threadRed1 = new Thread(()->move(carRed, 1, threadRed1));
        threadBlue2 = new Thread(()->move(carBlue, 2, threadBlue2));
        threadGreen3 = new Thread(()->move(carGreen, 3, threadGreen3));

        // Check if the current Race has already finished
        if (!finished){
            // Start the Threads to begin the race
            threadRed1.start();
            threadBlue2.start();
            threadGreen3.start();
        }
    }

    // When called this method uses a passed Thread object to loop through generating a random number 1-10, and moving
    //      a passed ImageView car object that many pixels in the GUI. A passed integer identifies the track
    //      number the car is racing on, so that a winner can be determined at the end of a race.
    private void move (ImageView car,  int trackNum, Thread currentThread){
        // Create Random object
        Random r = new Random();

        // Loop
        while (true && active){

            // Generate Random number 1-10
            int randomNum = r.nextInt(10) + 1;

            // Move car on track, Update GUI from Thread using lambda runLater
            Platform.runLater(() -> car.setX(car.getX() + randomNum));

            // Sleep Thread for 50 milliseconds
            try {
                currentThread.sleep(50);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            // Check if the Thread/Car has reached or exceeded the race distance
            if (car.getX() >= race_distance) {
                active = false;
                // Update GUI from Thread using runLater(lambda)
                Platform.runLater(() -> finished(trackNum));
            }
        }
    }

    // When a car has reached or exceed the race_distance, this method is called
    private void finished(int trackNumber){
        // End the Race
        finished = true;

        // Initialize Output String
        String color;

        // Assign correct identity information
        if (trackNumber == 1){
            color = "Red";
        } else if (trackNumber == 2){
            color = "Blue";
        } else if (trackNumber == 3){
            color = "Green";
        } else {
            color = "Best";
        }

        // Assign the Alert Object an output String, and show to the USER
        winner.setContentText("The " + color + " Car Won!");
        winner.show();
    }

    // Main()
    public static void main(String[] args) {
        //Start Application
        launch();
    }
}
