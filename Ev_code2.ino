#include <stdio.h>
#include <stdbool.h>
#include <unistd.h> // For sleep function

// Define charging states
typedef enum {
    CHARGING_IDLE,
    CHARGING_IN_PROGRESS,
    CHARGING_COMPLETE,
    CHARGING_ERROR
} ChargingState;

// Function prototypes
void startCharging();
void stopCharging();
void monitorCharging();
void simulateChargingProcess();
void reportChargingStatus(ChargingState state);

// Global variable to hold the current charging state
ChargingState currentChargingState = CHARGING_IDLE;

int main() {
    // Start the charging process
    startCharging();

    // Monitor the charging status
    monitorCharging();

    // Stop the charging process
    stopCharging();

    return 0;
}

void startCharging() {
    if (currentChargingState == CHARGING_IDLE) {
        printf("Starting wireless charging...\n");
        currentChargingState = CHARGING_IN_PROGRESS;
        simulateChargingProcess();
    } else {
        printf("Charging is already in progress or completed.\n");
    }
}

void stopCharging() {
    if (currentChargingState == CHARGING_IN_PROGRESS) {
        printf("Stopping wireless charging...\n");
        currentChargingState = CHARGING_IDLE;
    } else {
        printf("Charging is not in progress.\n");
    }
}

void monitorCharging() {
    while (currentChargingState == CHARGING_IN_PROGRESS) {
        // Simulate monitoring the charging status
        sleep(1); // Wait for 1 second
        reportChargingStatus(currentChargingState);
    }
}

void simulateChargingProcess() {
    // Simulate a charging process with a simple loop
    for (int i = 0; i < 5; i++) { // Simulate 5 seconds of charging
        sleep(1); // Wait for 1 second
        printf("Charging... %d seconds elapsed.\n", i + 1);
    }
    // Simulate charging complete
    currentChargingState = CHARGING_COMPLETE;
    printf("Charging complete!\n");
}

void reportChargingStatus(ChargingState state) {
    switch (state) {
        case CHARGING_IDLE:
            printf("Charging Status: Idle\n");
            break;
        case CHARGING_IN_PROGRESS:
            printf("Charging Status: In Progress\n");
            break;
        case CHARGING_COMPLETE:
            printf("Charging Status: Complete\n");
            break;
        case CHARGING_ERROR:
            printf("Charging Status: Error\n");
            break;
        default:
            break;
 
