#include <iostream>
#include <cmath>  // double sin(double), double cos(double)
#include <fstream>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <iomanip>
#include <windows.h>


using namespace std;

// const for pi
const double pi = 3.14159265358979323846;

double calculateWindChill( double temp, double wind){
        double cal = 35.74 + 0.6215 * (temp) - 35.75 * (pow(wind,0.16)) + 0.4275* (temp) * (pow(wind, 0.16));
        return cal;
}

bool isPrime(int anyNum){
   if (anyNum<= 1) {
        return false; // Numbers less than or equal to 1 are not prime
    }
    if (anyNum == 2) {
        return true; // 2 is a prime number
    }
    if (anyNum % 2 == 0) {
        return false; // Eliminate even numbers greater than 2
    }
    for (int i = 3; i * i <= anyNum; i += 2) {
        if (anyNum% i == 0) {
            return false; // Check divisibility by odd numbers only
        }
    }
    return true;
}




int main() {
    cout << "###########" << endl;
    cout << "Problem One" << endl;
    cout << "###########" << endl;
   int number;

    cout << "Please enter a number: ";
    cin >> number;

    if (isPrime(number)) {

        Sleep (1500); // thinking...
        cout << number << " is a prime number." << endl;
    } else {

        Sleep (1500); // thinking...

        cout << number << " is not a prime number." <<endl;
    }






    cout << "====[ end ]====" << endl;
    
    Sleep (2000); // Delay to next problem




    cout << "###########" << endl;
    cout << "Problem Two" << endl;
    cout << "###########" << endl;
    // // For problem Two, you will need to write your code here
    // first read file robotpath.dat and name it thefile by using ifstream
    // make sure you use the full path to .dat file, e.g., .././src/robotpath.dat
    
    string file = "robotpath.dat"; // it works without using full path location
    ifstream thefile(file);
    //check if thefile exist or not
    if (!thefile) {
        cerr << "File not found!" << endl;
        return 1;
    }else {
        cout << "File is open and ready" << endl << endl;
        }
    


    // define your variables each line r and theta from the polar coordinates

    cout << fixed << setprecision(8);
    double r, theta;

    // use defined constant pi value in your calculation
    // start reading file and do calculation


    // while reading print the following for each line:
    //  - print distance and angle
    //  - print angle in radian, 1 degree is equal (pi/180degree)
    //  - print x and y location
    //  - check your conversion and print angle in rad after finding x and y with cartesian coordinates conversion
    // don't forget to close your opened file
     
     while (thefile >> r >> theta) {
       
        cout << "Distance : " << r << ", Angle : " << theta << endl; // Print distance and angle
        
        double thetaToRad = theta * (pi / 180.0); // Convert angle to radians
        cout << "Angle (theta in radians): " << thetaToRad << endl; 

        
        double Xs = r * cos(thetaToRad); //  x coordinate
        double Ys = r * sin(thetaToRad); //  y coordinate
        
       
        cout << "x: " << Xs << ", y: "  << Ys << endl; // Print location

        // Check the conversion
        double conversionCheck = atan2(Ys, Xs);
         // Get angle back in radians
        if (conversionCheck < 0) {
            conversionCheck += 2 * pi; //  [0, 2π] For negative angles
        }

        cout << "Checked angle: " << conversionCheck << endl;

        cout << "   " << endl;
        
    }

    thefile.close();



    

    cout << "================================[ end ]========================" << endl;
    
    
    
    Sleep (2000); // Delay to next problem




    cout << "###########" << endl;
    cout << "Problem Three" << endl;
    cout << "###########" << endl;
    

    // use Boolean CanRun to decide to do calculation or not based on condition
  
    bool canRun = true;
    // define your input value and other variable
    double result ,t ,w;
    
    cout << "Enter Temperature: " << endl;
    cin >> t;
    

    // print out message to enter wind speed and take the input
    // Check if speed meet condition
    if(t > 50 ){
        cout << "Temperature above 50 F can not be use to calculate " << endl;
        cout << "Please run program again" << endl;
        
        canRun = false;
        
        return 0;
    }
    

    // print out message to enter temperature and take the input
    // check if temperature  meet condition

    cout << "Enter wind speed: " << endl;
    cin >> w;
    
    if(w < 3){
        cout << "Wind speed below 3 can not be use to calculate" << endl;
        cout << "Please run program again" << endl;
        canRun = false;
        
        return 0;
    }
    
    

    // check if all condition is met and use canRun to start calculation of wind chill
    // print out the value
    if (canRun){

        cout << "Conditions are met, calculating the wind chill ... " << endl;
        Sleep (1500); // Thinking
        
        result = calculateWindChill(t,w);
        cout << fixed << setprecision(2);
        cout <<"Result: " << result << "F" << endl; 

    }
   


    
    cout << "====================================[ end ]=======================" << endl;

    return 0;
}
