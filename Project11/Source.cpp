#include <iostream>
#include <string>

class ChristmasTree {
public:
    ChristmasTree(int lines) : base_lines(lines) {}

    void display() {
        int total_width = base_lines * 2 - 1 + base_lines + 5; // Adjusting total width
        displayBlock(base_lines, total_width);
        displayBlock(base_lines + 2, total_width);
        displayBlock(base_lines + 4, total_width);
        displayStem(total_width);
    }

private:
    int base_lines;

    void displayBlock(int lines, int total_width) {
        for (int i = 0; i < lines; ++i) {
            int asterisks = 1 + i * 2;
            int padding = (total_width - asterisks) / 2;
            if (padding < 0) {
                padding = 0;
            }
            std::cout << std::string(padding, ' ') + std::string(asterisks, '*') + std::string(padding, ' ') << std::endl;
        }
    }

    void displayStem(int total_width) {
        int stem_height = 4;
        int stem_width = base_lines / 3 | 1; // Ensure stem_width is odd
        int padding = (total_width - stem_width) / 2;
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

    if (lines <= 0) {
        std::cout << "Number of lines must be a positive integer." << std::endl;
        return 1;
    }

    ChristmasTree tree(lines);
    tree.display();

    return 0;
}
