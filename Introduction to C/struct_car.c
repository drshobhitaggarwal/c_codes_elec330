#include <stdio.h>
#include <string.h>
#include <stdbool.h> // For boolean type

// Define the Car structure
struct Car {
    char make[50];      // Manufacturer (e.g., Toyota, Ford)
    char model[50];     // Model name (e.g., Camry, Mustang)
    int year;           // Manufacturing year
    char color[20];     // Exterior color
    int mileage;        // Current mileage
    float engine_size; // Engine displacement (e.g., 2.0L, 3.5L)
    bool is_automatic; // Transmission type (true for automatic, false for manual)
    char vin[17];      // Vehicle Identification Number
};

// Function to print car information
void printCar(const struct Car *car) { // Takes a pointer to a const struct Car
    printf("Make: %s\n", car->make);
    printf("Model: %s\n", car->model);
    printf("Year: %d\n", car->year);
    printf("Color: %s\n", car->color);
    printf("Mileage: %d\n", car->mileage);
    printf("Engine Size: %.1f L\n", car->engine_size);
    printf("Transmission: %s\n", car->is_automatic ? "Automatic" : "Manual");
    printf("VIN: %s\n", car->vin);
    printf("\n");
}

int main() {
    // Declare and initialize a Car variable
    struct Car myCar = {
        .make = "Tesla",
        .model = "Model 3",
        .year = 2023,
        .color = "Red",
        .mileage = 15000,
        .engine_size = 0.0,
        .is_automatic = true,
        .vin = "ABC123XYZ7890DEFGH",
    };

    struct Car anotherCar;
    strcpy(anotherCar.make, "Toyota");
    strcpy(anotherCar.model, "Corolla");
    anotherCar.year = 2020;
    strcpy(anotherCar.color, "Blue");
    anotherCar.mileage = 50000;
    anotherCar.engine_size = 1.8;
    anotherCar.is_automatic = false;
    strcpy(anotherCar.vin, "GHI456JKL012MNOPQR");

    // Print the car information
    printf("My Car:\n");
    printCar(&myCar);

    printf("Another Car:\n");
    printCar(&anotherCar);

    // Array of Cars
    struct Car carLot[3];
    strcpy(carLot[0].make, "Ford");
    strcpy(carLot[0].model, "F-150");
    carLot[0].year = 2022;
    strcpy(carLot[0].color, "Black");
    carLot[0].mileage= 25000;
    carLot[0].engine_size = 5.0;
    carLot[0].is_automatic = true;
    strcpy(carLot[0].vin, "STU789VWX345ABCDEF");

    printf("Car from car lot:\n");
    printCar(&carLot[0]);

    return 0;
}