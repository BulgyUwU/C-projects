#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
/*99 Bottles

Create a program that prints out every line to the song "99 bottles of beer on the wall."

    -Do not use a list for all of the numbers, and do not manually type them all in. Use a built in function instead.
    -Besides the phrase "take one down," you may not type in any numbers/names of numbers directly into your song lyrics.
    -Remember, when you reach 1 bottle left, the word "bottles" becomes singular.

*/

int main() {
    int n_bottles = 99;
    printf("press enter to print each verse. (q to quit)");
    while (n_bottles) {
        if (getchar() == 'q') exit(0);
        printf("%d %s of beer on the wall.\n", n_bottles, n_bottles == 1 ? "bottle" : "bottles");
        printf("%d %s of beer.\n", n_bottles, n_bottles == 1 ? "bottle" : "bottles");
        printf("Take one down, pass it around.\n");
        printf("%d %s of beer on the wall.\n", --n_bottles, n_bottles - 1 == 1 ? "bottle" : "bottles");
    }
    printf("There's no beer left, Bye!\n");
    return 0;
}