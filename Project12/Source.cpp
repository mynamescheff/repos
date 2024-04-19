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

void printTree(int base_lines, int console_width) {
    // Calculate the maximum width of the tree
    int max_width = 1 + 2 * (base_lines - 1 + 2 + 4); // Based on block 3, which is the widest

    // Calculate the extra padding needed to center the tree in the console
    int extra_padding = (console_width - max_width) / 2;
    extra_padding = std::max(0, extra_padding); // Ensure padding is not negative

    // Initial space calculation including extra padding
    int initial_space = ((max_width - 1) / 2) + extra_padding;

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
    const int console_width = 120; // Adjust this to your actual console width
    // If the printout is not centered, set console to full screen or adjust the console width (works on 4k monitor for me)

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
        else {
            break; // Valid input
        }
    }

    printTree(lines, console_width);
    return 0;
    }
