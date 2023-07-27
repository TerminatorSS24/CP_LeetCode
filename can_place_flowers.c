#include <stdbool.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int count = 0;
    
    for (int i = 0; i < flowerbedSize; i++) {
        if (flowerbed[i] == 0) {
            bool prevEmpty = (i == 0) || (flowerbed[i - 1] == 0);
            bool nextEmpty = (i == flowerbedSize - 1) || (flowerbed[i + 1] == 0);
            
            if (prevEmpty && nextEmpty) {
                flowerbed[i] = 1; 
                count++; 
            }
        }
    }
    
    return count >= n;
}