#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 32

// Structure to represent a product
typedef struct {
    float price;
    char description[50];
} Product;

// Function to find and print valid configurations within the budget
void findValidConfigurations(float targetAmount, float currentAmount, Product* products, int numProducts, int* chosenProducts, int chosenCount, FILE* outputFile) {
    if (currentAmount == targetAmount) {
        // Print the current combination
        fprintf(outputFile, "Combination: ");

        for (int i = 0; i < chosenCount; i++) {
            fprintf(outputFile, "product %d (%s)", chosenProducts[i], products[chosenProducts[i] - 1].description);

            if (i < chosenCount - 1) {
                fprintf(outputFile, ", ");
            }
        }

        fprintf(outputFile, " - sum: %.2f\n", targetAmount);
        return;
    }

    if (currentAmount > targetAmount || numProducts <= 0) {
        return;
    }

    // Include the current product in the configuration
    chosenProducts[chosenCount] = numProducts;
    findValidConfigurations(targetAmount, currentAmount + products[numProducts - 1].price, products, numProducts - 1, chosenProducts, chosenCount + 1, outputFile);

    // Exclude the current product from the configuration
    findValidConfigurations(targetAmount, currentAmount, products, numProducts - 1, chosenProducts, chosenCount, outputFile);
}

int main() {
    FILE* inputFile;
    FILE* outputFile;

    fopen_s(&inputFile, "input.txt", "r");
    fopen_s(&outputFile, "output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    float totalAmount;
    fscanf_s(inputFile, "%f", &totalAmount);

    printf("Budget from the first line: %.2f\n", totalAmount);

    Product products[MAX_PRODUCTS];
    memset(products, 0, sizeof(products));
    int numProducts = 0;

    // Read product details from input file
    while (fscanf_s(inputFile, "%f %[^\n]", &products[numProducts].price, products[numProducts].description, (unsigned)_countof(products[numProducts].description)) != EOF) {
        printf("Product %d: %s - %.2f\n", numProducts + 1, products[numProducts].description, products[numProducts].price);
        numProducts++;
    }

    printf("Read %d products from the file.\n", numProducts);

    int chosenProducts[MAX_PRODUCTS];

    // Find and print valid configurations within the budget
    findValidConfigurations(totalAmount, 0, products, numProducts, chosenProducts, 0, outputFile);

    printf("Valid configurations written to 'output.txt'.\n");

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}