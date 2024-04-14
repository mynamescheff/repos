#include <iostream>
#include <string>
#include <algorithm> // For std::max

void printLine(int space, int stars) {
    // Ensure that space and stars are not negative
    space = std::max(0, space);
    stars = std::max(0, stars);

    std::cout << std::string(space, ' ') << std::string(stars, '*') << std::endl;
}

void printBlock(int start_stars, int lines, int initial_space, int max_width) {
    for (int i = 0; i < lines; ++i) {
        // Calculate the space needed to center the current line
        int current_stars = start_stars + 2 * i;
        int space = initial_space + (max_width - current_stars) / 2;
        printLine(space, current_stars);
    }
}

void printTree(int base_lines) {
    // Calculate the maximum width of the tree
    int max_width = 1 + 2 * (base_lines - 1 + 2 + 4); // Calculating based on block 3, which is the widest

    // Initial space calculation
    int initial_space = (max_width - 1) / 2;

    // Store the first line's space amount to use for stem alignment
    int first_line_space = initial_space;

    // Print block 1
    printBlock(1, base_lines, initial_space, max_width);

    // Print block 2, which starts with 2 stars less than the last line of block 1
    int start_stars = 1 + 2 * (base_lines - 1) - 2;
    printBlock(start_stars, base_lines + 2, initial_space, max_width);

    // Print block 3, which starts with 6 stars less than the last line of block 2
    start_stars += 2 * (base_lines + 1) - 6;
    printBlock(start_stars, base_lines + 4, initial_space, max_width);

    // Stem width should be one-third the base_lines, rounded up to nearest odd number
    int stem_width = std::max(1, (base_lines % 2 == 0) ? base_lines + 1 : base_lines) / 3;

    // Use the first line's space for the stem to ensure it aligns properly
    int stem_space = first_line_space + (max_width - stem_width) / 2;

    // Print stem
    for (int i = 0; i < base_lines; ++i) {
        printLine(stem_space, stem_width);
    }
}

int main() {
    int lines;

    while (true) {
        std::cout << "Enter number of lines for the top of the tree: ";
        std::cin >> lines;

        if (std::cin.fail() || lines <= 0) {
            std::cin.clear(); // Clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore bad input
            std::cout << "Number of lines must be a positive integer." << std::endl;
        }
        else if (lines < 2) {
            std::cout << "The tree must have at least 2 lines to look like a tree." << std::endl;
        }
        else if (lines > 11) {
            std::cout << "The tree will look weird with more than 11 lines." << std::endl;
        }
        else {
            break; // Valid input
        }
    }

    printTree(lines);
    return 0;
}
