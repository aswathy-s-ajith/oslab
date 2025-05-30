#include <stdio.h>
#include <stdlib.h>

#define MAX_REQUESTS 100

// Function to calculate total seek time using SCAN algorithm
int calculateTotalSeekTime(int *requests, int numRequests) {
    int totalSeekTime = 0;
    int currentTrack = 0;
    int direction = 1;  // Moving right initially

    for (int i = 0; i < numRequests; i++) {
        while (currentTrack >= 0 && currentTrack <= 199) {
            // Check if request exists at current track
            if (requests[i] == currentTrack) { // Add seek time
                requests[i] = -1;  // Mark request as serviced
                break;
            }
            currentTrack += direction;  // Move in current direction
            totalSeekTime++;  // Increment seek time
        }
      if (currentTrack == 200) {  
        direction = -1;  // Reverse direction
        currentTrack = 199;
    }
    else if (currentTrack == -1) {
        direction = 1;  // Move right again
        currentTrack = 0;
    }

    }

    // Change direction when boundary is reached
    
    return totalSeekTime;  // Return total seek time
}

int main() {
    int requests[MAX_REQUESTS];
    int numRequests;

    // Get number of disk requests from user
    printf("Enter the number of disk requests: ");
    scanf("%d", &numRequests);

    // Validate input
    if (numRequests <= 0 || numRequests > MAX_REQUESTS) {
        printf("Invalid number of requests.\n");
        return 1;  // Exit if invalid input
    }

    // Get disk requests
    printf("Enter the disk requests (track numbers):\n");
    for (int i = 0; i < numRequests; i++) {
        scanf("%d", &requests[i]);
    }

    // Calculate total seek time
    int totalSeekTime = calculateTotalSeekTime(requests, numRequests);

    // Display result
    printf("Total seek time using SCAN: %d\n", totalSeekTime);
    
    return 0;
}
