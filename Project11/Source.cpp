#include <iostream>
#include <string>

class ChristmasTree {
public:
    // Constructor
    ChristmasTree(int lines) : base_lines(lines) {}

    // Function to display the tree
    void display() {
        int total_width = base_lines * 2 - 1; // Total width of the largest tree block
        displayBlock(base_lines, total_width);
        displayBlock(base_lines + 2, total_width);
        displayBlock(base_lines + 4, total_width);
        displayStem(total_width);
    }

private:
    int base_lines;

    // Function to display one block of the tree
    void displayBlock(int lines, int total_width) {
        for (int i = 0; i < lines; ++i) {
            int asterisks = 1 + i * 2; // Number of asterisks
            int padding = (total_width - asterisks) / 2; // Padding on each side
            // Check for negative padding and adjust if necessary
            if (padding < 0) {
                padding = 0;
            }
            std::cout << std::string(padding, ' ') + std::string(asterisks, '*') + std::string(padding, ' ') << std::endl;
        }
    }

    // Function to display the stem of the tree
    void displayStem(int total_width) {
        int stem_height = 4; // The stem is 4 '*' signs tall
        int stem_width = base_lines / 3 | 1; // Ensure stem_width is odd so the stem is centered
        int padding = (total_width - stem_width) / 2;
        // Check for negative padding and adjust if necessary
        if (padding < 0) {
            padding = 0;
        }

        for (int i = 0; i < stem_height; ++i) {
            std::cout << std::string(padding, ' ') + std::string(stem_width, '*') + std::string(padding, ' ') << std::endl;
        }
    }
};

int main() {
    int lines;
    std::cout << "Enter number of lines for the base of the tree: ";
    std::cin >> lines;

    // Check for negative or zero lines input
    if (lines <= 0) {
        std::cout << "Number of lines must be a positive integer." << std::endl;
        return 1;
    }

    ChristmasTree tree(lines);
    tree.display();

    return 0;
}
