#include <iostream>
#include <string>
#include <algorithm> // For std::max

void printLine(int space, int stars) {
    // Ensure that space and stars are not negative
    space = std::max(0, space);
    stars = std::max(0, stars);

    std::cout << std::string(space, ' ') << std::string(stars, '*') << std::endl;
}

void printBlock(int start_stars, int lines, int space) {
    for (int i = 0; i < lines; ++i) {
        printLine(space - i, start_stars + 2 * i);
    }
}

void printTree(int base_lines) {
    // Ensure that the maximum width calculation does not result in a negative number
    int max_width = std::max(1, 1 + 2 * (base_lines - 1));

    // Calculate initial spacing based on the maximum width of the tree
    int space = (max_width - 1) / 2 + (base_lines + 4);

    // Print block 1
    printBlock(1, base_lines, space);

    // Print block 2, which starts with 2 stars less than the last line of block 1
    int start_stars = 1 + 2 * (base_lines - 1) - 2;
    printBlock(start_stars, base_lines + 2, space - 1);

    // Print block 3, which starts with 6 stars less than the last line of block 2
    start_stars += 2 * (base_lines + 1) - 6;
    printBlock(start_stars, base_lines + 4, space - 3);

    // Print stem, with a width of one-third of base_lines, rounded up to the nearest odd number
    int stem_width = std::max(1, (base_lines % 2 == 0) ? base_lines + 1 : base_lines) / 3;
    int stem_space = (max_width - stem_width) / 2;
    for (int i = 0; i < base_lines; ++i) {
        printLine(stem_space, stem_width);
    }
}

int main() {
    int lines;
    std::cout << "Enter number of lines for the top of the tree: ";
    std::cin >> lines;

    if (lines <= 0) {
        std::cout << "Number of lines must be a positive integer." << std::endl;
        return 1;
    }

    printTree(lines);

    return 0;
}
