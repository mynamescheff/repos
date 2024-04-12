#include <iostream>
#include <string>

class ChristmasTree {
public:
    ChristmasTree(int lines) : base_lines(lines) {}

    void display() {
        int max_asterisks = 1 + 2 * (base_lines + 4 + 4 - 1);  // Calculate the maximum number of asterisks at the bottom
        int total_width = max_asterisks; // Use this for consistent centering

        // Start asterisks calculations adjusted from your description
        int start_asterisks_block1 = 1;
        int start_asterisks_block2 = 1 + 2 * (base_lines - 2);
        int start_asterisks_block3 = start_asterisks_block2 + 2 * 2 - 6;

        displayBlock(base_lines, total_width, start_asterisks_block1);
        displayBlock(base_lines + 2, total_width, start_asterisks_block2);
        displayBlock(base_lines + 4, total_width, start_asterisks_block3);
        displayStem(total_width);
    }

private:
    int base_lines;

    void displayBlock(int lines, int total_width, int start_asterisks) {
        for (int i = 0; i < lines; ++i) {
            int asterisks = start_asterisks + i * 2;
            int padding = (total_width - asterisks) / 2;
            std::cout << std::string(padding, ' ') + std::string(asterisks, '*') + std::string(padding, ' ') << std::endl;
        }
    }

    void displayStem(int total_width) {
        int stem_width = base_lines / 3 | 1; // Ensure stem_width is odd
        int padding = (total_width - stem_width) / 2;
        for (int i = 0; i < base_lines; ++i) {  // stem height matches base_lines
            std::cout << std::string(padding, ' ') + std::string(stem_width, '*') + std::string(padding, ' ') << std::endl;
        }
    }
};

int main() {
    int lines;
    std::cout << "Enter number of lines for the top of the tree: ";
    std::cin >> lines;

    if (lines <= 0) {
        std::cout << "Number of lines must be a positive integer." << std::endl;
        return 1;
    }

    ChristmasTree tree(lines);
    tree.display();

    return 0;
}
